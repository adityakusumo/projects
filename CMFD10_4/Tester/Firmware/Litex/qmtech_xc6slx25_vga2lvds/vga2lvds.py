"""
VGA-to-LVDS Bridge - LiteX/Migen
Accepts standard VGA signals and serializes them to 7:1 LVDS (JEIDA/OpenLDI)

Input:  pixel clock (e.g. 40MHz), DE or HSync/VSync, RGB888
Output: 4x LVDS data lanes + 1x LVDS clock lane
"""

from migen import *


# ============================================================
# CK1DATA: LVDS clock pattern "1100011" (bits 0-6, LSB first)
# ============================================================
CK1DATA = 0b1100011  # bit0=1, bit1=1, bit2=0, bit3=0, bit4=0, bit5=1, bit6=1


class VGAToLVDS(Module):
    def __init__(self):
        # --------------------------------------------------
        # I/O Ports
        # --------------------------------------------------
        # VGA inputs (from external source / platform pins)
        self.pclk  = pclk  = Signal()        # pixel clock (e.g. 40MHz)
        self.de    = de    = Signal()         # data enable (active high)
        self.hsync = hsync = Signal()         # hsync (polarity depends on source)
        self.vsync = vsync = Signal()         # vsync (polarity depends on source)
        self.r     = r     = Signal(8)        # red   8-bit
        self.g     = g     = Signal(8)        # green 8-bit
        self.b     = b     = Signal(8)        # blue  8-bit

        self.en_video = en_video = Signal()    # active-low: enable BIST
        self.bist   = bist   = Signal()        # active-high BIST output

        # LVDS outputs
        self.ck1in_p = ck1in_p = Signal()
        self.ck1in_n = ck1in_n = Signal()
        self.tx_p    = tx_p    = Signal(4)
        self.tx_n    = tx_n    = Signal(4)

        # --------------------------------------------------
        # 1. Clock Generation
        #    DCM_SP: pclk * 7 -> cd_fast (280MHz for 40MHz input)
        #    Adjust CLKFX_MULTIPLY/DIVIDE for other pixel clocks
        # --------------------------------------------------
        self.clock_domains.cd_fast = ClockDomain()
        clkout_fast = Signal()
        self.specials += Instance("DCM_SP",
            p_CLKFX_DIVIDE   = 1,
            p_CLKFX_MULTIPLY = 7,    # 40MHz * 7 = 280MHz
            p_CLKIN_PERIOD   = 25.0, # 40MHz = 25ns
            i_CLKIN  = pclk,
            i_RST    = 0,
            o_CLKFX  = clkout_fast,
        )
        self.specials += Instance("BUFG", i_I=clkout_fast, o_O=self.cd_fast.clk)

        # --------------------------------------------------
        # 2. Internal Signals
        # --------------------------------------------------
        slot = Signal(3, reset=0)   # serializer slot 0-6

        RX0DATA     = Signal(7)
        RX1DATA     = Signal(7)
        RX2DATA     = Signal(7)
        RX3DATA     = Signal(7)
        CK1DATA_sig = Signal(7, reset=CK1DATA)

        RXIN0 = Signal()
        RXIN1 = Signal()
        RXIN2 = Signal()
        RXIN3 = Signal()
        CK1IN = Signal()

        # --------------------------------------------------
        # Combinational: timing flags & BIST
        # --------------------------------------------------
        self.comb += [
            bist.eq(~en_video),
        ]

        # --------------------------------------------------
        # 3. LVDS Bitstream Packing (combinational)
        #
        #  RX3: [0]=0,      [1:2]=b[7:6], [3:4]=g[7:6], [5:6]=r[7:6]
        #  RX2: [0]=de,     [1]=hsync,    [2]=vsync,     [3:6]=b[5:2]
        #  RX1: [0:1]=b[1:0],[2:6]=g[5:1]
        #  RX0: [0]=g[0],   [1:6]=r[5:0]
        # --------------------------------------------------
        self.comb += [
            RX3DATA[0].eq(0),
            RX3DATA[1].eq(b[7]),
            RX3DATA[2].eq(b[6]),
            RX3DATA[3].eq(g[7]),
            RX3DATA[4].eq(g[6]),
            RX3DATA[5].eq(r[7]),
            RX3DATA[6].eq(r[6]),

            RX2DATA[0].eq(de),
            RX2DATA[1].eq(hsync),   # pass through hsync
            RX2DATA[2].eq(vsync),   # pass through vsync
            RX2DATA[3].eq(b[5]),
            RX2DATA[4].eq(b[4]),
            RX2DATA[5].eq(b[3]),
            RX2DATA[6].eq(b[2]),

            RX1DATA[0].eq(b[1]),
            RX1DATA[1].eq(b[0]),
            RX1DATA[2].eq(g[5]),
            RX1DATA[3].eq(g[4]),
            RX1DATA[4].eq(g[3]),
            RX1DATA[5].eq(g[2]),
            RX1DATA[6].eq(g[1]),

            RX0DATA[0].eq(g[0]),
            RX0DATA[1].eq(r[5]),
            RX0DATA[2].eq(r[4]),
            RX0DATA[3].eq(r[3]),
            RX0DATA[4].eq(r[2]),
            RX0DATA[5].eq(r[1]),
            RX0DATA[6].eq(r[0]),
        ]

        # --------------------------------------------------
        # 4. Serializer (280MHz domain, 7 slots per pixel clock)
        # --------------------------------------------------
        self.sync.fast += [
            Case(slot, {
                0: [RXIN0.eq(RX0DATA[0]), RXIN1.eq(RX1DATA[0]), RXIN2.eq(RX2DATA[0]), RXIN3.eq(RX3DATA[0]), CK1IN.eq(CK1DATA_sig[0])],
                1: [RXIN0.eq(RX0DATA[1]), RXIN1.eq(RX1DATA[1]), RXIN2.eq(RX2DATA[1]), RXIN3.eq(RX3DATA[1]), CK1IN.eq(CK1DATA_sig[1])],
                2: [RXIN0.eq(RX0DATA[2]), RXIN1.eq(RX1DATA[2]), RXIN2.eq(RX2DATA[2]), RXIN3.eq(RX3DATA[2]), CK1IN.eq(CK1DATA_sig[2])],
                3: [RXIN0.eq(RX0DATA[3]), RXIN1.eq(RX1DATA[3]), RXIN2.eq(RX2DATA[3]), RXIN3.eq(RX3DATA[3]), CK1IN.eq(CK1DATA_sig[3])],
                4: [RXIN0.eq(RX0DATA[4]), RXIN1.eq(RX1DATA[4]), RXIN2.eq(RX2DATA[4]), RXIN3.eq(RX3DATA[4]), CK1IN.eq(CK1DATA_sig[4])],
                5: [RXIN0.eq(RX0DATA[5]), RXIN1.eq(RX1DATA[5]), RXIN2.eq(RX2DATA[5]), RXIN3.eq(RX3DATA[5]), CK1IN.eq(CK1DATA_sig[5])],
                6: [RXIN0.eq(RX0DATA[6]), RXIN1.eq(RX1DATA[6]), RXIN2.eq(RX2DATA[6]), RXIN3.eq(RX3DATA[6]), CK1IN.eq(CK1DATA_sig[6])],
            }),
            If(slot == 6,
                slot.eq(0),
            ).Else(
                slot.eq(slot + 1),
            )
        ]

        # --------------------------------------------------
        # 5. LVDS Output Buffers
        # --------------------------------------------------
        self.specials += Instance("OBUFDS", i_I=CK1IN,  o_O=ck1in_p, o_OB=ck1in_n)
        self.specials += Instance("OBUFDS", i_I=RXIN0,  o_O=tx_p[0], o_OB=tx_n[0])
        self.specials += Instance("OBUFDS", i_I=RXIN1,  o_O=tx_p[1], o_OB=tx_n[1])
        self.specials += Instance("OBUFDS", i_I=RXIN2,  o_O=tx_p[2], o_OB=tx_n[2])
        self.specials += Instance("OBUFDS", i_I=RXIN3,  o_O=tx_p[3], o_OB=tx_n[3])

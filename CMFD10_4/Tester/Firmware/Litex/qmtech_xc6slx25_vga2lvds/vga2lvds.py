"""
vga_to_lvds.py
Accepts a LiteX video_data_layout stream and serializes to 7:1 LVDS (JEIDA/OpenLDI).

Plug directly into VideoTimingGenerator + ColorBarsPattern pipeline from litex.soc.cores.video.
Stream layout expected: hsync, vsync, de, r[8], g[8], b[8]

Input pixel clock: sys clock domain (39MHz from CRG)
DCM_SP x7 -> 273MHz cd_fast for serialization
"""

from migen import *
from litex.soc.interconnect import stream
from litex.soc.cores.video import video_data_layout

# LVDS clock pattern "1100011" packed as integer (bit 0 = first transmitted)
CK1DATA = 0b1100011


class VGAToLVDS(Module):
    def __init__(self, pclk_freq=40e6):
        # --------------------------------------------------
        # Stream Sink  (connects to ColorBarsPattern.source)
        # --------------------------------------------------
        self.sink = sink = stream.Endpoint(video_data_layout)

        # Always accept data, no backpressure
        self.comb += sink.ready.eq(1)

        # --------------------------------------------------
        # LVDS Output Pads
        # --------------------------------------------------
        self.ck1in_p = ck1in_p = Signal()
        self.ck1in_n = ck1in_n = Signal()
        self.tx_p    = tx_p    = Signal(4)
        self.tx_n    = tx_n    = Signal(4)

        # --------------------------------------------------
        # 1. Clock: DCM_SP  sys_clk * 7 -> cd_fast
        #    39MHz * 7 = 273MHz  (7:1 serialization domain)
        # --------------------------------------------------
        self.clock_domains.cd_fast = ClockDomain()
        clkout_fast  = Signal()
        pclk_period_ns = 1e9 / pclk_freq   # 39MHz -> ~25.64ns

        self.specials += Instance("DCM_SP",
            p_CLKFX_DIVIDE   = 1,
            p_CLKFX_MULTIPLY = 7,
            p_CLKIN_PERIOD   = pclk_period_ns,
            i_CLKIN = ClockSignal("sys"),
            i_RST   = 0,
            o_CLKFX = clkout_fast,
        )
        self.specials += Instance("BUFG", i_I=clkout_fast, o_O=self.cd_fast.clk)

        # --------------------------------------------------
        # 2. Internal signals
        # --------------------------------------------------
        slot        = Signal(3, reset=0)
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

        # Aliases for readability
        de    = sink.de
        hsync = sink.hsync
        vsync = sink.vsync
        r     = sink.r
        g     = sink.g
        b     = sink.b

        # --------------------------------------------------
        # 3. LVDS Bitstream Packing  (JEIDA / OpenLDI)
        #
        #  RX3: [0]=0,    [1]=b[7],[2]=b[6],[3]=g[7],[4]=g[6],[5]=r[7],[6]=r[6]
        #  RX2: [0]=de,   [1]=hsync,[2]=vsync,[3]=b[5],[4]=b[4],[5]=b[3],[6]=b[2]
        #  RX1: [0]=b[1], [1]=b[0],[2]=g[5],[3]=g[4],[4]=g[3],[5]=g[2],[6]=g[1]
        #  RX0: [0]=g[0], [1]=r[5],[2]=r[4],[3]=r[3],[4]=r[2],[5]=r[1],[6]=r[0]
        # --------------------------------------------------
        self.comb += [
            RX3DATA[0].eq(0),
            RX3DATA[1].eq(b[7]),  RX3DATA[2].eq(b[6]),
            RX3DATA[3].eq(g[7]),  RX3DATA[4].eq(g[6]),
            RX3DATA[5].eq(r[7]),  RX3DATA[6].eq(r[6]),

            RX2DATA[0].eq(de),
            RX2DATA[1].eq(hsync), RX2DATA[2].eq(vsync),
            RX2DATA[3].eq(b[5]),  RX2DATA[4].eq(b[4]),
            RX2DATA[5].eq(b[3]),  RX2DATA[6].eq(b[2]),

            RX1DATA[0].eq(b[1]),  RX1DATA[1].eq(b[0]),
            RX1DATA[2].eq(g[5]),  RX1DATA[3].eq(g[4]),
            RX1DATA[4].eq(g[3]),  RX1DATA[5].eq(g[2]),
            RX1DATA[6].eq(g[1]),

            RX0DATA[0].eq(g[0]),
            RX0DATA[1].eq(r[5]),  RX0DATA[2].eq(r[4]),
            RX0DATA[3].eq(r[3]),  RX0DATA[4].eq(r[2]),
            RX0DATA[5].eq(r[1]),  RX0DATA[6].eq(r[0]),
        ]

        # --------------------------------------------------
        # 4. Serializer  (cd_fast domain, 7 slots per pixel clock)
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
        # 5. LVDS Output Buffers (OBUFDS primitives)
        # --------------------------------------------------
        self.specials += Instance("OBUFDS", i_I=CK1IN,  o_O=ck1in_p, o_OB=ck1in_n)
        self.specials += Instance("OBUFDS", i_I=RXIN0,  o_O=tx_p[0], o_OB=tx_n[0])
        self.specials += Instance("OBUFDS", i_I=RXIN1,  o_O=tx_p[1], o_OB=tx_n[1])
        self.specials += Instance("OBUFDS", i_I=RXIN2,  o_O=tx_p[2], o_OB=tx_n[2])
        self.specials += Instance("OBUFDS", i_I=RXIN3,  o_O=tx_p[3], o_OB=tx_n[3])

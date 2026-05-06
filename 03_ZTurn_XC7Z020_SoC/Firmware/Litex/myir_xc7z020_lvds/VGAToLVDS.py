"""
VGAToLVDS.py
Input: cd_pix (48 MHz) provided externally by CRG
PLLE2_ADV takes cd_pix and multiplies x7 -> cd_fast (336 MHz) for OSERDESE2
"""

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer
from litex.soc.interconnect import stream
from litex.soc.cores.video import video_data_layout

TX_CLK_PATTERN = 0b1100011


class VGAToLVDS(Module):
    def __init__(self, pclk_freq=48e6):
        self.sink = sink = stream.Endpoint(video_data_layout)
        self.comb += sink.ready.eq(1)

        self.ck_p = ck_p = Signal()
        self.ck_n = ck_n = Signal()
        self.tx_p = tx_p = Signal(4)
        self.tx_n = tx_n = Signal(4)

        # --------------------------------------------------
        # 1. PLLE2_ADV: cd_pix (48MHz) -> cd_fast (336MHz = 48*7)
        #    Input is ClockSignal("pix") — provided by CRG via crg_pix,
        #    renamed to "pix" by ClockDomainsRenamer in soc.py
        #    Only cd_fast is generated here; cd_pix comes from outside.
        # --------------------------------------------------
        self.clock_domains.cd_fast = ClockDomain()

        pclk_period_ns = 1e9 / pclk_freq
        clkout_fast    = Signal()
        clkfb          = Signal()
        clkfb_buf      = Signal()
        locked         = Signal()

        self.specials += Instance("PLLE2_ADV",
            p_BANDWIDTH          = "OPTIMIZED",
            p_COMPENSATION       = "ZHOLD",
            p_STARTUP_WAIT       = "FALSE",
            p_DIVCLK_DIVIDE      = 1,
            # VCO = 48 MHz * 21 = 1008 MHz  (within 800-1866 MHz for Zynq-7020)
            # cd_fast = VCO / 3 = 336 MHz   (7x pixel clock for OSERDESE2)
            p_CLKFBOUT_MULT      = 21,
            p_CLKFBOUT_PHASE     = 0.0,
            p_CLKIN1_PERIOD      = pclk_period_ns,
            # CLKOUT0: 7x fast clock for OSERDESE2 CLK = 1008/3 = 336 MHz
            p_CLKOUT0_DIVIDE     = 3,
            p_CLKOUT0_PHASE      = 0.0,
            p_CLKOUT0_DUTY_CYCLE = 0.5,
            # CLKFBOUT feeds back directly as pixel clock reference
            i_CLKIN1   = ClockSignal("pix"),  # 48 MHz from CRG
            i_CLKIN2   = 0,
            i_CLKINSEL = 1,
            i_RST      = ResetSignal("pix"),
            i_PWRDWN   = 0,
            i_CLKFBIN  = clkfb_buf,
            o_CLKFBOUT = clkfb,
            o_CLKOUT0  = clkout_fast,
            o_LOCKED   = locked,
        )
        self.specials += Instance("BUFG", i_I=clkfb,       o_O=clkfb_buf)
        self.specials += Instance("BUFG", i_I=clkout_fast,  o_O=self.cd_fast.clk)

        # cd_fast reset: driven only by locked signal, not touching cd_pix reset
        # AsyncResetSynchronizer for cd_fast only — cd_pix reset is owned by CRG
        self.specials += AsyncResetSynchronizer(self.cd_fast, ~locked)

        # reset_int: registered in cd_fast domain (matches XAPP585 pattern)
        # Do NOT use sync.pix here — cd_pix reset is owned by CRG, not VGAToLVDS
        reset_int = Signal(reset=1)
        self.sync.fast += reset_int.eq(~locked)

        # --------------------------------------------------
        # 2. LVDS Bitstream Packing (JEIDA / OpenLDI)
        # --------------------------------------------------
        de    = sink.de
        hsync = sink.hsync
        vsync = sink.vsync
        r     = sink.r
        g     = sink.g
        b     = sink.b

        RX0DATA = Signal(7)
        RX1DATA = Signal(7)
        RX2DATA = Signal(7)
        RX3DATA = Signal(7)

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
        # 3. OSERDESE2 — SDR, DATA_WIDTH=7, MASTER only (XAPP585)
        # --------------------------------------------------
        def add_oserdese2(data7, out_p, out_n):
            oq = Signal()
            self.specials += Instance("OSERDESE2",
                p_DATA_RATE_OQ   = "SDR",
                p_DATA_RATE_TQ   = "SDR",
                p_DATA_WIDTH     = 7,
                p_TRISTATE_WIDTH = 1,
                p_SERDES_MODE    = "MASTER",
                i_CLK     = ClockSignal("fast"),  # 336 MHz
                i_CLKDIV  = ClockSignal("pix"),   # 48 MHz
                i_RST     = reset_int,
                i_OCE     = 1,
                i_TCE     = 1,
                i_T1=0, i_T2=0, i_T3=0, i_T4=0,
                i_TBYTEIN = 0,
                i_D1 = data7[0], i_D2 = data7[1],
                i_D3 = data7[2], i_D4 = data7[3],
                i_D5 = data7[4], i_D6 = data7[5],
                i_D7 = data7[6], i_D8 = 0,
                i_SHIFTIN1  = 0,
                i_SHIFTIN2  = 0,
                o_OQ        = oq,
                o_SHIFTOUT1 = Signal(),
                o_SHIFTOUT2 = Signal(),
            )
            self.specials += Instance("OBUFDS",
                i_I=oq, o_O=out_p, o_OB=out_n,
            )

        ck_data = Signal(7, reset=TX_CLK_PATTERN)
        add_oserdese2(RX0DATA, tx_p[0], tx_n[0])
        add_oserdese2(RX1DATA, tx_p[1], tx_n[1])
        add_oserdese2(RX2DATA, tx_p[2], tx_n[2])
        add_oserdese2(RX3DATA, tx_p[3], tx_n[3])
        add_oserdese2(ck_data,  ck_p,    ck_n)

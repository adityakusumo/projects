"""
LVDS Transmitter - LiteX/Migen port of lvds_transmit.vhd
Target: Xilinx Spartan-6 (or compatible via LiteX platform)

Original: 960x1280 @ 60Hz custom resolution, 7:1 LVDS serialization
Clock: 40MHz input -> 280MHz via DCM_SP (x7)
"""

from migen import *
from migen.genlib.misc import WaitTimer
from litex.soc.cores.clock import S6DCM  # Spartan-6 DCM wrapper


# ============================================================
# Resolution / Timing Constants
# ============================================================
HRES  = 960
VRES  = 1280

HFPOR = 20
HSYN  = 10
HBPOR = 30

VFPOR = 10
VSYN  = 4
VBPOR = 26

H_MAX      = HRES - 1
HDAT_BEGIN = HBPOR + HSYN - 1
HDAT_END   = HDAT_BEGIN + HRES
HPIXEL_END = HDAT_END + HFPOR

V_MAX      = VRES - 1
VDAT_BEGIN = VBPOR + VSYN - 1
VDAT_END   = VDAT_BEGIN + VRES
VLINE_END  = VDAT_END + VFPOR

# ============================================================
# Rainbow / Color Bar Constants
# ============================================================
NUM_SEGMENTS = 9
INCREMENT    = VRES // NUM_SEGMENTS
LINE = [INCREMENT * (i + 1) for i in range(NUM_SEGMENTS)]

CK1DATA = 0b1100011  # "1100011" MSB-first -> bits 0..6





# ============================================================
# Main Module
# ============================================================
class LVDSTransmit(Module):
    def __init__(self, platform):
        # --------------------------------------------------
        # I/O Ports
        # --------------------------------------------------
        self.clk_in   = clk_in   = Signal()   # 40 MHz input clock
        self.en_video = en_video = Signal()    # active-low: enable BIST
        self.rainbow  = rainbow  = Signal()    # active-low: rainbow mode

        self.bist   = bist   = Signal()        # active-high BIST output

        self.ck1in_p = ck1in_p = Signal()
        self.ck1in_n = ck1in_n = Signal()
        self.tx_p    = tx_p    = Signal(4)
        self.tx_n    = tx_n    = Signal(4)

        # --------------------------------------------------
        # 1. Clock Generation  (Spartan-6 DCM, x7 -> 280 MHz)
        # --------------------------------------------------
        self.clock_domains.cd_fast = ClockDomain("fast")

        # Using LiteX S6DCM helper (adjust if using raw Instance instead)
        self.submodules.dcm = dcm = S6DCM(speedgrade=-2)
        dcm.register_clkin(clk_in, 40e6)
        dcm.create_clkout(self.cd_fast, 280e6)

        # # In LVDSTransmit.__init__, replace the DCM block with:
        # self.clock_domains.cd_fast = ClockDomain()
        #
        # clkout_fast = Signal()
        # self.specials += Instance("DCM_SP",
        #     p_CLKFX_DIVIDE   = 1,
        #     p_CLKFX_MULTIPLY = 7,   # 40MHz * 7 = 280MHz
        #     i_CLKIN  = clk_in,
        #     i_RST    = 0,
        #     o_CLKFX  = clkout_fast,
        # )
        # self.specials += Instance("BUFG", i_I=clkout_fast, o_O=self.cd_fast.clk)

        # --------------------------------------------------
        # 2. Internal Signals
        # --------------------------------------------------
        slot  = Signal(3, reset=0)   # 0-6 serializer slot

        hcount = Signal(max=HPIXEL_END + 1, reset=0)
        vcount = Signal(max=VLINE_END  + 1, reset=0)
        ex     = Signal(11, reset=0)   # pixel x within active area
        ye     = Signal(11, reset=0)   # pixel y within active area

        red   = Signal(8)
        green = Signal(8)
        blue  = Signal(8)

        red_rainbow   = Signal(8)
        green_rainbow = Signal(8)
        blue_rainbow  = Signal(8)

        pix_de    = Signal()
        hcount_ov = Signal()
        vcount_ov = Signal()

        RX0DATA = Signal(7)
        RX1DATA = Signal(7)
        RX2DATA = Signal(7)
        RX3DATA = Signal(7)
        CK1DATA_sig = Signal(7, reset=CK1DATA)

        RXIN0 = Signal()
        RXIN1 = Signal()
        RXIN2 = Signal()
        RXIN3 = Signal()
        CK1IN = Signal()

        # --------------------------------------------------
        # 3. Combinational: timing flags & BIST
        # --------------------------------------------------
        self.comb += [
            hcount_ov.eq(hcount == HPIXEL_END),
            vcount_ov.eq(vcount == VLINE_END),
            pix_de.eq(
                (hcount >= HDAT_BEGIN) & (hcount < HDAT_END) &
                (vcount >= VDAT_BEGIN) & (vcount < VDAT_END)
            ),
            bist.eq(~en_video),
        ]

        # --------------------------------------------------
        # 4. Rainbow Color Generator (combinational, based on ye)
        # --------------------------------------------------
        # Red channel
        self.comb += [
            If(ye < LINE[0],  red_rainbow.eq(0xFF))
            .Elif(ye < LINE[1], red_rainbow.eq(0x00))
            .Elif(ye < LINE[2], red_rainbow.eq(0x00))
            .Elif(ye < LINE[3], red_rainbow.eq(0xFF))
            .Elif(ye < LINE[4], red_rainbow.eq(0x00))
            .Elif(ye < LINE[5], red_rainbow.eq(0xFF))
            .Elif(ye < LINE[6], red_rainbow.eq(0xFF))
            .Elif(ye < LINE[7], red_rainbow.eq(0x0F))
            .Else(              red_rainbow.eq(0x00))
        ]
        # Green channel
        self.comb += [
            If(ye < LINE[0],  green_rainbow.eq(0x00))
            .Elif(ye < LINE[1], green_rainbow.eq(0xFF))
            .Elif(ye < LINE[2], green_rainbow.eq(0x00))
            .Elif(ye < LINE[3], green_rainbow.eq(0xFF))
            .Elif(ye < LINE[4], green_rainbow.eq(0xFF))
            .Elif(ye < LINE[5], green_rainbow.eq(0x00))
            .Elif(ye < LINE[6], green_rainbow.eq(0xFF))
            .Elif(ye < LINE[7], green_rainbow.eq(0x0F))
            .Else(              green_rainbow.eq(0x00))
        ]
        # Blue channel
        self.comb += [
            If(ye < LINE[0],  blue_rainbow.eq(0x00))
            .Elif(ye < LINE[1], blue_rainbow.eq(0x00))
            .Elif(ye < LINE[2], blue_rainbow.eq(0xFF))
            .Elif(ye < LINE[3], blue_rainbow.eq(0x00))
            .Elif(ye < LINE[4], blue_rainbow.eq(0xFF))
            .Elif(ye < LINE[5], blue_rainbow.eq(0xFF))
            .Elif(ye < LINE[6], blue_rainbow.eq(0xFF))
            .Elif(ye < LINE[7], blue_rainbow.eq(0x0F))
            .Else(              blue_rainbow.eq(0x00))
        ]

        # Final color mux (rainbow=1 -> rainbow, rainbow=0 -> white)
        self.comb += [
            If(rainbow,
                red.eq(red_rainbow),
                green.eq(green_rainbow),
                blue.eq(blue_rainbow),
            ).Else(
                red.eq(0xFF),
                green.eq(0xFF),
                blue.eq(0xFF),
            )
        ]

        # --------------------------------------------------
        # 5. LVDS Bitstream Packing (combinational)
        #    Bit order in each 7-bit word: index 0 = first sent
        #
        #  RX3: [0]=0, [1:2]=blue[7:6], [3:4]=green[7:6], [5:6]=red[7:6]
        #  RX2: [0]=pix_de, [1:2]=00, [3:6]=blue[5:2]
        #  RX1: [0:1]=blue[1:0], [2:6]=green[5:1]
        #  RX0: [0]=green[0], [1:6]=red[5:0]
        # --------------------------------------------------
        self.comb += [
            RX3DATA[0].eq(0),
            RX3DATA[1].eq(blue[7]),
            RX3DATA[2].eq(blue[6]),
            RX3DATA[3].eq(green[7]),
            RX3DATA[4].eq(green[6]),
            RX3DATA[5].eq(red[7]),
            RX3DATA[6].eq(red[6]),

            RX2DATA[0].eq(pix_de),
            RX2DATA[1].eq(0),   # HSync tied low
            RX2DATA[2].eq(0),   # VSync tied low
            RX2DATA[3].eq(blue[5]),
            RX2DATA[4].eq(blue[4]),
            RX2DATA[5].eq(blue[3]),
            RX2DATA[6].eq(blue[2]),

            RX1DATA[0].eq(blue[1]),
            RX1DATA[1].eq(blue[0]),
            RX1DATA[2].eq(green[5]),
            RX1DATA[3].eq(green[4]),
            RX1DATA[4].eq(green[3]),
            RX1DATA[5].eq(green[2]),
            RX1DATA[6].eq(green[1]),

            RX0DATA[0].eq(green[0]),
            RX0DATA[1].eq(red[5]),
            RX0DATA[2].eq(red[4]),
            RX0DATA[3].eq(red[3]),
            RX0DATA[4].eq(red[2]),
            RX0DATA[5].eq(red[1]),
            RX0DATA[6].eq(red[0]),
        ]

        # --------------------------------------------------
        # 6. Main Sequential Process (clocked at 280 MHz)
        # --------------------------------------------------
        self.sync.fast += [
            # Serialize: use Case since Migen doesn't support Signal as array index
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

                # Update pixel coordinate counters during active video
                If(pix_de,
                    If(ex >= H_MAX,
                        ex.eq(0),
                        If(ye >= V_MAX,
                            ye.eq(0),
                        ).Else(
                            ye.eq(ye + 1),
                        )
                    ).Else(
                        ex.eq(ex + 1),
                    )
                ),

                # Update global sync counters
                If(hcount_ov,
                    hcount.eq(0),
                    If(vcount_ov,
                        vcount.eq(0),
                    ).Else(
                        vcount.eq(vcount + 1),
                    )
                ).Else(
                    hcount.eq(hcount + 1),
                )
            ).Else(
                slot.eq(slot + 1),
            )
        ]

        # --------------------------------------------------
        # 7. LVDS Output Buffers (OBUFDS primitives)
        # --------------------------------------------------
        # Clock
        self.specials += Instance("OBUFDS", i_I=CK1IN, o_O=ck1in_p, o_OB=ck1in_n)

        # Data lanes
        for i, (rxin, p_bit, n_bit) in enumerate(zip(
            [RXIN0, RXIN1, RXIN2, RXIN3],
            [tx_p[0], tx_p[1], tx_p[2], tx_p[3]],
            [tx_n[0], tx_n[1], tx_n[2], tx_n[3]],
        )):
            self.specials += Instance("OBUFDS", i_I=rxin, o_O=p_bit, o_OB=n_bit)


# # ============================================================
# # Standalone build helper (example, adapt to your platform)
# # ============================================================
# if __name__ == "__main__":
#     from migen.fhdl.verilog import convert
#
#     # For simulation / Verilog export without a real platform,
#     # stub out the DCM by replacing cd_fast with a simple ClockDomain.
#     class LVDSTransmitSim(LVDSTransmit):
#         """Simulation-friendly version: uses sys clock directly."""
#         def __init__(self):
#             # Minimal platform stub
#             super().__init__(platform=None)
#
#     dut = LVDSTransmitSim()
#     print(convert(dut, ios={
#         dut.clk_in, dut.en_video, dut.rainbow,
#         dut.bist,
#         dut.ck1in_p, dut.ck1in_n,
#         dut.tx_p, dut.tx_n,
#     }))

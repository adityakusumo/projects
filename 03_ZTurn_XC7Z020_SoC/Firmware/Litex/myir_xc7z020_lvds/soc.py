"""
soc.py - LiteX SoC on 7-Series FPGA (e.g. Artix-7 / Zynq-7020 PL)
Includes:
  - LVDS display output (960x1280 portrait, colorbars / white)
  - RGB LED cycler (button-gated, active-low cathode)
  - GPIO status LED (CSR-controlled from firmware)
  - I2C master (LiteI2C)
  - No DDR RAM

Input oscillator : 12 MHz
System clock     : 96 MHz  (MMCME2_ADV x8)
VGA pixel clock  : 48 MHz  (MMCME2_ADV /2, fed into VGAToLVDS)
"""

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer
from migen.genlib.cdc import MultiReg

from litex.gen import *
from litex.soc.cores.clock import *
from litex.soc.cores.gpio import GPIOOut
from litex.soc.cores.video import VideoTimingGenerator, ColorBarsPattern, video_data_layout
from litex.soc.interconnect import stream
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.interconnect.csr import *
from litex.build.generic_platform import *
from litex.build.parser import LiteXArgumentParser
from litei2c import LiteI2C

from VGAToLVDS import VGAToLVDS

import zynq_board   # replace with your 7-series platform file

kB = 1024
mB = 1024 * kB


# ============================================================
# CRG
# ============================================================
# MMCME2_ADV on 7-Series replaces Spartan-6 S6PLL + BUFPLL.
# No BUFPLL, no SERDESSTROBE, no DDR clock domains needed.
#
# Clock plan (12 MHz input):
#   VCO  = 12 MHz * 64 = 768 MHz   (within 600–1200 MHz range for -1 speed)
#   sys  = VCO / 8  =  96 MHz
#   pix  = VCO / 16 =  48 MHz  (pixel clock for VGAToLVDS)
# ============================================================
class CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys = ClockDomain()
        self.clock_domains.cd_pix = ClockDomain()

        clk   = platform.request("clk_osc")
        rst_n = platform.request("rst_btn", 0)

        self.submodules.pll = pll = S7MMCM(speedgrade=-1)
        pll.register_clkin(clk, 12e6)

        # with_reset=False: disable S7MMCM's internal AsyncResetSynchronizer
        # so we can add our own combined reset (button + locked) without double-driving
        pll.create_clkout(self.cd_sys, sys_clk_freq, with_reset=False)
        pll.create_clkout(self.cd_pix, 48e6,         with_reset=False)

        # Now we are the sole driver of rst — no double-driver conflict
        self.specials += AsyncResetSynchronizer(self.cd_sys, ~rst_n | ~pll.locked)
        self.specials += AsyncResetSynchronizer(self.cd_pix, ~rst_n | ~pll.locked)


# ============================================================
# Simple LED blinker
# ============================================================
class Blink(Module):
    def __init__(self, led, sys_clk_freq):
        # Toggle at ~1 Hz: counter bit = log2(sys_clk_freq)
        # For 96 MHz: bit 26 toggles at ~96M/2^27 ≈ 0.7 Hz (close enough)
        counter = Signal(27)
        self.comb += led.eq(counter[26])
        self.sync += counter.eq(counter + 1)


# ============================================================
# RGB LED Cycler
# ============================================================
# Cycles through 8 colors at 1s each when btn=1.
# LEDs are active-low (cathode control), so outputs are inverted.
# When btn=0: all LEDs off, counter and state reset.
# ============================================================
class RGBCycler(Module):
    def __init__(self, led_r, led_g, led_b, btn, sys_clk_freq):
        sys_clk_freq = int(sys_clk_freq)

        # Colors: black, white, red, green, blue, yellow, magenta, cyan
        # (R, G, B) — will be inverted on output for active-low cathode
        colors = [
            (0, 0, 0),  # black
            (1, 1, 1),  # white
            (1, 0, 0),  # red
            (0, 1, 0),  # green
            (0, 0, 1),  # blue
            (1, 1, 0),  # yellow
            (1, 0, 1),  # magenta
            (0, 1, 1),  # cyan
        ]
        num_colors = len(colors)  # 8

        # Counter for 1s period (counts to sys_clk_freq*2 for 2s cycle)
        counter = Signal(max=int(sys_clk_freq * 2))
        state   = Signal(3)

        self.sync += [
            If(btn,
                If(counter == ((sys_clk_freq * 2) - 1),
                    counter.eq(0),
                    If(state == (num_colors - 1),
                        state.eq(0)
                    ).Else(
                        state.eq(state + 1)
                    )
                ).Else(
                    counter.eq(counter + 1)
                )
            ).Else(
                # Button inactive: reset everything, LEDs off
                counter.eq(0),
                state.eq(0)
            )
        ]

        # Combinational decode: inverted for active-low cathode
        cases = {i: [led_r.eq(~r), led_g.eq(~g), led_b.eq(~b)]
                 for i, (r, g, b) in enumerate(colors)}
        self.comb += [
            If(btn,
                Case(state, cases)
            ).Else(
                led_r.eq(1),  # off (cathode high)
                led_g.eq(1),
                led_b.eq(1),
            )
        ]


# ============================================================
# BaseSoC
# ============================================================
class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(96e6), **kwargs):

        platform = zynq_board.Platform()

        # kwargs["integrated_rom_size"] = 0x10000

        SoCCore.__init__(self, platform, sys_clk_freq,
            ident = "LiteX SoC on 7-Series (LVDS. no DDR)",
            **kwargs
        )

        # CRG ──────────────────────────────────────────────────────────────────
        self.submodules.crg = CRG(platform, sys_clk_freq)

        # Buttons ──────────────────────────────────────────────────────────────
        user_btn    = platform.request("user_btn",  0)  # RGB cycler enable
        rainbow_btn = platform.request("user_btn",  1)  # colorbars/white toggle

        # RGB LED (active-low cathode) ─────────────────────────────────────────
        led_b = platform.request("rgb_led", 0)
        led_g = platform.request("rgb_led", 1)
        led_r = platform.request("rgb_led", 2)
        self.submodules.rgb_cycler = RGBCycler(led_r, led_g, led_b, user_btn, sys_clk_freq)

        # Status LED (CSR-controlled from firmware) ────────────────────────────
        status_led = platform.request("user_led", 0)
        self.submodules.status_led = GPIOOut(status_led)

        # I2C ──────────────────────────────────────────────────────────────────
        pad_i2c = platform.request("i2c", 0)
        self.submodules.i2c = LiteI2C(pads=pad_i2c, sys_clk_freq=sys_clk_freq)

        # ── LVDS Display ──────────────────────────────────────────────────────
        # 960x1280 portrait @ ~30fps with 48 MHz pixel clock
        #
        # Pixel clock budget check:
        #   Total pixels per frame = (960+60) * (1280+40) = 1020 * 1320 = 1,346,400
        #   48 MHz / 1,346,400 ≈ 35.6 fps  (comfortable for most LVDS panels)
        #
        TIMING_960x1280 = {
            "pix_clk"       : 48e6,
            "h_active"      : 960,
            "h_blanking"    : 60,
            "h_sync_offset" : 30,
            "h_sync_width"  : 10,
            "v_active"      : 1280,
            "v_blanking"    : 40,
            "v_sync_offset" : 26,
            "v_sync_width"  : 4,
        }

        # VideoTimingGenerator runs in cd_pix (48 MHz)
        # ClockDomain override needed so LiteX uses cd_pix for video logic
        self.submodules.vtg = vtg = ClockDomainsRenamer("pix")(
            VideoTimingGenerator(default_video_timings=TIMING_960x1280)
        )

        # ColorBarsPattern also in cd_pix
        self.submodules.colorbars = colorbars = ClockDomainsRenamer("pix")(
            ColorBarsPattern()
        )
        self.comb += [
            colorbars.enable.eq(1),
            vtg.source.connect(colorbars.vtg_sink),
        ]

        # Video mux: rainbow_btn=1 -> colorbars, rainbow_btn=0 -> white
        # CDC: rainbow_btn is in cd_sys, synchronize to cd_pix
        rainbow_btn_pix = Signal()
        self.specials += MultiReg(rainbow_btn, rainbow_btn_pix, "pix")

        video_mux_source = stream.Endpoint(video_data_layout)
        self.comb += [
            video_mux_source.valid.eq(colorbars.source.valid),
            colorbars.source.ready.eq(1),
            video_mux_source.de.eq(colorbars.source.de),
            video_mux_source.hsync.eq(colorbars.source.hsync),
            video_mux_source.vsync.eq(colorbars.source.vsync),
            If(rainbow_btn_pix,
                video_mux_source.r.eq(colorbars.source.r),
                video_mux_source.g.eq(colorbars.source.g),
                video_mux_source.b.eq(colorbars.source.b),
            ).Else(
                video_mux_source.r.eq(0xFF),
                video_mux_source.g.eq(0xFF),
                video_mux_source.b.eq(0xFF),
            )
        ]

        # VGAToLVDS: takes cd_pix (48 MHz) as input,
        # internally generates cd_fast (48*7=336 MHz) via PLLE2_ADV
        lvds_pads = platform.request("lvds_tx", 0)

        self.submodules.vga2lvds = VGAToLVDS(pclk_freq=48e6)
        self.comb += [
            video_mux_source.connect(self.vga2lvds.sink),
            lvds_pads.clk_p.eq(self.vga2lvds.ck_p),
            lvds_pads.clk_n.eq(self.vga2lvds.ck_n),
            lvds_pads.data_p.eq(self.vga2lvds.tx_p),
            lvds_pads.data_n.eq(self.vga2lvds.tx_n),
        ]


# ============================================================
# Build
# ============================================================
def main():
    parser = LiteXArgumentParser(
        platform    = zynq_board.Platform,
        description = "LiteX SoC on 7-Series (LVDS, no DDR)."
    )
    # parser.add_target_argument("--flash",        action="store_true", help="Flash bitstream")
    parser.add_target_argument("--sys-clk-freq", default=96e6,        help="System clock frequency.")
    args = parser.parse_args()

    soc = BaseSoC(
        # toolchain    = args.toolchain,
        sys_clk_freq = int(float(args.sys_clk_freq)),
        **parser.soc_argdict
    )

    builder = Builder(soc, compile_gateware=True, compile_software=True)

    if args.build:
        builder.build(**parser.toolchain_argdict)

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram", ext=".bit"))

    # if args.flash:
    #     prog = soc.platform.create_programmer()
    #     prog.flash(0, builder.get_bitstream_filename(mode="flash", ext=".bit"))


if __name__ == "__main__":
    main()

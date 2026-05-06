"""
soc.py - LiteX SoC on Spartan-6 (QMTECH XC6SLX25)
Includes:
  - LVDS display output (960x1280 portrait, colorbars / white)
  - LiteDRAM DDR3 (MT41K128M16JT-125) with simple R/W test
  - LED blink and status indicators

LiteDRAM Learning Guide:
=========================
1. The DDR3 PHY (S6HalfRateDDRPHY) handles the low-level DDR3 signaling.
2. LiteDRAM wraps the PHY with a controller that exposes a simple "port" interface.
3. A "port" gives you two streams: cmd (command), wdata (write data), rdata (read data).
4. You write: send a cmd with we=1, then send wdata.
5. You read:  send a cmd with we=0, then receive rdata.
6. The DRAMTestModule below does exactly this in a simple FSM.
"""

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer
from migen.genlib.cdc import MultiReg

from litex.gen import *
from litex.soc.cores.clock import *
from litex.soc.cores.video import VideoTimingGenerator, ColorBarsPattern, video_data_layout
from litex.soc.interconnect import stream
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.interconnect.csr import *
from litex.soc.doc import generate_docs
from litex.build.generic_platform import *
from litex.build.parser import LiteXArgumentParser
from litex.build.io import DDROutput

from litedram.modules import MT41K128M16
from litedram.phy import s6ddrphy

from vga2lvds import VGAToLVDS

import spartan6_board

kB = 1024
mB = 1024 * kB


# ============================================================
# CRG
# ============================================================
class CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys    = ClockDomain()
        self.clock_domains.cd_sys2x  = ClockDomain()
        self.clock_domains.cd_sdram_half    = ClockDomain()
        self.clock_domains.cd_sdram_full_wr = ClockDomain()
        self.clock_domains.cd_sdram_full_rd = ClockDomain()
        self.unbuf_sdram_full               = ClockDomain()
        self.unbuf_sdram_half_a             = ClockDomain()
        self.unbuf_sdram_half_b             = ClockDomain()

        clk   = platform.request("clk_osc")
        rst_n = platform.request("rst_btn", 0)

        self.submodules.pll = pll = S6PLL(speedgrade=-2)
        pll.register_clkin(clk, 50e6)

        # unbuf_sdram_full MUST be first so S6PLL assigns it to CLKOUT0
        # (only CLKOUT0 and CLKOUT1 can drive BUFPLL on Spartan-6)
        pll.create_clkout(self.unbuf_sdram_full,   sys_clk_freq*8, with_reset=False, buf=None)
        pll.create_clkout(self.cd_sys2x,           sys_clk_freq*2, with_reset=False)
        pll.create_clkout(self.cd_sys,             sys_clk_freq,   with_reset=False)
        pll.create_clkout(self.unbuf_sdram_half_a, sys_clk_freq*4, with_reset=False, buf=None, phase=230)
        pll.create_clkout(self.unbuf_sdram_half_b, sys_clk_freq*4, with_reset=False, buf=None, phase=210)

        # BUFPLL: generates high-speed IOCLK and SERDESSTROBE for OSERDES2/ISERDES2
        # p_DIVIDE=4 with 8x input clock -> 2x output strobe (quarter rate mode)
        self.clk8x_wr_strb = Signal()
        self.clk8x_rd_strb = Signal()
        self.specials += Instance("BUFPLL",
            p_DIVIDE       = 4,
            i_PLLIN        = self.unbuf_sdram_full.clk,
            i_GCLK         = self.cd_sys2x.clk,
            i_LOCKED       = pll.locked,
            o_IOCLK        = self.cd_sdram_full_wr.clk,
            o_SERDESSTROBE = self.clk8x_wr_strb,
        )
        self.comb += [
            self.cd_sdram_full_rd.clk.eq(self.cd_sdram_full_wr.clk),
            self.clk8x_rd_strb.eq(self.clk8x_wr_strb),
        ]

        # Half-rate SDRAM clocks (buffered with BUFG)
        clk_sdram_half_shifted = Signal()
        self.specials += Instance("BUFG",
            i_I=self.unbuf_sdram_half_a.clk,
            o_O=self.cd_sdram_half.clk,
        )
        self.specials += Instance("BUFG",
            i_I=self.unbuf_sdram_half_b.clk,
            o_O=clk_sdram_half_shifted,
        )

        # DDR3 differential clock output to DRAM pins
        output_clk = Signal()
        ddr3_clk   = platform.request("ddram_clock")
        self.specials += DDROutput(1, 0, output_clk, clk_sdram_half_shifted)
        self.specials += Instance("OBUFDS",
            i_I=output_clk, o_O=ddr3_clk.p, o_OB=ddr3_clk.n,
        )

        # Resets
        self.specials += AsyncResetSynchronizer(self.cd_sys,   ~rst_n | ~pll.locked)
        self.specials += AsyncResetSynchronizer(self.cd_sys2x, ~rst_n | ~pll.locked)


# ============================================================
# DRAM Test Module (pure hardware, no CSR)
# ============================================================
# LiteDRAM port interface:
#
#  port.cmd.valid  - you drive high when command is ready
#  port.cmd.ready  - controller drives high when it accepts command
#  port.cmd.addr   - word address to read/write
#  port.cmd.we     - 1=write, 0=read
#
#  port.wdata.valid - you drive high when write data is ready
#  port.wdata.ready - controller drives high when it accepts data
#  port.wdata.data  - write data
#  port.wdata.we    - byte write enable mask (all 1s = write all bytes)
#
#  port.rdata.valid - controller drives high when read data is ready
#  port.rdata.ready - you drive high to accept read data
#  port.rdata.data  - read data
#
# Test pattern: data = address XOR 0xDEAD0000
# This detects address line faults because each address
# produces a unique expected value.
# ============================================================
class DRAMTestModule(Module):
    def __init__(self, port, start, led_pass, led_fail, led_busy):
        # Internal signals
        count   = Signal(7)        # 0-63 word counter (64 words tested)
        data_wr = Signal(port.data_width)
        result  = Signal(reset=1)  # 1=pass, assume pass until proven otherwise

        # FSM
        self.submodules.fsm = fsm = FSM(reset_state="IDLE")

        # ---- IDLE: wait for start button ----
        fsm.act("IDLE",
            led_busy.eq(0),
            led_pass.eq(1),
            led_fail.eq(0),
            If(start,
                NextValue(count,  0),
                NextValue(result, 1),
                NextState("WRITE"),
            )
        )

        # ---- WRITE COMMAND ----
        fsm.act("WRITE",
            led_busy.eq(1),
            port.cmd.valid.eq(1),
            port.cmd.we.eq(1),
            port.cmd.addr.eq(count),
            If(port.cmd.ready,
                NextValue(data_wr, count ^ 0xDEAD0000),
                NextState("WRITE_DAT"),
            )
        )

        # ---- WRITE DATA ----
        fsm.act("WRITE_DAT",
            led_busy.eq(1),
            port.wdata.valid.eq(1),
            port.wdata.data.eq(data_wr),
            port.wdata.we.eq(2**(port.data_width//8) - 1),  # all bytes enabled
            If(port.wdata.ready,
                NextValue(count, count + 1),
                If(count == 63,
                    NextValue(count, 0),
                    NextState("READ"),   # all 64 words written, now read back
                ).Else(
                    NextState("WRITE"),
                )
            )
        )

        # ---- READ COMMAND ----
        fsm.act("READ",
            led_busy.eq(1),
            port.cmd.valid.eq(1),
            port.cmd.we.eq(0),
            port.cmd.addr.eq(count),
            If(port.cmd.ready,
                NextState("READ_WAIT"),
            )
        )

        # ---- WAIT FOR READ DATA ----
        fsm.act("READ_WAIT",
            led_busy.eq(1),
            port.rdata.ready.eq(1),
            If(port.rdata.valid,
                # Compare read data against expected pattern
                If(port.rdata.data != (count ^ 0xDEAD0000),
                    NextValue(result, 0),   # mismatch -> FAIL
                ),
                NextValue(count, count + 1),
                If(count == 63,
                    NextState("DONE"),      # all 64 words verified
                ).Else(
                    NextState("READ"),
                )
            )
        )

        # ---- DONE: show result on LEDs ----
        fsm.act("DONE",
            led_busy.eq(0),
            led_pass.eq(~result),
            led_fail.eq(~result),
            # Re-arm when button is released
            If(~start,
                NextState("IDLE"),
            )
        )


# ============================================================
# Simple LED blinker
# ============================================================
class Blink(Module):
    def __init__(self, led):
        counter = Signal(26)
        self.comb += led.eq(counter[25])
        self.sync += counter.eq(counter + 1)


# ============================================================
# BaseSoC
# ============================================================
class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(50e6), toolchain="ise", platform=None, **kwargs):

        if platform is None:
            platform = spartan6_board.Platform(toolchain=toolchain)

        kwargs["integrated_rom_size"] = 0x10000

        SoCCore.__init__(self, platform, sys_clk_freq,
            ident = "LiteX SoC on Spartan6 (DDR3 + LVDS)",
            **kwargs
        )

        # CRG ──────────────────────────────────────────────────────────────────
        self.submodules.crg = CRG(platform, sys_clk_freq)

        # LEDs ─────────────────────────────────────────────────────────────────
        led_blink = platform.request("user_led",  0)
        led_pass  = platform.request("user_led2", 0)  # lights up on DRAM PASS
        self.submodules.blink = Blink(led_blink)

        # Buttons ──────────────────────────────────────────────────────────────
        user_button = platform.request("user_btn",  0)  # starts DRAM test
        rainbow_btn = platform.request("user_btn2", 0)  # colorbars/white toggle

        # ── LiteDRAM DDR3 ─────────────────────────────────────────────────────
        #
        # Step 1: PHY - handles physical DDR3 signaling (DQS, ODT, etc.)
        #
        self.submodules.ddrphy = s6ddrphy.S6QuarterRateDDRPHY(
            pads              = platform.request("ddram"),
            rd_bitslip        = 0,
            wr_bitslip        = 4,
            dqs_ddr_alignment = "C0",
        )

        # Connect strobe signals from CRG to PHY
        # S6HalfRateDDRPHY uses clk8x (half rate = 4x sys clock)
        self.comb += [
            self.ddrphy.clk8x_wr_strb.eq(self.crg.clk8x_wr_strb),
            self.ddrphy.clk8x_rd_strb.eq(self.crg.clk8x_rd_strb),
        ]

        # Step 2: Controller - wraps PHY, exposes memory-mapped SDRAM to SoC bus
        # MT41K128M16 = 128Mx16 = 256MB DDR3, "1:2" = half rate mode
        # Update add_sdram:
        self.add_sdram("sdram",
            phy    = self.ddrphy,
            module = MT41K128M16(sys_clk_freq, "1:4"),
            origin = self.mem_map.get("main_ram", 0x40000000),
            size   = 32*mB,
        )

        # Step 3: Native port for direct test access
        # data_width=32 -> each transaction = 32 bits
        # port.cmd  : send address + read/write command
        # port.wdata: send write data
        # port.rdata: receive read data
        dram_port = self.sdram.crossbar.get_port(data_width=32)

        # Step 4: Test module - press user_btn to run, led_pass lights on success
        led_fail_sig = Signal()  # no dedicated fail LED pin, extend if needed
        led_busy_sig = Signal()  # internal busy indicator
        self.submodules.dram_test = DRAMTestModule(
            port     = dram_port,
            start    = ~user_button,
            led_pass = led_pass,
            led_fail = led_fail_sig,
            led_busy = led_busy_sig,
        )

        # ── LVDS Display ──────────────────────────────────────────────────────
        # 960x1280 portrait @ ~30fps (40MHz pixel clock)
        # Note: true 60fps needs ~80MHz which exceeds DCM_SP x7 limits
        TIMING_960x1280 = {
            "pix_clk"       : 50e6,
            "h_active"      : 960,
            "h_blanking"    : 60,
            "h_sync_offset" : 30,
            "h_sync_width"  : 10,
            "v_active"      : 1280,
            "v_blanking"    : 40,
            "v_sync_offset" : 26,
            "v_sync_width"  : 4,
        }

        # Video timing generator (runs on cd_sys = 40MHz)
        self.submodules.vtg = vtg = VideoTimingGenerator(
            default_video_timings=TIMING_960x1280
        )

        # Color bars pattern (always enabled, FSM never reset)
        self.submodules.colorbars = colorbars = ColorBarsPattern()
        self.comb += [
            colorbars.enable.eq(1),
            vtg.source.connect(colorbars.vtg_sink),
        ]

        # Video mux: rainbow_btn=1 -> colorbars, rainbow_btn=0 -> white
        video_mux_source = stream.Endpoint(video_data_layout)
        self.comb += [
            video_mux_source.valid.eq(colorbars.source.valid),
            colorbars.source.ready.eq(1),
            video_mux_source.de.eq(colorbars.source.de),
            video_mux_source.hsync.eq(colorbars.source.hsync),
            video_mux_source.vsync.eq(colorbars.source.vsync),
            If(rainbow_btn,
                video_mux_source.r.eq(colorbars.source.r),
                video_mux_source.g.eq(colorbars.source.g),
                video_mux_source.b.eq(colorbars.source.b),
            ).Else(
                video_mux_source.r.eq(0xFF),
                video_mux_source.g.eq(0xFF),
                video_mux_source.b.eq(0xFF),
            )
        ]

        # LVDS serializer (VGAToLVDS: 40MHz sys -> DCM x7 -> 280MHz cd_fast)
        lvds_pads = platform.request("lvds_tx", 0)
        bist_o    = platform.request("bist_o",  0)

        self.submodules.vga2lvds = VGAToLVDS(pclk_freq=50e6)
        self.comb += [
            video_mux_source.connect(self.vga2lvds.sink),
            lvds_pads.clk_p.eq(self.vga2lvds.ck1in_p),
            lvds_pads.clk_n.eq(self.vga2lvds.ck1in_n),
            lvds_pads.data_p.eq(self.vga2lvds.tx_p),
            lvds_pads.data_n.eq(self.vga2lvds.tx_n),
            bist_o.eq(rainbow_btn & user_button),
        ]


# ============================================================
# Build
# ============================================================
def main():
    parser = LiteXArgumentParser(
        platform    = spartan6_board.Platform,
        description = "LiteX SoC on Spartan6 (DDR3 + LVDS)."
    )
    parser.add_target_argument("--flash",        action="store_true", help="Flash bitstream")
    parser.add_target_argument("--sys-clk-freq", default=50e6,        help="System clock frequency.")
    args = parser.parse_args()

    soc = BaseSoC(
        toolchain    = args.toolchain,
        sys_clk_freq = int(args.sys_clk_freq),
        **parser.soc_argdict
    )

    builder = Builder(soc, compile_gateware=True, compile_software=True)

    if args.build:
        builder.build(**parser.toolchain_argdict)

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram", ext=".bit"))

    if args.flash:
        prog = soc.platform.create_programmer()
        prog.flash(0, builder.get_bitstream_filename(mode="flash", ext=".bit"),
                   fpga_part="xc6slx25ftg256")

    generate_docs(soc, "build/documentation")


if __name__ == "__main__":
    main()

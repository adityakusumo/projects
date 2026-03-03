from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.gen import *
# from litei2c import LiteI2C
from litex.soc.cores.clock import *
from litex.soc.cores.gpio import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser
from litex.soc.interconnect.csr import *
from litex.soc.doc import generate_docs

from litex.build.generic_platform import *
from litex.build.parser import LiteXArgumentParser

from blinker import AdjustableBlink

import spartan6_board
# from spartan6_board import Platform

# from lvds_transmit import LVDSTransmit
from vga2lvds import VGAToLVDS

kB = 1024
mB = 1024*kB

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
NUM_SEGMENTS = 8
INCREMENT    = VRES // NUM_SEGMENTS
LINE = [INCREMENT * (i + 1) for i in range(NUM_SEGMENTS)]

CK1DATA = 0b0110001  # "1100011" MSB-first -> bits 0..6

# soc.py:
# CRG ----------------------------------------------------------------------------------------------
class CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys = ClockDomain()
        self.clock_domains.cd_clk_out2 = ClockDomain()
        # self.clock_domains.cd_fast = ClockDomain()

        clk = platform.request("clk50")
        rst_n = platform.request("rst_btn", 0) # Menjadikan button0 sebagai reset

        # Internal signals for the PLL
        pll_fb = Signal()
        pll_fb_buffered = Signal()
        clkout0 = Signal()
        clkout1 = Signal()
        locked = Signal()

        # ----------------------------------------------------------------------
        # PLL_BASE Instantiation (Matching your VHDL generics)
        # ----------------------------------------------------------------------
        self.specials += Instance("PLL_BASE",
            # Parameters (Generics in VHDL)
            p_BANDWIDTH          = "OPTIMIZED",
            p_CLK_FEEDBACK       = "CLKFBOUT",
            p_COMPENSATION       = "SYSTEM_SYNCHRONOUS",
            p_DIVCLK_DIVIDE      = 2,
            p_CLKFBOUT_MULT      = 39,  # 50MHz * 39 / 2 = 975MHz VCO
            p_CLKIN_PERIOD       = 20.0,
            p_REF_JITTER         = 0.010,

            # CLKOUT0: 975MHz / 25 = 39.0MHz
            p_CLKOUT0_DIVIDE     = 25,
            p_CLKOUT0_PHASE      = 0.0,
            p_CLKOUT0_DUTY_CYCLE = 0.5,

            # CLKOUT1: 975MHz / 9 = 108.33MHz
            p_CLKOUT1_DIVIDE     = 9,
            p_CLKOUT1_PHASE      = 0.0,
            p_CLKOUT1_DUTY_CYCLE = 0.5,

            # Ports (Port Map in VHDL)
            i_CLKIN    = clk,
            i_CLKFBIN  = pll_fb_buffered,
            i_RST      = 0,
            o_CLKFBOUT = pll_fb,
            o_CLKOUT0  = clkout0,
            o_CLKOUT1  = clkout1,
            o_LOCKED   = locked
        )

        # ----------------------------------------------------------------------
        # Buffering (BUFG)
        # ----------------------------------------------------------------------
        # Feedback buffer
        self.specials += Instance("BUFG", i_I=pll_fb, o_O=pll_fb_buffered)

        # Output buffers linked to Clock Domains
        self.specials += Instance("BUFG", i_I=clkout0, o_O=self.cd_sys.clk) # 39.0MHz clock for lvds input clock
        self.specials += Instance("BUFG", i_I=clkout1, o_O=self.cd_clk_out2.clk)

        # self.comb += self.cd_sys.clk.eq(clk)
        self.specials += AsyncResetSynchronizer(self.cd_sys, ~rst_n)        

# Create a led blinker module
class Blink(Module):
    def __init__(self, led):
        self.counter = Signal(26)
        
        # combinatorial assignment
        self.comb += [
            led.eq(self.counter[25])
        ]
        
        # synchronous assignment
        self.sync += self.counter.eq(self.counter + 1)

class Blinker(Module):
    def __init__(self, led, sys_clk_freq):
        # 1. Calculate the 'Limit' (e.g., 25,000,000)
        # Toggles every 0.5s for a 1s period
        limit_value = 20000000#int(sys_clk_freq / 1)
        
        # 2. Define the Counter Signal
        # max=limit_value tells Migen to calculate the bit-width (e.g., 25 bits)
        counter = Signal(max=limit_value)

        # 3. Synchronous Logic (always @(posedge clk))
        self.sync += [
            # Check if counter reached (25,000,000 - 1)
            If(counter == (limit_value - 1),
                counter.eq(0),     # Reset
                led.eq(~led)       # Toggle
            ).Else(
                counter.eq(counter + 1)
            )
        ]

# class LEDDriver(Module, AutoCSR):
#     def __init__(self, led_pin):
#         self.output = CSRStorage(1, description="LED Control Register")
#         # drive the passed led_pin with constant 1 (High)
#         self.comb += led_pin.eq(self.output.storage)
        
# class MyModule(Module, AutoCSR):
#     def __init__(self, sys_clk_freq):
#         # 1. Define a CSRStatus so the CPU can read the counter value
#         self.count_out = CSRStatus(3, description="1Hz Counter (0-7)")
        
#         # 2. Define our internal signals
#         counter = Signal(3)
#         timer = Signal(max=int(sys_clk_freq)) # Counter to track the 1s interval

#         # 3. Synchronous Logic (Sequential)
#         self.sync += [
#             If(timer == int(sys_clk_freq) - 1,
#                 timer.eq(0),            # Reset timer after 1 second
#                 counter.eq(counter + 1) # Increment our 3-bit counter
#             ).Else(
#                 timer.eq(timer + 1)     # Keep counting clock cycles
#             )
#         ]

#         # 4. Connect the internal counter to the CSRStatus
#         self.comb += self.count_out.status.eq(counter)
        
# BaseSoC ------------------------------------------------------------------------------------------
class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(50e6), toolchain="ise", platform=None, **kwargs):

        # If no platform is provided (Hardware mode), use Spartan6
        if platform is None:
            platform = spartan6_board.Platform(toolchain=toolchain)
        # platform = spartan6_board.Platform(toolchain=toolchain)
        # platform = Platform()

        kwargs["integrated_rom_size"] = 0x10000
        
        SoCCore.__init__(self, platform, sys_clk_freq,      
            ident                   = "LiteX SoC on Spartan6.",
            **kwargs
        )

        self.submodules.crg = CRG(platform, sys_clk_freq)
        
        # RAM for BootLoader -----------------------------------------------------------------------
        BASE_MEM1_ORIGIN        = 0x40000000
        self.add_ram(name="main_ram", origin=BASE_MEM1_ORIGIN, size=32*kB)          
     
        self.other_signals = Signal(3)
        
        # self.leds = LedChaser(
        #         pads         = platform.request_all("user_led"),
        #         sys_clk_freq = sys_clk_freq)
        
        # uartbone
        # self.add_uartbone(uart_name="serial", baudrate=115200) 

        # i2c
        # pad_i2c = platform.request("i2c", 0)
        # self.submodules.i2c = LiteI2C(pads=pad_i2c, sys_clk_freq=sys_clk_freq)

        # print("Available resources:", [res.name for res in platform.available])
        #blink led
        led1 = platform.request("user_led", 0)
        self.submodules.blink = Blink(led1)

        led2 = platform.request("user_led2", 0)
        self.submodules.blinker = Blinker(led2, sys_clk_freq)

        user_button = platform.request("user_btn")
        user_button2  = platform.request("user_btn2", 0)


        # # LVDS Transmitter
        # lvds_pads  = platform.request("lvds_tx", 0)
        # bist_o     = platform.request("bist_o", 0)
        # self.comb += bist_o.eq(0)
        #
        # self.submodules.lvds = LVDSTransmit(platform)
        #
        # self.comb += [
        #     # Inputs
        #     self.lvds.clk_in.eq(self.crg.cd_sys.clk),   # 39MHz from PLL CLKOUT0
        #     self.lvds.en_video.eq(user_button),           # user_btn (already requested above)
        #     self.lvds.rainbow.eq(user_button2),
        #
        #     # Outputs
        #     lvds_pads.clk_p.eq(self.lvds.ck1in_p),
        #     lvds_pads.clk_n.eq(self.lvds.ck1in_n),
        #     lvds_pads.data_p.eq(self.lvds.tx_p),
        #     lvds_pads.data_n.eq(self.lvds.tx_n),
        #     bist_o.eq(self.lvds.bist),
        # ]

        vga_pads  = platform.request("vga", 0)      # your VGA input resource
        lvds_pads = platform.request("lvds_tx", 0)
        bist_o    = platform.request("bist_o", 0)

        self.submodules.lvds = VGAToLVDS()

        self.comb += [
            # VGA inputs -> module
            self.lvds.pclk.eq(vga_pads.pclk),
            self.lvds.de.eq(vga_pads.de),         # or derive from hsync/vsync
            self.lvds.hsync.eq(vga_pads.hsync),
            self.lvds.vsync.eq(vga_pads.vsync),
            self.lvds.r.eq(vga_pads.r),
            self.lvds.g.eq(vga_pads.g),
            self.lvds.b.eq(vga_pads.b),

            self.lvds.en_video.eq(user_button),

            # LVDS outputs -> platform pins
            lvds_pads.clk_p.eq(self.lvds.ck1in_p),
            lvds_pads.clk_n.eq(self.lvds.ck1in_n),
            lvds_pads.data_p.eq(self.lvds.tx_p),
            lvds_pads.data_n.eq(self.lvds.tx_n),

            bist_o.eq(self.lvds.bist),
        ]

# Build --------------------------------------------------------------------------------------------
def main():    
    parser = LiteXArgumentParser(platform=spartan6_board.Platform, description="LiteX SoC on Spartan6.")
    parser.add_target_argument("--flash",           action="store_true",    help="Flash bitstream")
    parser.add_target_argument("--sys-clk-freq",    default=50e6,          help="System clock frequency.")
    args = parser.parse_args()

    soc = BaseSoC(
        toolchain           = args.toolchain,
        sys_clk_freq        = args.sys_clk_freq,
        **parser.soc_argdict
    )
    # builder = Builder(soc, **parser.builder_argdict)
    builder = Builder(soc, compile_gateware=True, compile_software=True)

    if args.build:
        builder.build(**parser.toolchain_argdict)
    
    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram", ext=".bit"))

    if args.flash:
        prog = soc.platform.create_programmer()
        prog.flash(0, builder.get_bitstream_filename(mode="flash", ext=".bit"), fpga_part="xc6slx25ftg256")
        # prog.flash(address=0, data_file=builder.get_bitstream_filename(mode="flash", ext=".bit"), unprotect_flash=True)

    generate_docs(soc, "build/documentation")

if __name__ == "__main__":
    main()

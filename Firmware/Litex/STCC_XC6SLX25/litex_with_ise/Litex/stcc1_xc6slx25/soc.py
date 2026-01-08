from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.gen import *
from litei2c import LiteI2C
from litex.soc.cores.clock import *
from litex.soc.cores.gpio import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser
from litex.soc.interconnect.csr import *
from litex.soc.doc import generate_docs

from litex.build.generic_platform import *
from litex.build.parser import LiteXArgumentParser

import spartan6_board

kB = 1024
mB = 1024*kB


# CRG ----------------------------------------------------------------------------------------------
class CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys = ClockDomain()

        clk = platform.request("clk100")
        rst_n = platform.request("rst_btn", 0) # Menjadikan button0 sebagai reset

        self.comb += self.cd_sys.clk.eq(clk)
        self.specials += AsyncResetSynchronizer(self.cd_sys, ~rst_n)

# # Create a led blinker module
# class Blink(Module):
#     def __init__(self, led):
#         self.counter = Signal(26)
        
#         # combinatorial assignment
#         self.comb += [
#             led.eq(self.counter[25])
#         ]
        
#         # synchronous assignment
#         self.sync += self.counter.eq(self.counter + 1)

class LEDDriver(Module, AutoCSR):
    def __init__(self, led_pin):
        self.output = CSRStorage(1, description="LED Control Register")
        # drive the passed led_pin with constant 1 (High)
        self.comb += led_pin.eq(self.output.storage)
        
class MyModule(Module, AutoCSR):
    def __init__(self, sys_clk_freq):
        # 1. Define a CSRStatus so the CPU can read the counter value
        self.count_out = CSRStatus(3, description="1Hz Counter (0-7)")
        
        # 2. Define our internal signals
        counter = Signal(3)
        timer = Signal(max=int(sys_clk_freq)) # Counter to track the 1s interval

        # 3. Synchronous Logic (Sequential)
        self.sync += [
            If(timer == int(sys_clk_freq) - 1,
                timer.eq(0),            # Reset timer after 1 second
                counter.eq(counter + 1) # Increment our 3-bit counter
            ).Else(
                timer.eq(timer + 1)     # Keep counting clock cycles
            )
        ]

        # 4. Connect the internal counter to the CSRStatus
        self.comb += self.count_out.status.eq(counter)
        
# BaseSoC ------------------------------------------------------------------------------------------
class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(50e6), toolchain="ise", **kwargs):

        platform = spartan6_board.Platform(toolchain=toolchain)

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
        pad_i2c = platform.request("i2c", 0)
        self.submodules.i2c = LiteI2C(pads=pad_i2c, sys_clk_freq=sys_clk_freq)

        # #blink led
        # led1 = platform.request("user_led", 0)
        # self.submodules.blink = Blink(led1)

        # Push Button input
        user_button = platform.request("user_btn")
        
        # Led output
        led = platform.request("user_led", 0) # Requests the first LED from platform
        # self.submodules.led_drive = LEDDriver(led)   
        
        # CSRs   
        # Led CSR - From Firmware to Hardware
        self.ctrl = CSRStorage(1, description="1-bit CSR LED")
        self.comb += led.eq(self.ctrl.storage[0])
        # UART CSR - From Hardware to Firmware
        self.submodules.my_module = MyModule(sys_clk_freq=int(50e6))
        # CSR for ISE from Firmware to Hardware
        my_external_bus = [
            ("from_litex_ctrl", 0, Pins(24))
        ]   # Create external bus pin for ISE connection
        platform.add_extension(my_external_bus)
        self.ctrl_reg   = CSRStorage(24)
        user_bus = platform.request("from_litex_ctrl")
        self.comb += [
            user_bus.eq(self.ctrl_reg.storage),  # CPU writes to CSR -> value appears on top-level port
        ]
        # Button CSR - From Hardware to Firmware
        self.button = CSRStatus(1, description="External User Button")
        self.comb += self.button.status.eq(user_button)


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
    builder = Builder(soc, compile_gateware=False, compile_software=True)

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

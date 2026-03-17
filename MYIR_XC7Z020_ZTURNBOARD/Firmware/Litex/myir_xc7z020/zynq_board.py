from litex.build.xilinx import *
from litex.build.generic_platform import *
from litex.build.xilinx import Xilinx7SeriesPlatform, VivadoProgrammer
from litex.build.openfpgaloader import OpenFPGALoader

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Clk / Rst
    ("clk_osc", 0, Pins("U14"), IOStandard("LVCMOS33")),

    # Leds
    ("rgb_led", 0, Pins("Y17"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")), #Blue
    ("rgb_led", 1, Pins("Y16"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")), #Green
    ("rgb_led", 2, Pins("W18"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")), #Dummy
    ("user_led", 0, Pins("R14"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")), #Red
    
    # Button
    ("rst_btn", 0, Pins("R19"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")),
    ("user_btn", 0, Pins("H17"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")),  #T19
    ("user_btn", 1, Pins("G14"), IOStandard("LVCMOS33"), Drive("8"), Misc("SLEW = FAST")),

    # Serial
    ("serial", 0,
        Subsignal("tx", Pins("E18")),
        Subsignal("rx", Pins("E19")),
        IOStandard("LVCMOS33")
    ),
    
    # # LVDS
    # ("lvds_tx", 0,
    #     Subsignal("clk_p", Pins("T9")),
    #     Subsignal("clk_n", Pins("U10")),
    #     Subsignal("data_p", Pins("Y9 V11 U7 Y7")),
    #     Subsignal("data_n", Pins("Y8 V10 V7 Y6")),
    #     Misc("DIFF_TERM=FALSE"),
    #     IOStandard("LVDS_25")
    #  ),

    # # GPIO
    # ("gpio_out", 0, Pins("L16"), IOStandard("LVCMOS33")),
    # ("gpio_out", 1, Pins("K16"), IOStandard("LVCMOS33")),
    # ("gpio_out", 2, Pins("J16"), IOStandard("LVCMOS33")),
    # ("gpio_out", 3, Pins("H15"), IOStandard("LVCMOS33")),
    # ("gpio_out", 4, Pins("E16"), IOStandard("LVCMOS33")),
    # ("gpio_out", 5, Pins("E15"), IOStandard("LVCMOS33")),
    # ("gpio_out", 6, Pins("C16"), IOStandard("LVCMOS33")),
    # ("gpio_out", 7, Pins("B16"), IOStandard("LVCMOS33")),
    

    # SPIFlash (W25Q128JV)
    # ("spiflash", 0,
    #     Subsignal("cs_n", Pins("N8"), IOStandard("LVCMOS33")),
    #     #Subsignal("clk",  Pins("N9"), IOStandard("LVCMOS33")),
    #     Subsignal("miso", Pins("T8"), IOStandard("LVCMOS33")),
    #     Subsignal("mosi", Pins("T7"), IOStandard("LVCMOS33")),
    # ),

    # SPIFlash4x (W25Q128JV)
    # ("spiflash4x", 0,  # clock needs to be accessed through STARTUPE2
    #     Subsignal("cs_n", Pins("N8")),
    #     Subsignal("dq",   Pins("T8 T7 M7 N7")),
    #     IOStandard("LVCMOS33")
    # ),

    #I2C
    ("i2c", 0,
        Subsignal("scl", Pins("P16"), IOStandard("LVCMOS33")),
        Subsignal("sda", Pins("P15"), IOStandard("LVCMOS33"))
    ),
]

# Platform -----------------------------------------------------------------------------------------

class Platform(Xilinx7SeriesPlatform):
    default_clk_name   = "clk_osc"
    default_clk_period = 1e9/12e6

    def __init__(self):
        Xilinx7SeriesPlatform.__init__(self, "xc7z020clg400-2", _io, toolchain="vivado")

    def create_programmer(self, kit="openfpgaloader"):
        return OpenFPGALoader(cable="ft2232")

    def do_finalize(self, fragment):
        Xilinx7SeriesPlatform.do_finalize(self, fragment)
        self.add_period_constraint(self.lookup_request("clk_osc", loose=True), 1e9/12e6)

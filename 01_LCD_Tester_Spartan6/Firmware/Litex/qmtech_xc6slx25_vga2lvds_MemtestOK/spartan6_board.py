from litex.build.xilinx import *
from litex.build.generic_platform import *
from litex.build.xilinx import XilinxSpartan6Platform
from litex.build.openfpgaloader import OpenFPGALoader

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Clk / Rst
    ("clk_osc", 0, Pins("A10"), IOStandard("LVCMOS33")),  # 80MHz oscillator

    # Leds
    ("user_led", 0, Pins("R9"), IOStandard("LVCMOS33")),
    ("user_led2", 0, Pins("T9"), IOStandard("LVCMOS33")),
    
    # Button
    ("rst_btn", 0, Pins("D5"), IOStandard("LVCMOS33"), Misc("PULLUP")),  # Active high reset pin
    ("user_btn", 0, Pins("T8"), IOStandard("LVCMOS33")),    # For Bist mode activation
    ("user_btn2", 0, Pins("R7"), IOStandard("LVCMOS33")),   # For Rainbow mode activation

    ("bist_o", 0, Pins("B6"), IOStandard("LVCMOS33")),  # BIST lcd mode output pin

    # Serial
    ("serial", 0,
        Subsignal("tx", Pins("M11")),
        Subsignal("rx", Pins("P12")),
        IOStandard("LVCMOS33")
    ),

    # LVDS
    ("lvds_tx", 0,
        Subsignal("clk_p", Pins("C9")),
        Subsignal("clk_n", Pins("A9")),
        Subsignal("data_p", Pins("C13 B12 C11 B8")),
        Subsignal("data_n", Pins("A13 A12 A11 A8")),
        IOStandard("LVDS_33")
     ),

    # DDR3 SDRAM
    # MT41K128M16
    ("ddram_clock", 0,
        Subsignal("p", Pins("E2")),
        Subsignal("n", Pins("E1")),
        IOStandard("DIFF_SSTL15_II"), Misc("IN_TERM=NONE")
    ),
    ("ddram", 0,
        Subsignal("cke",   Pins("F4"), IOStandard("SSTL15_II")),
        Subsignal("ras_n", Pins("J6"), IOStandard("SSTL15_II")),
        Subsignal("cas_n", Pins("H5"), IOStandard("SSTL15_II")),
        Subsignal("we_n",  Pins("C1"), IOStandard("SSTL15_II")),
        Subsignal("ba",    Pins("C3 C2 B1"), IOStandard("SSTL15_II")),
        # A0  A1  A2  A3  A4  A5  A6  A7  A8  A9  A10 A11 A12 A13 A14
        Subsignal("a", Pins("K5 K6 D1 L4 G5 H4 H3 D3 B2 A2 G6 E3 F3 F6 F5"),
            IOStandard("SSTL15_II")),
        # D0  D1  D2  D3  D4  D5  D6  D7  D8  D9  D10 D11 D12 D13 D14 D15
        Subsignal("dq", Pins(
            "G3 J3 G1 K1 F1 K2 F2 J1 "
            "R1 M2 R2 L3 P1 L1 P2 M1"),
            IOStandard("SSTL15_II")),
        # DQS0+/- (byte 0), DQS1+/- (byte 1)
        Subsignal("dqs",   Pins("H2 N3"), IOStandard("DIFF_SSTL15_II")),
        Subsignal("dqs_n", Pins("H1 N1"), IOStandard("DIFF_SSTL15_II")),
        Subsignal("dm",    Pins("J4 K3"), IOStandard("SSTL15_II")),
        Subsignal("odt",   Pins("L5"), IOStandard("SSTL15_II")),
        Subsignal("reset_n", Pins("E4"), IOStandard("LVCMOS15")),
        Misc("SLEW=FAST"),
        Misc("VCCAUX_IO=HIGH")
    ),

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
    # ("i2c", 0,
    #     Subsignal("scl", Pins("N5"), IOStandard("LVCMOS33")),
    #     Subsignal("sda", Pins("P9"), IOStandard("LVCMOS33"))
    # ),
]

# Platform -----------------------------------------------------------------------------------------

class Platform(XilinxSpartan6Platform):
    default_clk_name   = "clk_osc"
    default_clk_period = 1e9/50e6

    def __init__(self, toolchain="ise", **kwargs):
        XilinxSpartan6Platform.__init__(self, "xc6slx25-3n-ftg256", _io, toolchain=toolchain)
        self.toolchain.additional_commands = ["write_bitstream -force -bin_file {build_name}"]

    def create_programmer(self, kit="openfpgaloader"):
        return OpenFPGALoader(cable="dirtyJtag")

    def do_finalize(self, fragment):
        XilinxSpartan6Platform.do_finalize(self, fragment)
        self.add_period_constraint(self.lookup_request("clk_osc", loose=True), 1e9/50e6)

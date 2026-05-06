# STCC1 Spartan-6 Record Module

This project consists of a custom-designed PCB and a LiteX-based SoC for a data recording module using the Xilinx Spartan-6 FPGA.

## 📂 Project Components

- **[Hardware](./Hardware):** KiCad PCB design files for the STCC1-V5a Record Module. Includes schematics, PCB layout, and production files.
- **[Firmware](./Firmware):** LiteX SoC implementations, including DDR3 support and integration with Xilinx ISE.

## 🛠 Features

- **FPGA:** Spartan-6 XC6SLX25-FTG256.
- **Memory:** DDR3 RAM integration via LiteX.
- **Tools:** KiCad for PCB, LiteX for SoC generation, Xilinx ISE for gateware.

---

## 🚀 Quick Start (Firmware)

1. Navigate to `Firmware/stcc1_xc6slx25/`.
2. Run `./build_firmware.sh b` to build the SoC.
3. Run `./build_firmware.sh m` to compile the RISC-V firmware.
4. Load the bitstream using `openFPGALoader`.

For detailed hardware build instructions, refer to the `Hardware` directory.

# LiteX SoC on MYIR Z-Turn (XC7Z020)

This project implements a LiteX-based SoC on the MYIR Z-Turn board, featuring a Xilinx Zynq-7000 (XC7Z020) SoC. It includes support for standard peripherals and specialized LVDS output.

## 📂 Project Structure

- **[Standard SoC](./Firmware/Litex/myir_xc7z020):** Base SoC implementation with standard peripherals.
- **[LVDS SoC](./Firmware/Litex/myir_xc7z020_lvds):** SoC implementation with LVDS display support.
- **[Hardware Reference](./Hardware):** Original schematics and shield design files.

## 🛠 Key Features

- **Platform:** Zynq-7000 XC7Z020.
- **Peripherals:** Temperature sensing (STLM75), LVDS Display.
- **Build System:** LiteX build scripts for easy gateware and firmware compilation.

## 🚀 Quick Start

To build and load the standard SoC:

```bash
cd Firmware/Litex/myir_xc7z020
./build_firmware.sh b  # Build gateware
./build_firmware.sh m  # Compile firmware
./build_firmware.sh l  # Load to SRAM
```

For more detailed workflows, refer to the README files in the respective firmware directories.

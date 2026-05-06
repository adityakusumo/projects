# LiteX SoC on Qmtech Wukong (Artix-7)

This directory contains the LiteX SoC configuration and RISC-V firmware for the Qmtech Wukong Board.

## 📂 Folder Structure

- `soc.py`: Primary SoC configuration file.
- `qmtech_wukong.py`: Board-specific pinout and definition.
- `firmware/`: C-based firmware for the RISC-V CPU.
- `build/`: Generated gateware and BSP (created after build).

## 🚀 Build Instructions

### Basic Build
Build the SoC gateware and software:
```bash
./build_firmware.sh b
```

### Video Enabled Builds
Build with HDMI terminal console:
```bash
./build_firmware.sh bVid
```

Build with HDMI colorbars:
```bash
./build_firmware.sh bVidColorBar
```

### Compile Firmware
Compile the C firmware in the `firmware/` directory:
```bash
./build_firmware.sh m
```

### Load to Board
Load the generated bitstream into the FPGA SRAM:
```bash
./build_firmware.sh l
```

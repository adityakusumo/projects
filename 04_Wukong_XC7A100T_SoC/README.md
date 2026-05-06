# LiteX SoC on Qmtech Wukong Board (XC7A100T)

This project showcases a LiteX-based SoC implemented on the Qmtech Wukong Board, powered by the Xilinx Artix-7 XC7A100T FPGA.

## 🛠 Features

- **FPGA:** Artix-7 XC7A100T.
- **CPU:** RISC-V (SERV, VexRiscv, etc.).
- **Video:** HDMI output support with colorbar and terminal console.
- **Tools:** LiteX, openFPGALoader.

## 📂 Structure

- **[Firmware/SoC](./Firmware/Litex/qmtech_xc7a100t_wukong):** LiteX SoC configuration and RISC-V C firmware.
- **[Hardware Reference](./Hardware):** Original board schematics.

## 🚀 Quick Start

```bash
cd Firmware/Litex/qmtech_xc7a100t_wukong
./build_firmware.sh b  # Build gateware
./build_firmware.sh m  # Compile firmware
./build_firmware.sh l  # Load to SRAM
```

For HDMI output, use the `bVid` (video console) or `bVidColorBar` (colorbars) build targets.

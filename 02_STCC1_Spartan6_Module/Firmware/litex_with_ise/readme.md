# LiteX SoC with Xilinx ISE Integration

This project demonstrates how to integrate a LiteX-generated SoC into a Xilinx ISE project for the STCC1-V5a board.

## 🛠 Prerequisites

- **Hardware:** STCC1-V5a (XC6SLX25-FTG256)
- **Software:** Xilinx ISE 14.7, LiteX, Migen, VSCode

## 🚀 Workflow Guide

| Step | LiteX & Migen | Xilinx ISE |
| :--- | :--- | :--- |
| **1. Build SoC** | Run `./build_firmware.sh b` (Gateware) and `m` (Firmware). | |
| **2. Import** | | Open ISE project and add `.init` & `.v` files from `build/spartan6_board/gateware/`. |
| **3. Generate** | | Run `Generate Programming File` in ISE. |
| **4. Monitor** | Run `litex_term /dev/ttyACM1 --kernel=firmware/firmware.bin --safe`. | |
| **5. Load** | Run `openFPGALoader -c ft2232 topmod.bit`. | |

## 📊 Expected Output

The terminal will show the LiteX BIOS and firmware "Liftoff!" message. The VGA output should display a smiley face as shown below:

![VGA Output](https://github.com/adityakusumo/projects/blob/main/02_STCC1_Spartan6_Module/Firmware/litex_with_ise/doc/VGA_smile.gif)

---

> [!TIP]
> CSR bridge bus function names are located at: `build/spartan6_board/software/include/generated/csr.h`

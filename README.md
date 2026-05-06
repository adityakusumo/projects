# FPGA & Embedded Systems Portfolio

Welcome to my portfolio of FPGA and Embedded Systems projects. This repository showcases various hardware designs (KiCad), SoC implementations (LiteX), and firmware development (C/RISC-V) across different FPGA platforms.

## 🚀 Projects Overview

| Project | Platform | Key Features |
| :--- | :--- | :--- |
| **[01. LCD 10.4" Tester](./01_LCD_Tester_Spartan6)** | Spartan-6 (XC6SLX25) | LVDS high-res portrait display tester, Custom Firmware (ISE/LiteX). |
| **[02. STCC1 Record Module](./02_STCC1_Spartan6_Module)** | Spartan-6 (XC6SLX25) | Custom PCB Design (KiCad), LiteX SoC Integration, DDR3 Memory. |
| **[03. Z-Turn Board SoC](./03_ZTurn_XC7Z020_SoC)** | Zynq-7000 (XC7Z020) | LiteX SoC on MYIR Z-Turn, Temperature Sensing, LVDS support. |
| **[04. Wukong Board SoC](./04_Wukong_XC7A100T_SoC)** | Artix-7 (XC7A100T) | LiteX SoC on Qmtech Wukong, HDMI output, RISC-V (SERV/VexRiscv). |

---

## 🛠 Technologies & Tools

- **Languages:** Verilog, Python (Migen/LiteX), C (Embedded), Bash
- **SoC Framework:** [LiteX](https://github.com/enjoy-digital/litex) (Migen-based SoC builder)
- **EDA Tools:** KiCad (PCB), Xilinx ISE 14.7, Xilinx Vivado
- **Hardware Debugging:** openFPGALoader, litex_term, JTAG, Oscilloscope

---

## 📂 Repository Structure

```text
.
├── 01_LCD_Tester_Spartan6/    # LCD portrait display tester project
├── 02_STCC1_Spartan6_Module/  # Custom Record Module (Hardware + Firmware)
├── 03_ZTurn_XC7Z020_SoC/      # LiteX SoC on Zynq-7000 Platform
└── 04_Wukong_XC7A100T_SoC/    # LiteX SoC on Artix-7 Platform
```

Each directory contains its own documentation and build instructions.

---
*Created and maintained by [Aditya Kusumo](https://github.com/adityakusumo)*

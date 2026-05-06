# LCD 10.4" Portrait Tester (Spartan-6)

This project is an FPGA-based tester for a 10.4-inch high-resolution portrait display. It utilizes a Spartan-6 FPGA to drive the LVDS interface and handle user inputs for different test modes.

## 🛠 Hardware Specifications

- **FPGA:** QMTech Spartan-6 XC6SLX25FTG256-2 module
- **Display:** 10.4" 960x1280 Portrait LCD (HSD104JPW1-A10)
- **Power Management:** LM2576 DC-DC step-down module
- **Carrier Board:** Custom MFDB1-v2.0 board
- **Power Input:** 28V DC

## ⚙️ System Description

- **User Inputs:**
  - `SW1`: Reset System
  - `SW2`: White Screen Mode
  - `SW3`: BIST (Built-In Self-Test) Mode (Hold for 5 seconds)
- **Outputs:**
  - **LVDS:** High-speed differential signaling to LCD
  - **BIST Mode Discrete:** Status signal (FPGA pin B6 / QMTech U8-23)
  - **Status LED:** Blinking indicator (FPGA pin R9 / QMTech D3)

## 📖 Running Guide

1. **Power:** Connect the Red & Black Banana Jack connectors to a 28V DC power supply.
2. **Connections:** Ensure the MFDB1-V2.0 is correctly connected to the QMTech board:
   - FPC 50-pin connector, 1st pin -> FPGA B6 / QMTech U8-23.
   - Double-row header J1 -> QMTech U8 pins 3-22 (Refer to `.ucf` constraints for details).
3. **LCD Interface:** Connect both LCD flexible cables to the MFDB1-V2.0 board FPC connectors.

## 📺 Demo

<img src="image/lcd_test_demo.gif" width="600" alt="LCD Test Demo">

> [!TIP]
> Refer to the `image` and `reference` folders for detailed schematics and photos.

## 💾 Firmware Flash Guide

There are two versions of the firmware available: Xilinx ISE and LiteX SoC.

- **ISE Version:** Located in `Firmware/ISE/LVDS_Tester_LX25_v2/`
- **LiteX Version:** Located in `Firmware/Litex/qmtech_xc6slx25_vga2lvds/`

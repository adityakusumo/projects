# FPGA-based - LCD 10.4 inch Tester

## Hardware Spec

- QMtech Spartan 6 XC6SLX25FTG256 -2 module (5V power Input)
- LCD 10.4" 960x1280 potrait HSD104JPW1-A10
- LM2576 DC-DC stepdown module
- MFDB1-v2.0 board

## System Description

- Power Input = 28VDC
- Input : 
    1. QMtech Reset Button SW1
    2. QMtech White Screen Button SW2
    3. QMtech BIST Mode Button SW3 (Press at least 5 seconds)
- Output :
    1. LVDS
    2. BIST Mode discrete (FPGA B6 pin; QMtech U8-23 pin)
    3. Blinking LED (QMtech D3; FPGA R9 pin)
    
## Running Guide

1. Connect Red & Black Banana Jack connector to 28VDC power supply
2. Make sure MFDB1-V2.0 to QMtech board connection is in the right order:
- FPC 50pin connector, 1st pin -> FPGA B6/QMtech U8-23
- Double row header J1 -> QMtech U8 pin num. 3-22 (see firmware ucf constraint for more details)
3. Connect both LCD flexible cable to MFDB1-V2.0 board FPC connector

## Running Demo

<img src="image/lcd_test_demo.gif" width="600" alt="LCD Test Demo">

> [!note]
> Please see "image" and "reference" folder for more details

## Firmware Flash Guide

There are 2 version of this tester firmware, ISE and Litex version. Bitstream for both file can be found at:

- ISE: inside Firmware/LVDS_Tester_LX25_v2/boot/
- Litex: inside Firmware/qmtech_xc6slx25_vga2lvds/bitstream/
        

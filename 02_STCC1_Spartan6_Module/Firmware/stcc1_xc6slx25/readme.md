# LiteX SoC on STCC1-V5a (Spartan-6)

This directory contains the LiteX SoC configuration and firmware for the STCC1-V5a board.

## 🛠 Prerequisites

- Hardware: STCC1-V5a (XC6SLX25-FTG256)
- Toolchain: LiteX, RISC-V GCC, xc3sprog

## 🚀 Build & Flash Guide

### Build SoC Gateware
```bash
./build_firmware.sh b
```

### Compile Firmware
```bash
./build_firmware.sh m
```

### Flash to SPI Flash
```bash
./build_firmware.sh f
```

### Run and Monitor
Open a terminal and run `litex_term`:
```bash
litex_term /dev/ttyACM1 --kernel=firmware/firmware.bin --kernel-adr=0x60000000 --safe
```
*Note: Adjust `/dev/ttyACM1` to match your system's serial port.*

## 📊 Expected Output

Upon successful boot, you will see the LiteX BIOS and the custom firmware message:

```text
        __   _ __      _  __
       / /  (_) /____ | |/_/
      / /__/ / __/ -_)>  <
     /____/_/\__/\__/_/|_|

--=============== SoC ==================--
CPU:            SERV @ 50MHz
BUS:            wishbone 32-bit @ 4GiB
MAIN-RAM:       32.0KiB
...
Executing booted program at 0x60000000
--============= Liftoff! ===============--
```

CSR bridge bus definitions can be found at: `build/spartan6_board/software/include/generated/csr.h`

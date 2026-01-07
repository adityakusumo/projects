Prequisite
- hardware board: STCC1-V5a (xc6slx25ftg256)

help:
- ./build_firmware.sh help

how to run:
- ./build_firmware.sh b //for building the hardware bitstream
- ./build_firmware.sh m //for compiling the firmware
- ./build_firmware.sh f //for flashing the bitstream to spi flash using xc3sprog
open another terminal and type
- litex_term /dev/ttyACM1 --kernel=firmware/firmware.bin --kernel-adr=0x60000000 --safe

final step: press the FPGA reset button

viola! you will see this:

        __   _ __      _  __
       / /  (_) /____ | |/_/
      / /__/ / __/ -_)>  <
     /____/_/\__/\__/_/|_|
   Build your hardware, easily!

 (c) Copyright 2012-2025 Enjoy-Digital
 (c) Copyright 2007-2015 M-Labs

 BIOS built on Jan  7 2026 13:42:40
 BIOS CRC passed (9b3da452)

 LiteX git sha1: 0058351d7

--=============== SoC ==================--
CPU:            SERV @ 50MHz
BUS:            wishbone 32-bit @ 4GiB
CSR:            32-bit data big ordering
ROM:            128.0KiB
SRAM:           8.0KiB
MAIN-RAM:       32.0KiB

--========== Initialization ============--

Memtest at 0x60000000 (32.0KiB)...
  Write: 0x60000000-0x60008000 32.0KiB   
   Read: 0x60000000-0x60008000 32.0KiB   
Memtest OK
Memspeed at 0x60000000 (Sequential, 32.0KiB)...
  Write speed: 1.9MiB/s
   Read speed: 1.9MiB/s

--============== Boot ==================--
Booting from serial...
Press Q or ESC to abort boot completely.
sL5DdSMmkekro
[LITEX-TERM] Received firmware download request from the device.
[LITEX-TERM] Uploading firmware/firmware.bin to 0x60000000 (5412 bytes)...
[LITEX-TERM] Upload complete (7.3KB/s).
[LITEX-TERM] Booting the device.
[LITEX-TERM] Done.
Executing booted program at 0x60000000

--============= Liftoff! ===============--
i love anomali sawit >< <3
qiuqiu
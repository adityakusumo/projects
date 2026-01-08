## Prequisite

- hardware board: STCC1-V5a (xc6slx25ftg256)
- VSCode
- Xilinx ISE 14.7
- Litex 2025.4        ~/Litex/litex
- Litex-boards 2025.4 ~/Litex/litex-boards
- Migen 0.9.2
- help
```bash
./build_firmware.sh help
```

## How to Run Guide

The table below shows step by step how to run this litex + ISE project

<table>
  <tr>
    <th>Litex & Migen</th>
    <th>Xilinx ISE</th>
  </tr>
  <tr>
    <td>
      Open Litex and Migen Porject <code>stcc1_xc6slx25</code> in VSCode
    </td>
    <td></td>
  </tr>
  <tr>
    <td>
      <code>build</code> the bitstream and run <code>make</code> for the firmware<br><br>
      <code>./build_firmware.sh b</code> for building the hardware bitstream<br>
      <code>./build_firmware.sh m</code> for compiling the firmware<br><br>
      <i>Note: Requires 50MHz pixel clock.</i>
    </td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td>
      open Xilinx ISE - Litex_STCC_VGA project
    </td>
  </tr>
  <tr>
    <td></td>
    <td>
      on the Hierarchy tab:
      <ul>
        <li>right click</li>
        <li>Add Source...</li>
        <li>Head to stcc1_xc6slx25/build/spartan6_board/gateware/</li>
        <li>Add *.init & *.v files</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td></td>
    <td>
      Run -> <code>Generate Programming File</code>
    </td>
  </tr>  
  <tr>
    <td>
      open new terminal and type<br>
      <code>litex_term /dev/ttyACM1 --kernel=firmware/firmware.bin --safe</code><br>
      <br>
      <i>set /dev/tty* according to your system</i>
    </td>
    <td></td>
  </tr>    
  <tr>
    <td>
      <code>openFPGALoader -c ft2232 ~/Litex_STCC_VGA/topmod.bit</code><br>
      <br>
      <i>change ~/Litex_STCC_VGA to your ISE project directory location</i>      
    </td>
    <td></td>    
  </tr>     
  <tr>
    <td>
      viola! you will see this on the litex_term terminal:
      <pre style="color: hsla(254, 100%, 50%, 1.00); margin: 0; padding: 10px; font-family: monospace;">
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
i love sawit >< <3
qiuqiu</pre>
    </td>
    <td></td>    
  </tr>    
</table>

The VGA output will look like this:
![VGA](https://github.com/adityakusumo/projects/blob/main/Firmware/Litex/STCC_XC6SLX25/litex_with_ise/doc/VGA_smile.gif)

---

> [!TIP]
> CSR bridge bus function name can be seen at: build/spartan6_board/software/include/generated/csr.h
# LiteX Simulation Tutorial
## Running firmware simulation without FPGA hardware (Arch Linux)

---

## Prerequisites

Make sure these are installed:

```bash
# Verilator (required for simulation)
yay -S verilator

# LiteX simulation dependencies
yay -S libevent json-c

# Verify verilator works
verilator --version
```

---

## Project Structure

Your project should look like this:

```text
myir_xc7z020/
├── soc.py
├── zynq_board.py
├── VGAToLVDS.py
├── firmware/
│   ├── main.c
│   ├── Makefile
│   ├── firmware.bin        ← compiled output lives here
│   ├── firmware.elf        ← compiled output lives here
│   └── ...
└── build/
    └── zynq_board/
        └── software/
            └── bios/
                └── bios.bin
```

---

## Step 1 — Build the SoC (software only, no gateware needed for sim)

```bash
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020

python3 soc.py --build --no-compile-gateware
```

This generates:
- `build/zynq_board/software/bios/bios.bin` — the BIOS
- `build/zynq_board/software/firmware/variables.mak` — memory map with correct addresses for sim

---

## Step 2 — Build firmware using sim's memory map

This is the **critical step**. The sim uses different memory addresses than the real board.
You must build firmware using the sim's `variables.mak` so it links to the correct address (`0x40000000`).

```bash
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020/firmware

make BUILD_DIR=../build/zynq_board/software clean
make BUILD_DIR=../build/zynq_board/software
```

---

## Step 3 — Verify firmware links to correct address

```bash
nm firmware.elf | grep "main\|_ftext\|_start"
```

You should see addresses starting with `0x40000000`, for example:
```text
40000000 T _ftext
40000160 T main
40000000 T _start
```

If you see `0x00000000` instead, the linker script needs to be fixed (see Troubleshooting below).

---

## Step 4 — Run the simulation

```bash
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020

litex_sim --cpu-type=vexriscv \
    --integrated-main-ram-size=0x8000 \
    --ram-init=firmware/firmware.bin
```

Your `printf` output will appear **directly in this terminal** — no second terminal or litex-term needed.

Expected output:
```text
--============= Liftoff! ===============--
...
mulaiiii
STLM75 Temperature Reader on Zynq Z020
STLM75 NOT found at 0x49 — LED will not blink
```

Note: The sensor won't be found since there's no real I2C hardware in simulation.
The LED CSR toggle will execute silently without error.

---

## Quick Reference — Full flow from scratch

```bash
# 1. Go to project directory
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020

# 2. Build software only
python3 soc.py --build --no-compile-gateware

# 3. Build firmware with sim addresses
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020/firmware
make BUILD_DIR=../build/zynq_board/software clean && make BUILD_DIR=../build/zynq_board/software

# 4. Verify address (should show 0x40000000)
nm firmware.elf | grep "_ftext"

# 5. Run sim
cd ~/Remote_Syncthing/litex_prj/myir_xc7z020
litex_sim --cpu-type=vexriscv \
    --integrated-main-ram-size=0x8000 \
    --ram-init=firmware/firmware.bin
```

---

## Troubleshooting

### firmware links to 0x00000000 instead of 0x40000000

The linker script is targeting `rom` instead of `main_ram`. Edit `firmware/linker.ld`:

```bash
# Change all sections from rom/sram to main_ram:

.text     : { ... } > main_ram      # was: } > rom
.rodata   : { ... } > main_ram      # was: } > rom
.data     : { ... } > main_ram      # was: } > sram AT > rom
.bss      : { ... } > main_ram      # was: } > sram

PROVIDE(_fstack = ORIGIN(main_ram) + LENGTH(main_ram));
# was: PROVIDE(_fstack = ORIGIN(sram) + LENGTH(sram));
```

Then rebuild:
```bash
make BUILD_DIR=../build/zynq_board/software clean && make BUILD_DIR=../build/zynq_board/software
```

### Simulation crashes / segfault

This is usually a Verilator version incompatibility or your computer running low on memory.
Verilator 4.x is recommended:

```bash
verilator --version   # check version
yay -S verilator4     # install v4 if needed
```

### printf output not showing

Make sure `uart_init()` is called at the start of `main()`:

```c
int main(void)
{
    uart_init();   // must not be commented out
    printf("hello\r\n");
    ...
}
```

### snprintf not available

LiteX's libc stub does not provide `snprintf`. Add this replacement after your `#include` lines:

```c
#include <stdarg.h>

static int snprintf(char *buf, size_t size, const char *fmt, ...)
{
    va_list ap;
    int n;
    va_start(ap, fmt);
    n = vsnprintf(buf, size, fmt, ap);
    va_end(ap);
    return n;
}
```

### Simulation runs but hangs at clocker message

```text
[clocker] sys_clk: freq_hz=1000000, phase_deg=0
```

This is normal — the sim is running at 1 MHz (96x slower than real hardware).
Just wait, output will appear. If using `busy_wait(1000)` in firmware, each call
takes ~1 real second in sim. Reduce `busy_wait` values for faster sim output.

---

## Notes

- Sim clock is **1 MHz** by default (real board runs at 96 MHz) — everything runs 96x slower
- Xilinx primitives (OSERDESE2, PLLE2_ADV, OBUFDS) are **not simulated** — only CPU, UART, I2C CSRs, and memory work in sim
- Use sim to test firmware logic, printf output, and CSR register access before flashing to real hardware
- The `--integrated-main-ram-size=0x8000` creates 32KB of RAM — increase if your firmware is larger

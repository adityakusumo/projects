# LiteX SoC Build & Flash Guide
## myir_xc7z020 — Zynq XC7Z020

---

## Quick Reference

| Command | Description |
|---|---|
| `./build_firmware.sh b` | Build SoC gateware + software (first time / after soc.py changes) |
| `./build_firmware.sh m` | Compile firmware only (after editing main.c) |
| `./build_firmware.sh bi` | Build SoC with firmware.bin baked into bitstream |
| `./build_firmware.sh l` | Load bitstream into SRAM via openFPGALoader |
| `./build_firmware.sh f` | Flash bitstream to SPI Flash via openFPGALoader |

---

## Workflow A — Development (firmware uploaded via litex-term)

Use this when actively developing firmware. Gateware is loaded once,
firmware is uploaded over serial each time — much faster iteration.

### Step 1 — Build SoC (first time or after soc.py changes)

```bash
./build_firmware.sh b
```

This generates:
- `build/zynq_board/gateware/zynq_board.bit` — the bitstream
- `build/zynq_board/software/bios/bios.bin` — the BIOS
- `firmware/` — generated headers and variables

### Step 2 — Compile firmware

```bash
./build_firmware.sh m
```

This compiles `firmware/main.c` and produces `firmware/firmware.bin`.

### Step 3 — Load bitstream into SRAM

```bash
./build_firmware.sh l
```

The board will boot into the LiteX BIOS and wait for firmware upload.

### Step 4 — Open litex-term in a separate terminal to upload firmware

Find your serial port first:

```bash
ls /dev/ttyACM*
# or
ls /dev/ttyUSB*
```

Then connect litex-term and upload firmware:

```bash
litex_term /dev/ttyACM0 --kernel=firmware/firmware.bin --kernel-adr=0x40000000 --safe
```

> **Notes:**
> - Replace `/dev/ttyACM0` with your actual port (e.g. `/dev/ttyACM1`, `/dev/ttyUSB0`)
> - Replace `0x40000000` with the actual `main_ram` base address from your memory map
> - To check your `main_ram` address: `grep -i "main_ram" build/zynq_board/software/include/generated/regions.ld`
> - `--safe` flag ensures reliable upload even on slower connections

You should see the BIOS output, then firmware upload, then your firmware running:

```text
--============= Liftoff! ===============--
...
Memtest OK
--============== Boot ==================--
Booting from serial...
[LITEX-TERM] Uploading firmware/firmware.bin...
[LITEX-TERM] Upload complete.
Executing booted program at 0x40000000
--============= Liftoff! ===============--
mulaiiii
STLM75 Temperature Reader on Zynq Z020
```

### Iterating on firmware

After editing `main.c`, just recompile and re-upload — no need to rebuild gateware:

```bash
# Terminal 1
./build_firmware.sh m

# Terminal 2 (litex-term already open, press reset on board or restart litex-term)
litex_term /dev/ttyACM0 --kernel=firmware/firmware.bin --kernel-adr=0x40000000 --safe
```

---

## Workflow B — Production (firmware baked into bitstream)

Use this when firmware is finalized and you want a single self-contained bitstream
that boots directly into your firmware without needing litex-term.

### Step 1 — Compile firmware

```bash
./build_firmware.sh m
```

### Step 2 — Build SoC with firmware integrated

```bash
./build_firmware.sh bi
```

This runs `soc.py --integrated-rom-init firmware/firmware.bin --build` which bakes
`firmware/firmware.bin` directly into the bitstream ROM. On boot it runs your
firmware immediately with no BIOS upload step.

### Step 3 — Flash to SPI Flash (permanent)

```bash
./build_firmware.sh f
```

The bitstream is now stored in SPI Flash and will survive power cycles.
The board boots directly into your firmware on every power-on.

---

## Workflow C — Load to SRAM only (temporary, for testing)

Bitstream lives in SRAM — lost on power cycle. Good for quick testing.

```bash
./build_firmware.sh l
```

---

## Checking main_ram address

The `--kernel-adr` value for litex-term must match your SoC's `main_ram` base address.
Check it after building:

```bash
grep -i "main_ram" build/zynq_board/software/include/generated/regions.ld
```

Default for this board is `0x40000000`.

---

## Simulation (no hardware needed)

See `LITEX_SIM_README.md` for the full simulation workflow using `litex_sim`.

Quick command:

```bash
# Build firmware for sim (uses sim memory addresses)
cd firmware
make BUILD_DIR=../build/sim clean && make BUILD_DIR=../build/sim
cd ..

# Run sim
litex_sim --cpu-type=vexriscv \
    --integrated-main-ram-size=0x8000 \
    --ram-init=firmware/firmware.bin
```

Or use the build script shortcut:

```bash
./build_firmware.sh ms
```

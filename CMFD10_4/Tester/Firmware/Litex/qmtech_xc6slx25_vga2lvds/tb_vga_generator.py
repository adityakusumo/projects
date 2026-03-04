"""
tb_vga_generator.py
====================
Migen simulation testbench for VGAGenerator (vga_generator.py).
Pixel clock = 40 MHz  →  period = 25 ns

Simulates enough cycles to cover:
  - Several full horizontal lines (HPIXEL_END+1 = 1020 cycles each)
  - At least 2 full frames to verify vsync wrap-around

Output: vga_sim.vcd  →  open with GTKWave

Run:
    python tb_vga_generator.py

Requirements:
    pip install migen
"""

from migen import *
from migen.sim import run_simulation

# ── import the DUT ───────────────────────────────────────────────────────────
from VGAGenerator import VGAGenerator, HPIXEL_END, VLINE_END

# ============================================================
# Timing constants (from vga_generator.py)
# ============================================================
PIXEL_CLK_FREQ  = 40_000_000          # 40 MHz
PIXEL_PERIOD_NS = 1_000_000_000 // PIXEL_CLK_FREQ   # 25 ns

TOTAL_COLS = HPIXEL_END + 1           # 1020 pixels per line
TOTAL_ROWS = VLINE_END  + 1           # 1320 lines per frame
CYCLES_PER_FRAME = TOTAL_COLS * TOTAL_ROWS   # 1,346,400 cycles / frame

# How many frames to simulate (2 frames is enough to verify wrap-around)
SIM_FRAMES = 2
SIM_CYCLES = SIM_FRAMES * CYCLES_PER_FRAME + 100   # small margin


# ============================================================
# Testbench generator
# ============================================================
def testbench(dut):
    """
    Drive rainbow signal and run for SIM_CYCLES clocks.
    Prints key events to stdout for quick sanity checking.
    """
    print(f"[TB] Pixel clock : {PIXEL_CLK_FREQ/1e6:.1f} MHz  ({PIXEL_PERIOD_NS} ns period)")
    print(f"[TB] Frame size  : {TOTAL_COLS} x {TOTAL_ROWS} = {CYCLES_PER_FRAME} cycles/frame")
    print(f"[TB] Simulating  : {SIM_FRAMES} frames = {SIM_CYCLES} cycles\n")

    # ── First frame: rainbow = 1 ─────────────────────────────
    yield dut.rainbow.eq(1)
    print("[TB] Rainbow mode ON (frame 1)")

    prev_vsync = 1
    prev_hsync = 1
    hsync_count = 0
    vsync_count = 0

    for cycle in range(SIM_CYCLES):
        yield  # advance one clock

        # Sample outputs
        de_val    = yield dut.de
        hs_val    = yield dut.hsync
        vs_val    = yield dut.vsync
        r_val     = yield dut.r
        g_val     = yield dut.g
        b_val     = yield dut.b

        # Detect falling edge of hsync (active-low → pulse start)
        if prev_hsync == 1 and hs_val == 0:
            hsync_count += 1
            if hsync_count <= 5:
                print(f"  [cycle {cycle:>8}] HSync pulse #{hsync_count:>4}")

        # Detect falling edge of vsync
        if prev_vsync == 1 and vs_val == 0:
            vsync_count += 1
            print(f"  [cycle {cycle:>8}] *** VSync pulse #{vsync_count} (frame boundary) ***")

            # Switch rainbow off for the second frame
            if vsync_count == 1:
                yield dut.rainbow.eq(0)
                print("[TB] Rainbow mode OFF (frame 2 → white)")

        prev_hsync = hs_val
        prev_vsync = vs_val

    print(f"\n[TB] Done. HSync pulses: {hsync_count}, VSync pulses: {vsync_count}")
    print("[TB] VCD written → vga_sim.vcd")
    print("[TB] Open with:  gtkwave vga_sim.vcd")


# ============================================================
# Main
# ============================================================
if __name__ == "__main__":
    dut = VGAGenerator()

    # Signals to dump into the VCD
    # (run_simulation dumps ALL signals when vcd_name is given)
    run_simulation(
        dut,
        testbench(dut),
        vcd_name="vga_sim.vcd",
        clocks={"sys": PIXEL_PERIOD_NS},   # 40 MHz → 25 ns half-period
    )

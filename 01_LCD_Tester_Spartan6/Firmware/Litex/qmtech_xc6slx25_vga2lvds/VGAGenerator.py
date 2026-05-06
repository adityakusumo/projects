"""
vga_generator.py
Generates VGA timing (DE, HSync, VSync) and color data (RGB888)
for 960x1280 portrait @ 60Hz, clocked by an external pixel clock.

Rainbow stripes (horizontal bands) when rainbow=1, white when rainbow=0.
"""

from migen import *

# ============================================================
# Resolution / Timing Constants  (960x1280 @ 60Hz portrait)
# ============================================================
HRES  = 960
VRES  = 1280

HFPOR = 20
HSYN  = 10
HBPOR = 30

VFPOR = 10
VSYN  = 4
VBPOR = 26

HDAT_BEGIN = HBPOR + HSYN - 1
HDAT_END   = HDAT_BEGIN + HRES
HPIXEL_END = HDAT_END + HFPOR

VDAT_BEGIN = VBPOR + VSYN - 1
VDAT_END   = VDAT_BEGIN + VRES
VLINE_END  = VDAT_END + VFPOR

H_MAX = HRES - 1
V_MAX = VRES - 1

# HSync/VSync active regions (active low pulses)
HSYNC_START = 0
HSYNC_END   = HSYN - 1
VSYNC_START = 0
VSYNC_END   = VSYN - 1

# ============================================================
# Rainbow color bar constants
# 8 horizontal bands across VRES lines
# Colors: Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
# ============================================================
NUM_SEGMENTS = 8
INCREMENT    = VRES // NUM_SEGMENTS   # 160 lines per band
LINE = [INCREMENT * (i + 1) for i in range(NUM_SEGMENTS)]

# Each band: (R, G, B)
COLORS = [
    (0x00, 0x00, 0x00),  # 0: Black
    (0xFF, 0x00, 0x00),  # 1: Red
    (0x00, 0xFF, 0x00),  # 2: Green
    (0xFF, 0xFF, 0x00),  # 3: Yellow
    (0x00, 0x00, 0xFF),  # 4: Blue
    (0xFF, 0x00, 0xFF),  # 5: Magenta
    (0x00, 0xFF, 0xFF),  # 6: Cyan
    (0xFF, 0xFF, 0xFF),  # 7: White
]


class VGAGenerator(Module):
    def __init__(self):
        # --------------------------------------------------
        # I/O
        # --------------------------------------------------
        self.rainbow = rainbow = Signal()   # 1=rainbow, 0=white

        # VGA outputs (feed into VGAToLVDS)
        self.de    = de    = Signal()
        self.hsync = hsync = Signal()
        self.vsync = vsync = Signal()
        self.r     = r     = Signal(8)
        self.g     = g     = Signal(8)
        self.b     = b     = Signal(8)

        # --------------------------------------------------
        # Internal counters (driven by sys clock = pixel clock)
        # --------------------------------------------------
        hcount = Signal(max=HPIXEL_END + 1, reset=0)
        vcount = Signal(max=VLINE_END  + 1, reset=0)

        # Active-area pixel position (used for color generation)
        px = Signal(max=HRES + 1, reset=0)   # x within active area
        py = Signal(max=VRES + 1, reset=0)   # y within active area

        hcount_ov = Signal()
        vcount_ov = Signal()

        # --------------------------------------------------
        # Combinational: overflow flags, sync, DE
        # --------------------------------------------------
        self.comb += [
            hcount_ov.eq(hcount == HPIXEL_END),
            vcount_ov.eq(vcount == VLINE_END),

            de.eq(
                (hcount >= HDAT_BEGIN) & (hcount < HDAT_END) &
                (vcount >= VDAT_BEGIN) & (vcount < VDAT_END)
            ),

            # Active-low sync pulses
            hsync.eq(~((hcount >= HSYNC_START) & (hcount <= HSYNC_END))),
            vsync.eq(~((vcount >= VSYNC_START) & (vcount <= VSYNC_END))),
        ]

        # --------------------------------------------------
        # Sequential: counters (clocked by pixel clock = sys clock)
        # --------------------------------------------------
        self.sync += [
            # Horizontal counter
            If(hcount_ov,
                hcount.eq(0),
                If(vcount_ov,
                    vcount.eq(0),
                ).Else(
                    vcount.eq(vcount + 1),
                )
            ).Else(
                hcount.eq(hcount + 1),
            ),

            # Active-area pixel position tracking
            If(de,
                If(px >= H_MAX,
                    px.eq(0),
                    If(py >= V_MAX,
                        py.eq(0),
                    ).Else(
                        py.eq(py + 1),
                    )
                ).Else(
                    px.eq(px + 1),
                )
            ),
        ]

        # --------------------------------------------------
        # Color generation (combinational, based on py = vertical position)
        # Rainbow: 8 horizontal color bands
        # White: all channels 0xFF
        # Outside active area: black (DE=0, outputs don't matter but clean anyway)
        # --------------------------------------------------
        r_rainbow = Signal(8)
        g_rainbow = Signal(8)
        b_rainbow = Signal(8)

        # Build rainbow color selection using If/Elif chain
        self.comb += [
            If(py < LINE[0],
                r_rainbow.eq(COLORS[0][0]), g_rainbow.eq(COLORS[0][1]), b_rainbow.eq(COLORS[0][2]),
            ).Elif(py < LINE[1],
                r_rainbow.eq(COLORS[1][0]), g_rainbow.eq(COLORS[1][1]), b_rainbow.eq(COLORS[1][2]),
            ).Elif(py < LINE[2],
                r_rainbow.eq(COLORS[2][0]), g_rainbow.eq(COLORS[2][1]), b_rainbow.eq(COLORS[2][2]),
            ).Elif(py < LINE[3],
                r_rainbow.eq(COLORS[3][0]), g_rainbow.eq(COLORS[3][1]), b_rainbow.eq(COLORS[3][2]),
            ).Elif(py < LINE[4],
                r_rainbow.eq(COLORS[4][0]), g_rainbow.eq(COLORS[4][1]), b_rainbow.eq(COLORS[4][2]),
            ).Elif(py < LINE[5],
                r_rainbow.eq(COLORS[5][0]), g_rainbow.eq(COLORS[5][1]), b_rainbow.eq(COLORS[5][2]),
            ).Elif(py < LINE[6],
                r_rainbow.eq(COLORS[6][0]), g_rainbow.eq(COLORS[6][1]), b_rainbow.eq(COLORS[6][2]),
            ).Else(
                r_rainbow.eq(COLORS[7][0]), g_rainbow.eq(COLORS[7][1]), b_rainbow.eq(COLORS[7][2]),
            )
        ]

        # Final color mux: rainbow or white, blanked outside active area
        self.comb += [
            If(~de,
                # Blank during sync/blanking periods
                r.eq(0x00), g.eq(0x00), b.eq(0x00),
            ).Elif(rainbow,
                r.eq(r_rainbow), g.eq(g_rainbow), b.eq(b_rainbow),
            ).Else(
                r.eq(0xFF), g.eq(0xFF), b.eq(0xFF),
            )
        ]

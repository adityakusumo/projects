#!/bin/bash
set -e

# =============================================================================
# LiteX/Migen Firmware Build Script
# =============================================================================

source ~/Litex/LITEX_VENV/bin/activate

# Resolve project root relative to this script's location
PROJECT_ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# =============================================================================
# Configuration
# =============================================================================

BITSTREAM="$PROJECT_ROOT/build/zynq_board/gateware/zynq_board.bit"
BSCAN="/home/dit/Git/xilinx_spioverjtag/bscan_xc6slx25_ftg256.bit"
CABLE_TYPE="ftdi"
OPENFPGA_CABLE_TYPE="ft2232"

# =============================================================================
# Helpers
# =============================================================================

show_help() {
    echo "Usage: ./build_firmware.sh <option>"
    echo ""
    echo "Options:"
    echo "  b     Build SoC (soc.py --build)"
    echo "  bd    Build SoC with documentation"
    echo "  bS    Build SoC with SERV CPU and documentation"
    echo "  bi    Build SoC with integrated firmware ROM"
    echo "  biS   Build SoC with integrated firmware ROM and SERV CPU"
    echo "  m     Compile firmware (make)"
    echo "  l     Load bitstream into BRAM via openFPGALoader"
    echo "  l2    Load a hardcoded test bitstream into BRAM"
    echo "  f     Flash bitstream to SPI flash via openFPGALoader"
    echo "  f2    Flash bitstream to SPI flash via xc3sprog"
    echo "  all   Full flow: build SoC → compile firmware → flash"
    echo "  all2  Quick flow: build SoC → load into BRAM"
    echo "  h     Show this help message"
}

require_bitstream() {
    if [ ! -f "$BITSTREAM" ]; then
        echo "Error: Bitstream not found at $BITSTREAM"
        echo "Run with 'b' first to generate it."
        exit 1
    fi
}

# =============================================================================
# Pre-flight checks
# =============================================================================

if [ $# -eq 0 ]; then
    show_help
    exit 1
fi

if [ ! -f "soc.py" ]; then
    echo "Error: soc.py not found in current directory."
    exit 1
fi

if [ ! -d "firmware" ]; then
    echo "Error: firmware/ directory not found."
    exit 1
fi

# =============================================================================
# Commands
# =============================================================================

case "$1" in
    m)
        echo "--- Compiling Firmware ---"
        cd firmware
        make clean
        make
        cd ..
        ;;

    ms)
        echo "--- Compiling Firmware for Sim ---"
        cd firmware
        make BUILD_DIR=../build/sim clean && make BUILD_DIR=../build/sim
        cd ..
        ;;

    b)
        echo "--- Building SoC ---"
        python soc.py --build
        ;;

    bd)
        echo "--- Building SoC with Documentation ---"
        python soc.py --build --doc
        cd build/documentation
        sphinx-build -M html . _build
        cd ../..
        ;;

    bS)
        echo "--- Building SoC (SERV CPU) with Documentation ---"
        python soc.py --cpu-type serv --build --doc
        cd build/documentation
        sphinx-build -M html . _build
        cd ../..
        ;;

    bi)
        echo "--- Building SoC with Integrated Firmware ROM ---"
        python soc.py --integrated-rom-init firmware/firmware.bin --build
        ;;

    biS)
        echo "--- Building SoC with Integrated Firmware ROM (SERV CPU) ---"
        python soc.py --integrated-rom-init firmware/firmware.bin --cpu-type serv --build --doc
        ;;

    l)
        echo "--- Loading Bitstream into BRAM ---"
        echo "Bitstream: $BITSTREAM"
        openFPGALoader -c "$OPENFPGA_CABLE_TYPE" "$BITSTREAM"
        ;;

    l2)
        echo "--- Loading Test Bitstream into BRAM ---"
        openFPGALoader -c ft2232 ~/Xilinx_Prj/ISE/1_STCC/Litex_STCC_VGA/topmod.bit
        ;;

    f)
        echo "--- Flashing Bitstream to SPI Flash (openFPGALoader) ---"
        require_bitstream
        openFPGALoader --fpga-part xc6slx25ftg256 -c "$OPENFPGA_CABLE_TYPE" -f "$BITSTREAM"
        ;;

    f2)
        echo "--- Flashing Bitstream to SPI Flash (xc3sprog) ---"
        require_bitstream
        xc3sprog -c "$CABLE_TYPE" -I"$BSCAN" "$BITSTREAM"
        ;;

    s)
        echo "--- Run Simulation ---"
        litex_sim --cpu-type=vexriscv \
            --integrated-main-ram-size=0x8000 \
            --ram-init=firmware/firmware.bin
        ;;

    all)
        echo "--- Full Flow: Build → Firmware → Flash ---"
        "$0" b && "$0" m && "$0" f
        ;;

    all2)
        echo "--- Quick Flow: Build → Load BRAM ---"
        "$0" b && "$0" l
        ;;

    h|--help)
        show_help
        ;;

    *)
        echo "Error: Unknown option '$1'"
        echo ""
        show_help
        exit 1
        ;;
esac

# #!/bin/bash
# set -e


# # Navigate to the firmware directory
# cd firmware

# # Run make clean
# make clean

# # Run make
# make

# # Navigate back to the parent directory
# cd ..

# # Build the project
# # python soc.py --cpu-type serv --build
# # python soc.py --integrated-rom-init firmware/firmware.bin --cpu-type serv --build

# #xc3sprog -c ftdi -I/home/dit/Git/xilinx_spioverjtag/bscan_xc6slx25_ftg256.bit /home/dit/litex_prj/stcc1_xc6slx25/build/spartan6_board/gateware/spartan6_board.bit



#!/bin/bash

# Configuration - Change these to match your actual file names
BSCAN="/home/dit/Git/xilinx_spioverjtag/bscan_xc6slx25_ftg256.bit"
BITSTREAM="/home/dit/litex_prj/stcc1_xc6slx25/build/spartan6_board/gateware/spartan6_board.bit"
CABLE_TYPE="ftdi" # Change to your cable (e.g., xpc, ft2232, etc.)
OPENFPGA_CABLE_TYPE="ft2232" # Change to your cable (e.g., xpc, ft2232, etc.)

# Function to display help
show_help() {
    echo "Usage: ./build_firmware.sh [option]"
    echo "Options:"
    echo "  b    Build: Run the LiteX soc.py build"
    echo "  c    Build: Run the LiteX soc.py build with integrated ROM"
    echo "  m    Make: Compile the firmware"
    echo "  l    Load: Run OpenFPGALoader to load the bitstream into bram"
    echo "  f    Flash: Run xc3sprog to load the bitstream into spi flash"
    echo "  all  Build and then Flash"
    echo "  h    Show this help message"
}

# If no arguments are provided, show help
if [ $# -eq 0 ]; then
    show_help
    exit 1
fi

case "$1" in
    m)
        echo "--- Starting Firmware Make ---"
        set -e
        cd firmware
        make clean
        make
        cd ..        
        ;;
    b)
        echo "--- Starting Python Build ---"
        python soc.py --cpu-type serv --build --doc
        cd build/documentation
        sphinx-build -M html . _build
        cd ../..
        ;;
    c)
        echo "--- Starting Python Build Integrated ROM ---"
        python soc.py --integrated-rom-init firmware/firmware.bin --cpu-type serv --build --doc
        ;;
    l)
        echo "--- Load Bit File ---"
        openFPGALoader -c "$OPENFPGA_CABLE_TYPE" "$BITSTREAM"
        ;;
    l2)
        echo "--- Load Bit File ---"
        openFPGALoader -c ft2232 ~/Xilinx_Prj/ISE/1_STCC/Litex_STCC_VGA/topmod.bit
        ;;
    f)
        echo "--- Flashing Device ---"
        if [ -f "$BITSTREAM" ]; then
            xc3sprog -c "$CABLE_TYPE" -I"$BSCAN"  "$BITSTREAM"
        else
            echo "Error: Bitstream $BITSTREAM not found. Run with 'b' first."
            exit 1
        fi
        ;;
    f2)
        echo "--- Flashing Device ---"
        if [ -f "$BITSTREAM" ]; then
            xc3sprog -c "$CABLE_TYPE" -I"$BSCAN"  /home/dit/Xilinx_Prj/ISE/1_STCC/Litex_STCC_VGA/topmod.bit

        else
            echo "Error: Bitstream $BITSTREAM not found. Run with 'b' first."
            exit 1
        fi
        ;;
    all)
        $0 b && $0 m && $0 f
        ;;
    h|--help)
        show_help
        ;;
    *)
        echo "Invalid option: $1"
        show_help
        exit 1
        ;;
esac
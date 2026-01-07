#!/bin/bash
set -e

# Build the project
# python soc.py --cpu-type serv --build
python soc.py --build --doc --cpu-type serv

# Navigate to the firmware directory
cd demo

# Run make clean
make clean

# Run make
make

# Navigate back to the parent directory
cd ..

# Run the Python script with arguments
# python soc.py --cpu-type serv --integrated-rom-init firmware/firmware.bin --build

openFPGALoader --cable dirtyJtag --bitstream /home/dit/litex_prj/stcc1_xc6slx25/build/spartan6_board/gateware/spartan6_board.bit
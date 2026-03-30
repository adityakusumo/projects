## Folder Structure

```bash
qmtech_xc7a100t_wukong
├── build                 # build folder from litex (generete BSP + SOC verilog)
├── firmware              # RISC-V firmware (C/Cpp Code Here)
├── readme.md             # this readme
├── soc.py                # python file to create SOC
└── qmtech_wukong.py      # python for board pinout and family
```

## How To Build

```bash
python soc.py --cpu-type serv --build # you can change cpu-type (picorv, vexriscv, etc).
```

or use build_firmware.sh

```bash
./build_firmware.sh b
```

for showing litex_term on hdmi:

```bash
./build_firmware.sh bVid
```

for showing colorbars on hdmi:

```bash
./build_firmware.sh bVidColorBar
```

and then load the bitstream using (openFPGALoader)

```bash
./build_firmware.sh l
```

if build complete without error. Go to firmware folder.
Build firware with `make`. We need firmware.bin to build into bitstream:

```bash
./build_firmware.sh m
```

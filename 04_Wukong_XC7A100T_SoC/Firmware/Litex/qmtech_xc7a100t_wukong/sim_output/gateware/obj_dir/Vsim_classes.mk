# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vsim.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  Vsim \
  Vsim___024root__DepSet_h104c642d__0 \
  Vsim___024root__DepSet_hb1836b75__0 \
  Vsim_sim__DepSet_h837b84dc__0 \
  Vsim_sim__DepSet_h40728c06__0 \
  Vsim_VexRiscv__DepSet_hda50bfa8__0 \
  Vsim_VexRiscv__DepSet_hda50bfa8__1 \
  Vsim_VexRiscv__DepSet_h9f7c89a9__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  Vsim__ConstPool_0 \
  Vsim___024root__Slow \
  Vsim___024root__DepSet_h104c642d__0__Slow \
  Vsim___024root__DepSet_hb1836b75__0__Slow \
  Vsim_sim__Slow \
  Vsim_sim__DepSet_h837b84dc__0__Slow \
  Vsim_sim__DepSet_h40728c06__0__Slow \
  Vsim_VexRiscv__Slow \
  Vsim_VexRiscv__DepSet_hda50bfa8__0__Slow \
  Vsim_VexRiscv__DepSet_hda50bfa8__1__Slow \
  Vsim_VexRiscv__DepSet_h9f7c89a9__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  Vsim__Dpi \
  Vsim__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  Vsim__Syms \
  Vsim__Trace__0__Slow \
  Vsim__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_dpi \
  verilated_vcd_c \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"
#include "Vsim__Syms.h"

void Vsim_VexRiscv___ctor_var_reset(Vsim_VexRiscv* vlSelf);

Vsim_VexRiscv::Vsim_VexRiscv(Vsim__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsim_VexRiscv___ctor_var_reset(this);
}

void Vsim_VexRiscv::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsim_VexRiscv::~Vsim_VexRiscv() {
}

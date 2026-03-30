// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim__Syms.h"
#include "Vsim_sim.h"

void Vsim_sim___ctor_var_reset(Vsim_sim* vlSelf);

Vsim_sim::Vsim_sim(Vsim__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsim_sim___ctor_var_reset(this);
}

void Vsim_sim::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsim_sim::~Vsim_sim() {
}

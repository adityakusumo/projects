// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim.h for the primary calling header

#ifndef VERILATED_VSIM___024ROOT_H_
#define VERILATED_VSIM___024ROOT_H_  // guard

#include "verilated.h"
class Vsim_sim;


class Vsim__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim___024root final : public VerilatedModule {
  public:
    // CELLS
    Vsim_sim* sim;

    // DESIGN SPECIFIC STATE
    VL_IN8(serial_sink_data,7,0);
    VL_OUT8(serial_sink_ready,0,0);
    VL_IN8(serial_sink_valid,0,0);
    VL_OUT8(serial_source_data,7,0);
    VL_IN8(serial_source_ready,0,0);
    VL_OUT8(serial_source_valid,0,0);
    VL_OUT8(sim_trace,0,0);
    VL_IN8(sys_clk,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sys_clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsim__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim___024root(Vsim__Syms* symsp, const char* v__name);
    ~Vsim___024root();
    VL_UNCOPYABLE(Vsim___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

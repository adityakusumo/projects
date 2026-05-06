// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim___024root.h"

void Vsim___024root___eval_triggers__ico(Vsim___024root* vlSelf);
void Vsim___024root___eval_ico(Vsim___024root* vlSelf);

bool Vsim___024root___eval_phase__ico(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_phase__ico\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsim___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vsim___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsim___024root___eval_act(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_act\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vsim___024root___eval_triggers__act(Vsim___024root* vlSelf);

bool Vsim___024root___eval_phase__act(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_phase__act\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsim___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsim___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsim___024root___eval_nba(Vsim___024root* vlSelf);

bool Vsim___024root___eval_phase__nba(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_phase__nba\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsim___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__ico(Vsim___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__nba(Vsim___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__act(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim___024root___eval(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vsim___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/dit/Remote_Syncthing/litex_prj/qmtech_xc7a100t_wukong/sim_output/gateware/sim.v", 23, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsim___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsim___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/dit/Remote_Syncthing/litex_prj/qmtech_xc7a100t_wukong/sim_output/gateware/sim.v", 23, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsim___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/dit/Remote_Syncthing/litex_prj/qmtech_xc7a100t_wukong/sim_output/gateware/sim.v", 23, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsim___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsim___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsim___024root___eval_debug_assertions(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_debug_assertions\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.serial_sink_valid & 0xfeU)))) {
        Verilated::overWidthError("serial_sink_valid");}
    if (VL_UNLIKELY(((vlSelfRef.serial_source_ready 
                      & 0xfeU)))) {
        Verilated::overWidthError("serial_source_ready");}
    if (VL_UNLIKELY(((vlSelfRef.sys_clk & 0xfeU)))) {
        Verilated::overWidthError("sys_clk");}
}
#endif  // VL_DEBUG

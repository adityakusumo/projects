// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim__Syms.h"
#include "Vsim___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__ico(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim___024root___eval_triggers__ico(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_triggers__ico\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vsim_VexRiscv___ico_sequent__TOP__sim__VexRiscv__0(Vsim_VexRiscv* vlSelf);
void Vsim_sim___ico_sequent__TOP__sim__0(Vsim_sim* vlSelf);

void Vsim___024root___eval_ico(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_ico\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vsim_VexRiscv___ico_sequent__TOP__sim__VexRiscv__0((&vlSymsp->TOP__sim__VexRiscv));
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        Vsim_sim___ico_sequent__TOP__sim__0((&vlSymsp->TOP__sim));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim___024root___dump_triggers__act(Vsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim___024root___eval_triggers__act(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_triggers__act\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.sys_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sys_clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__sys_clk__0 = vlSelfRef.sys_clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__0(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__1(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__2(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__3(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__4(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__5(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__6(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__7(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__8(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__9(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__10(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__11(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__12(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__13(Vsim_VexRiscv* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__14(Vsim_VexRiscv* vlSelf);
void Vsim_sim___nba_sequent__TOP__sim__0(Vsim_sim* vlSelf);
void Vsim_sim___nba_sequent__TOP__sim__1(Vsim_sim* vlSelf);
void Vsim_sim___nba_sequent__TOP__sim__2(Vsim_sim* vlSelf);
void Vsim_sim___nba_sequent__TOP__sim__3(Vsim_sim* vlSelf);
void Vsim_sim___nba_sequent__TOP__sim__4(Vsim_sim* vlSelf);
void Vsim___024root___nba_sequent__TOP__0(Vsim___024root* vlSelf);
void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__15(Vsim_VexRiscv* vlSelf);

void Vsim___024root___eval_nba(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___eval_nba\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__0((&vlSymsp->TOP__sim__VexRiscv));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__1((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__2((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__3((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__4((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__5((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__6((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__7((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__8((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__9((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__10((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__11((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__12((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__13((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__14((&vlSymsp->TOP__sim__VexRiscv));
        Vsim_sim___nba_sequent__TOP__sim__0((&vlSymsp->TOP__sim));
        Vsim_sim___nba_sequent__TOP__sim__1((&vlSymsp->TOP__sim));
        Vsim_sim___nba_sequent__TOP__sim__2((&vlSymsp->TOP__sim));
        Vsim_sim___nba_sequent__TOP__sim__3((&vlSymsp->TOP__sim));
        Vsim_sim___nba_sequent__TOP__sim__4((&vlSymsp->TOP__sim));
        Vsim___024root___nba_sequent__TOP__0(vlSelf);
        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__15((&vlSymsp->TOP__sim__VexRiscv));
    }
}

VL_INLINE_OPT void Vsim___024root___nba_sequent__TOP__0(Vsim___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim___024root___nba_sequent__TOP__0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.serial_sink_ready = (0x10U != (IData)(vlSymsp->TOP__sim.__PVT__uart_rx_fifo_level0));
    vlSelfRef.serial_source_data = (0xffU & (IData)(vlSymsp->TOP__sim.__PVT__storage_dat1));
    vlSelfRef.serial_source_valid = vlSymsp->TOP__sim.__PVT__uart_tx_fifo_readable;
}

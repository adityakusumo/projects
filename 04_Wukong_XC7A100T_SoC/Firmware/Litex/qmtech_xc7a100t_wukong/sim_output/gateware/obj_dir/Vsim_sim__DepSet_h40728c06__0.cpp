// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_sim.h"

VL_INLINE_OPT void Vsim_sim___nba_sequent__TOP__sim__4(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___nba_sequent__TOP__sim__4\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdfgExtracted_he0b0452a__0 = (IData)(
                                                     (0x606U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b6a76a__0 = (IData)(
                                                     (0x607U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__PVT__uart_tx_fifo_do_read = ((0U != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0)) 
                                             & (IData)(vlSelfRef.__PVT__uart_tx_fifo_syncfifo_re));
    vlSelfRef.__PVT__uart_status_status = vlSelfRef.__PVT__uart_pending_status;
    vlSelfRef.__PVT__uart_rx_fifo_do_read = ((0U != (IData)(vlSelfRef.__PVT__uart_rx_fifo_level0)) 
                                             & (IData)(vlSelfRef.__PVT__uart_rx_fifo_syncfifo_re));
    vlSelfRef.__PVT__timer_value = vlSelfRef.__Vdly__timer_value;
    vlSelfRef.__PVT__interface1_dat_w = ((IData)(vlSelfRef.__PVT__state)
                                          ? 0U : vlSelfRef.__PVT__self1);
    vlSelfRef.__PVT__csr_bankarray_csrbank0_reset0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h98c9e6a1__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank0_reset0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h98c9e6a1__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank0_scratch0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h9ba6cb1b__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank0_scratch0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h9ba6cb1b__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank0_bus_errors_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h98c9c5c3__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank0_bus_errors_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h98c9c5c3__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_load0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ebcf5a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_load0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ebcf5a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_reload0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80d82d54__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_reload0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80d82d54__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_en0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ed6f3c__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_en0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ed6f3c__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_update_value0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80f68a32__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_update_value0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80f68a32__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_value_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80d83d63__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_value_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80d83d63__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_status_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ecb548__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_status_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ecb548__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_pending_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ed2fb2__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_pending_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ed2fb2__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_enable0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ecd666__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_enable0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_h80ecd666__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__uart_rxtx_re = ((IData)(vlSelfRef.__VdfgExtracted_he0b5a416__0) 
                                     & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__uart_rxtx_we = ((IData)(vlSelfRef.__VdfgExtracted_he0b5a416__0) 
                                     & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txfull_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0a8c030__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txfull_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0a8c030__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxempty_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6052c__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxempty_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6052c__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_status_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0af5e4a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_status_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0af5e4a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_pending_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0a8cdff__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_pending_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0a8cdff__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_enable0_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6c790__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_enable0_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6c790__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txempty_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b0452a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txempty_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b0452a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxfull_re 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6a76a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_we));
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxfull_we 
        = ((IData)(vlSelfRef.__VdfgExtracted_he0b6a76a__0) 
           & (IData)(vlSelfRef.__PVT__interface1_re));
    vlSelfRef.__PVT__int_rst = 0U;
}

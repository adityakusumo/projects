// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_sim.h"

VL_ATTR_COLD void Vsim_sim___eval_static__TOP__sim(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___eval_static__TOP__sim\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bus_errors = 0U;
    vlSelfRef.__PVT__bus_errors_re = 0U;
    vlSelfRef.__PVT__count = 0xf4240U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_bus_errors_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_bus_errors_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_reset0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_reset0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_scratch0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank0_scratch0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_en0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_en0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_enable0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_enable0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_pending_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_pending_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_status_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_ev_status_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_load0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_load0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_reload0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_reload0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_update_value0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_update_value0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_value_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank1_value_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_enable0_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_enable0_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_pending_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_pending_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_status_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_ev_status_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxempty_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxempty_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxfull_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_rxfull_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txempty_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txempty_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txfull_re = 0U;
    vlSelfRef.__PVT__csr_bankarray_csrbank2_txfull_we = 0U;
    vlSelfRef.__PVT__csr_bankarray_interface0_bank_bus_dat_r = 0U;
    vlSelfRef.__PVT__csr_bankarray_interface1_bank_bus_dat_r = 0U;
    vlSelfRef.__PVT__csr_bankarray_interface2_bank_bus_dat_r = 0U;
    vlSelfRef.__PVT__csr_bankarray_sel_r = 0U;
    vlSelfRef.__PVT__csr_bankarray_sram_bus_dat_r = 0U;
    vlSelfRef.__PVT__error = 0U;
    vlSelfRef.__PVT__grant = 0U;
    vlSelfRef.__PVT__int_rst = 1U;
    vlSelfRef.__PVT__interface0_ack = 0U;
    vlSelfRef.__PVT__interface0_dat_r = 0U;
    vlSelfRef.__PVT__interface1_adr = 0U;
    vlSelfRef.__PVT__interface1_dat_w = 0U;
    vlSelfRef.__PVT__interface1_re = 0U;
    vlSelfRef.__PVT__interface1_we = 0U;
    vlSelfRef.__PVT__interrupt = 0U;
    vlSelfRef.__PVT__master = 0U;
    vlSelfRef.__PVT__next_state = 0U;
    vlSelfRef.__PVT__ram_bus_ram_bus_ack = 0U;
    vlSelfRef.__PVT__ram_we = 0U;
    vlSelfRef.__PVT__reset_re = 0U;
    vlSelfRef.__PVT__reset_storage = 0U;
    vlSelfRef.__PVT__scratch_re = 0U;
    vlSelfRef.__PVT__scratch_storage = 0x12345678U;
    vlSelfRef.__PVT__self0 = 0U;
    vlSelfRef.__PVT__self1 = 0U;
    vlSelfRef.__PVT__self2 = 0U;
    vlSelfRef.__PVT__self3 = 0U;
    vlSelfRef.__PVT__self4 = 0U;
    vlSelfRef.__PVT__self5 = 0U;
    vlSelfRef.__PVT__self6 = 0U;
    vlSelfRef.__PVT__self7 = 0U;
    vlSelfRef.__PVT__shared_ack = 0U;
    vlSelfRef.__PVT__shared_dat_r = 0U;
    vlSelfRef.__PVT__simsoc_ram_bus_ack = 0U;
    vlSelfRef.__PVT__slaves = 0U;
    vlSelfRef.__PVT__soc_rst = 0U;
    vlSelfRef.__PVT__state = 0U;
    vlSelfRef.__PVT__timer_en_re = 0U;
    vlSelfRef.__PVT__timer_en_storage = 0U;
    vlSelfRef.__PVT__timer_enable_re = 0U;
    vlSelfRef.__PVT__timer_enable_storage = 0U;
    vlSelfRef.__PVT__timer_load_re = 0U;
    vlSelfRef.__PVT__timer_load_storage = 0U;
    vlSelfRef.__PVT__timer_pending_r = 0U;
    vlSelfRef.__PVT__timer_pending_re = 0U;
    vlSelfRef.__PVT__timer_reload_re = 0U;
    vlSelfRef.__PVT__timer_reload_storage = 0U;
    vlSelfRef.__PVT__timer_status_re = 0U;
    vlSelfRef.__PVT__timer_update_value_re = 0U;
    vlSelfRef.__PVT__timer_update_value_storage = 0U;
    vlSelfRef.__PVT__timer_value = 0U;
    vlSelfRef.__PVT__timer_value_re = 0U;
    vlSelfRef.__PVT__timer_value_status = 0U;
    vlSelfRef.__PVT__timer_zero_clear = 0U;
    vlSelfRef.__PVT__timer_zero_pending = 0U;
    vlSelfRef.__PVT__timer_zero_trigger_d = 0U;
    vlSelfRef.__PVT__uart_enable_re = 0U;
    vlSelfRef.__PVT__uart_enable_storage = 0U;
    vlSelfRef.__PVT__uart_pending_r = 0U;
    vlSelfRef.__PVT__uart_pending_re = 0U;
    vlSelfRef.__PVT__uart_pending_status = 0U;
    vlSelfRef.__PVT__uart_rx_clear = 0U;
    vlSelfRef.__PVT__uart_rx_fifo_consume = 0U;
    vlSelfRef.__PVT__uart_rx_fifo_level0 = 0U;
    vlSelfRef.__PVT__uart_rx_fifo_produce = 0U;
    vlSelfRef.__PVT__uart_rx_fifo_readable = 0U;
    vlSelfRef.__PVT__uart_rx_fifo_wrport_adr = 0U;
    vlSelfRef.__PVT__uart_rxempty_re = 0U;
    vlSelfRef.__PVT__uart_rxfull_re = 0U;
    vlSelfRef.__PVT__uart_rxtx_re = 0U;
    vlSelfRef.__PVT__uart_rxtx_we = 0U;
    vlSelfRef.__PVT__uart_status_re = 0U;
    vlSelfRef.__PVT__uart_status_status = 0U;
    vlSelfRef.__PVT__uart_tx_clear = 0U;
    vlSelfRef.__PVT__uart_tx_fifo_consume = 0U;
    vlSelfRef.__PVT__uart_tx_fifo_level0 = 0U;
    vlSelfRef.__PVT__uart_tx_fifo_produce = 0U;
    vlSelfRef.__PVT__uart_tx_fifo_readable = 0U;
    vlSelfRef.__PVT__uart_tx_fifo_wrport_adr = 0U;
    vlSelfRef.__PVT__uart_txempty_re = 0U;
    vlSelfRef.__PVT__uart_txfull_re = 0U;
}

VL_ATTR_COLD void Vsim_sim___eval_initial__TOP__sim(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___eval_initial__TOP__sim\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    __Vtemp_1[0U] = 0x696e6974U;
    __Vtemp_1[1U] = 0x726f6d2eU;
    __Vtemp_1[2U] = 0x73696d5fU;
    VL_READMEM_N(true, 32, 5890, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(vlSelfRef.__PVT__rom), 0, ~0ULL);
    __Vtemp_2[0U] = 0x696e6974U;
    __Vtemp_2[1U] = 0x72616d2eU;
    __Vtemp_2[2U] = 0x696d5f73U;
    __Vtemp_2[3U] = 0x73U;
    VL_READMEM_N(true, 32, 2048, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_2)
                 ,  &(vlSelfRef.__PVT__sram), 0, ~0ULL);
    __Vtemp_3[0U] = 0x696e6974U;
    __Vtemp_3[1U] = 0x6d656d2eU;
    __Vtemp_3[2U] = 0x73696d5fU;
    VL_READMEM_N(true, 8, 37, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_3)
                 ,  &(vlSelfRef.__PVT__mem), 0, ~0ULL);
    vlSelfRef.__PVT__self7 = 0U;
}

VL_ATTR_COLD void Vsim_sim___stl_sequent__TOP__sim__2(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___stl_sequent__TOP__sim__2\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vsim_sim___ctor_var_reset(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___ctor_var_reset\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->serial_sink_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9573462725403686387ull);
    vlSelf->serial_sink_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3758950120267853273ull);
    vlSelf->serial_sink_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13511602996822676087ull);
    vlSelf->serial_source_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17344215306608104219ull);
    vlSelf->serial_source_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9973345444914751179ull);
    vlSelf->serial_source_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18327467128597415915ull);
    vlSelf->__PVT__sim_trace = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16134794833742535666ull);
    vlSelf->sys_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7302336598091101382ull);
    vlSelf->__PVT__bus_errors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11658013399236785948ull);
    vlSelf->__PVT__bus_errors_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14313703195198197452ull);
    vlSelf->__PVT__count = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 10730142128712957955ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_bus_errors_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11335718356911753824ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_bus_errors_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8839073545395430274ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_reset0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10681778925953898707ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_reset0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13297514058866632984ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_scratch0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14396101537922375852ull);
    vlSelf->__PVT__csr_bankarray_csrbank0_scratch0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10332613363006377934ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_en0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1530711918530823419ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_en0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 315581724930436183ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_enable0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1825299715968494322ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_enable0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14756624982402918373ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_pending_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7453549555430145729ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_pending_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13902790855660295725ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5362528139577108335ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_ev_status_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12462789350260744661ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_load0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6807907696559839030ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_load0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5763284036044113685ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_reload0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7520457465250392731ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_reload0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17082238869741113019ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_update_value0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15363674585163690022ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_update_value0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3967084589542210544ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_value_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12537800412605594039ull);
    vlSelf->__PVT__csr_bankarray_csrbank1_value_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2049392042414575688ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_enable0_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13571978344985989053ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_enable0_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8871372851401504415ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_pending_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13838109736800436997ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_pending_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14984736740121514356ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15332006806948775049ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_ev_status_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16719384476970710220ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_rxempty_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11996405504455486979ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_rxempty_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3868272252271329390ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_rxfull_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11085771212997536444ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_rxfull_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1931500921890777548ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_txempty_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11284193288322827577ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_txempty_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10098602667163079230ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_txfull_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17660123150983391561ull);
    vlSelf->__PVT__csr_bankarray_csrbank2_txfull_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13640216977795884212ull);
    vlSelf->__PVT__csr_bankarray_interface0_bank_bus_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9011785849024005270ull);
    vlSelf->__PVT__csr_bankarray_interface1_bank_bus_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7695537463142560592ull);
    vlSelf->__PVT__csr_bankarray_interface2_bank_bus_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3595323792986951051ull);
    vlSelf->__PVT__csr_bankarray_sel_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9950559241586199619ull);
    vlSelf->__PVT__csr_bankarray_sram_bus_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4921087481268021405ull);
    vlSelf->__PVT__error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10895628271336369153ull);
    vlSelf->__PVT__grant = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 741988092961692266ull);
    vlSelf->__PVT__int_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1524821605481500626ull);
    vlSelf->__PVT__interface0_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13931060324989221549ull);
    vlSelf->__PVT__interface0_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9296242788412289964ull);
    vlSelf->__PVT__interface1_adr = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 17004769154713734657ull);
    vlSelf->__PVT__interface1_dat_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6662210566234371197ull);
    vlSelf->__PVT__interface1_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5979792407759442602ull);
    vlSelf->__PVT__interface1_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6151596964738358452ull);
    vlSelf->__PVT__interrupt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8310372361048121531ull);
    vlSelf->__PVT__master = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15396453058866127591ull);
    vlSelf->__PVT__next_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10383377256973303270ull);
    vlSelf->__PVT__ram_bus_ram_bus_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6132150569281892109ull);
    vlSelf->__PVT__ram_bus_ram_bus_cyc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11619767034955778958ull);
    vlSelf->__PVT__ram_we = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2261664746123919997ull);
    vlSelf->__PVT__request = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16104405464408049176ull);
    vlSelf->__PVT__reset_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8185501355545483988ull);
    vlSelf->__PVT__reset_storage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16143869979142916394ull);
    vlSelf->__PVT__scratch_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8095583920831590815ull);
    vlSelf->__PVT__scratch_storage = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5907622826217665633ull);
    vlSelf->__PVT__self0 = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 160531701696309372ull);
    vlSelf->__PVT__self1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6836421141350476675ull);
    vlSelf->__PVT__self2 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7079595618278098319ull);
    vlSelf->__PVT__self3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3190518141735665833ull);
    vlSelf->__PVT__self4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15642619645884852156ull);
    vlSelf->__PVT__self5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17456990061704040268ull);
    vlSelf->__PVT__self6 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18253935241648670873ull);
    vlSelf->__PVT__self7 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15435645624223470239ull);
    vlSelf->__PVT__shared_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13574176661712144159ull);
    vlSelf->__PVT__shared_dat_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3277654642534973380ull);
    vlSelf->__PVT__simsoc_ram_bus_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11984335742428282375ull);
    vlSelf->__PVT__slaves = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4812097366326612225ull);
    vlSelf->__PVT__soc_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15921584844231664847ull);
    vlSelf->__PVT__state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9404372463396948974ull);
    vlSelf->__PVT__timer_en_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4527946263442320059ull);
    vlSelf->__PVT__timer_en_storage = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16877833863563935872ull);
    vlSelf->__PVT__timer_enable_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11598062483447473202ull);
    vlSelf->__PVT__timer_enable_storage = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5202178602246932804ull);
    vlSelf->__PVT__timer_load_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16583445993310111124ull);
    vlSelf->__PVT__timer_load_storage = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3531958920460039380ull);
    vlSelf->__PVT__timer_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15732747086647271424ull);
    vlSelf->__PVT__timer_pending_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9914499374795090872ull);
    vlSelf->__PVT__timer_reload_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6721316683757374316ull);
    vlSelf->__PVT__timer_reload_storage = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10548718177569095382ull);
    vlSelf->__PVT__timer_status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10989344889607517601ull);
    vlSelf->__PVT__timer_update_value_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4285153574822696015ull);
    vlSelf->__PVT__timer_update_value_storage = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8889867180404138285ull);
    vlSelf->__PVT__timer_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3535834608967038298ull);
    vlSelf->__PVT__timer_value_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18284033301401148786ull);
    vlSelf->__PVT__timer_value_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2292847198616187345ull);
    vlSelf->__PVT__timer_zero_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5544185636907293628ull);
    vlSelf->__PVT__timer_zero_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14120174115943517879ull);
    vlSelf->__PVT__timer_zero_trigger_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14749171490241593305ull);
    vlSelf->__PVT__uart_enable_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4646218964829957559ull);
    vlSelf->__PVT__uart_enable_storage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4232233257389581945ull);
    vlSelf->__PVT__uart_pending_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5558489971598557676ull);
    vlSelf->__PVT__uart_pending_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16455644892796732992ull);
    vlSelf->__PVT__uart_pending_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12671682272249020788ull);
    vlSelf->__PVT__uart_rx_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14121199456271791468ull);
    vlSelf->__PVT__uart_rx_fifo_consume = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4940739508063652912ull);
    vlSelf->__PVT__uart_rx_fifo_do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17707738422806439108ull);
    vlSelf->__PVT__uart_rx_fifo_level0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5050668381270347378ull);
    vlSelf->__PVT__uart_rx_fifo_produce = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8742426296094598707ull);
    vlSelf->__PVT__uart_rx_fifo_readable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16122020553516116422ull);
    vlSelf->__PVT__uart_rx_fifo_syncfifo_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11962787407090652384ull);
    vlSelf->__PVT__uart_rx_fifo_wrport_adr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12499115221282638740ull);
    vlSelf->__PVT__uart_rxempty_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10480310709522956770ull);
    vlSelf->__PVT__uart_rxfull_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5775230339129299236ull);
    vlSelf->__PVT__uart_rxtx_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6669038635651185508ull);
    vlSelf->__PVT__uart_rxtx_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10911184363342750219ull);
    vlSelf->__PVT__uart_status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 389304635013335417ull);
    vlSelf->__PVT__uart_status_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11413870778686456058ull);
    vlSelf->__PVT__uart_tx0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1140734399998505682ull);
    vlSelf->__PVT__uart_tx_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7790238094678614836ull);
    vlSelf->__PVT__uart_tx_fifo_consume = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8018260780877029539ull);
    vlSelf->__PVT__uart_tx_fifo_do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9015302498883743745ull);
    vlSelf->__PVT__uart_tx_fifo_level0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9109585756824715326ull);
    vlSelf->__PVT__uart_tx_fifo_produce = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12095880149381732282ull);
    vlSelf->__PVT__uart_tx_fifo_readable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14094679167452690649ull);
    vlSelf->__PVT__uart_tx_fifo_syncfifo_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6458036053111026453ull);
    vlSelf->__PVT__uart_tx_fifo_wrport_adr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12316488999893118548ull);
    vlSelf->__PVT__uart_txempty_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17217519448754099108ull);
    vlSelf->__PVT__uart_txfull_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2927725571395305484ull);
    for (int __Vi0 = 0; __Vi0 < 5890; ++__Vi0) {
        vlSelf->__PVT__rom[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1318411374457351833ull);
    }
    vlSelf->__PVT__rom_dat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18261490102182092130ull);
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->__PVT__sram[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7876200907025440328ull);
    }
    vlSelf->__PVT__sram_adr0 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 7631859601901898596ull);
    for (int __Vi0 = 0; __Vi0 < 37; ++__Vi0) {
        vlSelf->__PVT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4032165174000709208ull);
    }
    vlSelf->__PVT__mem_adr0 = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13581139293503917481ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__storage[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 6967744052328620840ull);
    }
    vlSelf->__PVT__storage_dat0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 11008759732800391247ull);
    vlSelf->__PVT__storage_dat1 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 2691829541705940851ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__storage_1[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 15654753350756652249ull);
    }
    vlSelf->__PVT__storage_1_dat0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 18238170054545187141ull);
    vlSelf->__PVT__storage_1_dat1 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 8149492790143177989ull);
    vlSelf->__PVT__mem_write_block__DOT__we_index = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4579764801529735646ull);
    vlSelf->__VdfgExtracted_hc7e76799__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10521744890500380765ull);
    vlSelf->__VdfgExtracted_h98c9e6a1__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8219908605545146864ull);
    vlSelf->__VdfgExtracted_h9ba6cb1b__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 305674723079910590ull);
    vlSelf->__VdfgExtracted_h98c9c5c3__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12113454202956359760ull);
    vlSelf->__VdfgExtracted_h80ebcf5a__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3426871570851463725ull);
    vlSelf->__VdfgExtracted_h80d82d54__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9689798362247899818ull);
    vlSelf->__VdfgExtracted_h80ed6f3c__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5701406659072619851ull);
    vlSelf->__VdfgExtracted_h80f68a32__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12524844564381488504ull);
    vlSelf->__VdfgExtracted_h80d83d63__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6544383375997584114ull);
    vlSelf->__VdfgExtracted_h80ecb548__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10227260177868957298ull);
    vlSelf->__VdfgExtracted_h80ed2fb2__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8379547500978977215ull);
    vlSelf->__VdfgExtracted_h80ecd666__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4700803703009709872ull);
    vlSelf->__VdfgExtracted_he0b5a416__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8883364461719305670ull);
    vlSelf->__VdfgExtracted_he0a8c030__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16059105580336231148ull);
    vlSelf->__VdfgExtracted_he0b6052c__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10877779338415627225ull);
    vlSelf->__VdfgExtracted_he0af5e4a__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17579806969520927621ull);
    vlSelf->__VdfgExtracted_he0a8cdff__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4137297441804853161ull);
    vlSelf->__VdfgExtracted_he0b6c790__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18014568212231857045ull);
    vlSelf->__VdfgExtracted_he0b0452a__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4236876527085791043ull);
    vlSelf->__VdfgExtracted_he0b6a76a__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10813776816185637426ull);
    vlSelf->__VdfgRegularize_hfb9f42e9_0_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17818426622857700337ull);
    vlSelf->__Vdly__timer_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4460975891945325352ull);
    vlSelf->__Vdly__uart_rx_fifo_level0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3629410401613015844ull);
    vlSelf->__Vdly__uart_rx_fifo_consume = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15057078428291787045ull);
    vlSelf->__Vdly__bus_errors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 489743327918157157ull);
    vlSelf->__Vdly__ram_bus_ram_bus_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4380940108278286123ull);
    vlSelf->__Vdly__uart_tx_fifo_level0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 276452681982279934ull);
    vlSelf->__Vdly__simsoc_ram_bus_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4300201494381946472ull);
    vlSelf->__Vdly__uart_tx_fifo_consume = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12576656278767473174ull);
    vlSelf->__VdlyVal__sram__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12462076991704969158ull);
    vlSelf->__VdlyDim0__sram__v0 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 1060485925791794502ull);
    vlSelf->__VdlySet__sram__v0 = 0;
    vlSelf->__VdlyVal__sram__v1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17867694934649883138ull);
    vlSelf->__VdlyDim0__sram__v1 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 9178277887806312286ull);
    vlSelf->__VdlySet__sram__v1 = 0;
    vlSelf->__VdlyVal__sram__v2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3391995813250763201ull);
    vlSelf->__VdlyDim0__sram__v2 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 8873562216177745348ull);
    vlSelf->__VdlySet__sram__v2 = 0;
    vlSelf->__VdlyVal__sram__v3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1211098439402713659ull);
    vlSelf->__VdlyDim0__sram__v3 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 10294794375091538106ull);
    vlSelf->__VdlySet__sram__v3 = 0;
    vlSelf->__VdlyVal__storage__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 14177728667420286272ull);
    vlSelf->__VdlyDim0__storage__v0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3222848339908150112ull);
    vlSelf->__VdlySet__storage__v0 = 0;
    vlSelf->__VdlyVal__storage_1__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9704752058595617135ull);
    vlSelf->__VdlyDim0__storage_1__v0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6690866465903381960ull);
    vlSelf->__VdlySet__storage_1__v0 = 0;
}

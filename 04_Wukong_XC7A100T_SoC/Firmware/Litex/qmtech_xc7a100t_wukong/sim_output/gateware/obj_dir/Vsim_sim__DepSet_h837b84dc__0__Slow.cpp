// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim__Syms.h"
#include "Vsim_sim.h"

VL_ATTR_COLD void Vsim_sim___stl_sequent__TOP__sim__0(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___stl_sequent__TOP__sim__0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__uart_tx_fifo_wrport_adr = vlSelfRef.__PVT__uart_tx_fifo_produce;
    vlSelfRef.__PVT__uart_rx_fifo_wrport_adr = vlSelfRef.__PVT__uart_rx_fifo_produce;
    vlSelfRef.__PVT__uart_tx0 = (0x10U != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0));
    vlSelfRef.__PVT__interface0_ack = vlSelfRef.__PVT__state;
    vlSelfRef.__PVT__uart_tx_clear = ((IData)(vlSelfRef.__PVT__uart_pending_re) 
                                      & (IData)(vlSelfRef.__PVT__uart_pending_r));
    vlSelfRef.__PVT__timer_zero_clear = ((IData)(vlSelfRef.__PVT__timer_pending_r) 
                                         & (IData)(vlSelfRef.__PVT__timer_pending_re));
    vlSelfRef.__PVT__interrupt = ((((IData)(vlSelfRef.__PVT__timer_enable_storage) 
                                    & (IData)(vlSelfRef.__PVT__timer_zero_pending)) 
                                   << 1U) | (((0x10U 
                                               != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0)) 
                                              & (IData)(vlSelfRef.__PVT__uart_enable_storage)) 
                                             | ((IData)(vlSelfRef.__PVT__uart_rx_fifo_readable) 
                                                & ((IData)(vlSelfRef.__PVT__uart_enable_storage) 
                                                   >> 1U))));
    vlSelfRef.__PVT__uart_pending_status = (((IData)(vlSelfRef.__PVT__uart_rx_fifo_readable) 
                                             << 1U) 
                                            | (0x10U 
                                               != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0)));
    if (vlSelfRef.__PVT__grant) {
        vlSelfRef.__PVT__self1 = vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_data;
        vlSelfRef.__PVT__self2 = ((IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_wr)
                                   ? (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_mask)
                                   : 0xfU);
        vlSelfRef.__PVT__self0 = (0x3fffffffU & (((5U 
                                                   == (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size))
                                                   ? 
                                                  ((0xffffffe0U 
                                                    & vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_address) 
                                                   | ((IData)(vlSymsp->TOP__sim__VexRiscv.__PVT___zz_dBusWishbone_ADR) 
                                                      << 2U))
                                                   : 
                                                  (0xfffffffcU 
                                                   & vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_address)) 
                                                 >> 2U));
    } else {
        vlSelfRef.__PVT__self1 = 0U;
        vlSelfRef.__PVT__self2 = 0xfU;
        vlSelfRef.__PVT__self0 = (0x3fffffffU & ((0x3ffffff8U 
                                                  & (vlSymsp->TOP__sim__VexRiscv.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_address 
                                                     >> 2U)) 
                                                 | (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT___zz_iBusWishbone_ADR)));
    }
    vlSelfRef.__PVT__uart_tx_fifo_syncfifo_re = ((0U 
                                                  != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0)) 
                                                 & ((~ (IData)(vlSelfRef.__PVT__uart_tx_fifo_readable)) 
                                                    | (IData)(vlSymsp->TOP.serial_source_ready)));
    vlSelfRef.__PVT__soc_rst = ((IData)(vlSelfRef.__PVT__reset_re) 
                                & (IData)(vlSelfRef.__PVT__reset_storage));
    vlSelfRef.__PVT__uart_rx_clear = ((IData)(vlSelfRef.__PVT__uart_pending_re) 
                                      & ((IData)(vlSelfRef.__PVT__uart_pending_r) 
                                         >> 1U));
    vlSelfRef.__PVT__csr_bankarray_sram_bus_dat_r = 
        ((IData)(vlSelfRef.__PVT__csr_bankarray_sel_r)
          ? ((0x24U >= (IData)(vlSelfRef.__PVT__mem_adr0))
              ? vlSelfRef.__PVT__mem[vlSelfRef.__PVT__mem_adr0]
              : 0U) : 0U);
    vlSelfRef.__VdfgRegularize_hfb9f42e9_0_15 = ((IData)(vlSelfRef.__PVT__simsoc_ram_bus_ack) 
                                                 | ((IData)(vlSelfRef.__PVT__ram_bus_ram_bus_ack) 
                                                    | (IData)(vlSelfRef.__PVT__state)));
    vlSelfRef.__PVT__error = (0U == vlSelfRef.__PVT__count);
    vlSelfRef.__PVT__self5 = ((IData)(vlSelfRef.__PVT__grant) 
                              & (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_wr));
    vlSelfRef.__PVT__uart_status_status = vlSelfRef.__PVT__uart_pending_status;
    if (vlSelfRef.__PVT__state) {
        vlSelfRef.__PVT__interface1_dat_w = 0U;
        vlSelfRef.__PVT__interface0_dat_r = (vlSelfRef.__PVT__csr_bankarray_interface0_bank_bus_dat_r 
                                             | (vlSelfRef.__PVT__csr_bankarray_interface1_bank_bus_dat_r 
                                                | (vlSelfRef.__PVT__csr_bankarray_interface2_bank_bus_dat_r 
                                                   | vlSelfRef.__PVT__csr_bankarray_sram_bus_dat_r)));
    } else {
        vlSelfRef.__PVT__interface1_dat_w = vlSelfRef.__PVT__self1;
        vlSelfRef.__PVT__interface0_dat_r = 0U;
    }
    vlSelfRef.__PVT__uart_tx_fifo_do_read = ((0U != (IData)(vlSelfRef.__PVT__uart_tx_fifo_level0)) 
                                             & (IData)(vlSelfRef.__PVT__uart_tx_fifo_syncfifo_re));
    vlSelfRef.__PVT__uart_rx_fifo_syncfifo_re = ((0U 
                                                  != (IData)(vlSelfRef.__PVT__uart_rx_fifo_level0)) 
                                                 & ((~ (IData)(vlSelfRef.__PVT__uart_rx_fifo_readable)) 
                                                    | (IData)(vlSelfRef.__PVT__uart_rx_clear)));
    vlSelfRef.__PVT__shared_ack = ((IData)(vlSelfRef.__PVT__error) 
                                   | (IData)(vlSelfRef.__VdfgRegularize_hfb9f42e9_0_15));
    vlSelfRef.__PVT__master = (((0xf000U == (0xffffU 
                                             & (vlSelfRef.__PVT__self0 
                                                >> 0xeU))) 
                                << 2U) | (((0x8000U 
                                            == (0x7ffffU 
                                                & (vlSelfRef.__PVT__self0 
                                                   >> 0xbU))) 
                                           << 1U) | 
                                          (0U == (0x7fffU 
                                                  & (vlSelfRef.__PVT__self0 
                                                     >> 0xfU)))));
    vlSelfRef.__PVT__uart_rx_fifo_do_read = ((0U != (IData)(vlSelfRef.__PVT__uart_rx_fifo_level0)) 
                                             & (IData)(vlSelfRef.__PVT__uart_rx_fifo_syncfifo_re));
    vlSelfRef.__PVT__shared_dat_r = ((IData)(vlSelfRef.__PVT__error)
                                      ? 0xffffffffU
                                      : (((- (IData)(
                                                     (1U 
                                                      & (IData)(vlSelfRef.__PVT__slaves)))) 
                                          & vlSelfRef.__PVT__rom_dat0) 
                                         | (((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.__PVT__slaves) 
                                                            >> 1U)))) 
                                             & vlSelfRef.__PVT__sram
                                             [vlSelfRef.__PVT__sram_adr0]) 
                                            | ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelfRef.__PVT__slaves) 
                                                              >> 2U)))) 
                                               & vlSelfRef.__PVT__interface0_dat_r))));
}

VL_ATTR_COLD void Vsim_sim___stl_sequent__TOP__sim__1(Vsim_sim* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_sim___stl_sequent__TOP__sim__1\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdfgRegularize_h7bf93d5d_0_2;
    __VdfgRegularize_h7bf93d5d_0_2 = 0;
    // Body
    if (vlSelfRef.__PVT__grant) {
        vlSelfRef.__PVT__self6 = ((5U == (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size))
                                   ? ((IData)(vlSymsp->TOP__sim__VexRiscv.__PVT___zz_dBus_cmd_ready_2)
                                       ? 7U : 2U) : 0U);
        vlSelfRef.__PVT__self3 = vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid;
    } else {
        vlSelfRef.__PVT__self6 = ((7U == (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT___zz_iBusWishbone_ADR))
                                   ? 7U : 2U);
        vlSelfRef.__PVT__self3 = vlSymsp->TOP__sim__VexRiscv.__PVT__iBusWishbone_CYC;
    }
    vlSelfRef.__PVT__request = (((IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid) 
                                 << 1U) | (IData)(vlSymsp->TOP__sim__VexRiscv.__PVT__iBusWishbone_CYC));
    vlSelfRef.__PVT__self4 = vlSelfRef.__PVT__self3;
    vlSelfRef.__PVT__ram_bus_ram_bus_cyc = ((IData)(vlSelfRef.__PVT__self3) 
                                            & (0x4000000U 
                                               == (0x3ffff800U 
                                                   & vlSelfRef.__PVT__self0)));
    vlSelfRef.__VdfgExtracted_hc7e76799__0 = ((IData)(vlSelfRef.__PVT__self3) 
                                              & (0x3c000000U 
                                                 == 
                                                 (0x3fffc000U 
                                                  & vlSelfRef.__PVT__self0)));
    __VdfgRegularize_h7bf93d5d_0_2 = ((IData)(vlSelfRef.__PVT__ram_bus_ram_bus_cyc) 
                                      & ((IData)(vlSelfRef.__PVT__self3) 
                                         & (IData)(vlSelfRef.__PVT__self5)));
    if (vlSelfRef.__PVT__state) {
        vlSelfRef.__PVT__next_state = 1U;
        vlSelfRef.__PVT__next_state = 0U;
    } else {
        vlSelfRef.__PVT__next_state = 0U;
        if (vlSelfRef.__VdfgExtracted_hc7e76799__0) {
            vlSelfRef.__PVT__next_state = 1U;
        }
    }
    vlSelfRef.__PVT__interface1_re = 0U;
    vlSelfRef.__PVT__interface1_we = 0U;
    vlSelfRef.__PVT__interface1_adr = 0U;
    if ((1U & (~ (IData)(vlSelfRef.__PVT__state)))) {
        if (vlSelfRef.__VdfgExtracted_hc7e76799__0) {
            vlSelfRef.__PVT__interface1_re = ((~ (IData)(vlSelfRef.__PVT__self5)) 
                                              & (0U 
                                                 != (IData)(vlSelfRef.__PVT__self2)));
            vlSelfRef.__PVT__interface1_we = ((IData)(vlSelfRef.__PVT__self5) 
                                              & (0U 
                                                 != (IData)(vlSelfRef.__PVT__self2)));
            vlSelfRef.__PVT__interface1_adr = (0x3fffU 
                                               & vlSelfRef.__PVT__self0);
        }
    }
    vlSelfRef.__PVT__ram_we = ((0xfffffff8U & (((IData)(__VdfgRegularize_h7bf93d5d_0_2) 
                                                << 3U) 
                                               & (IData)(vlSelfRef.__PVT__self2))) 
                               | ((0xfffffffcU & (((IData)(__VdfgRegularize_h7bf93d5d_0_2) 
                                                   << 2U) 
                                                  & (IData)(vlSelfRef.__PVT__self2))) 
                                  | (3U & ((- (IData)((IData)(__VdfgRegularize_h7bf93d5d_0_2))) 
                                           & (IData)(vlSelfRef.__PVT__self2)))));
    vlSelfRef.__VdfgExtracted_h98c9e6a1__0 = (IData)(
                                                     (0U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h9ba6cb1b__0 = (IData)(
                                                     (1U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h98c9c5c3__0 = (IData)(
                                                     (2U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80ebcf5a__0 = (IData)(
                                                     (0x400U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80d82d54__0 = (IData)(
                                                     (0x401U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80ed6f3c__0 = (IData)(
                                                     (0x402U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80f68a32__0 = (IData)(
                                                     (0x403U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80d83d63__0 = (IData)(
                                                     (0x404U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80ecb548__0 = (IData)(
                                                     (0x405U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80ed2fb2__0 = (IData)(
                                                     (0x406U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_h80ecd666__0 = (IData)(
                                                     (0x407U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b5a416__0 = (IData)(
                                                     (0x600U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0a8c030__0 = (IData)(
                                                     (0x601U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b6052c__0 = (IData)(
                                                     (0x602U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0af5e4a__0 = (IData)(
                                                     (0x603U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0a8cdff__0 = (IData)(
                                                     (0x604U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b6c790__0 = (IData)(
                                                     (0x605U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b0452a__0 = (IData)(
                                                     (0x606U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
    vlSelfRef.__VdfgExtracted_he0b6a76a__0 = (IData)(
                                                     (0x607U 
                                                      == (IData)(vlSelfRef.__PVT__interface1_adr)));
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
}

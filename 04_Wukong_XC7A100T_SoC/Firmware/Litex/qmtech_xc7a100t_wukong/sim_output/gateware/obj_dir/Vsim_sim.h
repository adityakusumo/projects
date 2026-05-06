// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim.h for the primary calling header

#ifndef VERILATED_VSIM_SIM_H_
#define VERILATED_VSIM_SIM_H_  // guard

#include "verilated.h"
class Vsim_VexRiscv;


class Vsim__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim_sim final : public VerilatedModule {
  public:
    // CELLS
    Vsim_VexRiscv* VexRiscv;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(serial_sink_data,7,0);
        VL_OUT8(serial_sink_ready,0,0);
        VL_IN8(serial_sink_valid,0,0);
        VL_OUT8(serial_source_data,7,0);
        VL_IN8(serial_source_ready,0,0);
        VL_OUT8(serial_source_valid,0,0);
        VL_OUT8(__PVT__sim_trace,0,0);
        VL_IN8(sys_clk,0,0);
        CData/*0:0*/ __PVT__bus_errors_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_bus_errors_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_bus_errors_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_reset0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_reset0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_scratch0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank0_scratch0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_en0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_en0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_enable0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_enable0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_pending_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_pending_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_status_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_ev_status_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_load0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_load0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_reload0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_reload0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_update_value0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_update_value0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_value_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank1_value_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_enable0_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_enable0_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_pending_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_pending_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_status_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_ev_status_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_rxempty_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_rxempty_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_rxfull_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_rxfull_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_txempty_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_txempty_we;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_txfull_re;
        CData/*0:0*/ __PVT__csr_bankarray_csrbank2_txfull_we;
        CData/*0:0*/ __PVT__csr_bankarray_sel_r;
        CData/*0:0*/ __PVT__error;
        CData/*0:0*/ __PVT__grant;
        CData/*0:0*/ __PVT__int_rst;
        CData/*0:0*/ __PVT__interface0_ack;
        CData/*0:0*/ __PVT__interface1_re;
        CData/*0:0*/ __PVT__interface1_we;
        CData/*2:0*/ __PVT__master;
        CData/*0:0*/ __PVT__next_state;
        CData/*0:0*/ __PVT__ram_bus_ram_bus_ack;
        CData/*0:0*/ __PVT__ram_bus_ram_bus_cyc;
        CData/*3:0*/ __PVT__ram_we;
        CData/*1:0*/ __PVT__request;
        CData/*0:0*/ __PVT__reset_re;
        CData/*1:0*/ __PVT__reset_storage;
        CData/*0:0*/ __PVT__scratch_re;
        CData/*3:0*/ __PVT__self2;
        CData/*0:0*/ __PVT__self3;
        CData/*0:0*/ __PVT__self4;
    };
    struct {
        CData/*0:0*/ __PVT__self5;
        CData/*2:0*/ __PVT__self6;
        CData/*1:0*/ __PVT__self7;
        CData/*0:0*/ __PVT__shared_ack;
        CData/*0:0*/ __PVT__simsoc_ram_bus_ack;
        CData/*2:0*/ __PVT__slaves;
        CData/*0:0*/ __PVT__soc_rst;
        CData/*0:0*/ __PVT__state;
        CData/*0:0*/ __PVT__timer_en_re;
        CData/*0:0*/ __PVT__timer_en_storage;
        CData/*0:0*/ __PVT__timer_enable_re;
        CData/*0:0*/ __PVT__timer_enable_storage;
        CData/*0:0*/ __PVT__timer_load_re;
        CData/*0:0*/ __PVT__timer_pending_r;
        CData/*0:0*/ __PVT__timer_pending_re;
        CData/*0:0*/ __PVT__timer_reload_re;
        CData/*0:0*/ __PVT__timer_status_re;
        CData/*0:0*/ __PVT__timer_update_value_re;
        CData/*0:0*/ __PVT__timer_update_value_storage;
        CData/*0:0*/ __PVT__timer_value_re;
        CData/*0:0*/ __PVT__timer_zero_clear;
        CData/*0:0*/ __PVT__timer_zero_pending;
        CData/*0:0*/ __PVT__timer_zero_trigger_d;
        CData/*0:0*/ __PVT__uart_enable_re;
        CData/*1:0*/ __PVT__uart_enable_storage;
        CData/*1:0*/ __PVT__uart_pending_r;
        CData/*0:0*/ __PVT__uart_pending_re;
        CData/*1:0*/ __PVT__uart_pending_status;
        CData/*0:0*/ __PVT__uart_rx_clear;
        CData/*3:0*/ __PVT__uart_rx_fifo_consume;
        CData/*0:0*/ __PVT__uart_rx_fifo_do_read;
        CData/*4:0*/ __PVT__uart_rx_fifo_level0;
        CData/*3:0*/ __PVT__uart_rx_fifo_produce;
        CData/*0:0*/ __PVT__uart_rx_fifo_readable;
        CData/*0:0*/ __PVT__uart_rx_fifo_syncfifo_re;
        CData/*3:0*/ __PVT__uart_rx_fifo_wrport_adr;
        CData/*0:0*/ __PVT__uart_rxempty_re;
        CData/*0:0*/ __PVT__uart_rxfull_re;
        CData/*0:0*/ __PVT__uart_rxtx_re;
        CData/*0:0*/ __PVT__uart_rxtx_we;
        CData/*0:0*/ __PVT__uart_status_re;
        CData/*1:0*/ __PVT__uart_status_status;
        CData/*0:0*/ __PVT__uart_tx0;
        CData/*0:0*/ __PVT__uart_tx_clear;
        CData/*3:0*/ __PVT__uart_tx_fifo_consume;
        CData/*0:0*/ __PVT__uart_tx_fifo_do_read;
        CData/*4:0*/ __PVT__uart_tx_fifo_level0;
        CData/*3:0*/ __PVT__uart_tx_fifo_produce;
        CData/*0:0*/ __PVT__uart_tx_fifo_readable;
        CData/*0:0*/ __PVT__uart_tx_fifo_syncfifo_re;
        CData/*3:0*/ __PVT__uart_tx_fifo_wrport_adr;
        CData/*0:0*/ __PVT__uart_txempty_re;
        CData/*0:0*/ __PVT__uart_txfull_re;
        CData/*5:0*/ __PVT__mem_adr0;
        CData/*0:0*/ __VdfgExtracted_hc7e76799__0;
        CData/*0:0*/ __VdfgExtracted_h98c9e6a1__0;
        CData/*0:0*/ __VdfgExtracted_h9ba6cb1b__0;
        CData/*0:0*/ __VdfgExtracted_h98c9c5c3__0;
        CData/*0:0*/ __VdfgExtracted_h80ebcf5a__0;
        CData/*0:0*/ __VdfgExtracted_h80d82d54__0;
        CData/*0:0*/ __VdfgExtracted_h80ed6f3c__0;
        CData/*0:0*/ __VdfgExtracted_h80f68a32__0;
        CData/*0:0*/ __VdfgExtracted_h80d83d63__0;
        CData/*0:0*/ __VdfgExtracted_h80ecb548__0;
    };
    struct {
        CData/*0:0*/ __VdfgExtracted_h80ed2fb2__0;
        CData/*0:0*/ __VdfgExtracted_h80ecd666__0;
        CData/*0:0*/ __VdfgExtracted_he0b5a416__0;
        CData/*0:0*/ __VdfgExtracted_he0a8c030__0;
        CData/*0:0*/ __VdfgExtracted_he0b6052c__0;
        CData/*0:0*/ __VdfgExtracted_he0af5e4a__0;
        CData/*0:0*/ __VdfgExtracted_he0a8cdff__0;
        CData/*0:0*/ __VdfgExtracted_he0b6c790__0;
        CData/*0:0*/ __VdfgExtracted_he0b0452a__0;
        CData/*0:0*/ __VdfgExtracted_he0b6a76a__0;
        CData/*0:0*/ __VdfgRegularize_hfb9f42e9_0_15;
        CData/*4:0*/ __Vdly__uart_rx_fifo_level0;
        CData/*3:0*/ __Vdly__uart_rx_fifo_consume;
        CData/*0:0*/ __Vdly__ram_bus_ram_bus_ack;
        CData/*4:0*/ __Vdly__uart_tx_fifo_level0;
        CData/*0:0*/ __Vdly__simsoc_ram_bus_ack;
        CData/*3:0*/ __Vdly__uart_tx_fifo_consume;
        CData/*7:0*/ __VdlyVal__sram__v0;
        CData/*0:0*/ __VdlySet__sram__v0;
        CData/*7:0*/ __VdlyVal__sram__v1;
        CData/*0:0*/ __VdlySet__sram__v1;
        CData/*7:0*/ __VdlyVal__sram__v2;
        CData/*0:0*/ __VdlySet__sram__v2;
        CData/*7:0*/ __VdlyVal__sram__v3;
        CData/*0:0*/ __VdlySet__sram__v3;
        CData/*3:0*/ __VdlyDim0__storage__v0;
        CData/*0:0*/ __VdlySet__storage__v0;
        CData/*3:0*/ __VdlyDim0__storage_1__v0;
        CData/*0:0*/ __VdlySet__storage_1__v0;
        SData/*13:0*/ __PVT__interface1_adr;
        SData/*10:0*/ __PVT__sram_adr0;
        SData/*9:0*/ __PVT__storage_dat0;
        SData/*9:0*/ __PVT__storage_dat1;
        SData/*9:0*/ __PVT__storage_1_dat0;
        SData/*9:0*/ __PVT__storage_1_dat1;
        SData/*10:0*/ __VdlyDim0__sram__v0;
        SData/*10:0*/ __VdlyDim0__sram__v1;
        SData/*10:0*/ __VdlyDim0__sram__v2;
        SData/*10:0*/ __VdlyDim0__sram__v3;
        SData/*9:0*/ __VdlyVal__storage__v0;
        SData/*9:0*/ __VdlyVal__storage_1__v0;
        IData/*31:0*/ __PVT__bus_errors;
        IData/*19:0*/ __PVT__count;
        IData/*31:0*/ __PVT__csr_bankarray_interface0_bank_bus_dat_r;
        IData/*31:0*/ __PVT__csr_bankarray_interface1_bank_bus_dat_r;
        IData/*31:0*/ __PVT__csr_bankarray_interface2_bank_bus_dat_r;
        IData/*31:0*/ __PVT__csr_bankarray_sram_bus_dat_r;
        IData/*31:0*/ __PVT__interface0_dat_r;
        IData/*31:0*/ __PVT__interface1_dat_w;
        IData/*31:0*/ __PVT__interrupt;
        IData/*31:0*/ __PVT__scratch_storage;
        IData/*29:0*/ __PVT__self0;
        IData/*31:0*/ __PVT__self1;
        IData/*31:0*/ __PVT__shared_dat_r;
        IData/*31:0*/ __PVT__timer_load_storage;
        IData/*31:0*/ __PVT__timer_reload_storage;
        IData/*31:0*/ __PVT__timer_value;
        IData/*31:0*/ __PVT__timer_value_status;
        IData/*31:0*/ __PVT__rom_dat0;
        IData/*31:0*/ __PVT__mem_write_block__DOT__we_index;
        IData/*31:0*/ __Vdly__timer_value;
        IData/*31:0*/ __Vdly__bus_errors;
        VlUnpacked<IData/*31:0*/, 5890> __PVT__rom;
        VlUnpacked<IData/*31:0*/, 2048> __PVT__sram;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 37> __PVT__mem;
        VlUnpacked<SData/*9:0*/, 16> __PVT__storage;
        VlUnpacked<SData/*9:0*/, 16> __PVT__storage_1;
    };

    // INTERNAL VARIABLES
    Vsim__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim_sim(Vsim__Syms* symsp, const char* v__name);
    ~Vsim_sim();
    VL_UNCOPYABLE(Vsim_sim);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

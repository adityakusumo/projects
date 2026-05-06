// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"

VL_ATTR_COLD void Vsim_VexRiscv___eval_initial__TOP__sim__VexRiscv(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___eval_initial__TOP__sim__VexRiscv\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.CsrPlugin_inWfi = 0U;
}

extern const VlUnpacked<IData/*31:0*/, 4> Vsim__ConstPool__TABLE_h4deb4691_0;
extern const VlUnpacked<VlWide<3>/*71:0*/, 4> Vsim__ConstPool__TABLE_hef978607_0;
extern const VlUnpacked<IData/*23:0*/, 4> Vsim__ConstPool__TABLE_hc6edd28f_0;
extern const VlUnpacked<VlWide<3>/*95:0*/, 4> Vsim__ConstPool__TABLE_h957f924c_0;

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__0(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx17;
    __Vtableidx17 = 0;
    CData/*1:0*/ __Vtableidx19;
    __Vtableidx19 = 0;
    CData/*1:0*/ __Vtableidx21;
    __Vtableidx21 = 0;
    CData/*1:0*/ __Vtableidx23;
    __Vtableidx23 = 0;
    CData/*1:0*/ __Vtableidx25;
    __Vtableidx25 = 0;
    CData/*1:0*/ __Vtableidx37;
    __Vtableidx37 = 0;
    CData/*1:0*/ __Vtableidx38;
    __Vtableidx38 = 0;
    CData/*1:0*/ __Vtableidx39;
    __Vtableidx39 = 0;
    CData/*1:0*/ __Vtableidx40;
    __Vtableidx40 = 0;
    CData/*1:0*/ __Vtableidx41;
    __Vtableidx41 = 0;
    // Body
    vlSelfRef.__PVT__decode_ENV_CTRL = (((0x50U == 
                                          (0x10003050U 
                                           & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                         << 1U) | (0x10000050U 
                                                   == 
                                                   (0x10403050U 
                                                    & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    vlSelfRef.__PVT__decode_IS_CSR = ((0x1050U == (0x1050U 
                                                   & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                      | (0x2050U == 
                                         (0x2050U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    vlSelfRef.dataCache_1__DOT____VdfgRegularize_h4c3f712f_0_0 
        = (1U & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                 >> 7U));
    vlSelfRef.lastStageInstruction = vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION;
    vlSelfRef.lastStageIsValid = vlSelfRef.__PVT__writeBack_arbitration_isValid;
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_write_tag_0_payload_data_valid 
        = (1U & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter) 
                 >> 7U));
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1125 
        = (1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid)));
    vlSelfRef.lastStagePc = vlSelfRef.__PVT__memory_to_writeBack_PC;
    vlSelfRef.__PVT__dataCache_1__DOT___zz_loader_waysAllocator 
        = (3U & (- (IData)((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator))));
    vlSelfRef.lastStageRegFileWrite_payload_address 
        = (0x1fU & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                    >> 7U));
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_payload_address = 0U;
    }
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire = 0U;
    if (vlSelfRef.__PVT___zz_iBus_rsp_valid) {
        if ((7U == (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex))) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire = 1U;
        }
    }
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs2 = ((vlSelfRef.__PVT__decode_to_execute_RS2 
                                                  >> 0x1fU) 
                                                 & (IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS2_SIGNED));
    vlSelfRef.__PVT__execute_MulPlugin_aHigh = ((0x10000U 
                                                 & ((((1U 
                                                       == 
                                                       (3U 
                                                        & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                           >> 0xcU))) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                             >> 0xcU)))) 
                                                     << 0x10U) 
                                                    & (vlSelfRef.__PVT__decode_to_execute_RS1 
                                                       >> 0xfU))) 
                                                | (vlSelfRef.__PVT__decode_to_execute_RS1 
                                                   >> 0x10U));
    vlSelfRef.__PVT__execute_MulPlugin_bHigh = (((IData)(
                                                         ((0x1000U 
                                                           == 
                                                           (0x3000U 
                                                            & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)) 
                                                          & (vlSelfRef.__PVT__decode_to_execute_RS2 
                                                             >> 0x1fU))) 
                                                 << 0x10U) 
                                                | (vlSelfRef.__PVT__decode_to_execute_RS2 
                                                   >> 0x10U));
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MTIE) 
                                                 & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MTIP));
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_1 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MSIE) 
                                                   & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MSIP));
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_2 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MEIE) 
                                                   & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MEIP));
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs1_1 = (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS1_SIGNED) 
                                                                     & (vlSelfRef.__PVT__decode_to_execute_RS1 
                                                                        >> 0x1fU)))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.__PVT__decode_to_execute_RS1)));
    if ((3U == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL))) {
        vlSelfRef.__PVT__execute_BranchPlugin_branch_src2 
            = (((- (IData)((vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                            >> 0x1fU))) << 0xcU) | 
               (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                >> 0x14U));
    } else {
        vlSelfRef.__PVT__execute_BranchPlugin_branch_src2 
            = ((2U == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL))
                ? ((((- (IData)((vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                 >> 0x1fU))) << 0x15U) 
                    | (0x100000U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                    >> 0xbU))) | ((
                                                   (0xff000U 
                                                    & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION) 
                                                   | (0x800U 
                                                      & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                         >> 9U))) 
                                                  | (0x7feU 
                                                     & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                        >> 0x14U))))
                : (((- (IData)((vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                >> 0x1fU))) << 0xdU) 
                   | (((0x1000U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                   >> 0x13U)) | (0x800U 
                                                 & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                    << 4U))) 
                      | ((0x7e0U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                    >> 0x14U)) | (0x1eU 
                                                  & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                     >> 7U))))));
        if (vlSelfRef.__PVT__decode_to_execute_PREDICTION_HAD_BRANCHED2) {
            vlSelfRef.__PVT__execute_BranchPlugin_branch_src2 = 4U;
        }
    }
    vlSelfRef.__PVT___zz_memory_DivPlugin_div_result 
        = ((0x2000U & vlSelfRef.__PVT__execute_to_memory_INSTRUCTION)
            ? vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U]
            : (IData)(vlSelfRef.__PVT__memory_DivPlugin_rs1));
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs1 = ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_DIV) 
                                                 & ((vlSelfRef.__PVT__decode_to_execute_RS1 
                                                     >> 0x1fU) 
                                                    & (IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS1_SIGNED)));
    __Vtableidx17 = vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL;
    vlSelfRef.__PVT__execute_BRANCH_CTRL_string = Vsim__ConstPool__TABLE_h4deb4691_0
        [__Vtableidx17];
    __Vtableidx19 = vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL;
    vlSelfRef.__PVT__memory_SHIFT_CTRL_string[0U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx19][0U];
    vlSelfRef.__PVT__memory_SHIFT_CTRL_string[1U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx19][1U];
    vlSelfRef.__PVT__memory_SHIFT_CTRL_string[2U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx19][2U];
    __Vtableidx21 = vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL;
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][0U];
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][1U];
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][2U];
    __Vtableidx23 = vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL;
    vlSelfRef.__PVT__execute_SRC2_CTRL_string = Vsim__ConstPool__TABLE_hc6edd28f_0
        [__Vtableidx23];
    __Vtableidx25 = vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL;
    vlSelfRef.__PVT__execute_SRC1_CTRL_string[0U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx25][0U];
    vlSelfRef.__PVT__execute_SRC1_CTRL_string[1U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx25][1U];
    vlSelfRef.__PVT__execute_SRC1_CTRL_string[2U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx25][2U];
    __Vtableidx37 = vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL;
    vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx37][0U];
    vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx37][1U];
    vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx37][2U];
    __Vtableidx38 = vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL;
    vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL_string 
        = Vsim__ConstPool__TABLE_hc6edd28f_0[__Vtableidx38];
    __Vtableidx39 = vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL;
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][0U];
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][1U];
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][2U];
    __Vtableidx40 = vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL;
    vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx40][0U];
    vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx40][1U];
    vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx40][2U];
    __Vtableidx41 = vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL;
    vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL_string 
        = Vsim__ConstPool__TABLE_h4deb4691_0[__Vtableidx41];
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__when_InstructionCache_l351 
        = ((~ (((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_s1_tightlyCoupledHit)) 
                & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1)) 
               | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid))) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushPending));
    vlSelfRef.__PVT__dataCache_1__DOT___zz_stage0_mask = 0U;
    if ((0U == (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                      >> 0xcU)))) {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_stage0_mask = 1U;
    } else if ((1U == (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                             >> 0xcU)))) {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_stage0_mask = 3U;
    } else if ((2U == (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                             >> 0xcU)))) {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_stage0_mask = 0xfU;
    }
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderShifted 
        = (((QData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U])) 
            << 1U) | (QData)((IData)((1U & (IData)(
                                                   (vlSelfRef.__PVT__memory_DivPlugin_rs1 
                                                    >> 0x1fU))))));
    vlSelfRef.__PVT__dataCache_1_io_cpu_execute_isValid 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_MEMORY_ENABLE) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT___zz_dBus_cmd_ready_2 = ((5U != (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size)) 
                                             | (7U 
                                                == (IData)(vlSelfRef.__PVT___zz_dBusWishbone_ADR)));
    vlSelfRef.__PVT__CsrPlugin_targetPrivilege = ((IData)(vlSelfRef.CsrPlugin_hadException)
                                                   ? 3U
                                                   : (IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45 = 
        ((IData)(vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_VALID) 
         & (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid));
    vlSelfRef.__PVT___zz_decode_RS2_3 = ((((((vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                              << 0x1fU) 
                                             | (0x40000000U 
                                                & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                   << 0x1dU))) 
                                            | ((0x20000000U 
                                                & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                   << 0x1bU)) 
                                               | (0x10000000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 0x19U)))) 
                                           | (((0x8000000U 
                                                & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                   << 0x17U)) 
                                               | (0x4000000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 0x15U))) 
                                              | ((0x2000000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 0x13U)) 
                                                 | (0x1000000U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       << 0x11U))))) 
                                          | ((((0x800000U 
                                                & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                   << 0xfU)) 
                                               | (0x400000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 0xdU))) 
                                              | ((0x200000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 0xbU)) 
                                                 | (0x100000U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       << 9U)))) 
                                             | (((0x80000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     << 7U)) 
                                                 | (0x40000U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       << 5U))) 
                                                | ((0x20000U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       << 3U)) 
                                                   | (0x10000U 
                                                      & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                         << 1U)))))) 
                                         | (((((0x8000U 
                                                & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                   >> 1U)) 
                                               | (0x4000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     >> 3U))) 
                                              | ((0x2000U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     >> 5U)) 
                                                 | (0x1000U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 7U)))) 
                                             | (((0x800U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     >> 9U)) 
                                                 | (0x400U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 0xbU))) 
                                                | ((0x200U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 0xdU)) 
                                                   | (0x100U 
                                                      & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                         >> 0xfU))))) 
                                            | ((((0x80U 
                                                  & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                     >> 0x11U)) 
                                                 | (0x40U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 0x13U))) 
                                                | ((0x20U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 0x15U)) 
                                                   | (0x10U 
                                                      & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                         >> 0x17U)))) 
                                               | (((8U 
                                                    & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                       >> 0x19U)) 
                                                   | (4U 
                                                      & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                         >> 0x1bU))) 
                                                  | ((2U 
                                                      & (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                         >> 0x1dU)) 
                                                     | (vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT 
                                                        >> 0x1fU))))));
}

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__1(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__1\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__decode_LEGAL_INSTRUCTION = ((0x17U 
                                                  == 
                                                  (0x5fU 
                                                   & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                 | ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                    | ((0x1073U 
                                                        == 
                                                        (0x107fU 
                                                         & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                       | ((0x2073U 
                                                           == 
                                                           (0x207fU 
                                                            & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                          | ((0x4063U 
                                                              == 
                                                              (0x407fU 
                                                               & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                             | ((0x2013U 
                                                                 == 
                                                                 (0x207fU 
                                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                | ((0x13U 
                                                                    == 
                                                                    (0x107fU 
                                                                     & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                   | ((0x23U 
                                                                       == 
                                                                       (0x603fU 
                                                                        & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                      | ((3U 
                                                                          == 
                                                                          (0x207fU 
                                                                           & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                         | ((3U 
                                                                             == 
                                                                             (0x505fU 
                                                                              & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                            | ((0x63U 
                                                                                == 
                                                                                (0x707bU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                               | ((0xfU 
                                                                                == 
                                                                                (0x607fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x33U 
                                                                                == 
                                                                                (0xfc00007fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x500fU 
                                                                                == 
                                                                                (0x1f0707fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x5013U 
                                                                                == 
                                                                                (0xbe00705fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x1013U 
                                                                                == 
                                                                                (0xfe00305fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x33U 
                                                                                == 
                                                                                (0xbe00707fU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x10200073U 
                                                                                == 
                                                                                (0xdfffffffU 
                                                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                                                | ((0x10500073U 
                                                                                == vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen) 
                                                                                | (0x73U 
                                                                                == vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))))))))))))))))))));
    vlSelfRef.__PVT__dataCache_1_io_cpu_flush_ready 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_waitDone) 
           & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
              >> 7U));
    vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_MEMORY_MANAGMENT) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__execute_arbitration_flushNext 
        = ((IData)(vlSelfRef.__PVT__execute_arbitration_isValid) 
           & (2U == (IData)(vlSelfRef.__PVT__decode_to_execute_ENV_CTRL)));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement 
        = ((IData)(vlSelfRef.__PVT___zz_dBus_rsp_valid) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l51_1 
        = ((0x1fU & (vlSelfRef.__PVT__execute_to_memory_INSTRUCTION 
                     >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                          >> 0x14U)));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l51_2 
        = ((0x1fU & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                     >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                          >> 0x14U)));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l48_1 
        = ((0x1fU & (vlSelfRef.__PVT__execute_to_memory_INSTRUCTION 
                     >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                          >> 0xfU)));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l48_2 
        = ((0x1fU & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                     >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                          >> 0xfU)));
    vlSelfRef.__PVT___zz_externalInterrupt = (vlSelfRef.__PVT___zz_CsrPlugin_csrMapping_readDataInit 
                                              & vlSelfRef.__PVT__externalInterruptArray_regNext);
    vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid 
        = ((IData)(vlSelfRef.__PVT__memory_arbitration_isValid) 
           & ((IData)(vlSelfRef.__PVT__execute_to_memory_BRANCH_DO) 
              & (vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC 
                 >> 1U)));
    vlSelfRef.__PVT__decode_SRC_LESS_UNSIGNED = ((0x2000U 
                                                  == 
                                                  (0x2010U 
                                                   & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                 | (0x1000U 
                                                    == 
                                                    (0x5000U 
                                                     & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    vlSelfRef.__PVT__decode_BYPASSABLE_MEMORY_STAGE 
        = ((0x40U == (0x40U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
           | ((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
              | ((0x4020U == (0x4020U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                 | ((0x10U == (0x30U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                    | (0x20U == (0x2000020U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))))));
    vlSelfRef.__PVT__decode_BYPASSABLE_EXECUTE_STAGE 
        = ((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
           | ((0x2010U == (0x2030U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
              | ((0x10U == (0x1030U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                 | ((0x2020U == (0x2002060U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                    | (0x20U == (0x2003020U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))))));
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_68 
        = ((0x48U == (0x48U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
           | ((0x1010U == (0x1010U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
              | ((0x2010U == (0x2010U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                 | ((0x10U == (0x50U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                    | ((4U == (0xcU & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                       | (0U == (0x28U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)))))));
    vlSelfRef.__PVT__decode_SRC_USE_SUB_LESS = ((0x40U 
                                                 == 
                                                 (0x44U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                | ((0x2010U 
                                                    == 
                                                    (0x2014U 
                                                     & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                   | (0x40000030U 
                                                      == 
                                                      (0x40000034U 
                                                       & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))));
    vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_BRANCH_DO) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121 
        = ((((4U == (0x14U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
             | (0x4050U == (0x4050U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
            << 2U) | ((((4U == (0x44U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                        | (0x4050U == (0x4050U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
                       << 1U) | (0x1008U == (0x5048U 
                                             & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45_2 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__when_CsrPlugin_l1587 = ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_CSR) 
                                             & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__decode_RS2_USE = ((0x20U == (0x34U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                       | (0x20U == 
                                          (0x64U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    vlSelfRef.__PVT__when_MulDivIterativePlugin_l128 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_IS_DIV) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT__decode_RS1_USE = ((0U == (0x44U 
                                               & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                       | ((0U == (0x18U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                          | ((0x2000U 
                                              == (0x6004U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                             | ((0x1000U 
                                                 == 
                                                 (0x5004U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                | (0x4000U 
                                                   == 
                                                   (0x4050U 
                                                    & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))))));
    vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done 
        = vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_2;
    if ((0U != (((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_writeBack) 
                 << 2U) | (((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory) 
                            << 1U) | (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_execute))))) {
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done = 0U;
    }
    if (vlSelfRef.CsrPlugin_hadException) {
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done = 0U;
    }
    vlSelfRef.__PVT__execute_SRC2 = ((0U == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL))
                                      ? vlSelfRef.__PVT__decode_to_execute_RS2
                                      : ((1U == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL))
                                          ? (((- (IData)(
                                                         (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                          >> 0x1fU))) 
                                              << 0xcU) 
                                             | (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                >> 0x14U))
                                          : ((2U == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC2_CTRL))
                                              ? (((- (IData)(
                                                             (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                          >> 7U))))
                                              : vlSelfRef.__PVT__decode_to_execute_PC)));
    vlSelfRef.__PVT__when_CsrPlugin_l1456 = ((IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid) 
                                             & (1U 
                                                == (IData)(vlSelfRef.__PVT__memory_to_writeBack_ENV_CTRL)));
    vlSelfRef.__PVT__execute_SRC1 = ((0U == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL))
                                      ? vlSelfRef.__PVT__decode_to_execute_RS1
                                      : ((2U == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL))
                                          ? 4U : ((1U 
                                                   == (IData)(vlSelfRef.__PVT__decode_to_execute_SRC1_CTRL))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)
                                                   : 
                                                  (0x1fU 
                                                   & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                      >> 0xfU)))));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vsim__ConstPool__TABLE_hb704cd4e_0;

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__3(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__3\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    CData/*5:0*/ __Vtableidx46;
    __Vtableidx46 = 0;
    // Body
    vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2 
        = (0xffU & ((2U & vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA)
                     ? (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                        >> 0x18U) : (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                                     >> 8U)));
    vlSelfRef.__PVT__iBusWishbone_CYC = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid) 
                                         | (0U != (IData)(vlSelfRef.__PVT___zz_iBusWishbone_ADR)));
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits) 
           | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr));
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_unalignedAccess 
        = ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_unaligned));
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_loadStoreFault 
        = ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) 
           & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_exception) 
              | (((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_allowWrite)) 
                  & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr)) 
                 | ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_allowRead)) 
                    & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr))))));
    vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling));
    vlSelfRef.__PVT___zz_dBus_cmd_ready = ((IData)(vlSelfRef.__PVT__dBusWishbone_ACK) 
                                           & (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid));
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_outNumerator 
        = (((IData)(vlSelfRef.__PVT__memory_DivPlugin_rs1) 
            << 1U) | (1U & (~ (IData)((vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator 
                                       >> 0x20U)))));
    vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_error 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_error));
    vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_way = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_address = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                  >> 7U)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_way = 1U;
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_address 
            = (0x7fU & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter));
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid = 0U;
    } else {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid = 0U;
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_address 
            = (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
               >> 0xcU);
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_way 
            = vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator;
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_address 
            = (0x7fU & (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
                        >> 5U));
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid 
            = (1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_killReg)));
    } else {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_address = 0U;
    }
    vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
        = ((0x2000U & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)
            ? ((0x1000U & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)
                ? ((~ vlSelfRef.__PVT__execute_SRC1) 
                   & vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal)
                : (vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal 
                   | vlSelfRef.__PVT__execute_SRC1))
            : vlSelfRef.__PVT__execute_SRC1);
    vlSelfRef.__PVT__CsrPlugin_csrMapping_allowCsrSignal = 0U;
    if (((IData)(vlSelfRef.__PVT__when_CsrPlugin_l1587) 
         & ((0xe8U == (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                       >> 0x16U)) | (0x3bU == (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                               >> 0x18U))))) {
        vlSelfRef.__PVT__CsrPlugin_csrMapping_allowCsrSignal = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__when_CsrPlugin_l1587) 
         & ((3U <= (0x1fU & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                             >> 0x14U))) & ((0xb00U 
                                             == (0xf60U 
                                                 & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                    >> 0x14U))) 
                                            | (((~ (IData)(vlSelfRef.__PVT__execute_CsrPlugin_writeInstruction)) 
                                                & (0xc0000000U 
                                                   == 
                                                   (0xf6000000U 
                                                    & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION))) 
                                               | (0x320U 
                                                  == 
                                                  (0xfe0U 
                                                   & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                      >> 0x14U)))))))) {
        vlSelfRef.__PVT__CsrPlugin_csrMapping_allowCsrSignal = 1U;
    }
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_82 
        = ((((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
             | (0x20U == (0x70U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
            << 9U) | ((((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                        | (0U == (0x20U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
                       << 8U) | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_33)));
    vlSelfRef.__PVT__when_CsrPlugin_l1390 = ((IData)(vlSelfRef.CsrPlugin_hadException) 
                                             | (IData)(vlSelfRef.CsrPlugin_interruptJump));
    vlSelfRef.__PVT__dataCache_1__DOT__stage0_mask 
        = (0xfU & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_stage0_mask) 
                   << (3U & vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address)));
    vlSelfRef.__PVT__execute_SRC_LESS = (1U & (((vlSelfRef.__PVT__execute_SRC1 
                                                 >> 0x1fU) 
                                                == 
                                                (vlSelfRef.__PVT__execute_SRC2 
                                                 >> 0x1fU))
                                                ? (vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
                                                   >> 0x1fU)
                                                : ((IData)(vlSelfRef.__PVT__decode_to_execute_SRC_LESS_UNSIGNED)
                                                    ? 
                                                   (vlSelfRef.__PVT__execute_SRC2 
                                                    >> 0x1fU)
                                                    : 
                                                   (vlSelfRef.__PVT__execute_SRC1 
                                                    >> 0x1fU))));
    vlSelfRef.__VdfgRegularize_h1463825b_0_35 = (((IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2) 
                                                  << 8U) 
                                                 | (IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted));
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress;
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr;
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_size;
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache = 0U;
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009)))) {
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address 
                    = (0xffffffe0U & vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address);
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr = 0U;
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size = 5U;
            }
            if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009) {
                vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache = 1U;
            }
        }
    }
    __Vtableidx46 = (((((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid_regNext)) 
                        & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid)) 
                       << 5U) | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_refilling) 
                                  << 4U) | (((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr)) 
                                             & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_dataColisions) 
                                                & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits))) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009) 
                         << 2U) | ((2U & ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)) 
                                          << 1U)) | (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid))));
    vlSelfRef.__PVT__dataCache_1_io_cpu_redo = Vsim__ConstPool__TABLE_hb704cd4e_0
        [__Vtableidx46];
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_mmuException 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loadStoreFault) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging));
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_accessError 
        = ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)) 
           & (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits) 
               & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_error)) 
              | ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging)) 
                 & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loadStoreFault))));
    vlSelfRef.__PVT__when_IBusCachedPlugin_l250 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1)) 
                                                      & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling)) 
                                                         & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging) 
                                                            & (IData)(vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0)))));
    vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid)) 
                 | ((IData)(vlSelfRef.__PVT___zz_dBus_cmd_ready) 
                    & ((IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_wr) 
                       | (IData)(vlSelfRef.__PVT___zz_dBus_cmd_ready_2)))));
    vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 1U;
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_3264) {
        if (vlSelfRef.__PVT__decode_to_execute_CSR_READ_OPCODE) {
            vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
        }
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_768) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_836) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_772) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_773) {
        if (vlSelfRef.__PVT__decode_to_execute_CSR_WRITE_OPCODE) {
            vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
        }
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_833) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_834) {
        if (vlSelfRef.__PVT__decode_to_execute_CSR_READ_OPCODE) {
            vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
        }
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_835) {
        if (vlSelfRef.__PVT__decode_to_execute_CSR_READ_OPCODE) {
            vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
        }
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_3008) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_4032) {
        if (vlSelfRef.__PVT__decode_to_execute_CSR_READ_OPCODE) {
            vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
        }
    }
    if (vlSelfRef.__PVT__CsrPlugin_csrMapping_allowCsrSignal) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__when_CsrPlugin_l1587)))) {
        vlSelfRef.__PVT__execute_CsrPlugin_illegalAccess = 0U;
    }
    __Vtableidx9 = (3U & ((IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_82) 
                          >> 8U));
    vlSelfRef.__PVT__decode_SRC2_CTRL_string = Vsim__ConstPool__TABLE_hc6edd28f_0
        [__Vtableidx9];
    vlSelfRef.__VdfgRegularize_h1463825b_0_32 = (((
                                                   ((0x1000U 
                                                     == 
                                                     (0x1000U 
                                                      & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                    << 0x13U) 
                                                   | (((0x2000U 
                                                        == 
                                                        (0x3000U 
                                                         & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                       << 0x12U) 
                                                      | ((IData)(vlSelfRef.__PVT__decode_SRC_LESS_UNSIGNED) 
                                                         << 0x11U))) 
                                                  | (((0x4008U 
                                                       == 
                                                       (0x4048U 
                                                        & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                      << 0x10U) 
                                                     | ((IData)(vlSelfRef.__PVT__decode_RS2_USE) 
                                                        << 0xfU))) 
                                                 | (((((0x40U 
                                                        == 
                                                        (0x50U 
                                                         & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                       | ((0U 
                                                           == 
                                                           (0x18U 
                                                            & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                          | (0x40U 
                                                             == 
                                                             (0x403040U 
                                                              & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)))) 
                                                      << 0xeU) 
                                                     | (((0x20U 
                                                          == 
                                                          (0x20U 
                                                           & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                         << 0xdU) 
                                                        | ((IData)(vlSelfRef.__PVT__decode_BYPASSABLE_MEMORY_STAGE) 
                                                           << 0xcU))) 
                                                    | (((IData)(vlSelfRef.__PVT__decode_BYPASSABLE_EXECUTE_STAGE) 
                                                        << 0xbU) 
                                                       | (((IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_68) 
                                                           << 0xaU) 
                                                          | (IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_82)))));
}

extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h73d03be8_0;

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__4(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__4\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT___zz_execute_BRANCH_COND_RESULT;
    __PVT___zz_execute_BRANCH_COND_RESULT = 0;
    CData/*6:0*/ __Vtableidx44;
    __Vtableidx44 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    // Body
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload = 0U;
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 0U;
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
            = (((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))
                 ? vlSelfRef.__PVT__CsrPlugin_mtvec_base
                 : 0U) << 2U);
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
    }
    __Vtableidx44 = ((((IData)(vlSelfRef.__PVT__execute_BranchPlugin_eq) 
                       << 6U) | (0x20U & ((~ (IData)(vlSelfRef.__PVT__execute_BranchPlugin_eq)) 
                                          << 5U))) 
                     | (((IData)(vlSelfRef.__PVT__execute_SRC_LESS) 
                         << 4U) | ((8U & ((~ (IData)(vlSelfRef.__PVT__execute_SRC_LESS)) 
                                          << 3U)) | 
                                   (7U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                          >> 0xcU)))));
    __PVT___zz_execute_BRANCH_COND_RESULT = Vsim__ConstPool__TABLE_h73d03be8_0
        [__Vtableidx44];
    vlSelfRef.__PVT___zz_decode_RS2 = ((IData)(vlSelfRef.__PVT__when_CsrPlugin_l1587)
                                        ? vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal
                                        : ((2U == (IData)(vlSelfRef.__PVT__decode_to_execute_ALU_CTRL))
                                            ? ((2U 
                                                == (IData)(vlSelfRef.__PVT__decode_to_execute_ALU_BITWISE_CTRL))
                                                ? (vlSelfRef.__PVT__execute_SRC1 
                                                   & vlSelfRef.__PVT__execute_SRC2)
                                                : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.__PVT__decode_to_execute_ALU_BITWISE_CTRL))
                                                    ? 
                                                   (vlSelfRef.__PVT__execute_SRC1 
                                                    | vlSelfRef.__PVT__execute_SRC2)
                                                    : 
                                                   (vlSelfRef.__PVT__execute_SRC1 
                                                    ^ vlSelfRef.__PVT__execute_SRC2)))
                                            : ((1U 
                                                == (IData)(vlSelfRef.__PVT__decode_to_execute_ALU_CTRL))
                                                ? (IData)(vlSelfRef.__PVT__execute_SRC_LESS)
                                                : vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address)));
    vlSelfRef.__PVT___zz_decode_RS2_2 = vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA;
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        vlSelfRef.__PVT___zz_decode_RS2_2 = ((0U == 
                                              (3U & 
                                               (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                                                >> 0xcU)))
                                              ? (((- (IData)(
                                                             ((~ 
                                                               (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                                                                >> 0xeU)) 
                                                              & ((IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted) 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | (IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted))
                                              : ((1U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                                                      >> 0xcU)))
                                                  ? 
                                                 (((- (IData)(
                                                              ((~ 
                                                                (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                                                                 >> 0xeU)) 
                                                               & ((IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2) 
                                                                  >> 7U)))) 
                                                   << 0x10U) 
                                                  | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_35))
                                                  : 
                                                 ((0xffff0000U 
                                                   & vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data) 
                                                  | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_35))));
    }
    if (((IData)(vlSelfRef.__PVT__memory_to_writeBack_IS_MUL) 
         & (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid))) {
        __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW);
        __Vtemp_2[1U] = (((- (IData)((1U & (IData)(
                                                   (vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW 
                                                    >> 0x33U))))) 
                          << 0x14U) | (IData)((vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW 
                                               >> 0x20U)));
        __Vtemp_2[2U] = (3U & ((- (IData)((1U & (IData)(
                                                        (vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW 
                                                         >> 0x33U))))) 
                               >> 0xcU));
        __Vtemp_3[0U] = (IData)(vlSelfRef.__PVT__memory_to_writeBack_MUL_HH);
        __Vtemp_3[1U] = (IData)((vlSelfRef.__PVT__memory_to_writeBack_MUL_HH 
                                 >> 0x20U));
        __Vtemp_3[2U] = 0U;
        VL_SHIFTL_WWI(66,66,6, __Vtemp_4, __Vtemp_3, 0x20U);
        VL_ADD_W(3, __Vtemp_5, __Vtemp_2, __Vtemp_4);
        vlSelfRef.__PVT___zz_decode_RS2_2 = ((0U == 
                                              (3U & 
                                               (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                                                >> 0xcU)))
                                              ? (IData)(vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW)
                                              : __Vtemp_5[1U]);
    }
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data = 0U;
    if (vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache) {
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mask;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address 
            = (0x3ffU & (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
                         >> 2U));
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
            = vlSelfRef.__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits;
    } else {
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way = 0U;
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement) {
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask = 0xfU;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address 
            = ((0x3f8U & (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
                          >> 2U)) | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value));
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
            = vlSelfRef.__PVT__dBusWishbone_DAT_MISO_regNext;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way 
            = vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator;
    }
    vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid = 0U;
    vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code = 0U;
    vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 0U;
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_accessError) {
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code 
                = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_MEMORY_WR)
                    ? 7U : 5U);
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 1U;
        }
        if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_mmuException) {
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code 
                = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_MEMORY_WR)
                    ? 0xfU : 0xdU);
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 1U;
        }
        if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_unalignedAccess) {
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code 
                = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_MEMORY_WR)
                    ? 6U : 4U);
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 1U;
        }
        if (vlSelfRef.__PVT__dataCache_1_io_cpu_redo) {
            vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid = 1U;
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 0U;
        }
    }
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_refilling) 
           | ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_accessError) 
              | ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_mmuException) 
                 | (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_unalignedAccess))));
    vlSelfRef.__PVT__when_IBusCachedPlugin_l256 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l250)) 
                                                      & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1)) 
                                                         & (~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_valid)))));
    vlSelfRef.__VdfgRegularize_h1463825b_0_31 = (((0x5010U 
                                                   == 
                                                   (0x2007054U 
                                                    & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                  << 0x16U) 
                                                 | ((((0x40001010U 
                                                       == 
                                                       (0x40003054U 
                                                        & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                      | (0x1010U 
                                                         == 
                                                         (0x2007054U 
                                                          & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
                                                     << 0x15U) 
                                                    | (((0x24U 
                                                         == 
                                                         (0x64U 
                                                          & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                        << 0x14U) 
                                                       | vlSelfRef.__VdfgRegularize_h1463825b_0_32)));
    vlSelfRef.__PVT__execute_BRANCH_COND_RESULT = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                   & ((2U 
                                                       == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                      | ((3U 
                                                          == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                         | (IData)(__PVT___zz_execute_BRANCH_COND_RESULT))));
    vlSelfRef.lastStageRegFileWrite_payload_data = vlSelfRef.__PVT___zz_decode_RS2_2;
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_payload_data = 0U;
    }
    vlSelfRef.__PVT__decode_RS2 = vlSelfRef.__PVT___zz_RegFilePlugin_regFile_port1;
    if (vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_valid) {
        if (((IData)(vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_payload_address) 
             == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U)))) {
            vlSelfRef.__PVT__decode_RS2 = vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_payload_data;
        }
    }
    if (vlSelfRef.__PVT__when_HazardSimplePlugin_l45) {
        if (((0x1fU & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                       >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                            >> 0x14U)))) {
            vlSelfRef.__PVT__decode_RS2 = vlSelfRef.__PVT___zz_decode_RS2_2;
        }
    }
    if (vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1) {
        if (vlSelfRef.__PVT__execute_to_memory_BYPASSABLE_MEMORY_STAGE) {
            if (vlSelfRef.__PVT__when_HazardSimplePlugin_l51_1) {
                vlSelfRef.__PVT__decode_RS2 = vlSelfRef.__PVT___zz_decode_RS2_1;
            }
        }
    }
    vlSelfRef.__PVT__decode_RS1 = vlSelfRef.__PVT___zz_RegFilePlugin_regFile_port0;
    if (vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_valid) {
        if (((IData)(vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_payload_address) 
             == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0xfU)))) {
            vlSelfRef.__PVT__decode_RS1 = vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_payload_data;
        }
    }
    if (vlSelfRef.__PVT__when_HazardSimplePlugin_l45) {
        if (((0x1fU & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                       >> 7U)) == (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                            >> 0xfU)))) {
            vlSelfRef.__PVT__decode_RS1 = vlSelfRef.__PVT___zz_decode_RS2_2;
        }
    }
    if (vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1) {
        if (vlSelfRef.__PVT__execute_to_memory_BYPASSABLE_MEMORY_STAGE) {
            if (vlSelfRef.__PVT__when_HazardSimplePlugin_l48_1) {
                vlSelfRef.__PVT__decode_RS1 = vlSelfRef.__PVT___zz_decode_RS2_1;
            }
        }
    }
    if (vlSelfRef.__PVT__when_HazardSimplePlugin_l45_2) {
        if (vlSelfRef.__PVT__decode_to_execute_BYPASSABLE_EXECUTE_STAGE) {
            if (vlSelfRef.__PVT__when_HazardSimplePlugin_l51_2) {
                vlSelfRef.__PVT__decode_RS2 = vlSelfRef.__PVT___zz_decode_RS2;
            }
            if (vlSelfRef.__PVT__when_HazardSimplePlugin_l48_2) {
                vlSelfRef.__PVT__decode_RS1 = vlSelfRef.__PVT___zz_decode_RS2;
            }
        }
    }
    vlSelfRef.__PVT__writeBack_arbitration_removeIt = 0U;
    vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack 
        = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_writeBack;
    vlSelfRef.__PVT__writeBack_arbitration_flushNext = 0U;
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__writeBack_arbitration_removeIt = 1U;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) {
        vlSelfRef.__PVT__writeBack_arbitration_removeIt = 1U;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack = 1U;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack = 0U;
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
        if ((3U == (3U & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                          >> 0x1cU)))) {
            vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
                = vlSelfRef.__PVT__CsrPlugin_mepc;
        }
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
}

extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h2ce50dca_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsim__ConstPool__TABLE_hc8bc3dde_0;

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__5(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__5\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*1:0*/ __Vtableidx31;
    __Vtableidx31 = 0;
    CData/*5:0*/ __Vtableidx45;
    __Vtableidx45 = 0;
    CData/*6:0*/ __Vtableidx47;
    __Vtableidx47 = 0;
    // Body
    vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                  >> 7U)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 1U;
    }
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) {
            vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 0U;
        }
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 1U;
    }
    __Vtableidx47 = (((((IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) 
                        << 6U) | (0x20U & ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__memCmdSent)) 
                                           << 5U))) 
                      | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr) 
                          << 4U) | ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009) 
                                    << 3U))) | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__memCmdSent) 
                                                 << 2U) 
                                                | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid))));
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_valid = 
        Vsim__ConstPool__TABLE_h2ce50dca_0[__Vtableidx47];
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid = 0U;
    if (vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache) {
        if (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr) 
             & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits))) {
            vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid = 1U;
        }
    }
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) {
            vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid = 0U;
        }
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement) {
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid = 1U;
    }
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid = 0U;
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009)))) {
                if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
                    vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid = 1U;
                }
            }
        }
        if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) {
            vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid = 0U;
        }
    }
    __Vtableidx45 = ((((IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) 
                       << 5U) | ((0x10U & (((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr)) 
                                            | (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN)) 
                                           << 4U)) 
                                 | ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009) 
                                    << 3U))) | ((((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr)
                                                   ? (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN)
                                                   : (IData)(vlSelfRef.__PVT___zz_dBus_rsp_valid)) 
                                                 << 2U) 
                                                | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid))));
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_haltIt 
        = Vsim__ConstPool__TABLE_hc8bc3dde_0[__Vtableidx45];
    vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1) {
        vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch = 1U;
    }
    if (vlSelfRef.__PVT__when_IBusCachedPlugin_l256) {
        vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch = 1U;
    }
    vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_3 
        = ((IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l256) 
           | ((IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l250) 
              | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1)));
    __Vtableidx5 = (3U & (vlSelfRef.__VdfgRegularize_h1463825b_0_31 
                          >> 0x15U));
    vlSelfRef.__PVT__decode_SHIFT_CTRL_string[0U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx5][0U];
    vlSelfRef.__PVT__decode_SHIFT_CTRL_string[1U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx5][1U];
    vlSelfRef.__PVT__decode_SHIFT_CTRL_string[2U] = 
        Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx5][2U];
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
        = ((((0x48U == (0x48U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
             | (4U == (0x1cU & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
            << 0x18U) | (((0x40U == (0x58U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                          << 0x17U) | vlSelfRef.__VdfgRegularize_h1463825b_0_31));
    vlSelfRef.__PVT__memory_arbitration_isFlushed = 
        ((IData)(vlSelfRef.__PVT__writeBack_arbitration_flushNext) 
         | (0U != ((IData)(vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) 
                   << 1U)));
    vlSelfRef.__PVT__execute_arbitration_isFlushed 
        = ((0U != (((IData)(vlSelfRef.__PVT__writeBack_arbitration_flushNext) 
                    << 1U) | (IData)(vlSelfRef.__PVT__memory_arbitration_flushNext))) 
           | (0U != ((IData)(vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) 
                     << 2U)));
    vlSelfRef.__PVT__decode_arbitration_isFlushed = 
        ((0U != (((IData)(vlSelfRef.__PVT__writeBack_arbitration_flushNext) 
                  << 2U) | (((IData)(vlSelfRef.__PVT__memory_arbitration_flushNext) 
                             << 1U) | (IData)(vlSelfRef.__PVT__execute_arbitration_flushNext)))) 
         | (0U != ((IData)(vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) 
                   << 3U)));
    vlSelfRef.__PVT__dataCache_1__DOT___zz_1 = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way) 
                                                & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid));
    vlSelfRef.__PVT__memory_arbitration_isStuckByOthers 
        = ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) 
           & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_haltIt));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_fill_valid 
        = ((IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l256) 
           | ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling)) 
              & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch)));
    vlSelfRef.__PVT__when_IBusCachedPlugin_l262 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_3)) 
                                                      & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_error) 
                                                         | ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging)) 
                                                            & (IData)(vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0)))));
    __Vtableidx31 = (3U & (vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
                           >> 0x17U));
    vlSelfRef.__PVT__decode_BRANCH_CTRL_string = Vsim__ConstPool__TABLE_h4deb4691_0
        [__Vtableidx31];
    vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_payload 
        = (vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload 
           + ((2U == (3U & (vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
                            >> 0x17U))) ? ((((- (IData)(
                                                        (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                         >> 0x1fU))) 
                                             << 0x15U) 
                                            | (0x100000U 
                                               & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                  >> 0xbU))) 
                                           | (((0xff000U 
                                                & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen) 
                                               | (0x800U 
                                                  & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                     >> 9U))) 
                                              | (0x7feU 
                                                 & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                    >> 0x14U))))
               : (((- (IData)((vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                               >> 0x1fU))) << 0xdU) 
                  | (((0x1000U & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                  >> 0x13U)) | (0x800U 
                                                & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                   << 4U))) 
                     | ((0x7e0U & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                   >> 0x14U)) | (0x1eU 
                                                 & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                    >> 7U)))))));
    vlSelfRef.__PVT__decode_PREDICTION_HAD_BRANCHED2 
        = ((~ ((2U == (3U & (vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
                             >> 0x17U))) ? (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                            >> 0x15U)
                : (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                   >> 8U))) & ((2U == (3U & (vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
                                             >> 0x17U))) 
                               | (IData)(((0x800000U 
                                           == (0x1800000U 
                                               & vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9)) 
                                          & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                             >> 0x1fU)))));
    vlSelfRef.__PVT__memory_arbitration_removeIt = 0U;
    if (vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid) {
        vlSelfRef.__PVT__memory_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory = 1U;
    } else {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory;
    }
    if (vlSelfRef.__PVT__memory_arbitration_isFlushed) {
        vlSelfRef.__PVT__memory_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory = 0U;
    }
    vlSelfRef.__PVT__execute_arbitration_removeIt = 0U;
    if (vlSelfRef.__PVT__execute_arbitration_flushNext) {
        vlSelfRef.__PVT__execute_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_execute;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute = 1U;
    } else {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_execute;
    }
    if (vlSelfRef.__PVT__execute_arbitration_isFlushed) {
        vlSelfRef.__PVT__execute_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute = 0U;
    }
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l829 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)) 
                 & (~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid) 
                       | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid)))));
    vlSelfRef.lastStageIsFiring = ((IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid) 
                                   & ((~ (IData)(vlSelfRef.__PVT__writeBack_arbitration_removeIt)) 
                                      & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers))));
    vlSelfRef.__PVT__memory_arbitration_isStuck = ((IData)(vlSelfRef.__PVT__memory_arbitration_haltItself) 
                                                   | (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers));
    vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_payload_code = 0U;
    if (vlSelfRef.__PVT__when_IBusCachedPlugin_l250) {
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_payload_code = 0xcU;
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid 
            = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1;
    } else {
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid = 0U;
    }
    if (vlSelfRef.__PVT__when_IBusCachedPlugin_l262) {
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_payload_code = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid 
            = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1;
    }
    vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l262)) 
                 & (~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_3))));
    vlSelfRef.__PVT__HazardSimplePlugin_writeBackWrites_valid 
        = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.lastStageIsFiring));
    vlSelfRef.__PVT__memory_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_removeIt))));
    vlSelfRef.__PVT__memory_DivPlugin_div_counter_valueNext 
        = ((IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)
            ? (((0x21U == (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_value)) 
                & (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement))
                ? 0U : (0x3fU & ((IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_value) 
                                 + (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement))))
            : 0U);
    vlSelfRef.__PVT__dataCache_1__DOT__tagsReadCmd_valid 
        = ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_execute_isValid));
    vlSelfRef.__VdfgRegularize_h1463825b_0_29 = ((IData)(vlSelfRef.__PVT__memory_arbitration_isStuck) 
                                                 | (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers));
    vlSelfRef.__PVT__decode_arbitration_isValid = ((IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready) 
                                                   & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid));
    vlSelfRef.lastStageRegFileWrite_valid = vlSelfRef.__PVT__HazardSimplePlugin_writeBackWrites_valid;
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_valid = 1U;
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__tagsReadCmd_valid) {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tagsReadRsp_valid 
            = (1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)));
        vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload 
            = (0x3ffU & (vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
                         >> 2U));
    } else {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tagsReadRsp_valid = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload = 0U;
    }
}

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__6(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__6\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload = 0;
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 = 0;
    // Body
    vlSelfRef.__PVT__execute_arbitration_isStuck = 
        ((IData)(vlSelfRef.__PVT__execute_arbitration_haltItself) 
         | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid) 
             & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid)) 
            | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_29)));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_flush 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isValid) 
           & (0x1008U == (0x5048U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active 
        = ((IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_valid) 
           & (IData)(vlSelfRef.__PVT__decode_arbitration_isValid));
    vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code 
        = ((((~ (IData)(vlSelfRef.__PVT__decode_LEGAL_INSTRUCTION)) 
             & (IData)(vlSelfRef.__PVT__decode_arbitration_isValid)) 
            << 1U) | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid));
    vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isValid) 
           & (IData)(vlSelfRef.__PVT__decode_PREDICTION_HAD_BRANCHED2));
    vlSelfRef.__PVT__execute_CsrPlugin_writeEnable 
        = ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT__execute_CsrPlugin_writeInstruction));
    vlSelfRef.__PVT__execute_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_removeIt))));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid) 
           | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushPending));
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter) 
                  >> 7U)))) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_when_InstructionCache_l342)))) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt = 1U;
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_cache_io_flush) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt = 1U;
    }
    vlSelfRef.__PVT__decode_arbitration_haltByOther = 0U;
    if (((IData)(vlSelfRef.__PVT__decode_arbitration_isValid) 
         & ((IData)(vlSelfRef.__PVT__HazardSimplePlugin_src0Hazard) 
            | (IData)(vlSelfRef.__PVT__HazardSimplePlugin_src1Hazard)))) {
        vlSelfRef.__PVT__decode_arbitration_haltByOther = 1U;
    }
    if (vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active) {
        vlSelfRef.__PVT__decode_arbitration_haltByOther = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__when_CsrPlugin_l1456) 
         | (((IData)(vlSelfRef.__PVT__memory_arbitration_isValid) 
             & (1U == (IData)(vlSelfRef.__PVT__execute_to_memory_ENV_CTRL))) 
            | ((IData)(vlSelfRef.__PVT__execute_arbitration_isValid) 
               & (1U == (IData)(vlSelfRef.__PVT__decode_to_execute_ENV_CTRL)))))) {
        vlSelfRef.__PVT__decode_arbitration_haltByOther = 1U;
    }
    vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code_1 
        = (1U & ((~ ((IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code) 
                     - (IData)(1U))) & (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code)));
    vlSelfRef.__PVT__decode_arbitration_removeIt = 0U;
    vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode 
        = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_decode;
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__decode_arbitration_removeIt = 1U;
    }
    if (vlSelfRef.__PVT__decode_arbitration_isFlushed) {
        vlSelfRef.__PVT__decode_arbitration_removeIt = 1U;
    }
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode = 1U;
    }
    if (vlSelfRef.__PVT__decode_arbitration_isFlushed) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode = 0U;
    }
    vlSelfRef.__PVT__decode_arbitration_flushNext = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid) {
        vlSelfRef.__PVT__decode_arbitration_flushNext = 1U;
    }
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__decode_arbitration_flushNext = 1U;
    }
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload 
        = ((((IData)(vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid) 
             << 3U) | ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong) 
                       << 2U)) | (((IData)(vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid) 
                                   << 1U) | (IData)(vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid)));
    vlSelfRef.__PVT__IBusCachedPlugin_jump_pcLoad_valid 
        = (0U != ((((IData)(vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid) 
                    << 3U) | ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong) 
                              << 2U)) | (((IData)(vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) 
                                          << 1U) | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid))));
    vlSelfRef.__PVT__decode_arbitration_isStuck = ((IData)(vlSelfRef.__PVT__decode_arbitration_haltByOther) 
                                                   | ((IData)(vlSelfRef.__PVT__execute_arbitration_isStuck) 
                                                      | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_29)));
    vlSelfRef.__PVT__when_CsrPlugin_l1340 = (1U & (
                                                   (~ (IData)(vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active)) 
                                                   | (IData)(vlSelfRef.__PVT__decode_arbitration_removeIt)));
    vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt = 0U;
    if ((0U != ((((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack) 
                  << 3U) | ((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory) 
                            << 2U)) | (((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute) 
                                        << 1U) | (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode))))) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt = 1U;
    }
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 
        = ((~ ((IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload) 
               - (IData)(1U))) & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 0U;
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 1U;
    }
    vlSelfRef.__PVT__decode_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__decode_arbitration_removeIt))));
    vlSelfRef.__PVT__decode_INSTRUCTION_ANTICIPATED 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)
            ? vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen
            : vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_banks_0_port1);
    vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_removeIt) 
           | (((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (IData)(vlSelfRef.__PVT__decode_arbitration_flushNext)) 
              | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch)));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate 
        = ((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_booted));
    vlSelfRef.__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6 
        = (((IData)((0U != (0xcU & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1)))) 
            << 1U) | (IData)((0U != (0xaU & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1)))));
    if (vlSelfRef.__PVT__IBusCachedPlugin_jump_pcLoad_valid) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 1U;
    }
    vlSelfRef.__PVT__when_Fetcher_l133 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction) 
                                          | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc = 
        (vlSelfRef.IBusCachedPlugin_fetchPc_pcReg + 
         ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_inc) 
          << 2U));
    if (vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc 
            = vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload;
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_jump_pcLoad_valid) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc 
            = ((0U == (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6))
                ? vlSelfRef.__PVT__memory_to_writeBack_PC
                : ((1U == (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6))
                    ? vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload
                    : ((2U == (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6))
                        ? vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC
                        : vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_payload)));
    }
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc = 
        (0xfffffffcU & vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc);
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_fire 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready));
}

VL_ATTR_COLD void Vsim_VexRiscv___ctor_var_reset_0(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___ctor_var_reset_0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__PVT__externalResetVector = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17290297869447326567ull);
    vlSelf->__PVT__timerInterrupt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4287585456911163044ull);
    vlSelf->__PVT__softwareInterrupt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16866690491941050520ull);
    vlSelf->__PVT__externalInterruptArray = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10469481714636426648ull);
    vlSelf->__PVT__iBusWishbone_CYC = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9331567082151214436ull);
    vlSelf->__PVT__iBusWishbone_STB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8596794262491203245ull);
    vlSelf->__PVT__iBusWishbone_ACK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10638071750315046196ull);
    vlSelf->__PVT__iBusWishbone_WE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3108100321664379167ull);
    vlSelf->__PVT__iBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 3720253804277902682ull);
    vlSelf->__PVT__iBusWishbone_DAT_MISO = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3387387550718055065ull);
    vlSelf->__PVT__iBusWishbone_DAT_MOSI = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2039202983677540698ull);
    vlSelf->__PVT__iBusWishbone_SEL = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6532769153774031233ull);
    vlSelf->__PVT__iBusWishbone_ERR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2001607436780477263ull);
    vlSelf->__PVT__iBusWishbone_CTI = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7711855334640482193ull);
    vlSelf->__PVT__iBusWishbone_BTE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5361071638209335772ull);
    vlSelf->__PVT__dBusWishbone_CYC = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9854781746111216993ull);
    vlSelf->__PVT__dBusWishbone_STB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1900518867861988994ull);
    vlSelf->__PVT__dBusWishbone_ACK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4216156700039998768ull);
    vlSelf->__PVT__dBusWishbone_WE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9492090167808115405ull);
    vlSelf->__PVT__dBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 16872559486728266751ull);
    vlSelf->__PVT__dBusWishbone_DAT_MISO = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13026828571797791865ull);
    vlSelf->__PVT__dBusWishbone_DAT_MOSI = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1200989737471195003ull);
    vlSelf->__PVT__dBusWishbone_SEL = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5160658312990301174ull);
    vlSelf->__PVT__dBusWishbone_ERR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16342584325256105989ull);
    vlSelf->__PVT__dBusWishbone_CTI = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14148866810079913239ull);
    vlSelf->__PVT__dBusWishbone_BTE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17841019996139454823ull);
    vlSelf->__PVT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__PVT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6313788745778468952ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3078682447314868387ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_cpu_fetch_isRemoved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14663545206295549471ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8331552228974468552ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_cpu_fill_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3677403171680696990ull);
    vlSelf->__PVT__dataCache_1_io_cpu_execute_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7634856819849700243ull);
    vlSelf->__PVT__dataCache_1_io_cpu_execute_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13446562813526539622ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4174243022299329260ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_SW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5864189405770165281ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_SR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13743579812625564235ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_SO = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11440688447162627859ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_SI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10964931747074914282ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_PW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15903075648271901479ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_PR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6916388729264115463ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_PO = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13678548375320074924ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_PI = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9848433442398017399ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_fence_FM = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10627382207919818537ull);
    vlSelf->__PVT__dataCache_1_io_cpu_flush_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1428245750144912244ull);
    vlSelf->__PVT___zz_RegFilePlugin_regFile_port0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1788123123477987112ull);
    vlSelf->__PVT___zz_RegFilePlugin_regFile_port1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13095834255199973740ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14538637863466183649ull);
    vlSelf->__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4708273627923057901ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_haltIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10368595139052134116ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11025085949127113037ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_mmuException = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11678707503980841801ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_unalignedAccess = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13763546732505892111ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_accessError = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13124569886263856867ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writeBack_exclusiveOk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13730647278083133572ull);
    vlSelf->__PVT__dataCache_1_io_cpu_flush_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4104385436567228326ull);
    vlSelf->__PVT__dataCache_1_io_cpu_redo = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13254379681248807280ull);
    vlSelf->__PVT__dataCache_1_io_cpu_writesPending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14924254442946761302ull);
    vlSelf->__PVT__dataCache_1_io_mem_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13577389004339833277ull);
    vlSelf->__PVT__dataCache_1_io_mem_cmd_payload_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10024293738539865709ull);
    vlSelf->__PVT__dataCache_1_io_mem_cmd_payload_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9992963736279387468ull);
    vlSelf->__PVT__dataCache_1_io_mem_cmd_payload_size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10116134083980874796ull);
    vlSelf->__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8354569651121469798ull);
    vlSelf->__PVT___zz_writeBack_DBusCachedPlugin_rspShifted = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 399947628968362475ull);
    vlSelf->__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11056726483208374803ull);
    vlSelf->__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 11123885779160088329ull);
    vlSelf->__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_68 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13761427302564163847ull);
    vlSelf->__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_82 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 16168612408861810988ull);
    vlSelf->__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13139548278245128183ull);
    vlSelf->__PVT__decode_PREDICTION_HAD_BRANCHED2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15165509676606863495ull);
    vlSelf->__PVT__decode_ENV_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10893325958113963114ull);
    vlSelf->__PVT__decode_IS_CSR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13035646230782854139ull);
    vlSelf->__PVT__decode_SRC_LESS_UNSIGNED = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16139875891813123961ull);
    vlSelf->__PVT__decode_BYPASSABLE_MEMORY_STAGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4246640828760841557ull);
    vlSelf->__PVT__decode_BYPASSABLE_EXECUTE_STAGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3317951558969977455ull);
    vlSelf->__PVT__execute_BRANCH_COND_RESULT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692434601696949056ull);
    vlSelf->__PVT__decode_RS2_USE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15652144591536648846ull);
    vlSelf->__PVT__decode_RS1_USE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11635357443534409678ull);
    vlSelf->__PVT___zz_decode_RS2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15137069597084337354ull);
    vlSelf->__PVT__decode_RS2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12670011375524861773ull);
    vlSelf->__PVT__decode_RS1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1621850154405875389ull);
    vlSelf->__PVT___zz_decode_RS2_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6795616548415120460ull);
    vlSelf->__PVT__decode_SRC_USE_SUB_LESS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11073961411138940176ull);
    vlSelf->__PVT__execute_SRC_LESS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17891424215491376657ull);
    vlSelf->__PVT__execute_SRC2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7147996165191310738ull);
    vlSelf->__PVT__execute_SRC1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8214844316300821021ull);
    vlSelf->__PVT__decode_INSTRUCTION_ANTICIPATED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3214481631732891372ull);
    vlSelf->__PVT__decode_LEGAL_INSTRUCTION = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2312223372608665575ull);
    vlSelf->__PVT___zz_decode_RS2_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 436848494187308778ull);
    vlSelf->__PVT__IBusCachedPlugin_rsp_issueDetected_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11737749939136692010ull);
    vlSelf->__PVT__IBusCachedPlugin_rsp_issueDetected_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2423874179753734670ull);
    vlSelf->__PVT__decode_arbitration_haltByOther = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2321656182353674293ull);
    vlSelf->__PVT__decode_arbitration_removeIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8269364244066748166ull);
    vlSelf->__PVT__decode_arbitration_flushNext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14840007307387654930ull);
    vlSelf->__PVT__decode_arbitration_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16046260467967632854ull);
    vlSelf->__PVT__decode_arbitration_isStuck = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17724877958800773426ull);
    vlSelf->__PVT__decode_arbitration_isFlushed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1398116637121990814ull);
    vlSelf->__PVT__decode_arbitration_isMoving = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8127436742139375710ull);
    vlSelf->__PVT__execute_arbitration_haltItself = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17763505969833358840ull);
    vlSelf->__PVT__execute_arbitration_removeIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 822985223213601320ull);
    vlSelf->__PVT__execute_arbitration_flushNext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5228022396395479534ull);
    vlSelf->__PVT__execute_arbitration_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2179162886483397008ull);
    vlSelf->__PVT__execute_arbitration_isStuck = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13070245385138640914ull);
    vlSelf->__PVT__execute_arbitration_isFlushed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13842480543826615952ull);
    vlSelf->__PVT__execute_arbitration_isMoving = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13191454491945456896ull);
    vlSelf->__PVT__memory_arbitration_haltItself = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16785656208847024154ull);
    vlSelf->__PVT__memory_arbitration_removeIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10535041838916052380ull);
    vlSelf->__PVT__memory_arbitration_flushNext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6376462050733357894ull);
    vlSelf->__PVT__memory_arbitration_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13168068744977233315ull);
    vlSelf->__PVT__memory_arbitration_isStuck = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3086325998487703639ull);
    vlSelf->__PVT__memory_arbitration_isStuckByOthers = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12097952363233914039ull);
    vlSelf->__PVT__memory_arbitration_isFlushed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15125880220478274089ull);
    vlSelf->__PVT__memory_arbitration_isMoving = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9428471063900859073ull);
    vlSelf->__PVT__writeBack_arbitration_removeIt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15283736521924185669ull);
    vlSelf->__PVT__writeBack_arbitration_flushNext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7059562840019847537ull);
    vlSelf->__PVT__writeBack_arbitration_isValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17344032567304701006ull);
    vlSelf->lastStageInstruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4100212620214316805ull);
    vlSelf->lastStagePc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1214765487219586732ull);
    vlSelf->lastStageIsValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5509764516179143221ull);
    vlSelf->lastStageIsFiring = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8099300479213945053ull);
    vlSelf->__PVT__IBusCachedPlugin_fetcherHalt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10815937223305108018ull);
    vlSelf->__PVT__IBusCachedPlugin_predictionJumpInterface_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17560032879835994331ull);
    vlSelf->__PVT__IBusCachedPlugin_predictionJumpInterface_payload = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5360164282836354541ull);
    vlSelf->__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12768047296897156348ull);
    vlSelf->__PVT__IBusCachedPlugin_decodeExceptionPort_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13271702521978256091ull);
    vlSelf->__PVT__IBusCachedPlugin_decodeExceptionPort_payload_code = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13195680208826035297ull);
    vlSelf->__PVT__IBusCachedPlugin_mmuBus_rsp_bypassTranslation = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4289984724489157624ull);
    vlSelf->__PVT__dBus_rsp_payload_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7194473129347454251ull);
    vlSelf->__PVT__DBusCachedPlugin_mmuBus_rsp_bypassTranslation = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17430642673460886355ull);
    vlSelf->__PVT__DBusCachedPlugin_redoBranch_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15970371873755848873ull);
    vlSelf->__PVT__DBusCachedPlugin_exceptionBus_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10939668565347336057ull);
    vlSelf->__PVT__DBusCachedPlugin_exceptionBus_payload_code = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5933916207627567871ull);
    vlSelf->__PVT__BranchPlugin_branchExceptionPort_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18289207458225203837ull);
    vlSelf->__PVT__CsrPlugin_csrMapping_readDataSignal = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7907387683543938657ull);
    vlSelf->__PVT__CsrPlugin_csrMapping_writeDataSignal = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16763969951014364031ull);
    vlSelf->__PVT__CsrPlugin_csrMapping_allowCsrSignal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 250899081916635508ull);
    vlSelf->CsrPlugin_inWfi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17566866111919295960ull);
    vlSelf->__PVT__CsrPlugin_jumpInterface_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1049975670439051422ull);
    vlSelf->__PVT__CsrPlugin_jumpInterface_payload = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 136340434973462600ull);
    vlSelf->__PVT__IBusCachedPlugin_jump_pcLoad_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4293560001906124424ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4609175741095925847ull);
    vlSelf->IBusCachedPlugin_fetchPc_pcReg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8359382611411103589ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_correction = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11806800487480710264ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_correctionReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4723948918303799124ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_output_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9476467369289593872ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11179928582020598288ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_booted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 280870193332234333ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_inc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4325662570339320334ull);
    vlSelf->__PVT__when_Fetcher_l133 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16382708560245834771ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3111223333121426965ull);
    vlSelf->__PVT__IBusCachedPlugin_fetchPc_flushed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6159765650618033568ull);
    vlSelf->__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1486807538237579753ull);
    vlSelf->__PVT__IBusCachedPlugin_iBusRsp_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 719029023931342789ull);
    vlSelf->__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15953834003125793732ull);
    vlSelf->__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10181561141026132062ull);
    vlSelf->__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11336602339295080006ull);
    vlSelf->__PVT__IBusCachedPlugin_iBusRsp_output_payload_rsp_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13951051549687001425ull);
    vlSelf->__PVT__IBusCachedPlugin_iBusRsp_output_payload_isRvc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13582457638442977456ull);
    vlSelf->__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12957864553867871378ull);
    vlSelf->__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14772234969687040874ull);
    vlSelf->__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16217978799053459837ull);
    vlSelf->__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7244672529173171190ull);
    vlSelf->__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10840721101015663221ull);
    vlSelf->__PVT__IBusCachedPlugin_rspCounter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18104958095538981315ull);
    vlSelf->__PVT__IBusCachedPlugin_s1_tightlyCoupledHit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6034716068907798257ull);
    vlSelf->__PVT__IBusCachedPlugin_s2_tightlyCoupledHit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6020679222022720255ull);
    vlSelf->__PVT__IBusCachedPlugin_rsp_redoFetch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16633965637840668245ull);
    vlSelf->__PVT__when_IBusCachedPlugin_l250 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14186606358893841926ull);
    vlSelf->__PVT__when_IBusCachedPlugin_l256 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5817193017441588040ull);
    vlSelf->__PVT__when_IBusCachedPlugin_l262 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5742097076711738446ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12721540458309218478ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3792049732566024987ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5463121155659765051ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_uncached = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7767781268669197011ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17424531674866727558ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17209379263806980668ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15331125332675446731ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2719068604503405731ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_rData_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13877318159464433922ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3690144155405399889ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7486794433340801399ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_uncached = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5011810596044645517ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17388749337605822266ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4136842804329057137ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13566218774009427366ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11807881361715263823ull);
    vlSelf->__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14455355915109968873ull);
    vlSelf->__PVT__DBusCachedPlugin_rspCounter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4282534390432980029ull);
    vlSelf->lastStageRegFileWrite_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9194742863531283084ull);
    vlSelf->lastStageRegFileWrite_payload_address = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 838885902433046142ull);
    vlSelf->lastStageRegFileWrite_payload_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14495078890946051064ull);
    vlSelf->__PVT___zz_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17428798716449827010ull);
    vlSelf->__PVT__execute_FullBarrelShifterPlugin_reversed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10785007304506526087ull);
    vlSelf->__PVT___zz_decode_RS2_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17824169261946892674ull);
    vlSelf->__PVT__HazardSimplePlugin_src0Hazard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9562753913290703326ull);
    vlSelf->__PVT__HazardSimplePlugin_src1Hazard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16247299615878236721ull);
    vlSelf->__PVT__HazardSimplePlugin_writeBackWrites_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6677433728876933673ull);
    vlSelf->__PVT__HazardSimplePlugin_writeBackBuffer_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13655483050013257101ull);
    vlSelf->__PVT__HazardSimplePlugin_writeBackBuffer_payload_address = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4414117107806631161ull);
    vlSelf->__PVT__HazardSimplePlugin_writeBackBuffer_payload_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5644346687912537122ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l45 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16800899240049386498ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l48_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10236893112997631967ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l51_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9615011417446133063ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l45_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10093495457748458669ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l48_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16737732658002496287ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l51_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12219136904454774323ull);
    vlSelf->__PVT__when_HazardSimplePlugin_l45_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15360949792062927069ull);
    vlSelf->__PVT__execute_BranchPlugin_eq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5968259416008575675ull);
    vlSelf->__PVT__execute_BranchPlugin_branch_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3727183673130179367ull);
    vlSelf->__PVT__CsrPlugin_mtvec_mode = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10922872930214055057ull);
    vlSelf->__PVT__CsrPlugin_mtvec_base = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 16292409853326205831ull);
    vlSelf->__PVT__CsrPlugin_mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2153532493279580097ull);
    vlSelf->__PVT__CsrPlugin_mstatus_MIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 994627285713076281ull);
    vlSelf->__PVT__CsrPlugin_mstatus_MPIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8198901469150759290ull);
    vlSelf->__PVT__CsrPlugin_mstatus_MPP = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14473756257728872718ull);
    vlSelf->__PVT__CsrPlugin_mip_MEIP = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11320584415622808409ull);
    vlSelf->__PVT__CsrPlugin_mip_MTIP = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16179317262568397546ull);
    vlSelf->__PVT__CsrPlugin_mip_MSIP = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6140614885098046065ull);
    vlSelf->__PVT__CsrPlugin_mie_MEIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1734363182412384152ull);
    vlSelf->__PVT__CsrPlugin_mie_MTIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3365384700781923946ull);
    vlSelf->__PVT__CsrPlugin_mie_MSIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17187024325919583886ull);
    vlSelf->__PVT__CsrPlugin_mcause_interrupt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7455589850633583571ull);
    vlSelf->__PVT__CsrPlugin_mcause_exceptionCode = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8916543666354068504ull);
    vlSelf->__PVT__CsrPlugin_mtval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2755894790967403428ull);
    vlSelf->__PVT__CsrPlugin_mcycle = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1730451543179871746ull);
    vlSelf->__PVT__CsrPlugin_minstret = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9396276452143891377ull);
    vlSelf->__PVT___zz_when_CsrPlugin_l1302 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7870151810008471493ull);
    vlSelf->__PVT___zz_when_CsrPlugin_l1302_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16904060706213381905ull);
    vlSelf->__PVT___zz_when_CsrPlugin_l1302_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14334455595593021964ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13298400492223523085ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15791301838962346051ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5341784099793885602ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16171788322775828863ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_decode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15571499153023953362ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_execute = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15232375913947642315ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 517725324929396906ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_writeBack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17230134425695147138ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14059808488702764101ull);
    vlSelf->__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2715525414393623309ull);
    vlSelf->__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5965274003338518808ull);
    vlSelf->__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3674505140160160087ull);
    vlSelf->__PVT__CsrPlugin_interrupt_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14559866967938791428ull);
    vlSelf->CsrPlugin_interrupt_code = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12176855862582922624ull);
    vlSelf->__PVT__CsrPlugin_interrupt_targetPrivilege = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1998650785393120370ull);
    vlSelf->__PVT__CsrPlugin_pipelineLiberator_pcValids_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17178128937230649699ull);
    vlSelf->__PVT__CsrPlugin_pipelineLiberator_pcValids_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9255588546263163951ull);
    vlSelf->__PVT__CsrPlugin_pipelineLiberator_pcValids_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2107157145334259121ull);
    vlSelf->__PVT__CsrPlugin_pipelineLiberator_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7525618397960440744ull);
    vlSelf->__PVT__when_CsrPlugin_l1340 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1752402945628809249ull);
    vlSelf->__PVT__CsrPlugin_pipelineLiberator_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2337773200922453338ull);
    vlSelf->CsrPlugin_interruptJump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4788868692184108978ull);
    vlSelf->CsrPlugin_hadException = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14702747150294127822ull);
    vlSelf->__PVT__CsrPlugin_targetPrivilege = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7028588764360114596ull);
    vlSelf->__PVT__when_CsrPlugin_l1390 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2055240396118654359ull);
    vlSelf->__PVT__when_CsrPlugin_l1456 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10746759088379770334ull);
    vlSelf->__PVT__execute_CsrPlugin_wfiWake = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18214182708207317727ull);
    vlSelf->__PVT__execute_CsrPlugin_illegalAccess = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13325485051248348947ull);
    vlSelf->__PVT__execute_CsrPlugin_writeInstruction = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7208207665625869699ull);
    vlSelf->__PVT__execute_CsrPlugin_writeEnable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10089773410573486602ull);
    vlSelf->__PVT__when_CsrPlugin_l1587 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6762598022181577477ull);
    vlSelf->__PVT__execute_MulPlugin_aHigh = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18372872715020303814ull);
    vlSelf->__PVT__execute_MulPlugin_bHigh = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18113668923123645650ull);
    vlSelf->__PVT__memory_DivPlugin_rs1 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 12227866228116354510ull);
    vlSelf->__PVT__memory_DivPlugin_rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3567365128911177178ull);
    VL_SCOPED_RAND_RESET_W(65, vlSelf->__PVT__memory_DivPlugin_accumulator, __VscopeHash, 10681572719191793579ull);
    vlSelf->__PVT__memory_DivPlugin_div_needRevert = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4563863268396469782ull);
    vlSelf->__PVT__memory_DivPlugin_div_counter_willIncrement = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3686623198536148397ull);
    vlSelf->__PVT__memory_DivPlugin_div_counter_valueNext = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17569339673310105398ull);
    vlSelf->__PVT__memory_DivPlugin_div_counter_value = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13773910315655426616ull);
    vlSelf->__PVT__memory_DivPlugin_div_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3906815008626701792ull);
    vlSelf->__PVT__memory_DivPlugin_div_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5871090959218229399ull);
    vlSelf->__PVT__when_MulDivIterativePlugin_l128 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2742498752238127098ull);
    vlSelf->__PVT__memory_DivPlugin_div_stage_0_remainderShifted = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 3739171589127355043ull);
    vlSelf->__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 1113163919177592778ull);
    vlSelf->__PVT__memory_DivPlugin_div_stage_0_outNumerator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7780450368506497842ull);
    vlSelf->__PVT___zz_memory_DivPlugin_div_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10197226155587262585ull);
    vlSelf->__PVT___zz_memory_DivPlugin_rs2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10599334587758963077ull);
    vlSelf->__PVT___zz_memory_DivPlugin_rs1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18309155484275891679ull);
    vlSelf->__PVT___zz_memory_DivPlugin_rs1_1 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 4785452090899685921ull);
    vlSelf->__PVT__externalInterruptArray_regNext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10431980879607169368ull);
    vlSelf->__PVT___zz_CsrPlugin_csrMapping_readDataInit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13026895675361818587ull);
    vlSelf->__PVT___zz_externalInterrupt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12724364638845375180ull);
    vlSelf->__PVT__decode_to_execute_PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2530998747069268032ull);
    vlSelf->__PVT__execute_to_memory_PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4105179214261539673ull);
    vlSelf->__PVT__memory_to_writeBack_PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7843115636492409787ull);
    vlSelf->__PVT__decode_to_execute_INSTRUCTION = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1814596896273961752ull);
    vlSelf->__PVT__execute_to_memory_INSTRUCTION = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2172750810875966761ull);
    vlSelf->__PVT__memory_to_writeBack_INSTRUCTION = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6904260113499686653ull);
    vlSelf->__PVT__decode_to_execute_FORMAL_PC_NEXT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9175945128227627828ull);
    vlSelf->__PVT__execute_to_memory_FORMAL_PC_NEXT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5489058303236699925ull);
    vlSelf->__PVT__memory_to_writeBack_FORMAL_PC_NEXT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10603560145861878157ull);
    vlSelf->__PVT__decode_to_execute_MEMORY_FORCE_CONSTISTENCY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9703935593872641337ull);
    vlSelf->__PVT__decode_to_execute_SRC1_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17885324952462750896ull);
    vlSelf->__PVT__decode_to_execute_SRC_USE_SUB_LESS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1770268910660555100ull);
    vlSelf->__PVT__decode_to_execute_MEMORY_ENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 668424650087682664ull);
    vlSelf->__PVT__execute_to_memory_MEMORY_ENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 953251555680606227ull);
    vlSelf->__PVT__memory_to_writeBack_MEMORY_ENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14244041105701205430ull);
    vlSelf->__PVT__decode_to_execute_ALU_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13672293294532760000ull);
    vlSelf->__PVT__decode_to_execute_SRC2_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9211283468967767261ull);
    vlSelf->__PVT__decode_to_execute_REGFILE_WRITE_VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2347037320591930280ull);
    vlSelf->__PVT__execute_to_memory_REGFILE_WRITE_VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2388043375082790564ull);
    vlSelf->__PVT__memory_to_writeBack_REGFILE_WRITE_VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7705289521456773667ull);
    vlSelf->__PVT__decode_to_execute_BYPASSABLE_EXECUTE_STAGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7387357811270418938ull);
    vlSelf->__PVT__decode_to_execute_BYPASSABLE_MEMORY_STAGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11330217779133697600ull);
    vlSelf->__PVT__execute_to_memory_BYPASSABLE_MEMORY_STAGE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12944789343030037412ull);
    vlSelf->__PVT__decode_to_execute_MEMORY_WR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2248881388141253662ull);
    vlSelf->__PVT__execute_to_memory_MEMORY_WR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11987875512714936400ull);
    vlSelf->__PVT__memory_to_writeBack_MEMORY_WR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 640853795882583372ull);
    vlSelf->__PVT__decode_to_execute_MEMORY_MANAGMENT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11064459963245213133ull);
    vlSelf->__PVT__decode_to_execute_SRC_LESS_UNSIGNED = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1375752279788688849ull);
    vlSelf->__PVT__decode_to_execute_ALU_BITWISE_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5895464822317338444ull);
    vlSelf->__PVT__decode_to_execute_SHIFT_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7751777086706362448ull);
    vlSelf->__PVT__execute_to_memory_SHIFT_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7819338985546237443ull);
    vlSelf->__PVT__decode_to_execute_BRANCH_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16587634066081569315ull);
    vlSelf->__PVT__decode_to_execute_IS_CSR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15376847163764193216ull);
    vlSelf->__PVT__decode_to_execute_ENV_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11141546719462301957ull);
    vlSelf->__PVT__execute_to_memory_ENV_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13489789325196598694ull);
    vlSelf->__PVT__memory_to_writeBack_ENV_CTRL = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 378853717744893633ull);
    vlSelf->__PVT__decode_to_execute_IS_MUL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12163274624080607600ull);
    vlSelf->__PVT__execute_to_memory_IS_MUL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1212551207746168995ull);
    vlSelf->__PVT__memory_to_writeBack_IS_MUL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13525039374684063466ull);
    vlSelf->__PVT__decode_to_execute_IS_DIV = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17196234279030979662ull);
    vlSelf->__PVT__execute_to_memory_IS_DIV = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18120234459366940065ull);
    vlSelf->__PVT__decode_to_execute_IS_RS1_SIGNED = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14810384324516011406ull);
    vlSelf->__PVT__decode_to_execute_IS_RS2_SIGNED = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16885024265092835157ull);
    vlSelf->__PVT__decode_to_execute_RS1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16362480633436042600ull);
    vlSelf->__PVT__decode_to_execute_RS2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10063381391531851594ull);
    vlSelf->__PVT__decode_to_execute_SRC2_FORCE_ZERO = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1088371258315175847ull);
    vlSelf->__PVT__decode_to_execute_PREDICTION_HAD_BRANCHED2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2337367367430231347ull);
    vlSelf->__PVT__decode_to_execute_CSR_WRITE_OPCODE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14222965169653891828ull);
    vlSelf->__PVT__decode_to_execute_CSR_READ_OPCODE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18169795319954296917ull);
    vlSelf->__PVT__execute_to_memory_MEMORY_STORE_DATA_RF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15756114100937795368ull);
    vlSelf->__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16824870401426155072ull);
    vlSelf->__PVT__execute_to_memory_REGFILE_WRITE_DATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18364331463395196421ull);
    vlSelf->__PVT__memory_to_writeBack_REGFILE_WRITE_DATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15989483851358482331ull);
    vlSelf->__PVT__execute_to_memory_SHIFT_RIGHT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8765802742080820430ull);
    vlSelf->__PVT__execute_to_memory_BRANCH_DO = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15581377606181410177ull);
    vlSelf->__PVT__execute_to_memory_BRANCH_CALC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8663249323290038497ull);
    vlSelf->__PVT__execute_to_memory_MUL_LL = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12762696071681918316ull);
    vlSelf->__PVT__execute_to_memory_MUL_LH = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10272955328392279355ull);
    vlSelf->__PVT__execute_to_memory_MUL_HL = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 3276565705149556999ull);
    vlSelf->__PVT__execute_to_memory_MUL_HH = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15507982403310686890ull);
    vlSelf->__PVT__memory_to_writeBack_MUL_HH = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13483210568407700044ull);
    vlSelf->__PVT__memory_to_writeBack_MUL_LOW = VL_SCOPED_RAND_RESET_Q(52, __VscopeHash, 6145369799732192044ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_3264 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7583645279980261999ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_768 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4529444274892953634ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_836 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17660131614538216235ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_772 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17990105160976728349ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_773 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13417913305126958342ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_833 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1760795981105719295ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_834 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17677125405663414055ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_835 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 732667386306282722ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_3008 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4135818045151429300ull);
    vlSelf->__PVT__execute_CsrPlugin_csr_4032 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3310271676548673590ull);
    vlSelf->__PVT___zz_iBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18368411408148188498ull);
    vlSelf->__PVT___zz_iBus_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2802196461538736645ull);
    vlSelf->__PVT__iBusWishbone_DAT_MISO_regNext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12213970510098260612ull);
    vlSelf->__PVT___zz_dBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2284691052989904097ull);
    vlSelf->__PVT___zz_dBus_cmd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6884560593497568251ull);
    vlSelf->__PVT___zz_dBus_cmd_ready_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14099378616336910183ull);
    vlSelf->__PVT___zz_dBus_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2865871627622436145ull);
    vlSelf->__PVT__dBusWishbone_DAT_MISO_regNext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6188282414394378223ull);
    VL_SCOPED_RAND_RESET_W(72, vlSelf->__PVT__decode_SHIFT_CTRL_string, __VscopeHash, 8174087711277461162ull);
    vlSelf->__PVT__decode_SRC2_CTRL_string = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2445388301854145009ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->__PVT__decode_SRC1_CTRL_string, __VscopeHash, 13665314752915864646ull);
    vlSelf->__PVT__execute_BRANCH_CTRL_string = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13633262062673534985ull);
    VL_SCOPED_RAND_RESET_W(72, vlSelf->__PVT__memory_SHIFT_CTRL_string, __VscopeHash, 15043857912658760229ull);
    VL_SCOPED_RAND_RESET_W(72, vlSelf->__PVT__execute_SHIFT_CTRL_string, __VscopeHash, 17654259194498389439ull);
    vlSelf->__PVT__execute_SRC2_CTRL_string = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8674826649148022231ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->__PVT__execute_SRC1_CTRL_string, __VscopeHash, 108158552028414417ull);
    vlSelf->__PVT__decode_BRANCH_CTRL_string = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11821068239023696382ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->__PVT__decode_to_execute_SRC1_CTRL_string, __VscopeHash, 2612500258602956931ull);
    vlSelf->__PVT__decode_to_execute_SRC2_CTRL_string = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 547362015973776420ull);
    VL_SCOPED_RAND_RESET_W(72, vlSelf->__PVT__decode_to_execute_SHIFT_CTRL_string, __VscopeHash, 17961869437680587349ull);
    VL_SCOPED_RAND_RESET_W(72, vlSelf->__PVT__execute_to_memory_SHIFT_CTRL_string, __VscopeHash, 17963505774425989394ull);
    vlSelf->__PVT__decode_to_execute_BRANCH_CTRL_string = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12190710204400533819ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->RegFilePlugin_regFile[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3721712529686665558ull);
    }
    vlSelf->__VdfgRegularize_h1463825b_0_29 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11120183776645513089ull);
    vlSelf->__VdfgRegularize_h1463825b_0_31 = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10687361397836833791ull);
    vlSelf->__VdfgRegularize_h1463825b_0_32 = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 9019684409619049731ull);
    vlSelf->__VdfgRegularize_h1463825b_0_33 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1534394705907689919ull);
    vlSelf->__VdfgRegularize_h1463825b_0_35 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13813973715908946623ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT___zz_banks_0_port1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4294889720414889766ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT___zz_ways_0_tags_port1 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 1758341910817964757ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13496536536007213559ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12669110063064878796ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11067007189008752574ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_hadError = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16082787165953517813ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushPending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12180315315129419720ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14489849180922038804ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT___zz_when_InstructionCache_l342 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14640126629813274611ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__when_InstructionCache_l351 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9717198678467702255ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4421673795659683708ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2618550662466097704ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__lineLoader_write_tag_0_payload_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10398004749068729568ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9967247401333829457ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_physicalAddress = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 262027593954057475ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isIoAccess = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3097290763314059991ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8489787616277301931ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowRead = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8058528592989761354ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4141998526531884850ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowExecute = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7157333262431522215ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2884848561407748744ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10286606496542118175ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_bypassTranslation = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3790449396915663982ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 729546790940163799ull);
    vlSelf->__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4133991827678222151ull);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__IBusCachedPlugin_cache__DOT__banks_0[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8772070151031998650ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->__PVT__IBusCachedPlugin_cache__DOT__ways_0_tags[__Vi0] = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 6177875376049384928ull);
    }
    vlSelf->IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11813203319214385430ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_tags_port0 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 203572058075974173ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_loader_waysAllocator = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11215618931535894277ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1699399150595985619ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsReadCmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6290056995266574101ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11741238689739735006ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_payload_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9421455504015334870ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_payload_address = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7429794779021068162ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9857673379670085521ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9424321548480678206ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_address = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 4988007963142005679ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14080302512506276694ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_payload_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11262941023431098049ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_payload_address = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3582506800361842248ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_payload_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9217649842872204359ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_payload_data_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18326726378995943652ull);
    vlSelf->__PVT__dataCache_1__DOT__tagsWriteLastCmd_payload_data_address = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 12365452120931503546ull);
    vlSelf->__PVT__dataCache_1__DOT__dataReadCmd_payload = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 7429603521647132548ull);
    vlSelf->__PVT__dataCache_1__DOT__dataWriteCmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9739220021282341709ull);
    vlSelf->__PVT__dataCache_1__DOT__dataWriteCmd_payload_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1187762957709073845ull);
    vlSelf->__PVT__dataCache_1__DOT__dataWriteCmd_payload_address = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 13065108095357151908ull);
    vlSelf->__PVT__dataCache_1__DOT__dataWriteCmd_payload_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14036185091799948862ull);
    vlSelf->__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16803641986271553665ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_tagsReadRsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15715284555364613304ull);
    vlSelf->__PVT__dataCache_1__DOT__memCmdSent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9918104877793713202ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_stage0_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3975699298388467260ull);
    vlSelf->__PVT__dataCache_1__DOT__stage0_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11799771917274443948ull);
    vlSelf->__PVT__dataCache_1__DOT__stageA_request_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16650578533286907150ull);
    vlSelf->__PVT__dataCache_1__DOT__stageA_request_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10089485893372569665ull);
    vlSelf->__PVT__dataCache_1__DOT__stageA_request_totalyConsistent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1332484389488944174ull);
    vlSelf->__PVT__dataCache_1__DOT__stageA_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12452547337759404834ull);
    vlSelf->__PVT__dataCache_1__DOT__stageA_wayInvalidate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16527043127517638940ull);
    vlSelf->__PVT__dataCache_1__DOT__stage0_dataColisions_regNextWhen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8015216272888900489ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_request_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10867823114058563825ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_request_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7209148720890730067ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_request_totalyConsistent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3743107717741052558ull);
    vlSelf->__PVT__dataCache_1__DOT__when_DataCache_l829 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13167405546149275804ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11191451490618667686ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11731095723657954137ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5538599227917439036ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_allowRead = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11938214510781384773ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_allowWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13318219759817862342ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_allowExecute = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15025904355620189795ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8885224051727775360ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_refilling = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5088558698105842800ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mmuRsp_bypassTranslation = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13735517431198026060ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12705611273320669080ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12463715536500609801ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_address = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 14860058351700708223ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_dataReadRsp_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15595148213778092372ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_wayInvalidate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14196907671761671154ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_dataColisions = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13999686093602005953ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_unaligned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7611544336564907780ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_waysHitsBeforeInvalidate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4961131223037478537ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_waysHits = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12201726094199909215ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4601469453299506314ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_loaderValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12495566809095325495ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_flusher_waitDone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2734953930120107403ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_flusher_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2288796322766560891ull);
    vlSelf->__PVT__dataCache_1__DOT__when_DataCache_l863 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12323916610334338322ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_flusher_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18256187241413850941ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_cpuWriteToCache = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5163733997402150766ull);
    vlSelf->__PVT__dataCache_1__DOT__stageB_loadStoreFault = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9344509359261496154ull);
    vlSelf->__PVT__dataCache_1__DOT__when_DataCache_l1009 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707884664429454411ull);
    vlSelf->__PVT__dataCache_1__DOT__when_DataCache_l1072 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16835052580706326766ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10380708027241804809ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_counter_willIncrement = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 843968388551059701ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_counter_valueNext = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17461591642217729490ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_counter_value = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6434832350872798799ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_counter_willOverflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13927668128005576642ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_waysAllocator = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15835089606902673378ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16043176656790849018ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_killReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2979842577831988618ull);
    vlSelf->__PVT__dataCache_1__DOT__when_DataCache_l1125 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16698420208539562874ull);
    vlSelf->__PVT__dataCache_1__DOT__loader_valid_regNext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 791514551659499193ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->__PVT__dataCache_1__DOT__ways_0_tags[__Vi0] = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 1496947967002838568ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__dataCache_1__DOT__ways_0_data_symbol0[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 118662737165963126ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__dataCache_1__DOT__ways_0_data_symbol1[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4672113670029164530ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__dataCache_1__DOT__ways_0_data_symbol2[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11385075142690398710ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__dataCache_1__DOT__ways_0_data_symbol3[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12117403254416502552ull);
    }
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14751115278605657548ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17994393498983642924ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 228911718855363074ull);
    vlSelf->__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5991428940826502669ull);
    vlSelf->dataCache_1__DOT____VdfgRegularize_h4c3f712f_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15499434690796779075ull);
    vlSelf->__Vdly___zz_dBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13401203234100216764ull);
    vlSelf->__Vdly___zz_iBusWishbone_ADR = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3493390080420454076ull);
    vlSelf->__Vdly__IBusCachedPlugin_rspCounter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17583555634548939323ull);
    vlSelf->__Vdly__DBusCachedPlugin_rspCounter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1642865769509331677ull);
    vlSelf->__Vdly__CsrPlugin_mstatus_MPIE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5594568558237452210ull);
    vlSelf->__Vdly__CsrPlugin_minstret = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12481010454249457452ull);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"
#include "Vsim__Syms.h"

extern const VlUnpacked<VlWide<3>/*95:0*/, 4> Vsim__ConstPool__TABLE_h957f924c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h8d24d1d2_0;

VL_ATTR_COLD void Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__2(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___stl_sequent__TOP__sim__VexRiscv__2\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx13;
    __Vtableidx13 = 0;
    CData/*6:0*/ __Vtableidx42;
    __Vtableidx42 = 0;
    CData/*6:0*/ __Vtableidx43;
    __Vtableidx43 = 0;
    // Body
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)
            ? vlSelfRef.__PVT__dBusWishbone_DAT_MISO_regNext
            : vlSelfRef.__PVT__dataCache_1__DOT__stageB_dataReadRsp_0);
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid));
    vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowExecute)) 
                 | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_exception)));
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits 
        = ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_wayInvalidate)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHitsBeforeInvalidate));
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid 
        = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_MEMORY_ENABLE) 
           & (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_s2_tightlyCoupledHit)) 
           & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid));
    vlSelfRef.__PVT__reset = (((IData)(vlSymsp->TOP__sim.__PVT__int_rst) 
                               | (IData)(vlSymsp->TOP__sim.__PVT__soc_rst)) 
                              | ((IData)(vlSymsp->TOP__sim.__PVT__reset_storage) 
                                 >> 1U));
    vlSelfRef.__PVT__iBusWishbone_ACK = ((~ (IData)(vlSymsp->TOP__sim.__PVT__grant)) 
                                         & (IData)(vlSymsp->TOP__sim.__PVT__shared_ack));
    vlSelfRef.__PVT__dBusWishbone_ACK = ((IData)(vlSymsp->TOP__sim.__PVT__grant) 
                                         & (IData)(vlSymsp->TOP__sim.__PVT__shared_ack));
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator 
        = (0x1ffffffffULL & (vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderShifted 
                             - (QData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_rs2))));
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l863 
        = ((0U != (0x1fU & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                            >> 0xfU))) & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_valueNext 
        = (7U & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value) 
                 + (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement)));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow 
        = ((7U == (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement));
    vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal 
        = (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_3264)
             ? 0x2001000U : 0U) | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_768)
                                     ? (((IData)(vlSelfRef.__PVT__CsrPlugin_mstatus_MPP) 
                                         << 0xbU) | 
                                        (((IData)(vlSelfRef.__PVT__CsrPlugin_mstatus_MPIE) 
                                          << 7U) | 
                                         ((IData)(vlSelfRef.__PVT__CsrPlugin_mstatus_MIE) 
                                          << 3U))) : 0U) 
                                   | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_836)
                                        ? (((IData)(vlSelfRef.__PVT__CsrPlugin_mip_MEIP) 
                                            << 0xbU) 
                                           | (((IData)(vlSelfRef.__PVT__CsrPlugin_mip_MTIP) 
                                               << 7U) 
                                              | ((IData)(vlSelfRef.__PVT__CsrPlugin_mip_MSIP) 
                                                 << 3U)))
                                        : 0U) | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_772)
                                                   ? 
                                                  (((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MEIE) 
                                                    << 0xbU) 
                                                   | (((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MTIE) 
                                                       << 7U) 
                                                      | ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MSIE) 
                                                         << 3U)))
                                                   : 0U) 
                                                 | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_833)
                                                      ? vlSelfRef.__PVT__CsrPlugin_mepc
                                                      : 0U) 
                                                    | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_834)
                                                         ? 
                                                        (((IData)(vlSelfRef.__PVT__CsrPlugin_mcause_interrupt) 
                                                          << 0x1fU) 
                                                         | (IData)(vlSelfRef.__PVT__CsrPlugin_mcause_exceptionCode))
                                                         : 0U) 
                                                       | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_835)
                                                            ? vlSelfRef.__PVT__CsrPlugin_mtval
                                                            : 0U) 
                                                          | (((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_3008)
                                                               ? vlSelfRef.__PVT___zz_CsrPlugin_csrMapping_readDataInit
                                                               : 0U) 
                                                             | ((IData)(vlSelfRef.__PVT__execute_CsrPlugin_csr_4032)
                                                                 ? vlSelfRef.__PVT___zz_externalInterrupt
                                                                 : 0U)))))))));
    vlSelfRef.__PVT__memory_arbitration_flushNext = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong) {
        vlSelfRef.__PVT__memory_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid) {
        vlSelfRef.__PVT__memory_arbitration_flushNext = 1U;
    }
    __Vtableidx13 = (3U & ((IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121) 
                           >> 1U));
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[0U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][0U];
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[1U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][1U];
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[2U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][2U];
    vlSelfRef.__PVT__execute_CsrPlugin_writeInstruction 
        = ((IData)(vlSelfRef.__PVT__when_CsrPlugin_l1587) 
           & (IData)(vlSelfRef.__PVT__decode_to_execute_CSR_WRITE_OPCODE));
    vlSelfRef.__PVT__execute_arbitration_haltItself = 0U;
    if ((1U & ((~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                   >> 7U)) | ((~ (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_flush_ready)) 
                              & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid))))) {
        vlSelfRef.__PVT__execute_arbitration_haltItself = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1587) {
        if (((IData)(vlSelfRef.__PVT__memory_arbitration_isValid) 
             | (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid))) {
            vlSelfRef.__PVT__execute_arbitration_haltItself = 1U;
        }
    }
    __Vtableidx43 = ((((0x40U & ((~ (IData)(vlSelfRef.__PVT__decode_RS2_USE)) 
                                 << 6U)) | ((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l51_2) 
                                            << 5U)) 
                      | ((0x10U & ((~ (IData)(vlSelfRef.__PVT__decode_to_execute_BYPASSABLE_EXECUTE_STAGE)) 
                                   << 4U)) | ((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l45_2) 
                                              << 3U))) 
                     | (((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l51_1) 
                         << 2U) | ((2U & ((~ (IData)(vlSelfRef.__PVT__execute_to_memory_BYPASSABLE_MEMORY_STAGE)) 
                                          << 1U)) | (IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1))));
    vlSelfRef.__PVT__HazardSimplePlugin_src1Hazard 
        = Vsim__ConstPool__TABLE_h8d24d1d2_0[__Vtableidx43];
    vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement = 0U;
    vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA;
    if (vlSelfRef.__PVT__memory_arbitration_isValid) {
        if ((1U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL))) {
            vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT___zz_decode_RS2_3;
        } else if (((2U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL)) 
                    || (3U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL)))) {
            vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT;
        }
    }
    vlSelfRef.__PVT__memory_arbitration_haltItself = 0U;
    if (vlSelfRef.__PVT__when_MulDivIterativePlugin_l128) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_done)))) {
            vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement = 1U;
            vlSelfRef.__PVT__memory_arbitration_haltItself = 1U;
        }
        vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__memory_DivPlugin_div_result;
    }
    __Vtableidx42 = ((((0x40U & ((~ (IData)(vlSelfRef.__PVT__decode_RS1_USE)) 
                                 << 6U)) | ((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l48_2) 
                                            << 5U)) 
                      | ((0x10U & ((~ (IData)(vlSelfRef.__PVT__decode_to_execute_BYPASSABLE_EXECUTE_STAGE)) 
                                   << 4U)) | ((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l45_2) 
                                              << 3U))) 
                     | (((IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l48_1) 
                         << 2U) | ((2U & ((~ (IData)(vlSelfRef.__PVT__execute_to_memory_BYPASSABLE_MEMORY_STAGE)) 
                                          << 1U)) | (IData)(vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1))));
    vlSelfRef.__PVT__HazardSimplePlugin_src0Hazard 
        = Vsim__ConstPool__TABLE_h8d24d1d2_0[__Vtableidx42];
    vlSelfRef.__VdfgRegularize_h1463825b_0_33 = (((
                                                   ((0x4010U 
                                                     == 
                                                     (0x4014U 
                                                      & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                    << 7U) 
                                                   | ((0x2010U 
                                                       == 
                                                       (0x6014U 
                                                        & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                      << 6U)) 
                                                  | (((IData)(vlSelfRef.__PVT__decode_RS1_USE) 
                                                      << 5U) 
                                                     | ((0U 
                                                         == 
                                                         (0x58U 
                                                          & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                                        << 4U))) 
                                                 | (((IData)(vlSelfRef.__PVT__decode_SRC_USE_SUB_LESS) 
                                                     << 3U) 
                                                    | (IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121)));
    vlSelfRef.CsrPlugin_interruptJump = ((IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_valid) 
                                         & (IData)(vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done));
    vlSelfRef.__PVT__execute_FullBarrelShifterPlugin_reversed 
        = ((1U == (IData)(vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL))
            ? ((((((vlSelfRef.__PVT__execute_SRC1 << 0x1fU) 
                   | (0x40000000U & (vlSelfRef.__PVT__execute_SRC1 
                                     << 0x1dU))) | 
                  ((0x20000000U & (vlSelfRef.__PVT__execute_SRC1 
                                   << 0x1bU)) | (0x10000000U 
                                                 & (vlSelfRef.__PVT__execute_SRC1 
                                                    << 0x19U)))) 
                 | (((0x8000000U & (vlSelfRef.__PVT__execute_SRC1 
                                    << 0x17U)) | (0x4000000U 
                                                  & (vlSelfRef.__PVT__execute_SRC1 
                                                     << 0x15U))) 
                    | ((0x2000000U & (vlSelfRef.__PVT__execute_SRC1 
                                      << 0x13U)) | 
                       (0x1000000U & (vlSelfRef.__PVT__execute_SRC1 
                                      << 0x11U))))) 
                | ((((0x800000U & (vlSelfRef.__PVT__execute_SRC1 
                                   << 0xfU)) | (0x400000U 
                                                & (vlSelfRef.__PVT__execute_SRC1 
                                                   << 0xdU))) 
                    | ((0x200000U & (vlSelfRef.__PVT__execute_SRC1 
                                     << 0xbU)) | (0x100000U 
                                                  & (vlSelfRef.__PVT__execute_SRC1 
                                                     << 9U)))) 
                   | (((0x80000U & (vlSelfRef.__PVT__execute_SRC1 
                                    << 7U)) | (0x40000U 
                                               & (vlSelfRef.__PVT__execute_SRC1 
                                                  << 5U))) 
                      | ((0x20000U & (vlSelfRef.__PVT__execute_SRC1 
                                      << 3U)) | (0x10000U 
                                                 & (vlSelfRef.__PVT__execute_SRC1 
                                                    << 1U)))))) 
               | (((((0x8000U & (vlSelfRef.__PVT__execute_SRC1 
                                 >> 1U)) | (0x4000U 
                                            & (vlSelfRef.__PVT__execute_SRC1 
                                               >> 3U))) 
                    | ((0x2000U & (vlSelfRef.__PVT__execute_SRC1 
                                   >> 5U)) | (0x1000U 
                                              & (vlSelfRef.__PVT__execute_SRC1 
                                                 >> 7U)))) 
                   | (((0x800U & (vlSelfRef.__PVT__execute_SRC1 
                                  >> 9U)) | (0x400U 
                                             & (vlSelfRef.__PVT__execute_SRC1 
                                                >> 0xbU))) 
                      | ((0x200U & (vlSelfRef.__PVT__execute_SRC1 
                                    >> 0xdU)) | (0x100U 
                                                 & (vlSelfRef.__PVT__execute_SRC1 
                                                    >> 0xfU))))) 
                  | ((((0x80U & (vlSelfRef.__PVT__execute_SRC1 
                                 >> 0x11U)) | (0x40U 
                                               & (vlSelfRef.__PVT__execute_SRC1 
                                                  >> 0x13U))) 
                      | ((0x20U & (vlSelfRef.__PVT__execute_SRC1 
                                   >> 0x15U)) | (0x10U 
                                                 & (vlSelfRef.__PVT__execute_SRC1 
                                                    >> 0x17U)))) 
                     | (((8U & (vlSelfRef.__PVT__execute_SRC1 
                                >> 0x19U)) | (4U & 
                                              (vlSelfRef.__PVT__execute_SRC1 
                                               >> 0x1bU))) 
                        | ((2U & (vlSelfRef.__PVT__execute_SRC1 
                                  >> 0x1dU)) | (vlSelfRef.__PVT__execute_SRC1 
                                                >> 0x1fU))))))
            : vlSelfRef.__PVT__execute_SRC1);
    vlSelfRef.__PVT__execute_BranchPlugin_eq = (vlSelfRef.__PVT__execute_SRC1 
                                                == vlSelfRef.__PVT__execute_SRC2);
    vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_SRC2_FORCE_ZERO)
            ? vlSelfRef.__PVT__execute_SRC1 : ((vlSelfRef.__PVT__execute_SRC1 
                                                + ((IData)(vlSelfRef.__PVT__decode_to_execute_SRC_USE_SUB_LESS)
                                                    ? 
                                                   (~ vlSelfRef.__PVT__execute_SRC2)
                                                    : vlSelfRef.__PVT__execute_SRC2)) 
                                               + ((IData)(vlSelfRef.__PVT__decode_to_execute_SRC_USE_SUB_LESS)
                                                   ? 1U
                                                   : 0U)));
    vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted 
        = (0xffU & ((0U == (3U & vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA))
                     ? vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data
                     : ((1U == (3U & vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA))
                         ? (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                            >> 8U) : ((2U == (3U & vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA))
                                       ? (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                                          >> 0x10U)
                                       : (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                                          >> 0x18U)))));
}

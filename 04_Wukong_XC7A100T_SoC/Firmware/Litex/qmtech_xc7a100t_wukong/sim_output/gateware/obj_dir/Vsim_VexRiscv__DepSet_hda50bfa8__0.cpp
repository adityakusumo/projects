// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"

VL_INLINE_OPT void Vsim_VexRiscv___ico_sequent__TOP__sim__VexRiscv__0(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___ico_sequent__TOP__sim__VexRiscv__0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload = 0;
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 = 0;
    // Body
    vlSelfRef.__PVT__HazardSimplePlugin_writeBackWrites_valid 
        = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.lastStageIsFiring));
    vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done 
        = vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_2;
    if ((0U != (((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_writeBack) 
                 << 2U) | (((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory) 
                            << 1U) | (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_execute))))) {
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done = 0U;
    }
    if (vlSelfRef.CsrPlugin_hadException) {
        vlSelfRef.__PVT__CsrPlugin_targetPrivilege = 3U;
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done = 0U;
    } else {
        vlSelfRef.__PVT__CsrPlugin_targetPrivilege 
            = vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege;
    }
    vlSelfRef.lastStageRegFileWrite_valid = vlSelfRef.__PVT__HazardSimplePlugin_writeBackWrites_valid;
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_valid = 1U;
    }
    vlSelfRef.CsrPlugin_interruptJump = ((IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_valid) 
                                         & (IData)(vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done));
    vlSelfRef.__PVT__when_CsrPlugin_l1390 = ((IData)(vlSelfRef.CsrPlugin_hadException) 
                                             | (IData)(vlSelfRef.CsrPlugin_interruptJump));
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload = 0U;
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 0U;
    vlSelfRef.__PVT__writeBack_arbitration_flushNext = 0U;
    if (vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid) {
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
            = (((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))
                 ? vlSelfRef.__PVT__CsrPlugin_mtvec_base
                 : 0U) << 2U);
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
        if ((3U == (3U & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                          >> 0x1cU)))) {
            vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
                = vlSelfRef.__PVT__CsrPlugin_mepc;
        }
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
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
    if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
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
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 
        = ((~ ((IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload) 
               - (IData)(1U))) & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 0U;
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 1U;
    }
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
    vlSelfRef.__PVT__decode_arbitration_removeIt = 0U;
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__decode_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_decode;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode = 1U;
    } else {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode 
            = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_decode;
    }
    if (vlSelfRef.__PVT__decode_arbitration_isFlushed) {
        vlSelfRef.__PVT__decode_arbitration_removeIt = 1U;
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_decode = 0U;
    }
    vlSelfRef.__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_6 
        = (((IData)((0U != (0xcU & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1)))) 
            << 1U) | (IData)((0U != (0xaU & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1)))));
    if (vlSelfRef.__PVT__IBusCachedPlugin_jump_pcLoad_valid) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 1U;
    }
    vlSelfRef.__PVT__when_Fetcher_l133 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction) 
                                          | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate));
    vlSelfRef.__PVT__memory_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_removeIt))));
    vlSelfRef.__PVT__execute_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_removeIt))));
    vlSelfRef.__PVT__when_CsrPlugin_l1340 = (1U & (
                                                   (~ (IData)(vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active)) 
                                                   | (IData)(vlSelfRef.__PVT__decode_arbitration_removeIt)));
    vlSelfRef.__PVT__decode_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__decode_arbitration_removeIt))));
    vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_removeIt) 
           | (((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (IData)(vlSelfRef.__PVT__decode_arbitration_flushNext)) 
              | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch)));
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
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_booted));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_fire 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready));
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__0(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__0\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__RegFilePlugin_regFile__v0 = 0U;
    vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_tags__v0 = 0U;
    vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol2__v0 = 0U;
    vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol0__v0 = 0U;
    vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol1__v0 = 0U;
    vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol3__v0 = 0U;
    vlSelfRef.__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter 
        = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter;
    vlSelfRef.__Vdly__CsrPlugin_minstret = vlSelfRef.__PVT__CsrPlugin_minstret;
    vlSelfRef.__Vdly__IBusCachedPlugin_rspCounter = vlSelfRef.__PVT__IBusCachedPlugin_rspCounter;
    vlSelfRef.__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex 
        = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex;
    vlSelfRef.__VdlySet__IBusCachedPlugin_cache__DOT__ways_0_tags__v0 = 0U;
    vlSelfRef.__VdlySet__IBusCachedPlugin_cache__DOT__banks_0__v0 = 0U;
    vlSelfRef.__Vdly___zz_iBusWishbone_ADR = vlSelfRef.__PVT___zz_iBusWishbone_ADR;
    vlSelfRef.__Vdly___zz_dBusWishbone_ADR = vlSelfRef.__PVT___zz_dBusWishbone_ADR;
    vlSelfRef.__Vdly__DBusCachedPlugin_rspCounter = vlSelfRef.__PVT__DBusCachedPlugin_rspCounter;
    vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_start 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_start;
    vlSelfRef.__Vdly__dataCache_1__DOT__loader_error 
        = vlSelfRef.__PVT__dataCache_1__DOT__loader_error;
    vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_waitDone 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_waitDone;
    vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter;
    vlSelfRef.__Vdly__CsrPlugin_mstatus_MPIE = vlSelfRef.__PVT__CsrPlugin_mstatus_MPIE;
    if (vlSelfRef.lastStageRegFileWrite_valid) {
        vlSelfRef.__VdlyVal__RegFilePlugin_regFile__v0 
            = vlSelfRef.lastStageRegFileWrite_payload_data;
        vlSelfRef.__VdlyDim0__RegFilePlugin_regFile__v0 
            = vlSelfRef.lastStageRegFileWrite_payload_address;
        vlSelfRef.__VdlySet__RegFilePlugin_regFile__v0 = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_way) 
         & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid))) {
        vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_tags__v0 
            = ((vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_address 
                << 2U) | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_error) 
                           << 1U) | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_data_valid)));
        vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_tags__v0 
            = vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_payload_address;
        vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_tags__v0 = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask) 
          >> 2U) & (IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_1))) {
        vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol2__v0 
            = (0xffU & (vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
                        >> 0x10U));
        vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol2__v0 
            = vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address;
        vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol2__v0 = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask) 
         & (IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_1))) {
        vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol0__v0 
            = (0xffU & vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data);
        vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol0__v0 
            = vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address;
        vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol0__v0 = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask) 
          >> 1U) & (IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_1))) {
        vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol1__v0 
            = (0xffU & (vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
                        >> 8U));
        vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol1__v0 
            = vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address;
        vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol1__v0 = 1U;
    }
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__2(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__2\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_memory 
        = ((1U & (~ (IData)(vlSelfRef.__PVT__reset))) 
           && ((IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)
                ? (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory)
                : ((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_execute) 
                   & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))));
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_4 = 0U;
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_2 = 0U;
    } else {
        if (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_fill_valid) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid = 1U;
        }
        if (((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid) 
             & (IData)(vlSelfRef.__PVT__iBusWishbone_ACK))) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent = 1U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_4 = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_4 
                = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_4 = 0U;
        }
        if (vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
                vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_2 
                    = vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_1;
            }
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1340) {
            vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_2 = 0U;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_dataReadRsp_0 
            = ((((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_3) 
                 << 0x18U) | ((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_2) 
                              << 0x10U)) | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_1) 
                                             << 8U) 
                                            | (IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read)));
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_error 
            = (1U & (vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tags_port0 
                     >> 1U));
        vlSelfRef.__PVT__memory_to_writeBack_ENV_CTRL 
            = vlSelfRef.__PVT__execute_to_memory_ENV_CTRL;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_dataColisions 
            = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stage0_dataColisions_regNextWhen) 
               | ((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_1) 
                  & (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address) 
                      == (0x3ffU & (vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA 
                                    >> 2U))) & (0U 
                                                != 
                                                ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask) 
                                                 & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageA_mask))))));
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_wayInvalidate 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageA_wayInvalidate;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHitsBeforeInvalidate 
            = (((vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA 
                 >> 0xcU) == (0xfffffU & (vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tags_port0 
                                          >> 2U))) 
               & vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tags_port0);
        vlSelfRef.__PVT__memory_to_writeBack_FORMAL_PC_NEXT 
            = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong)
                ? vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC
                : vlSelfRef.__PVT__execute_to_memory_FORMAL_PC_NEXT);
        vlSelfRef.__PVT__memory_to_writeBack_MUL_LOW 
            = (0xfffffffffffffULL & (((QData)((IData)(vlSelfRef.__PVT__execute_to_memory_MUL_LL)) 
                                      + (((QData)((IData)(
                                                          (3U 
                                                           & (- (IData)(
                                                                        (1U 
                                                                         & (IData)(
                                                                                (1ULL 
                                                                                & (vlSelfRef.__PVT__execute_to_memory_MUL_LH 
                                                                                >> 0x21U))))))))) 
                                          << 0x32U) 
                                         | (0x3ffffffffffffULL 
                                            & (vlSelfRef.__PVT__execute_to_memory_MUL_LH 
                                               << 0x10U)))) 
                                     + (((QData)((IData)(
                                                         (3U 
                                                          & (- (IData)(
                                                                       (1U 
                                                                        & (IData)(
                                                                                (1ULL 
                                                                                & (vlSelfRef.__PVT__execute_to_memory_MUL_HL 
                                                                                >> 0x21U))))))))) 
                                         << 0x32U) 
                                        | (0x3ffffffffffffULL 
                                           & (vlSelfRef.__PVT__execute_to_memory_MUL_HL 
                                              << 0x10U)))));
        vlSelfRef.__PVT__memory_to_writeBack_MEMORY_WR 
            = vlSelfRef.__PVT__execute_to_memory_MEMORY_WR;
    }
    vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValidsRegs_writeBack 
        = ((1U & (~ (IData)(vlSelfRef.__PVT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers))) 
               && ((IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_memory) 
                   & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))));
    if (vlSelfRef.__PVT__when_MulDivIterativePlugin_l128) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_done)))) {
            vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U] 
                = ((1U & (IData)((vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator 
                                  >> 0x20U))) ? (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderShifted)
                    : (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator));
            vlSelfRef.__PVT__memory_DivPlugin_rs1 = 
                ((0x100000000ULL & vlSelfRef.__PVT__memory_DivPlugin_rs1) 
                 | (IData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_outNumerator)));
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U] = 0U;
        vlSelfRef.__PVT__memory_DivPlugin_accumulator[1U] = 0U;
        vlSelfRef.__PVT__memory_DivPlugin_accumulator[2U] = 0U;
        vlSelfRef.__PVT__memory_DivPlugin_rs2 = (((IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs2)
                                                   ? 
                                                  (~ vlSelfRef.__PVT__decode_to_execute_RS2)
                                                   : vlSelfRef.__PVT__decode_to_execute_RS2) 
                                                 + (IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs2));
        vlSelfRef.__PVT__memory_DivPlugin_rs1 = (0x1ffffffffULL 
                                                 & (((IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs1)
                                                      ? 
                                                     (~ vlSelfRef.__PVT___zz_memory_DivPlugin_rs1_1)
                                                      : vlSelfRef.__PVT___zz_memory_DivPlugin_rs1_1) 
                                                    + (QData)((IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs1))));
        vlSelfRef.__PVT__execute_to_memory_IS_DIV = vlSelfRef.__PVT__decode_to_execute_IS_DIV;
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l829) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_refilling = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_allowRead = 1U;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_exception = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_allowWrite = 1U;
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_valid 
            = (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_ways_0_tags_port1 
               & ((0xfffffU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_ways_0_tags_port1 
                               >> 2U)) == (vlSelfRef.IBusCachedPlugin_fetchPc_pcReg 
                                           >> 0xcU)));
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowExecute = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_exception = 0U;
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_last 
            = ((IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) 
               || (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_last));
        if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_address 
                = vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size 
                = vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_mask 
                = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mask;
        } else {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_address 
                = vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_address;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size 
                = vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_size;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_mask 
                = vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_mask;
        }
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        if ((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))) {
            vlSelfRef.__PVT__CsrPlugin_mcause_interrupt 
                = (1U & (~ (IData)(vlSelfRef.CsrPlugin_hadException)));
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
        vlSelfRef.__PVT__decode_to_execute_IS_RS1_SIGNED 
            = (0U == (0x1000U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__decode_to_execute_CSR_READ_OPCODE 
            = (0x20U != (0x7fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                  >> 7U)));
        vlSelfRef.__PVT__decode_to_execute_CSR_WRITE_OPCODE 
            = (1U & (~ (IData)(((0U == (0xf8000U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                & ((1U == (3U & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                 >> 0xdU))) 
                                   | (3U == (3U & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                                   >> 0xdU))))))));
        vlSelfRef.__PVT__decode_to_execute_MEMORY_MANAGMENT 
            = (0x4008U == (0x4048U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_4032 
            = (0xfc0U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_835 
            = (0x343U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_3264 
            = (0xcc0U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_834 
            = (0x342U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__decode_to_execute_SRC2_FORCE_ZERO 
            = ((~ (IData)(vlSelfRef.__PVT__decode_SRC_USE_SUB_LESS)) 
               & (0x24U == (0x64U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_773) {
        if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
            vlSelfRef.__PVT__CsrPlugin_mtvec_base = 
                (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                 >> 2U);
        }
    }
    vlSelfRef.__PVT__CsrPlugin_mip_MSIP = 0U;
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_836) {
        if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
            vlSelfRef.__PVT__CsrPlugin_mip_MSIP = (1U 
                                                   & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                                                      >> 3U));
        }
    }
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__3(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__3\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__CsrPlugin_mie_MEIE = 0U;
        vlSelfRef.__PVT__CsrPlugin_mie_MTIE = 0U;
        vlSelfRef.__PVT__CsrPlugin_mie_MSIE = 0U;
        vlSelfRef.__PVT___zz_CsrPlugin_csrMapping_readDataInit = 0U;
        vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid = 0U;
        vlSelfRef.__PVT__writeBack_arbitration_isValid = 0U;
        vlSelfRef.__PVT__CsrPlugin_mstatus_MPP = 3U;
        vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 0U;
    } else {
        if (vlSelfRef.__PVT__execute_CsrPlugin_csr_772) {
            if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
                vlSelfRef.__PVT__CsrPlugin_mie_MEIE 
                    = (1U & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                             >> 0xbU));
                vlSelfRef.__PVT__CsrPlugin_mie_MTIE 
                    = (1U & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                             >> 7U));
                vlSelfRef.__PVT__CsrPlugin_mie_MSIE 
                    = (1U & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                             >> 3U));
            }
        }
        if (vlSelfRef.__PVT__execute_CsrPlugin_csr_3008) {
            if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
                vlSelfRef.__PVT___zz_CsrPlugin_csrMapping_readDataInit 
                    = vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal;
            }
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush) {
            vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
            vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid 
                = ((IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1) 
                   & (~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush)));
        }
        if ((1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)) 
                   | (IData)(vlSelfRef.__PVT__writeBack_arbitration_removeIt)))) {
            vlSelfRef.__PVT__writeBack_arbitration_isValid = 0U;
        }
        if (vlSelfRef.__PVT__memory_arbitration_isMoving) {
            vlSelfRef.__PVT__writeBack_arbitration_isValid 
                = vlSelfRef.__PVT__memory_arbitration_isValid;
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
            if ((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))) {
                vlSelfRef.__PVT__CsrPlugin_mstatus_MPP = 3U;
            }
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
            if ((3U == (3U & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                              >> 0x1cU)))) {
                vlSelfRef.__PVT__CsrPlugin_mstatus_MPP = 0U;
            }
        }
        if (vlSelfRef.__PVT__execute_CsrPlugin_csr_768) {
            if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
                if ((3U == (3U & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                                  >> 0xbU)))) {
                    vlSelfRef.__PVT__CsrPlugin_mstatus_MPP = 3U;
                }
            }
        }
        vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 0U;
        if (vlSelfRef.__PVT__CsrPlugin_mstatus_MIE) {
            if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302) {
                vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 1U;
            }
            if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_1) {
                vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 1U;
            }
            if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_2) {
                vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 1U;
            }
        }
        if (vlSelfRef.CsrPlugin_interruptJump) {
            vlSelfRef.__PVT__CsrPlugin_interrupt_valid = 0U;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
        vlSelfRef.__PVT__memory_to_writeBack_IS_MUL 
            = vlSelfRef.__PVT__execute_to_memory_IS_MUL;
        vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_VALID 
            = vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_VALID;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_size 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_size;
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_unaligned 
            = (0U != ((((2U == (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_size)) 
                        & (0U != (3U & vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA))) 
                       << 1U) | ((1U == (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_size)) 
                                 & vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA)));
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_wr;
        vlSelfRef.__PVT__memory_to_writeBack_MEMORY_ENABLE 
            = vlSelfRef.__PVT__execute_to_memory_MEMORY_ENABLE;
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_s2_tightlyCoupledHit 
            = vlSelfRef.__PVT__IBusCachedPlugin_s1_tightlyCoupledHit;
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        if ((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))) {
            vlSelfRef.__PVT__CsrPlugin_mepc = vlSelfRef.__PVT__memory_to_writeBack_PC;
            if (vlSelfRef.CsrPlugin_hadException) {
                vlSelfRef.__PVT__CsrPlugin_mcause_exceptionCode 
                    = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code;
                vlSelfRef.__PVT__CsrPlugin_mtval = vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr;
            } else {
                vlSelfRef.__PVT__CsrPlugin_mcause_exceptionCode 
                    = vlSelfRef.CsrPlugin_interrupt_code;
            }
        }
    }
    if (vlSelfRef.__PVT__execute_CsrPlugin_csr_833) {
        if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
            vlSelfRef.__PVT__CsrPlugin_mepc = vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal;
        }
    }
    vlSelfRef.__PVT__HazardSimplePlugin_writeBackBuffer_payload_address 
        = (0x1fU & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                    >> 7U));
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__execute_to_memory_BRANCH_DO 
            = (((IData)(vlSelfRef.__PVT__decode_to_execute_PREDICTION_HAD_BRANCHED2) 
                != (IData)(vlSelfRef.__PVT__execute_BRANCH_COND_RESULT)) 
               | ((IData)(vlSelfRef.__PVT__execute_BRANCH_COND_RESULT) 
                  & ((3U == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL))
                      ? ((vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                          >> 0x15U) ^ (vlSelfRef.__PVT__decode_to_execute_RS1 
                                       >> 1U)) : ((2U 
                                                   == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL))
                                                   ? 
                                                  (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                   >> 0x15U)
                                                   : 
                                                  (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                   >> 8U)))));
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready) {
        if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_uncached 
                = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_data 
                = vlSelfRef.__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF;
        } else {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_uncached 
                = vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_uncached;
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_data 
                = vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_data;
        }
    }
    if (vlSelfRef.__PVT__when_MulDivIterativePlugin_l128) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_done)))) {
            if ((0x20U == (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_value))) {
                vlSelfRef.__PVT__memory_DivPlugin_div_result 
                    = (((IData)(vlSelfRef.__PVT__memory_DivPlugin_div_needRevert)
                         ? (~ vlSelfRef.__PVT___zz_memory_DivPlugin_div_result)
                         : vlSelfRef.__PVT___zz_memory_DivPlugin_div_result) 
                       + (IData)((QData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_div_needRevert))));
            }
        }
    }
    if (vlSelfRef.__PVT__CsrPlugin_mstatus_MIE) {
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302) {
            vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege = 3U;
        }
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_1) {
            vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege = 3U;
        }
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_2) {
            vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege = 3U;
        }
    }
    vlSelfRef.__PVT__dataCache_1__DOT__loader_valid_regNext 
        = vlSelfRef.__PVT__dataCache_1__DOT__loader_valid;
    vlSelfRef.__PVT__CsrPlugin_minstret = vlSelfRef.__Vdly__CsrPlugin_minstret;
    vlSelfRef.__PVT__IBusCachedPlugin_rspCounter = vlSelfRef.__Vdly__IBusCachedPlugin_rspCounter;
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex 
        = vlSelfRef.__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex;
    vlSelfRef.__PVT___zz_iBusWishbone_ADR = vlSelfRef.__Vdly___zz_iBusWishbone_ADR;
    vlSelfRef.__PVT___zz_dBusWishbone_ADR = vlSelfRef.__Vdly___zz_dBusWishbone_ADR;
    vlSelfRef.__PVT__DBusCachedPlugin_rspCounter = vlSelfRef.__Vdly__DBusCachedPlugin_rspCounter;
    if (vlSelfRef.__VdlySet__RegFilePlugin_regFile__v0) {
        vlSelfRef.RegFilePlugin_regFile[vlSelfRef.__VdlyDim0__RegFilePlugin_regFile__v0] 
            = vlSelfRef.__VdlyVal__RegFilePlugin_regFile__v0;
    }
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter 
        = vlSelfRef.__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter;
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__5(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__5\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
        vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL 
            = (3U & (vlSelfRef.__VdfgRegularize_h1463825b_0_31 
                     >> 0x15U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_773 
            = (0x305U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_836 
            = (0x344U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__decode_to_execute_IS_DIV = 
            (0x2004020U == (0x2004064U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_772 
            = (0x304U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_3008 
            = (0xbc0U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__execute_CsrPlugin_csr_833 
            = (0x341U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__decode_to_execute_PREDICTION_HAD_BRANCHED2 
            = vlSelfRef.__PVT__decode_PREDICTION_HAD_BRANCHED2;
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tagsReadRsp_valid) {
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_3 
            = vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol3
            [vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload];
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_2 
            = vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol2
            [vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload];
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read_1 
            = vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol1
            [vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload];
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_datasymbol_read 
            = vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol0
            [vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload];
        vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tags_port0 
            = vlSelfRef.__PVT__dataCache_1__DOT__ways_0_tags
            [((IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsReadCmd_valid)
               ? (0x7fU & (vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
                           >> 5U)) : 0U)];
    }
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderShifted 
        = (((QData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U])) 
            << 1U) | (QData)((IData)((1U & (IData)(
                                                   (vlSelfRef.__PVT__memory_DivPlugin_rs1 
                                                    >> 0x1fU))))));
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_cmdSent)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid));
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3 = 0U;
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_1 = 0U;
        vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1 = 0U;
    } else {
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3 = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3 
                = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_3 = 0U;
        }
        if (vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
                vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_1 
                    = vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_0;
            }
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1340) {
            vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_1 = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush) {
            vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1 = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
            vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1 
                = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt)) 
                   & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid));
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__execute_to_memory_ENV_CTRL 
            = vlSelfRef.__PVT__decode_to_execute_ENV_CTRL;
        vlSelfRef.__PVT__dataCache_1__DOT__stage0_dataColisions_regNextWhen 
            = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_1) 
               & (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address) 
                   == (0x3ffU & (vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
                                 >> 2U))) & (0U != 
                                             ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stage0_mask) 
                                              & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask)))));
        vlSelfRef.__PVT__dataCache_1__DOT__stageA_wayInvalidate = 0U;
        vlSelfRef.__PVT__execute_to_memory_FORMAL_PC_NEXT 
            = vlSelfRef.__PVT__decode_to_execute_FORMAL_PC_NEXT;
        vlSelfRef.__PVT__execute_to_memory_MUL_HL = 
            (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                               & VL_EXTENDS_QI(34,17, vlSelfRef.__PVT__execute_MulPlugin_aHigh)), 
                                          (0x3ffffffffULL 
                                           & VL_EXTENDS_QI(34,17, 
                                                           (0xffffU 
                                                            & vlSelfRef.__PVT__decode_to_execute_RS2)))));
        vlSelfRef.__PVT__execute_to_memory_MUL_LH = 
            (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                               & VL_EXTENDS_QI(34,17, 
                                                               (0xffffU 
                                                                & vlSelfRef.__PVT__decode_to_execute_RS1))), 
                                          (0x3ffffffffULL 
                                           & VL_EXTENDS_QI(34,17, vlSelfRef.__PVT__execute_MulPlugin_bHigh))));
        vlSelfRef.__PVT__execute_to_memory_MUL_LL = 
            ((0xffffU & vlSelfRef.__PVT__decode_to_execute_RS1) 
             * (0xffffU & vlSelfRef.__PVT__decode_to_execute_RS2));
        vlSelfRef.__PVT__execute_to_memory_MEMORY_WR 
            = vlSelfRef.__PVT__decode_to_execute_MEMORY_WR;
        vlSelfRef.__PVT__execute_to_memory_IS_MUL = vlSelfRef.__PVT__decode_to_execute_IS_MUL;
        vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_VALID 
            = vlSelfRef.__PVT__decode_to_execute_REGFILE_WRITE_VALID;
        vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_size 
            = (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                     >> 0xcU));
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_ways_0_tags_port1 
            = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__ways_0_tags
            [(0x7fU & (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc 
                       >> 5U))];
        vlSelfRef.__PVT__IBusCachedPlugin_s1_tightlyCoupledHit = 0U;
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_last = 1U;
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_address 
            = vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address;
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_size 
            = vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size;
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_mask 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mask;
    }
    vlSelfRef.__PVT___zz_dBus_cmd_ready_2 = ((5U != (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_size)) 
                                             | (7U 
                                                == (IData)(vlSelfRef.__PVT___zz_dBusWishbone_ADR)));
    vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_allowExecute)) 
                 | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_exception)));
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits 
        = ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_wayInvalidate)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHitsBeforeInvalidate));
    vlSelfRef.__PVT___zz_externalInterrupt = (vlSelfRef.__PVT___zz_CsrPlugin_csrMapping_readDataInit 
                                              & vlSelfRef.__PVT__externalInterruptArray_regNext);
    if ((1U & ((~ (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack)) 
               & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers))))) {
        vlSelfRef.__PVT__memory_to_writeBack_PC = vlSelfRef.__PVT__execute_to_memory_PC;
    }
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_s2_tightlyCoupledHit)) 
           & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid));
    vlSelfRef.lastStageIsValid = vlSelfRef.__PVT__writeBack_arbitration_isValid;
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45 = 
        ((IData)(vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_VALID) 
         & (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid));
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__6(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__6\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x20U == (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_counter_value))) {
        vlSelfRef.__PVT__memory_DivPlugin_div_done = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageA_request_wr 
            = vlSelfRef.__PVT__decode_to_execute_MEMORY_WR;
        vlSelfRef.__PVT__memory_DivPlugin_div_done = 0U;
        vlSelfRef.__PVT__memory_DivPlugin_div_needRevert 
            = (((IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs1) 
                ^ ((IData)(vlSelfRef.__PVT___zz_memory_DivPlugin_rs2) 
                   & (~ (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                         >> 0xdU)))) & (~ (((0U == vlSelfRef.__PVT__decode_to_execute_RS2) 
                                            & (IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS2_SIGNED)) 
                                           & (~ (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                                 >> 0xdU)))));
    }
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code 
            = ((IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code_1)
                ? (IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_payload_code)
                : 2U);
    }
    if (vlSelfRef.__PVT__execute_arbitration_flushNext) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code 
            = ((IData)(vlSelfRef.__PVT__execute_arbitration_flushNext)
                ? 0xbU : 0U);
    }
    if (vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code = 0U;
    }
    if (vlSelfRef.__PVT__CsrPlugin_mstatus_MIE) {
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302) {
            vlSelfRef.CsrPlugin_interrupt_code = 7U;
        }
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_1) {
            vlSelfRef.CsrPlugin_interrupt_code = 3U;
        }
        if (vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_2) {
            vlSelfRef.CsrPlugin_interrupt_code = 0xbU;
        }
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_uncached 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_code 
            = vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code;
    }
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__dataCache_1__DOT__memCmdSent = 0U;
        vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_waitDone = 0U;
        vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter = 0U;
        vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_start = 1U;
        vlSelfRef.__PVT__dataCache_1__DOT__loader_valid = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator = 1U;
        vlSelfRef.__Vdly__dataCache_1__DOT__loader_error = 0U;
        vlSelfRef.__PVT__dataCache_1__DOT__loader_killReg = 0U;
    } else {
        if (vlSelfRef.__PVT__dataCache_1_io_cpu_flush_ready) {
            vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_waitDone = 0U;
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) 
                           & (~ (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_haltIt))) 
                          & (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers))))) {
            VL_WRITEF_NX("ERROR writeBack stuck by another plugin is not allowed\n",0);
        }
        if (((IData)(vlSelfRef.__PVT__dataCache_1_io_mem_cmd_valid) 
             & (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN))) {
            vlSelfRef.__PVT__dataCache_1__DOT__memCmdSent = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.dataCache_1__DOT____VdfgRegularize_h4c3f712f_0_0)))) {
            vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter)));
            if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l863) {
                vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter 
                    = (0x80U | (IData)(vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter));
            }
        }
        if (vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid) {
            vlSelfRef.__PVT__dataCache_1__DOT__loader_valid = 1U;
        }
        vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value 
            = vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_valueNext;
        if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1125) {
            vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator 
                = (1U & (IData)(vlSelfRef.__PVT__dataCache_1__DOT___zz_loader_waysAllocator));
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
            vlSelfRef.__PVT__dataCache_1__DOT__memCmdSent = 0U;
        }
        vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_start 
            = (((((((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_waitDone)) 
                    & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_start))) 
                   & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid)) 
                  & (~ (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_execute_isValid))) 
                 & (~ ((IData)(vlSelfRef.__PVT__execute_to_memory_MEMORY_ENABLE) 
                       & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid)))) 
                & (~ (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid))) 
               & (~ (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_redo)));
        if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement) {
            vlSelfRef.__Vdly__dataCache_1__DOT__loader_error 
                = vlSelfRef.__PVT__dataCache_1__DOT__loader_error;
        }
        if (vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_start) {
            vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_waitDone = 1U;
            vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter = 0U;
            if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l863) {
                vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter 
                    = (0x7fU & (vlSelfRef.__PVT__decode_to_execute_RS1 
                                >> 5U));
            }
        }
        if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow) {
            vlSelfRef.__PVT__dataCache_1__DOT__loader_valid = 0U;
            vlSelfRef.__Vdly__dataCache_1__DOT__loader_error = 0U;
            vlSelfRef.__PVT__dataCache_1__DOT__loader_killReg = 0U;
        }
    }
    if ((0U != (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code))) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr 
            = ((IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code_1)
                ? (0xfffffffcU & vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload)
                : vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen);
    }
    if (vlSelfRef.__PVT__execute_arbitration_flushNext) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr 
            = vlSelfRef.__PVT__decode_to_execute_INSTRUCTION;
    }
    if (vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr 
            = vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC;
    }
    if (vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid) {
        vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionContext_badAddr 
            = vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA;
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_data 
            = vlSelfRef.__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF;
    }
    vlSelfRef.CsrPlugin_hadException = ((1U & (~ (IData)(vlSelfRef.__PVT__reset))) 
                                        && (IData)(vlSelfRef.__PVT__CsrPlugin_exceptionPortCtrl_exceptionValids_writeBack));
    if (vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol3__v0) {
        vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol3[vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol3__v0] 
            = vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol3__v0;
    }
    if (vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol2__v0) {
        vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol2[vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol2__v0] 
            = vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol2__v0;
    }
    if (vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol1__v0) {
        vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol1[vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol1__v0] 
            = vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol1__v0;
    }
    if (vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_data_symbol0__v0) {
        vlSelfRef.__PVT__dataCache_1__DOT__ways_0_data_symbol0[vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol0__v0] 
            = vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_data_symbol0__v0;
    }
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator 
        = (0x1ffffffffULL & (vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderShifted 
                             - (QData)((IData)(vlSelfRef.__PVT__memory_DivPlugin_rs2))));
    vlSelfRef.__PVT__iBusWishbone_CYC = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_mem_cmd_valid) 
                                         | (0U != (IData)(vlSelfRef.__PVT___zz_iBusWishbone_ADR)));
    if (vlSelfRef.__VdlySet__IBusCachedPlugin_cache__DOT__ways_0_tags__v0) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__ways_0_tags[vlSelfRef.__VdlyDim0__IBusCachedPlugin_cache__DOT__ways_0_tags__v0] 
            = vlSelfRef.__VdlyVal__IBusCachedPlugin_cache__DOT__ways_0_tags__v0;
    }
    if (vlSelfRef.__VdlySet__dataCache_1__DOT__ways_0_tags__v0) {
        vlSelfRef.__PVT__dataCache_1__DOT__ways_0_tags[vlSelfRef.__VdlyDim0__dataCache_1__DOT__ways_0_tags__v0] 
            = vlSelfRef.__VdlyVal__dataCache_1__DOT__ways_0_tags__v0;
    }
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits) 
           | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr));
    vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling));
}

extern const VlUnpacked<VlWide<3>/*71:0*/, 4> Vsim__ConstPool__TABLE_hef978607_0;

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__7(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__7\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx21;
    __Vtableidx21 = 0;
    CData/*1:0*/ __Vtableidx39;
    __Vtableidx39 = 0;
    // Body
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MTIE) 
                                                 & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MTIP));
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_1 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MSIE) 
                                                   & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MSIP));
    vlSelfRef.__PVT___zz_when_CsrPlugin_l1302_2 = ((IData)(vlSelfRef.__PVT__CsrPlugin_mie_MEIE) 
                                                   & (IData)(vlSelfRef.__PVT__CsrPlugin_mip_MEIP));
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_start 
        = vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_start;
    vlSelfRef.__PVT__dataCache_1__DOT__loader_error 
        = vlSelfRef.__Vdly__dataCache_1__DOT__loader_error;
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_waitDone 
        = vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_waitDone;
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter 
        = vlSelfRef.__Vdly__dataCache_1__DOT__stageB_flusher_counter;
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid 
        = ((IData)(vlSelfRef.__PVT__memory_to_writeBack_MEMORY_ENABLE) 
           & (IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid));
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire = 0U;
    if (vlSelfRef.__PVT___zz_iBus_rsp_valid) {
        if ((7U == (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex))) {
            vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_fire = 1U;
        }
    }
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_physicalAddress 
            = vlSelfRef.IBusCachedPlugin_fetchPc_pcReg;
    }
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid = 0U;
        vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2 = 0U;
        vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_0 = 0U;
        vlSelfRef.__PVT__memory_DivPlugin_div_counter_value = 0U;
        vlSelfRef.__PVT__CsrPlugin_mstatus_MIE = 0U;
        vlSelfRef.__PVT__memory_arbitration_isValid = 0U;
    } else {
        if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready) {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rValid 
                = (1U & ((~ (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN)) 
                         | (IData)(vlSelfRef.__PVT__dataCache_1_io_mem_cmd_valid)));
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2 = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2 
                = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_2 = 0U;
        }
        if (vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
                vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_0 = 1U;
            }
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1340) {
            vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_pcValids_0 = 0U;
        }
        vlSelfRef.__PVT__memory_DivPlugin_div_counter_value 
            = vlSelfRef.__PVT__memory_DivPlugin_div_counter_valueNext;
        if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
            if ((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))) {
                vlSelfRef.__PVT__CsrPlugin_mstatus_MIE = 0U;
            }
        }
        if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
            if ((3U == (3U & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                              >> 0x1cU)))) {
                vlSelfRef.__PVT__CsrPlugin_mstatus_MIE 
                    = vlSelfRef.__PVT__CsrPlugin_mstatus_MPIE;
            }
        }
        if (vlSelfRef.__PVT__execute_CsrPlugin_csr_768) {
            if (vlSelfRef.__PVT__execute_CsrPlugin_writeEnable) {
                vlSelfRef.__PVT__CsrPlugin_mstatus_MIE 
                    = (1U & (vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
                             >> 3U));
            }
        }
        if ((1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)) 
                   | (IData)(vlSelfRef.__PVT__memory_arbitration_removeIt)))) {
            vlSelfRef.__PVT__memory_arbitration_isValid = 0U;
        }
        if (vlSelfRef.__PVT__execute_arbitration_isMoving) {
            vlSelfRef.__PVT__memory_arbitration_isValid 
                = vlSelfRef.__PVT__execute_arbitration_isValid;
        }
    }
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_rData_wr 
            = ((IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN)
                ? (IData)(vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr)
                : (IData)(vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_wr));
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
        vlSelfRef.__PVT__decode_to_execute_MEMORY_FORCE_CONSTISTENCY = 0U;
        vlSelfRef.__PVT__decode_to_execute_ENV_CTRL 
            = vlSelfRef.__PVT__decode_ENV_CTRL;
        vlSelfRef.__PVT__decode_to_execute_FORMAL_PC_NEXT 
            = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid)
                ? vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_payload
                : ((IData)(4U) + vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload));
        vlSelfRef.__PVT__decode_to_execute_IS_MUL = 
            (0x2000030U == (0x2004074U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__decode_to_execute_REGFILE_WRITE_VALID 
            = ((0U != (0x1fU & (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                                >> 7U))) & (IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_68));
        vlSelfRef.__PVT__decode_to_execute_MEMORY_WR 
            = (0x20U == (0x20U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__decode_to_execute_IS_RS2_SIGNED 
            = (0U == (0x1000U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
    }
    __Vtableidx21 = vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL;
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][0U];
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][1U];
    vlSelfRef.__PVT__execute_SHIFT_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx21][2U];
    __Vtableidx39 = vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL;
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[0U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][0U];
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[1U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][1U];
    vlSelfRef.__PVT__decode_to_execute_SHIFT_CTRL_string[2U] 
        = Vsim__ConstPool__TABLE_hef978607_0[__Vtableidx39][2U];
    vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_outNumerator 
        = (((IData)(vlSelfRef.__PVT__memory_DivPlugin_rs1) 
            << 1U) | (1U & (~ (IData)((vlSelfRef.__PVT__memory_DivPlugin_div_stage_0_remainderMinusDenominator 
                                       >> 0x20U)))));
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mask 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageA_mask;
        vlSelfRef.__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF 
            = vlSelfRef.__PVT__execute_to_memory_MEMORY_STORE_DATA_RF;
        vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA 
            = vlSelfRef.__PVT___zz_decode_RS2_1;
    }
    vlSelfRef.lastStagePc = vlSelfRef.__PVT__memory_to_writeBack_PC;
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__execute_to_memory_PC = vlSelfRef.__PVT__decode_to_execute_PC;
        vlSelfRef.__PVT__execute_to_memory_MEMORY_ENABLE 
            = vlSelfRef.__PVT__decode_to_execute_MEMORY_ENABLE;
        vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC 
            = (0xfffffffeU & (((3U == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL))
                                ? vlSelfRef.__PVT__decode_to_execute_RS1
                                : vlSelfRef.__PVT__decode_to_execute_PC) 
                              + vlSelfRef.__PVT__execute_BranchPlugin_branch_src2));
    }
    vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__when_InstructionCache_l351 
        = ((~ (((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_s1_tightlyCoupledHit)) 
                & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_input_valid_1)) 
               | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_valid))) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__lineLoader_flushPending));
    vlSelfRef.__PVT__when_IBusCachedPlugin_l250 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1)) 
                                                      & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling)) 
                                                         & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging) 
                                                            & (IData)(vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0)))));
    if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l829) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess 
            = (vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA 
               >> 0x1fU);
    }
    vlSelfRef.__PVT__dataCache_1__DOT___zz_loader_waysAllocator 
        = (3U & (- (IData)((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator))));
    vlSelfRef.dataCache_1__DOT____VdfgRegularize_h4c3f712f_0_0 
        = (1U & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                 >> 7U));
    vlSelfRef.__PVT__dataCache_1_io_cpu_flush_ready 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_waitDone) 
           & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
              >> 7U));
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1125 
        = (1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid)));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement 
        = ((IData)(vlSelfRef.__PVT___zz_dBus_rsp_valid) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid));
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
}

extern const VlUnpacked<CData/*0:0*/, 64> Vsim__ConstPool__TABLE_hb704cd4e_0;

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__8(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__8\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*5:0*/ __Vtableidx46;
    __Vtableidx46 = 0;
    // Body
    vlSelfRef.__PVT__when_IBusCachedPlugin_l256 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l250)) 
                                                      & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_1)) 
                                                         & (~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_valid)))));
    vlSelfRef.__PVT__CsrPlugin_targetPrivilege = ((IData)(vlSelfRef.CsrPlugin_hadException)
                                                   ? 3U
                                                   : (IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_targetPrivilege));
    vlSelfRef.__PVT__CsrPlugin_mstatus_MPIE = vlSelfRef.__Vdly__CsrPlugin_mstatus_MPIE;
    vlSelfRef.__PVT__when_CsrPlugin_l1456 = ((IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid) 
                                             & (1U 
                                                == (IData)(vlSelfRef.__PVT__memory_to_writeBack_ENV_CTRL)));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_valueNext 
        = (7U & ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value) 
                 + (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement)));
    vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow 
        = ((7U == (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willIncrement));
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_mmuException 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loadStoreFault) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging));
    vlSelfRef.CsrPlugin_interruptJump = ((IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_valid) 
                                         & (IData)(vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_done));
    if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rData_wr 
            = vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr;
    }
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1 = 0U;
        vlSelfRef.__PVT__execute_arbitration_isValid = 0U;
    } else {
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1 = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1 
                = vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_0;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_1 = 0U;
        }
        if ((1U & ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
                   | (IData)(vlSelfRef.__PVT__execute_arbitration_removeIt)))) {
            vlSelfRef.__PVT__execute_arbitration_isValid = 0U;
        }
        if (vlSelfRef.__PVT__decode_arbitration_isMoving) {
            vlSelfRef.__PVT__execute_arbitration_isValid 
                = vlSelfRef.__PVT__decode_arbitration_isValid;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__stageA_mask 
            = vlSelfRef.__PVT__dataCache_1__DOT__stage0_mask;
        vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA 
            = vlSelfRef.__PVT___zz_decode_RS2;
        vlSelfRef.__PVT__execute_to_memory_MEMORY_STORE_DATA_RF 
            = ((0U == (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                             >> 0xcU))) ? ((vlSelfRef.__PVT__decode_to_execute_RS2 
                                            << 0x18U) 
                                           | ((0xff0000U 
                                               & (vlSelfRef.__PVT__decode_to_execute_RS2 
                                                  << 0x10U)) 
                                              | ((0xff00U 
                                                  & (vlSelfRef.__PVT__decode_to_execute_RS2 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlSelfRef.__PVT__decode_to_execute_RS2))))
                : ((1U == (3U & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                                 >> 0xcU))) ? ((vlSelfRef.__PVT__decode_to_execute_RS2 
                                                << 0x10U) 
                                               | (0xffffU 
                                                  & vlSelfRef.__PVT__decode_to_execute_RS2))
                    : vlSelfRef.__PVT__decode_to_execute_RS2));
    }
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
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress;
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_size;
    vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache = 0U;
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)
            ? vlSelfRef.__PVT__dBusWishbone_DAT_MISO_regNext
            : vlSelfRef.__PVT__dataCache_1__DOT__stageB_dataReadRsp_0);
    vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_accessError 
        = ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)) 
           & (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits) 
               & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_tagsReadRsp_0_error)) 
              | ((~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isPaging)) 
                 & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loadStoreFault))));
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
    if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
        vlSelfRef.__PVT__execute_CsrPlugin_csr_768 
            = (0x300U == (vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
                          >> 0x14U));
        vlSelfRef.__PVT__decode_to_execute_MEMORY_ENABLE 
            = (0U == (0x58U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen));
        vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL 
            = (3U & (vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_9 
                     >> 0x17U));
        vlSelfRef.__PVT__decode_to_execute_RS1 = vlSelfRef.__PVT__decode_RS1;
        vlSelfRef.__PVT__decode_to_execute_PC = vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload;
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)))) {
        vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
            = vlSelfRef.__PVT__execute_to_memory_INSTRUCTION;
    }
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
    vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_BRANCH_DO) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45_1 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT__when_MulDivIterativePlugin_l128 
        = ((IData)(vlSelfRef.__PVT__execute_to_memory_IS_DIV) 
           & (IData)(vlSelfRef.__PVT__memory_arbitration_isValid));
    vlSelfRef.__PVT__when_CsrPlugin_l1390 = ((IData)(vlSelfRef.CsrPlugin_hadException) 
                                             | (IData)(vlSelfRef.CsrPlugin_interruptJump));
    vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid 
        = ((IData)(vlSelfRef.__PVT__memory_arbitration_isValid) 
           & ((IData)(vlSelfRef.__PVT__execute_to_memory_BRANCH_DO) 
              & (vlSelfRef.__PVT__execute_to_memory_BRANCH_CALC 
                 >> 1U)));
    vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr 
        = vlSelfRef.__PVT__dataCache_1__DOT__stageB_request_wr;
    if (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_isIoAccess)))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009)))) {
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address 
                    = (0xffffffe0U & vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_address);
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_size = 5U;
                vlSelfRef.__PVT__dataCache_1_io_mem_cmd_payload_wr = 0U;
            }
            if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1009) {
                vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache = 1U;
            }
        }
    }
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_fill_valid 
        = ((IData)(vlSelfRef.__PVT__when_IBusCachedPlugin_l256) 
           | ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_refilling)) 
              & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch)));
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__9(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__9\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__when_IBusCachedPlugin_l262 = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_decode_isValid) 
                                                   & ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_issueDetected_3)) 
                                                      & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_hit_error) 
                                                         | ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__decodeStage_mmuRsp_isPaging)) 
                                                            & (IData)(vlSelfRef.IBusCachedPlugin_cache__DOT____VdfgRegularize_h7c702150_0_0)))));
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way = 0U;
    if (vlSelfRef.__PVT__dataCache_1__DOT__stageB_cpuWriteToCache) {
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_mask;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address 
            = (0x3ffU & (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
                         >> 2U));
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
            = vlSelfRef.__PVT__memory_to_writeBack_MEMORY_STORE_DATA_RF;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way 
            = vlSelfRef.__PVT__dataCache_1__DOT__stageB_waysHits;
    }
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
    vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2 
        = (0xffU & ((2U & vlSelfRef.__PVT__memory_to_writeBack_REGFILE_WRITE_DATA)
                     ? (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                        >> 0x18U) : (vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_data 
                                     >> 8U)));
    vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_payload_code = 0U;
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_refilling) 
           | ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_accessError) 
              | ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_mmuException) 
                 | (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_unalignedAccess))));
    vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 0U;
    vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid = 0U;
    vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement = 0U;
    vlSelfRef.__PVT__memory_arbitration_haltItself = 0U;
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 0U;
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
    }
    vlSelfRef.__PVT__memory_arbitration_flushNext = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_decodePrediction_rsp_wasWrong) {
        vlSelfRef.__PVT__memory_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__BranchPlugin_branchExceptionPort_valid) {
        vlSelfRef.__PVT__memory_arbitration_flushNext = 1U;
    }
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_0 = 0U;
    } else {
        if (vlSelfRef.__PVT__dataCache_1_io_mem_cmd_valid) {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN = 0U;
        }
        if (vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_s2mPipe_ready) {
            vlSelfRef.__PVT__toplevel_dataCache_1_io_mem_cmd_rValidN = 1U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_0 = 0U;
        }
        if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
            vlSelfRef.__PVT__IBusCachedPlugin_injector_nextPcCalc_valids_0 = 1U;
        }
    }
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
    vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__execute_to_memory_REGFILE_WRITE_DATA;
    if (vlSelfRef.__PVT__memory_arbitration_isValid) {
        if ((1U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL))) {
            vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT___zz_decode_RS2_3;
        } else if (((2U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL)) 
                    || (3U == (IData)(vlSelfRef.__PVT__execute_to_memory_SHIFT_CTRL)))) {
            vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__execute_to_memory_SHIFT_RIGHT;
        }
    }
    if (vlSelfRef.__PVT__when_MulDivIterativePlugin_l128) {
        if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_DivPlugin_div_done)))) {
            vlSelfRef.__PVT__memory_DivPlugin_div_counter_willIncrement = 1U;
            vlSelfRef.__PVT__memory_arbitration_haltItself = 1U;
        }
        vlSelfRef.__PVT___zz_decode_RS2_1 = vlSelfRef.__PVT__memory_DivPlugin_div_result;
    }
    vlSelfRef.__VdfgRegularize_h1463825b_0_35 = (((IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted_2) 
                                                  << 8U) 
                                                 | (IData)(vlSelfRef.__PVT___zz_writeBack_DBusCachedPlugin_rspShifted));
    vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_flusher_counter) 
                  >> 7U)))) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 1U;
    }
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
            vlSelfRef.__PVT__DBusCachedPlugin_exceptionBus_valid = 0U;
            vlSelfRef.__PVT__DBusCachedPlugin_redoBranch_valid = 1U;
        }
        if (vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l1072) {
            vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 0U;
        }
    }
    if (vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_willOverflow) {
        vlSelfRef.__PVT__dataCache_1__DOT__tagsWriteCmd_valid = 1U;
    }
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
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_mask = 0xfU;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_address 
            = ((0x3f8U & (vlSelfRef.__PVT__dataCache_1__DOT__stageB_mmuRsp_physicalAddress 
                          >> 2U)) | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_counter_value));
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_data 
            = vlSelfRef.__PVT__dBusWishbone_DAT_MISO_regNext;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way 
            = vlSelfRef.__PVT__dataCache_1__DOT__loader_waysAllocator;
        vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid = 1U;
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
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_valid = 1U;
        vlSelfRef.__PVT__writeBack_arbitration_flushNext = 1U;
    }
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
}

extern const VlUnpacked<IData/*31:0*/, 4> Vsim__ConstPool__TABLE_h4deb4691_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h2ce50dca_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsim__ConstPool__TABLE_hc8bc3dde_0;

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__10(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__10\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx17;
    __Vtableidx17 = 0;
    CData/*1:0*/ __Vtableidx41;
    __Vtableidx41 = 0;
    CData/*5:0*/ __Vtableidx45;
    __Vtableidx45 = 0;
    CData/*6:0*/ __Vtableidx47;
    __Vtableidx47 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    // Body
    vlSelfRef.lastStageInstruction = vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION;
    vlSelfRef.lastStageRegFileWrite_payload_address 
        = (0x1fU & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                    >> 7U));
    vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload = 0U;
    if (vlSelfRef.__PVT__when_CsrPlugin_l1390) {
        vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
            = (((3U == (IData)(vlSelfRef.__PVT__CsrPlugin_targetPrivilege))
                 ? vlSelfRef.__PVT__CsrPlugin_mtvec_base
                 : 0U) << 2U);
    }
    if (vlSelfRef.__PVT__when_CsrPlugin_l1456) {
        if ((3U == (3U & (vlSelfRef.__PVT__memory_to_writeBack_INSTRUCTION 
                          >> 0x1cU)))) {
            vlSelfRef.__PVT__CsrPlugin_jumpInterface_payload 
                = vlSelfRef.__PVT__CsrPlugin_mepc;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)))) {
        vlSelfRef.__PVT__execute_to_memory_INSTRUCTION 
            = vlSelfRef.__PVT__decode_to_execute_INSTRUCTION;
    }
    vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_MEMORY_MANAGMENT) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__execute_arbitration_flushNext 
        = ((IData)(vlSelfRef.__PVT__execute_arbitration_isValid) 
           & (2U == (IData)(vlSelfRef.__PVT__decode_to_execute_ENV_CTRL)));
    vlSelfRef.__PVT__when_HazardSimplePlugin_l45_2 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_REGFILE_WRITE_VALID) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__when_CsrPlugin_l1587 = ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_CSR) 
                                             & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    vlSelfRef.__PVT__dataCache_1_io_cpu_execute_isValid 
        = ((IData)(vlSelfRef.__PVT__decode_to_execute_MEMORY_ENABLE) 
           & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid));
    if ((1U & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)))) {
        vlSelfRef.__PVT__decode_to_execute_RS2 = vlSelfRef.__PVT__decode_RS2;
        vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
            = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen;
    }
    __Vtableidx17 = vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL;
    vlSelfRef.__PVT__execute_BRANCH_CTRL_string = Vsim__ConstPool__TABLE_h4deb4691_0
        [__Vtableidx17];
    __Vtableidx41 = vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL;
    vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL_string 
        = Vsim__ConstPool__TABLE_h4deb4691_0[__Vtableidx41];
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs1_1 = (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS1_SIGNED) 
                                                                     & (vlSelfRef.__PVT__decode_to_execute_RS1 
                                                                        >> 0x1fU)))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.__PVT__decode_to_execute_RS1)));
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs1 = ((IData)(vlSelfRef.__PVT__decode_to_execute_IS_DIV) 
                                                 & ((vlSelfRef.__PVT__decode_to_execute_RS1 
                                                     >> 0x1fU) 
                                                    & (IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS1_SIGNED)));
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_payload 
            = vlSelfRef.IBusCachedPlugin_fetchPc_pcReg;
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
    vlSelfRef.__PVT__decode_arbitration_isValid = ((IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready) 
                                                   & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_1_output_m2sPipe_valid));
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
    vlSelfRef.__PVT__dataCache_1__DOT___zz_1 = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_payload_way) 
                                                & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__dataWriteCmd_valid));
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
    vlSelfRef.__PVT__CsrPlugin_pipelineLiberator_active 
        = ((IData)(vlSelfRef.__PVT__CsrPlugin_interrupt_valid) 
           & (IData)(vlSelfRef.__PVT__decode_arbitration_isValid));
    vlSelfRef.lastStageRegFileWrite_payload_data = vlSelfRef.__PVT___zz_decode_RS2_2;
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_payload_address = 0U;
        vlSelfRef.lastStageRegFileWrite_payload_data = 0U;
    }
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
    vlSelfRef.__PVT___zz_memory_DivPlugin_div_result 
        = ((0x2000U & vlSelfRef.__PVT__execute_to_memory_INSTRUCTION)
            ? vlSelfRef.__PVT__memory_DivPlugin_accumulator[0U]
            : (IData)(vlSelfRef.__PVT__memory_DivPlugin_rs1));
    vlSelfRef.__PVT___zz_memory_DivPlugin_rs2 = ((vlSelfRef.__PVT__decode_to_execute_RS2 
                                                  >> 0x1fU) 
                                                 & (IData)(vlSelfRef.__PVT__decode_to_execute_IS_RS2_SIGNED));
    if (vlSelfRef.__PVT__reset) {
        vlSelfRef.IBusCachedPlugin_fetchPc_pcReg = 0U;
    } else if (((IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_booted) 
                & ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready) 
                   | (IData)(vlSelfRef.__PVT__when_Fetcher_l133)))) {
        vlSelfRef.IBusCachedPlugin_fetchPc_pcReg = vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc;
    }
    vlSelfRef.__PVT__memory_arbitration_isStuckByOthers 
        = ((IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_isValid) 
           & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_writeBack_haltIt));
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l829 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers)) 
                 & (~ ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid) 
                       | (IData)(vlSelfRef.__PVT__dataCache_1__DOT__stageB_loaderValid)))));
    vlSelfRef.lastStageIsFiring = ((IData)(vlSelfRef.__PVT__writeBack_arbitration_isValid) 
                                   & ((~ (IData)(vlSelfRef.__PVT__writeBack_arbitration_removeIt)) 
                                      & (~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers))));
}

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__11(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__11\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__memory_arbitration_isStuck = ((IData)(vlSelfRef.__PVT__memory_arbitration_haltItself) 
                                                   | (IData)(vlSelfRef.__PVT__memory_arbitration_isStuckByOthers));
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
    vlSelfRef.__PVT__dataCache_1__DOT__when_DataCache_l863 
        = ((0U != (0x1fU & (vlSelfRef.__PVT__decode_to_execute_INSTRUCTION 
                            >> 0xfU))) & (IData)(vlSelfRef.__PVT__dataCache_1_io_cpu_flush_valid));
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
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen 
            = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_banks_0_port1;
    }
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_booted 
        = (1U & (~ (IData)(vlSelfRef.__PVT__reset)));
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
}

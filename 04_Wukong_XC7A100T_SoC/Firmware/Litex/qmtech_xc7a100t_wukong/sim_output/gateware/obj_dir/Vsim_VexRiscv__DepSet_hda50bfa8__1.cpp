// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__12(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__12\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__CsrPlugin_csrMapping_writeDataSignal 
        = ((0x2000U & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)
            ? ((0x1000U & vlSelfRef.__PVT__decode_to_execute_INSTRUCTION)
                ? ((~ vlSelfRef.__PVT__execute_SRC1) 
                   & vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal)
                : (vlSelfRef.__PVT__CsrPlugin_csrMapping_readDataSignal 
                   | vlSelfRef.__PVT__execute_SRC1))
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
    vlSelfRef.lastStageRegFileWrite_valid = vlSelfRef.__PVT__HazardSimplePlugin_writeBackWrites_valid;
    if (vlSelfRef.__PVT___zz_10) {
        vlSelfRef.lastStageRegFileWrite_valid = 1U;
    }
    vlSelfRef.__PVT__dataCache_1__DOT___zz_ways_0_tagsReadRsp_valid 
        = ((~ (IData)(vlSelfRef.__PVT__memory_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsReadCmd_valid));
    vlSelfRef.__PVT__execute_arbitration_isStuck = 
        ((IData)(vlSelfRef.__PVT__execute_arbitration_haltItself) 
         | (((IData)(vlSelfRef.__PVT__dataCache_1__DOT__loader_valid) 
             & (IData)(vlSelfRef.__PVT__execute_arbitration_isValid)) 
            | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_29)));
    vlSelfRef.__PVT__dataCache_1__DOT__dataReadCmd_payload 
        = ((IData)(vlSelfRef.__PVT__dataCache_1__DOT__tagsReadCmd_valid)
            ? (0x3ffU & (vlSelfRef.__PVT__dataCache_1_io_cpu_execute_address 
                         >> 2U)) : 0U);
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
    if (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_banks_0_port1 
            = vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__banks_0
            [(0x3ffU & (vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pc 
                        >> 2U))];
    }
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
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_flush 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isValid) 
           & (0x1008U == (0x5048U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
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
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121 
        = ((((4U == (0x14U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
             | (0x4050U == (0x4050U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
            << 2U) | ((((4U == (0x44U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                        | (0x4050U == (0x4050U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
                       << 1U) | (0x1008U == (0x5048U 
                                             & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))));
    vlSelfRef.__PVT__decode_RS2_USE = ((0x20U == (0x34U 
                                                  & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                                       | (0x20U == 
                                          (0x64U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)));
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
}

extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h73d03be8_0;
extern const VlUnpacked<VlWide<3>/*95:0*/, 4> Vsim__ConstPool__TABLE_h957f924c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim__ConstPool__TABLE_h8d24d1d2_0;
extern const VlUnpacked<IData/*23:0*/, 4> Vsim__ConstPool__TABLE_hc6edd28f_0;

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__13(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__13\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT___zz_execute_BRANCH_COND_RESULT;
    __PVT___zz_execute_BRANCH_COND_RESULT = 0;
    CData/*1:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    CData/*1:0*/ __Vtableidx13;
    __Vtableidx13 = 0;
    CData/*6:0*/ __Vtableidx42;
    __Vtableidx42 = 0;
    CData/*6:0*/ __Vtableidx43;
    __Vtableidx43 = 0;
    CData/*6:0*/ __Vtableidx44;
    __Vtableidx44 = 0;
    // Body
    vlSelfRef.__PVT__execute_CsrPlugin_writeEnable 
        = ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT__execute_CsrPlugin_writeInstruction));
    vlSelfRef.__PVT__execute_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__execute_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__execute_arbitration_removeIt))));
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
    if (vlSelfRef.__VdlySet__IBusCachedPlugin_cache__DOT__banks_0__v0) {
        vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__banks_0[vlSelfRef.__VdlyDim0__IBusCachedPlugin_cache__DOT__banks_0__v0] 
            = vlSelfRef.__VdlyVal__IBusCachedPlugin_cache__DOT__banks_0__v0;
    }
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
    vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code 
        = ((((~ (IData)(vlSelfRef.__PVT__decode_LEGAL_INSTRUCTION)) 
             & (IData)(vlSelfRef.__PVT__decode_arbitration_isValid)) 
            << 1U) | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_decodeExceptionPort_valid));
    __Vtableidx13 = (3U & ((IData)(vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_121) 
                           >> 1U));
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[0U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][0U];
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[1U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][1U];
    vlSelfRef.__PVT__decode_SRC1_CTRL_string[2U] = 
        Vsim__ConstPool__TABLE_h957f924c_0[__Vtableidx13][2U];
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
    vlSelfRef.__PVT__execute_BRANCH_COND_RESULT = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                   & ((2U 
                                                       == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                      | ((3U 
                                                          == (IData)(vlSelfRef.__PVT__decode_to_execute_BRANCH_CTRL)) 
                                                         | (IData)(__PVT___zz_execute_BRANCH_COND_RESULT))));
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
    vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code_1 
        = (1U & ((~ ((IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code) 
                     - (IData)(1U))) & (IData)(vlSelfRef.__PVT___zz_CsrPlugin_exceptionPortCtrl_exceptionContext_code)));
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
    vlSelfRef.__PVT___zz___05Fzz_decode_IS_RS2_SIGNED_82 
        = ((((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
             | (0x20U == (0x70U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
            << 9U) | ((((4U == (4U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen)) 
                        | (0U == (0x20U & vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen))) 
                       << 8U) | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_33)));
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
    vlSelfRef.__PVT__decode_arbitration_isStuck = ((IData)(vlSelfRef.__PVT__decode_arbitration_haltByOther) 
                                                   | ((IData)(vlSelfRef.__PVT__execute_arbitration_isStuck) 
                                                      | (IData)(vlSelfRef.__VdfgRegularize_h1463825b_0_29)));
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

extern const VlUnpacked<VlWide<3>/*71:0*/, 4> Vsim__ConstPool__TABLE_hef978607_0;
extern const VlUnpacked<IData/*31:0*/, 4> Vsim__ConstPool__TABLE_h4deb4691_0;

VL_INLINE_OPT void Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__14(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___nba_sequent__TOP__sim__VexRiscv__14\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload = 0;
    CData/*3:0*/ __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1;
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 = 0;
    CData/*1:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*1:0*/ __Vtableidx31;
    __Vtableidx31 = 0;
    // Body
    vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetcherHalt)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_booted));
    vlSelfRef.__PVT__decode_arbitration_isMoving = 
        (1U & ((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (~ (IData)(vlSelfRef.__PVT__decode_arbitration_removeIt))));
    vlSelfRef.__PVT__decode_INSTRUCTION_ANTICIPATED 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)
            ? vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT__io_cpu_fetch_data_regNextWhen
            : vlSelfRef.__PVT__IBusCachedPlugin_cache__DOT___zz_banks_0_port1);
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate 
        = ((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
           & (IData)(vlSelfRef.__PVT___zz_IBusCachedPlugin_iBusRsp_stages_2_input_ready));
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
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready 
        = ((~ (IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_haltIt)) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_pcRegPropagate));
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
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_fire 
        = ((IData)(vlSelfRef.__PVT__IBusCachedPlugin_cache_io_cpu_prefetch_isValid) 
           & (IData)(vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_output_ready));
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
    vlSelfRef.__PVT__IBusCachedPlugin_predictionJumpInterface_valid 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_isValid) 
           & (IData)(vlSelfRef.__PVT__decode_PREDICTION_HAD_BRANCHED2));
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
    vlSelfRef.__PVT__IBusCachedPlugin_iBusRsp_flush 
        = ((IData)(vlSelfRef.__PVT__decode_arbitration_removeIt) 
           | (((~ (IData)(vlSelfRef.__PVT__decode_arbitration_isStuck)) 
               & (IData)(vlSelfRef.__PVT__decode_arbitration_flushNext)) 
              | (IData)(vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch)));
    __PVT___zz_IBusCachedPlugin_jump_pcLoad_payload_1 
        = ((~ ((IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload) 
               - (IData)(1U))) & (IData)(__PVT___zz_IBusCachedPlugin_jump_pcLoad_payload));
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 0U;
    vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 0U;
    if (vlSelfRef.__PVT__IBusCachedPlugin_rsp_redoFetch) {
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_flushed = 1U;
        vlSelfRef.__PVT__IBusCachedPlugin_fetchPc_correction = 1U;
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
}

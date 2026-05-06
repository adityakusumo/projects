// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim.h for the primary calling header

#include "Vsim__pch.h"
#include "Vsim_VexRiscv.h"

VL_ATTR_COLD void Vsim_VexRiscv___ctor_var_reset_1(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___ctor_var_reset_1\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_wordIndex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15240623420380068361ull);
    vlSelf->__Vdly__IBusCachedPlugin_cache__DOT__lineLoader_flushCounter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13241526340376875157ull);
    vlSelf->__Vdly__dataCache_1__DOT__stageB_flusher_waitDone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14090595012948818322ull);
    vlSelf->__Vdly__dataCache_1__DOT__stageB_flusher_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17446769321907330618ull);
    vlSelf->__Vdly__dataCache_1__DOT__stageB_flusher_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18397168399730840357ull);
    vlSelf->__Vdly__dataCache_1__DOT__loader_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5990814911345360567ull);
    vlSelf->__VdlyVal__RegFilePlugin_regFile__v0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3957623211695051818ull);
    vlSelf->__VdlyDim0__RegFilePlugin_regFile__v0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3084040502333740183ull);
    vlSelf->__VdlySet__RegFilePlugin_regFile__v0 = 0;
    vlSelf->__VdlyVal__IBusCachedPlugin_cache__DOT__banks_0__v0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18269450633766032961ull);
    vlSelf->__VdlyDim0__IBusCachedPlugin_cache__DOT__banks_0__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 4202199102981472952ull);
    vlSelf->__VdlySet__IBusCachedPlugin_cache__DOT__banks_0__v0 = 0;
    vlSelf->__VdlyVal__IBusCachedPlugin_cache__DOT__ways_0_tags__v0 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 17457909257425033476ull);
    vlSelf->__VdlyDim0__IBusCachedPlugin_cache__DOT__ways_0_tags__v0 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3811726833289273462ull);
    vlSelf->__VdlySet__IBusCachedPlugin_cache__DOT__ways_0_tags__v0 = 0;
    vlSelf->__VdlyVal__dataCache_1__DOT__ways_0_tags__v0 = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 5811650217557142880ull);
    vlSelf->__VdlyDim0__dataCache_1__DOT__ways_0_tags__v0 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 17900002978629523758ull);
    vlSelf->__VdlySet__dataCache_1__DOT__ways_0_tags__v0 = 0;
    vlSelf->__VdlyVal__dataCache_1__DOT__ways_0_data_symbol2__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17133033910215178933ull);
    vlSelf->__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol2__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 12509451006115895702ull);
    vlSelf->__VdlySet__dataCache_1__DOT__ways_0_data_symbol2__v0 = 0;
    vlSelf->__VdlyVal__dataCache_1__DOT__ways_0_data_symbol0__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17978341733733695950ull);
    vlSelf->__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol0__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 10301413319686830083ull);
    vlSelf->__VdlySet__dataCache_1__DOT__ways_0_data_symbol0__v0 = 0;
    vlSelf->__VdlyVal__dataCache_1__DOT__ways_0_data_symbol1__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 345513109110822901ull);
    vlSelf->__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol1__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 5139025180793177959ull);
    vlSelf->__VdlySet__dataCache_1__DOT__ways_0_data_symbol1__v0 = 0;
    vlSelf->__VdlyVal__dataCache_1__DOT__ways_0_data_symbol3__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 176392154940159140ull);
    vlSelf->__VdlyDim0__dataCache_1__DOT__ways_0_data_symbol3__v0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9585716651219540506ull);
    vlSelf->__VdlySet__dataCache_1__DOT__ways_0_data_symbol3__v0 = 0;
}

VL_ATTR_COLD void Vsim_VexRiscv___ctor_var_reset_0(Vsim_VexRiscv* vlSelf);

VL_ATTR_COLD void Vsim_VexRiscv___ctor_var_reset(Vsim_VexRiscv* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_VexRiscv___ctor_var_reset\n"); );
    Vsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsim_VexRiscv___ctor_var_reset_0(vlSelf);
    Vsim_VexRiscv___ctor_var_reset_1(vlSelf);
}

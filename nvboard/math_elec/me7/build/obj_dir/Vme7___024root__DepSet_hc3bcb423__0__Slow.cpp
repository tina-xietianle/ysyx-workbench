// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme7.h for the primary calling header

#include "verilated.h"

#include "Vme7___024root.h"

VL_ATTR_COLD void Vme7___024root___eval_static(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vme7___024root___eval_initial__TOP(Vme7___024root* vlSelf);

VL_ATTR_COLD void Vme7___024root___eval_initial(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_initial\n"); );
    // Body
    Vme7___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__ps2_clk = vlSelf->ps2_clk;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vme7___024root___eval_initial__TOP(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->me7__DOT__count = 0U;
    vlSelf->me7__DOT__state = 0U;
    vlSelf->me7__DOT__flag = 0U;
    vlSelf->xian3 = 0x3fffU;
}

VL_ATTR_COLD void Vme7___024root___eval_final(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vme7___024root___eval_triggers__stl(Vme7___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme7___024root___dump_triggers__stl(Vme7___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vme7___024root___eval_stl(Vme7___024root* vlSelf);

VL_ATTR_COLD void Vme7___024root___eval_settle(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vme7___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vme7___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me7/vsrc/me7.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vme7___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vme7___024root___dump_triggers__stl(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*7:0*/, 256> Vme7__ConstPool__TABLE_h56039e0d_0;

VL_ATTR_COLD void Vme7___024root___stl_sequent__TOP__0(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0dad6d82__0;
    me7__DOT__two__DOT____VdfgTmp_h0dad6d82__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_he5f23ad2__0;
    me7__DOT__two__DOT____VdfgTmp_he5f23ad2__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hc6383fdc__0;
    me7__DOT__two__DOT____VdfgTmp_hc6383fdc__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0ce55c0c__0;
    me7__DOT__two__DOT____VdfgTmp_h0ce55c0c__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h62484482__0;
    me7__DOT__two__DOT____VdfgTmp_h62484482__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h50a4b07f__0;
    me7__DOT__two__DOT____VdfgTmp_h50a4b07f__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hba4b7945__0;
    me7__DOT__two__DOT____VdfgTmp_hba4b7945__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_had1ba820__0;
    me7__DOT__two__DOT____VdfgTmp_had1ba820__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h57d55214__0;
    me7__DOT__two__DOT____VdfgTmp_h57d55214__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hf9ed8658__0;
    me7__DOT__two__DOT____VdfgTmp_hf9ed8658__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hf0b094ca__0;
    me7__DOT__two__DOT____VdfgTmp_hf0b094ca__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_ha05db24d__0;
    me7__DOT__two__DOT____VdfgTmp_ha05db24d__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h8520a34c__0;
    me7__DOT__two__DOT____VdfgTmp_h8520a34c__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hac91d8d1__0;
    me7__DOT__two__DOT____VdfgTmp_hac91d8d1__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h0b8eb8cb__0;
    me7__DOT__two__DOT____VdfgTmp_h0b8eb8cb__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_h27208e0a__0;
    me7__DOT__two__DOT____VdfgTmp_h27208e0a__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_had7bfc82__0;
    me7__DOT__two__DOT____VdfgTmp_had7bfc82__0 = 0;
    CData/*0:0*/ me7__DOT__two__DOT____VdfgTmp_hac748cac__0;
    me7__DOT__two__DOT____VdfgTmp_hac748cac__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hede0c227__0;
    me7__DOT__three__DOT____VdfgTmp_hede0c227__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hf71681aa__0;
    me7__DOT__three__DOT____VdfgTmp_hf71681aa__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h34fc6167__0;
    me7__DOT__three__DOT____VdfgTmp_h34fc6167__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h37c9d5f5__0;
    me7__DOT__three__DOT____VdfgTmp_h37c9d5f5__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h1c342157__0;
    me7__DOT__three__DOT____VdfgTmp_h1c342157__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hdd3649dd__0;
    me7__DOT__three__DOT____VdfgTmp_hdd3649dd__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0dad6d82__0;
    me7__DOT__three__DOT____VdfgTmp_h0dad6d82__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h15732fc1__0;
    me7__DOT__three__DOT____VdfgTmp_h15732fc1__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h60ae9ad8__0;
    me7__DOT__three__DOT____VdfgTmp_h60ae9ad8__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h1997ee49__0;
    me7__DOT__three__DOT____VdfgTmp_h1997ee49__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h1e156eb1__0;
    me7__DOT__three__DOT____VdfgTmp_h1e156eb1__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h5171ac0e__0;
    me7__DOT__three__DOT____VdfgTmp_h5171ac0e__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_he5f23ad2__0;
    me7__DOT__three__DOT____VdfgTmp_he5f23ad2__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hc6383fdc__0;
    me7__DOT__three__DOT____VdfgTmp_hc6383fdc__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h13ade830__0;
    me7__DOT__three__DOT____VdfgTmp_h13ade830__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h5499cb8d__0;
    me7__DOT__three__DOT____VdfgTmp_h5499cb8d__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h84cc0607__0;
    me7__DOT__three__DOT____VdfgTmp_h84cc0607__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h406caffd__0;
    me7__DOT__three__DOT____VdfgTmp_h406caffd__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h60dc900e__0;
    me7__DOT__three__DOT____VdfgTmp_h60dc900e__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h71eca00a__0;
    me7__DOT__three__DOT____VdfgTmp_h71eca00a__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h68b33184__0;
    me7__DOT__three__DOT____VdfgTmp_h68b33184__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h47a1452d__0;
    me7__DOT__three__DOT____VdfgTmp_h47a1452d__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0ce55c0c__0;
    me7__DOT__three__DOT____VdfgTmp_h0ce55c0c__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h92ee800c__0;
    me7__DOT__three__DOT____VdfgTmp_h92ee800c__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h3e8bdc5b__0;
    me7__DOT__three__DOT____VdfgTmp_h3e8bdc5b__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h5f4cce94__0;
    me7__DOT__three__DOT____VdfgTmp_h5f4cce94__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hb2ac9dc4__0;
    me7__DOT__three__DOT____VdfgTmp_hb2ac9dc4__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h78a13ad2__0;
    me7__DOT__three__DOT____VdfgTmp_h78a13ad2__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h62484482__0;
    me7__DOT__three__DOT____VdfgTmp_h62484482__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h50a4b07f__0;
    me7__DOT__three__DOT____VdfgTmp_h50a4b07f__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h7d356b2e__0;
    me7__DOT__three__DOT____VdfgTmp_h7d356b2e__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0e57f19f__0;
    me7__DOT__three__DOT____VdfgTmp_h0e57f19f__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hba4b7945__0;
    me7__DOT__three__DOT____VdfgTmp_hba4b7945__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_had1ba820__0;
    me7__DOT__three__DOT____VdfgTmp_had1ba820__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h57d55214__0;
    me7__DOT__three__DOT____VdfgTmp_h57d55214__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0e6a3af6__0;
    me7__DOT__three__DOT____VdfgTmp_h0e6a3af6__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hf9ed8658__0;
    me7__DOT__three__DOT____VdfgTmp_hf9ed8658__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hf0b094ca__0;
    me7__DOT__three__DOT____VdfgTmp_hf0b094ca__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_ha05db24d__0;
    me7__DOT__three__DOT____VdfgTmp_ha05db24d__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h30b18abd__0;
    me7__DOT__three__DOT____VdfgTmp_h30b18abd__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h8520a34c__0;
    me7__DOT__three__DOT____VdfgTmp_h8520a34c__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hac91d8d1__0;
    me7__DOT__three__DOT____VdfgTmp_hac91d8d1__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0b8eb8cb__0;
    me7__DOT__three__DOT____VdfgTmp_h0b8eb8cb__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h0e7e1c84__0;
    me7__DOT__three__DOT____VdfgTmp_h0e7e1c84__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h27208e0a__0;
    me7__DOT__three__DOT____VdfgTmp_h27208e0a__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_had7bfc82__0;
    me7__DOT__three__DOT____VdfgTmp_had7bfc82__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_hac748cac__0;
    me7__DOT__three__DOT____VdfgTmp_hac748cac__0 = 0;
    CData/*0:0*/ me7__DOT__three__DOT____VdfgTmp_h224682a9__0;
    me7__DOT__three__DOT____VdfgTmp_h224682a9__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0dad6d82__0;
    me7__DOT__five__DOT____VdfgTmp_h0dad6d82__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_he5f23ad2__0;
    me7__DOT__five__DOT____VdfgTmp_he5f23ad2__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hc6383fdc__0;
    me7__DOT__five__DOT____VdfgTmp_hc6383fdc__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0ce55c0c__0;
    me7__DOT__five__DOT____VdfgTmp_h0ce55c0c__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h62484482__0;
    me7__DOT__five__DOT____VdfgTmp_h62484482__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h50a4b07f__0;
    me7__DOT__five__DOT____VdfgTmp_h50a4b07f__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hba4b7945__0;
    me7__DOT__five__DOT____VdfgTmp_hba4b7945__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_had1ba820__0;
    me7__DOT__five__DOT____VdfgTmp_had1ba820__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h57d55214__0;
    me7__DOT__five__DOT____VdfgTmp_h57d55214__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hf9ed8658__0;
    me7__DOT__five__DOT____VdfgTmp_hf9ed8658__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hf0b094ca__0;
    me7__DOT__five__DOT____VdfgTmp_hf0b094ca__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_ha05db24d__0;
    me7__DOT__five__DOT____VdfgTmp_ha05db24d__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h8520a34c__0;
    me7__DOT__five__DOT____VdfgTmp_h8520a34c__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hac91d8d1__0;
    me7__DOT__five__DOT____VdfgTmp_hac91d8d1__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h0b8eb8cb__0;
    me7__DOT__five__DOT____VdfgTmp_h0b8eb8cb__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_h27208e0a__0;
    me7__DOT__five__DOT____VdfgTmp_h27208e0a__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_had7bfc82__0;
    me7__DOT__five__DOT____VdfgTmp_had7bfc82__0 = 0;
    CData/*0:0*/ me7__DOT__five__DOT____VdfgTmp_hac748cac__0;
    me7__DOT__five__DOT____VdfgTmp_hac748cac__0 = 0;
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    me7__DOT__three__DOT____VdfgTmp_ha05db24d__0 = (IData)(
                                                           (0x80U 
                                                            == 
                                                            (0xc0U 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__three__DOT____VdfgTmp_hac748cac__0 = (IData)(
                                                           (8U 
                                                            == 
                                                            (0xcU 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__two__DOT____VdfgTmp_ha05db24d__0 = (IData)(
                                                         (0x80U 
                                                          == 
                                                          (0xc0U 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__two__DOT____VdfgTmp_hac748cac__0 = (IData)(
                                                         (8U 
                                                          == 
                                                          (0xcU 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__three__DOT____VdfgTmp_hba4b7945__0 = (IData)(
                                                           (0U 
                                                            == 
                                                            (0xc0U 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__three__DOT____VdfgTmp_had1ba820__0 = (IData)(
                                                           (0x40U 
                                                            == 
                                                            (0xc0U 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__three__DOT____VdfgTmp_h8520a34c__0 = (IData)(
                                                           (0U 
                                                            == 
                                                            (0xcU 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__three__DOT____VdfgTmp_hac91d8d1__0 = (IData)(
                                                           (4U 
                                                            == 
                                                            (0xcU 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__two__DOT____VdfgTmp_hba4b7945__0 = (IData)(
                                                         (0U 
                                                          == 
                                                          (0xc0U 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__two__DOT____VdfgTmp_had1ba820__0 = (IData)(
                                                         (0x40U 
                                                          == 
                                                          (0xc0U 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__two__DOT____VdfgTmp_h8520a34c__0 = (IData)(
                                                         (0U 
                                                          == 
                                                          (0xcU 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__two__DOT____VdfgTmp_hac91d8d1__0 = (IData)(
                                                         (4U 
                                                          == 
                                                          (0xcU 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__three__DOT____VdfgTmp_h57d55214__0 = (IData)(
                                                           (0xc0U 
                                                            == 
                                                            (0xc0U 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__three__DOT____VdfgTmp_h0b8eb8cb__0 = (IData)(
                                                           (0xcU 
                                                            == 
                                                            (0xcU 
                                                             & (IData)(vlSelf->me7__DOT__count))));
    me7__DOT__two__DOT____VdfgTmp_h57d55214__0 = (IData)(
                                                         (0xc0U 
                                                          == 
                                                          (0xc0U 
                                                           & (IData)(vlSelf->data))));
    me7__DOT__two__DOT____VdfgTmp_h0b8eb8cb__0 = (IData)(
                                                         (0xcU 
                                                          == 
                                                          (0xcU 
                                                           & (IData)(vlSelf->data))));
    __Vtableidx1 = vlSelf->data;
    vlSelf->ascii = Vme7__ConstPool__TABLE_h56039e0d_0
        [__Vtableidx1];
    me7__DOT__three__DOT____VdfgTmp_h1997ee49__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_ha05db24d__0) 
         & (IData)((0x10U == (0x30U & (IData)(vlSelf->me7__DOT__count)))));
    me7__DOT__three__DOT____VdfgTmp_h5171ac0e__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_ha05db24d__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 5U));
    me7__DOT__three__DOT____VdfgTmp_h5f4cce94__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hac748cac__0) 
         & (IData)((1U == (3U & (IData)(vlSelf->me7__DOT__count)))));
    me7__DOT__three__DOT____VdfgTmp_h78a13ad2__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hac748cac__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 1U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1997ee49__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_ha05db24d__0) 
           & (IData)((0x10U == (0x30U & (IData)(vlSelf->data)))));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5171ac0e__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_ha05db24d__0) 
           & ((IData)(vlSelf->data) >> 5U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5f4cce94__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_hac748cac__0) 
           & (IData)((1U == (3U & (IData)(vlSelf->data)))));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h78a13ad2__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_hac748cac__0) 
           & ((IData)(vlSelf->data) >> 1U));
    me7__DOT__three__DOT____VdfgTmp_hf9ed8658__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hba4b7945__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 5U));
    me7__DOT__three__DOT____VdfgTmp_hede0c227__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 5U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_hba4b7945__0));
    me7__DOT__three__DOT____VdfgTmp_h13ade830__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_had1ba820__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 5U));
    me7__DOT__three__DOT____VdfgTmp_hf0b094ca__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 5U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_had1ba820__0));
    me7__DOT__three__DOT____VdfgTmp_h27208e0a__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h8520a34c__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 1U));
    me7__DOT__three__DOT____VdfgTmp_h84cc0607__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 1U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_h8520a34c__0));
    me7__DOT__three__DOT____VdfgTmp_h7d356b2e__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hac91d8d1__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 1U));
    me7__DOT__three__DOT____VdfgTmp_had7bfc82__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 1U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_hac91d8d1__0));
    me7__DOT__two__DOT____VdfgTmp_hf9ed8658__0 = ((IData)(me7__DOT__two__DOT____VdfgTmp_hba4b7945__0) 
                                                  & ((IData)(vlSelf->data) 
                                                     >> 5U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hede0c227__0 
        = ((~ ((IData)(vlSelf->data) >> 5U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_hba4b7945__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h13ade830__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_had1ba820__0) 
           & ((IData)(vlSelf->data) >> 5U));
    me7__DOT__two__DOT____VdfgTmp_hf0b094ca__0 = ((~ 
                                                   ((IData)(vlSelf->data) 
                                                    >> 5U)) 
                                                  & (IData)(me7__DOT__two__DOT____VdfgTmp_had1ba820__0));
    me7__DOT__two__DOT____VdfgTmp_h27208e0a__0 = ((IData)(me7__DOT__two__DOT____VdfgTmp_h8520a34c__0) 
                                                  & ((IData)(vlSelf->data) 
                                                     >> 1U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h84cc0607__0 
        = ((~ ((IData)(vlSelf->data) >> 1U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_h8520a34c__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h7d356b2e__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_hac91d8d1__0) 
           & ((IData)(vlSelf->data) >> 1U));
    me7__DOT__two__DOT____VdfgTmp_had7bfc82__0 = ((~ 
                                                   ((IData)(vlSelf->data) 
                                                    >> 1U)) 
                                                  & (IData)(me7__DOT__two__DOT____VdfgTmp_hac91d8d1__0));
    me7__DOT__three__DOT____VdfgTmp_h0e6a3af6__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 5U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_h57d55214__0));
    me7__DOT__three__DOT____VdfgTmp_h30b18abd__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h57d55214__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 5U));
    me7__DOT__three__DOT____VdfgTmp_h0e7e1c84__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 1U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_h0b8eb8cb__0));
    me7__DOT__three__DOT____VdfgTmp_h224682a9__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h0b8eb8cb__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 1U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e6a3af6__0 
        = ((~ ((IData)(vlSelf->data) >> 5U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_h57d55214__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h30b18abd__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_h57d55214__0) 
           & ((IData)(vlSelf->data) >> 5U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e7e1c84__0 
        = ((~ ((IData)(vlSelf->data) >> 1U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_h0b8eb8cb__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h224682a9__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_h0b8eb8cb__0) 
           & ((IData)(vlSelf->data) >> 1U));
    me7__DOT__five__DOT____VdfgTmp_ha05db24d__0 = (IData)(
                                                          (0x80U 
                                                           == 
                                                           (0xc0U 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_hac748cac__0 = (IData)(
                                                          (8U 
                                                           == 
                                                           (0xcU 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_hba4b7945__0 = (IData)(
                                                          (0U 
                                                           == 
                                                           (0xc0U 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_had1ba820__0 = (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0xc0U 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_h8520a34c__0 = (IData)(
                                                          (0U 
                                                           == 
                                                           (0xcU 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_hac91d8d1__0 = (IData)(
                                                          (4U 
                                                           == 
                                                           (0xcU 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_h57d55214__0 = (IData)(
                                                          (0xc0U 
                                                           == 
                                                           (0xc0U 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__five__DOT____VdfgTmp_h0b8eb8cb__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & (IData)(vlSelf->ascii))));
    me7__DOT__three__DOT____VdfgTmp_h5499cb8d__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h5171ac0e__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h0e57f19f__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h78a13ad2__0) 
         & (IData)(vlSelf->me7__DOT__count));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5499cb8d__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5171ac0e__0) 
           & ((IData)(vlSelf->data) >> 4U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e57f19f__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h78a13ad2__0) 
           & (IData)(vlSelf->data));
    me7__DOT__three__DOT____VdfgTmp_h1c342157__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 4U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_hf9ed8658__0));
    me7__DOT__three__DOT____VdfgTmp_hdd3649dd__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hf9ed8658__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_hf71681aa__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hede0c227__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h34fc6167__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h13ade830__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h60ae9ad8__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hf0b094ca__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h15732fc1__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 4U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_hf0b094ca__0));
    me7__DOT__three__DOT____VdfgTmp_h68b33184__0 = 
        ((~ (IData)(vlSelf->me7__DOT__count)) & (IData)(me7__DOT__three__DOT____VdfgTmp_h27208e0a__0));
    me7__DOT__three__DOT____VdfgTmp_h47a1452d__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h27208e0a__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__three__DOT____VdfgTmp_h406caffd__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h84cc0607__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__three__DOT____VdfgTmp_h60dc900e__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h7d356b2e__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__three__DOT____VdfgTmp_h3e8bdc5b__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_had7bfc82__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__three__DOT____VdfgTmp_h92ee800c__0 = 
        ((~ (IData)(vlSelf->me7__DOT__count)) & (IData)(me7__DOT__three__DOT____VdfgTmp_had7bfc82__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1c342157__0 
        = ((~ ((IData)(vlSelf->data) >> 4U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_hf9ed8658__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hdd3649dd__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_hf9ed8658__0) 
           & ((IData)(vlSelf->data) >> 4U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hede0c227__0) 
           & ((IData)(vlSelf->data) >> 4U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h13ade830__0) 
           & ((IData)(vlSelf->data) >> 4U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h60ae9ad8__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_hf0b094ca__0) 
           & ((IData)(vlSelf->data) >> 4U));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h15732fc1__0 
        = ((~ ((IData)(vlSelf->data) >> 4U)) & (IData)(me7__DOT__two__DOT____VdfgTmp_hf0b094ca__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h68b33184__0 
        = ((~ (IData)(vlSelf->data)) & (IData)(me7__DOT__two__DOT____VdfgTmp_h27208e0a__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h47a1452d__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_h27208e0a__0) 
           & (IData)(vlSelf->data));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h84cc0607__0) 
           & (IData)(vlSelf->data));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h7d356b2e__0) 
           & (IData)(vlSelf->data));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h3e8bdc5b__0 
        = ((IData)(me7__DOT__two__DOT____VdfgTmp_had7bfc82__0) 
           & (IData)(vlSelf->data));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h92ee800c__0 
        = ((~ (IData)(vlSelf->data)) & (IData)(me7__DOT__two__DOT____VdfgTmp_had7bfc82__0));
    me7__DOT__three__DOT____VdfgTmp_h0dad6d82__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h0e6a3af6__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h37c9d5f5__0 = 
        ((~ ((IData)(vlSelf->me7__DOT__count) >> 4U)) 
         & (IData)(me7__DOT__three__DOT____VdfgTmp_h0e6a3af6__0));
    me7__DOT__three__DOT____VdfgTmp_he5f23ad2__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h30b18abd__0) 
         & ((IData)(vlSelf->me7__DOT__count) >> 4U));
    me7__DOT__three__DOT____VdfgTmp_h0ce55c0c__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h0e7e1c84__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__three__DOT____VdfgTmp_h71eca00a__0 = 
        ((~ (IData)(vlSelf->me7__DOT__count)) & (IData)(me7__DOT__three__DOT____VdfgTmp_h0e7e1c84__0));
    me7__DOT__three__DOT____VdfgTmp_h62484482__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h224682a9__0) 
         & (IData)(vlSelf->me7__DOT__count));
    me7__DOT__two__DOT____VdfgTmp_h0dad6d82__0 = (1U 
                                                  & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e6a3af6__0) 
                                                        & ((IData)(vlSelf->data) 
                                                           >> 4U))));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h37c9d5f5__0 
        = ((~ ((IData)(vlSelf->data) >> 4U)) & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e6a3af6__0));
    me7__DOT__two__DOT____VdfgTmp_he5f23ad2__0 = (1U 
                                                  & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h30b18abd__0) 
                                                        & ((IData)(vlSelf->data) 
                                                           >> 4U))));
    me7__DOT__two__DOT____VdfgTmp_h0ce55c0c__0 = (1U 
                                                  & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e7e1c84__0) 
                                                        & (IData)(vlSelf->data))));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h71eca00a__0 
        = ((~ (IData)(vlSelf->data)) & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e7e1c84__0));
    me7__DOT__two__DOT____VdfgTmp_h62484482__0 = (1U 
                                                  & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h224682a9__0) 
                                                        & (IData)(vlSelf->data))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1997ee49__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_ha05db24d__0) 
           & (IData)((0x10U == (0x30U & (IData)(vlSelf->ascii)))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5171ac0e__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_ha05db24d__0) 
           & ((IData)(vlSelf->ascii) >> 5U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5f4cce94__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_hac748cac__0) 
           & (IData)((1U == (3U & (IData)(vlSelf->ascii)))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h78a13ad2__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_hac748cac__0) 
           & ((IData)(vlSelf->ascii) >> 1U));
    me7__DOT__five__DOT____VdfgTmp_hf9ed8658__0 = ((IData)(me7__DOT__five__DOT____VdfgTmp_hba4b7945__0) 
                                                   & ((IData)(vlSelf->ascii) 
                                                      >> 5U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hede0c227__0 
        = ((~ ((IData)(vlSelf->ascii) >> 5U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_hba4b7945__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h13ade830__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_had1ba820__0) 
           & ((IData)(vlSelf->ascii) >> 5U));
    me7__DOT__five__DOT____VdfgTmp_hf0b094ca__0 = (
                                                   (~ 
                                                    ((IData)(vlSelf->ascii) 
                                                     >> 5U)) 
                                                   & (IData)(me7__DOT__five__DOT____VdfgTmp_had1ba820__0));
    me7__DOT__five__DOT____VdfgTmp_h27208e0a__0 = ((IData)(me7__DOT__five__DOT____VdfgTmp_h8520a34c__0) 
                                                   & ((IData)(vlSelf->ascii) 
                                                      >> 1U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h84cc0607__0 
        = ((~ ((IData)(vlSelf->ascii) >> 1U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_h8520a34c__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h7d356b2e__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_hac91d8d1__0) 
           & ((IData)(vlSelf->ascii) >> 1U));
    me7__DOT__five__DOT____VdfgTmp_had7bfc82__0 = (
                                                   (~ 
                                                    ((IData)(vlSelf->ascii) 
                                                     >> 1U)) 
                                                   & (IData)(me7__DOT__five__DOT____VdfgTmp_hac91d8d1__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e6a3af6__0 
        = ((~ ((IData)(vlSelf->ascii) >> 5U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_h57d55214__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h30b18abd__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_h57d55214__0) 
           & ((IData)(vlSelf->ascii) >> 5U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e7e1c84__0 
        = ((~ ((IData)(vlSelf->ascii) >> 1U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_h0b8eb8cb__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h224682a9__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_h0b8eb8cb__0) 
           & ((IData)(vlSelf->ascii) >> 1U));
    me7__DOT__three__DOT____VdfgTmp_h1e156eb1__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_hf71681aa__0) 
         | (IData)(me7__DOT__three__DOT____VdfgTmp_h15732fc1__0));
    me7__DOT__three__DOT____VdfgTmp_hb2ac9dc4__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h406caffd__0) 
         | (IData)(me7__DOT__three__DOT____VdfgTmp_h92ee800c__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1e156eb1__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0) 
           | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h15732fc1__0));
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hb2ac9dc4__0 
        = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0) 
           | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h92ee800c__0));
    me7__DOT__three__DOT____VdfgTmp_hc6383fdc__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h37c9d5f5__0) 
         | (((~ ((IData)(vlSelf->me7__DOT__count) >> 4U)) 
             & (IData)(me7__DOT__three__DOT____VdfgTmp_h30b18abd__0)) 
            | (IData)(me7__DOT__three__DOT____VdfgTmp_he5f23ad2__0)));
    me7__DOT__three__DOT____VdfgTmp_h50a4b07f__0 = 
        ((IData)(me7__DOT__three__DOT____VdfgTmp_h71eca00a__0) 
         | (((~ (IData)(vlSelf->me7__DOT__count)) & (IData)(me7__DOT__three__DOT____VdfgTmp_h224682a9__0)) 
            | (IData)(me7__DOT__three__DOT____VdfgTmp_h62484482__0)));
    me7__DOT__two__DOT____VdfgTmp_hc6383fdc__0 = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h37c9d5f5__0) 
                                                  | (((~ 
                                                       ((IData)(vlSelf->data) 
                                                        >> 4U)) 
                                                      & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h30b18abd__0)) 
                                                     | (IData)(me7__DOT__two__DOT____VdfgTmp_he5f23ad2__0)));
    me7__DOT__two__DOT____VdfgTmp_h50a4b07f__0 = ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h71eca00a__0) 
                                                  | (((~ (IData)(vlSelf->data)) 
                                                      & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h224682a9__0)) 
                                                     | (IData)(me7__DOT__two__DOT____VdfgTmp_h62484482__0)));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5499cb8d__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5171ac0e__0) 
           & ((IData)(vlSelf->ascii) >> 4U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e57f19f__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h78a13ad2__0) 
           & (IData)(vlSelf->ascii));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1c342157__0 
        = ((~ ((IData)(vlSelf->ascii) >> 4U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_hf9ed8658__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hdd3649dd__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_hf9ed8658__0) 
           & ((IData)(vlSelf->ascii) >> 4U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hede0c227__0) 
           & ((IData)(vlSelf->ascii) >> 4U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h13ade830__0) 
           & ((IData)(vlSelf->ascii) >> 4U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h60ae9ad8__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_hf0b094ca__0) 
           & ((IData)(vlSelf->ascii) >> 4U));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h15732fc1__0 
        = ((~ ((IData)(vlSelf->ascii) >> 4U)) & (IData)(me7__DOT__five__DOT____VdfgTmp_hf0b094ca__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h68b33184__0 
        = ((~ (IData)(vlSelf->ascii)) & (IData)(me7__DOT__five__DOT____VdfgTmp_h27208e0a__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h47a1452d__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_h27208e0a__0) 
           & (IData)(vlSelf->ascii));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h84cc0607__0) 
           & (IData)(vlSelf->ascii));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h7d356b2e__0) 
           & (IData)(vlSelf->ascii));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h3e8bdc5b__0 
        = ((IData)(me7__DOT__five__DOT____VdfgTmp_had7bfc82__0) 
           & (IData)(vlSelf->ascii));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h92ee800c__0 
        = ((~ (IData)(vlSelf->ascii)) & (IData)(me7__DOT__five__DOT____VdfgTmp_had7bfc82__0));
    me7__DOT__five__DOT____VdfgTmp_h0dad6d82__0 = (1U 
                                                   & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e6a3af6__0) 
                                                         & ((IData)(vlSelf->ascii) 
                                                            >> 4U))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h37c9d5f5__0 
        = ((~ ((IData)(vlSelf->ascii) >> 4U)) & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e6a3af6__0));
    me7__DOT__five__DOT____VdfgTmp_he5f23ad2__0 = (1U 
                                                   & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h30b18abd__0) 
                                                         & ((IData)(vlSelf->ascii) 
                                                            >> 4U))));
    me7__DOT__five__DOT____VdfgTmp_h0ce55c0c__0 = (1U 
                                                   & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e7e1c84__0) 
                                                         & (IData)(vlSelf->ascii))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h71eca00a__0 
        = ((~ (IData)(vlSelf->ascii)) & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e7e1c84__0));
    me7__DOT__five__DOT____VdfgTmp_h62484482__0 = (1U 
                                                   & ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h224682a9__0) 
                                                         & (IData)(vlSelf->ascii))));
    vlSelf->xian2 = (((((~ ((IData)(vlSelf->me7__DOT__count) 
                            >> 4U)) & (IData)(me7__DOT__three__DOT____VdfgTmp_hede0c227__0)) 
                       | ((IData)(me7__DOT__three__DOT____VdfgTmp_hf71681aa__0) 
                          | ((IData)(me7__DOT__three__DOT____VdfgTmp_h34fc6167__0) 
                             | (IData)(me7__DOT__three__DOT____VdfgTmp_h37c9d5f5__0)))) 
                      << 0xdU) | ((((IData)(me7__DOT__three__DOT____VdfgTmp_hf71681aa__0) 
                                    | ((IData)(me7__DOT__three__DOT____VdfgTmp_h1c342157__0) 
                                       | ((IData)(me7__DOT__three__DOT____VdfgTmp_hdd3649dd__0) 
                                          | ((IData)(me7__DOT__three__DOT____VdfgTmp_h34fc6167__0) 
                                             | (IData)(me7__DOT__three__DOT____VdfgTmp_h0dad6d82__0))))) 
                                   << 0xcU) | ((((IData)(me7__DOT__three__DOT____VdfgTmp_hf71681aa__0) 
                                                 | ((IData)(me7__DOT__three__DOT____VdfgTmp_hdd3649dd__0) 
                                                    | ((IData)(me7__DOT__three__DOT____VdfgTmp_h15732fc1__0) 
                                                       | ((IData)(me7__DOT__three__DOT____VdfgTmp_h60ae9ad8__0) 
                                                          | ((IData)(me7__DOT__three__DOT____VdfgTmp_h34fc6167__0) 
                                                             | (IData)(me7__DOT__three__DOT____VdfgTmp_h1997ee49__0)))))) 
                                                << 0xbU) 
                                               | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h1e156eb1__0) 
                                                    | ((IData)(me7__DOT__three__DOT____VdfgTmp_h34fc6167__0) 
                                                       | ((IData)(me7__DOT__three__DOT____VdfgTmp_h1997ee49__0) 
                                                          | (((~ 
                                                               ((IData)(vlSelf->me7__DOT__count) 
                                                                >> 4U)) 
                                                              & (IData)(me7__DOT__three__DOT____VdfgTmp_h5171ac0e__0)) 
                                                             | (IData)(me7__DOT__three__DOT____VdfgTmp_he5f23ad2__0))))) 
                                                   << 0xaU) 
                                                  | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h1c342157__0) 
                                                       | (IData)(me7__DOT__three__DOT____VdfgTmp_hc6383fdc__0)) 
                                                      << 9U) 
                                                     | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h60ae9ad8__0) 
                                                          | (((~ 
                                                               ((IData)(vlSelf->me7__DOT__count) 
                                                                >> 4U)) 
                                                              & (IData)(me7__DOT__three__DOT____VdfgTmp_h13ade830__0)) 
                                                             | ((IData)(me7__DOT__three__DOT____VdfgTmp_h5499cb8d__0) 
                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_hc6383fdc__0)))) 
                                                         << 8U) 
                                                        | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h1e156eb1__0) 
                                                             | ((IData)(me7__DOT__three__DOT____VdfgTmp_h5499cb8d__0) 
                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_h0dad6d82__0))) 
                                                            << 7U) 
                                                           | (((((~ (IData)(vlSelf->me7__DOT__count)) 
                                                                 & (IData)(me7__DOT__three__DOT____VdfgTmp_h84cc0607__0)) 
                                                                | ((IData)(me7__DOT__three__DOT____VdfgTmp_h406caffd__0) 
                                                                   | ((IData)(me7__DOT__three__DOT____VdfgTmp_h60dc900e__0) 
                                                                      | (IData)(me7__DOT__three__DOT____VdfgTmp_h71eca00a__0)))) 
                                                               << 6U) 
                                                              | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h406caffd__0) 
                                                                   | ((IData)(me7__DOT__three__DOT____VdfgTmp_h68b33184__0) 
                                                                      | ((IData)(me7__DOT__three__DOT____VdfgTmp_h47a1452d__0) 
                                                                         | ((IData)(me7__DOT__three__DOT____VdfgTmp_h60dc900e__0) 
                                                                            | (IData)(me7__DOT__three__DOT____VdfgTmp_h0ce55c0c__0))))) 
                                                                  << 5U) 
                                                                 | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h406caffd__0) 
                                                                      | ((IData)(me7__DOT__three__DOT____VdfgTmp_h47a1452d__0) 
                                                                         | ((IData)(me7__DOT__three__DOT____VdfgTmp_h92ee800c__0) 
                                                                            | ((IData)(me7__DOT__three__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                               | ((IData)(me7__DOT__three__DOT____VdfgTmp_h60dc900e__0) 
                                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_h5f4cce94__0)))))) 
                                                                     << 4U) 
                                                                    | ((((IData)(me7__DOT__three__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                         | ((IData)(me7__DOT__three__DOT____VdfgTmp_h60dc900e__0) 
                                                                            | ((IData)(me7__DOT__three__DOT____VdfgTmp_h5f4cce94__0) 
                                                                               | (((~ (IData)(vlSelf->me7__DOT__count)) 
                                                                                & (IData)(me7__DOT__three__DOT____VdfgTmp_h78a13ad2__0)) 
                                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_h62484482__0))))) 
                                                                        << 3U) 
                                                                       | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h68b33184__0) 
                                                                            | (IData)(me7__DOT__three__DOT____VdfgTmp_h50a4b07f__0)) 
                                                                           << 2U) 
                                                                          | ((((IData)(me7__DOT__three__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                               | (((~ (IData)(vlSelf->me7__DOT__count)) 
                                                                                & (IData)(me7__DOT__three__DOT____VdfgTmp_h7d356b2e__0)) 
                                                                                | ((IData)(me7__DOT__three__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_h50a4b07f__0)))) 
                                                                              << 1U) 
                                                                             | ((IData)(me7__DOT__three__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                                | ((IData)(me7__DOT__three__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__three__DOT____VdfgTmp_h0ce55c0c__0))))))))))))))));
    vlSelf->xian = ((0x2000U & ((((~ ((IData)(vlSelf->data) 
                                      >> 4U)) & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hede0c227__0)) 
                                 | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0) 
                                    | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0) 
                                       | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                          | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h37c9d5f5__0))))) 
                                << 0xdU)) | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0) 
                                               | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1c342157__0) 
                                                  | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hdd3649dd__0) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0) 
                                                        | (IData)(me7__DOT__two__DOT____VdfgTmp_h0dad6d82__0))))) 
                                              << 0xcU) 
                                             | ((0x800U 
                                                 & (((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hdd3649dd__0) 
                                                        | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h15732fc1__0) 
                                                           | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60ae9ad8__0) 
                                                              | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0) 
                                                                 | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                    | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1997ee49__0))))))) 
                                                    << 0xbU)) 
                                                | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1e156eb1__0) 
                                                     | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0) 
                                                        | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1997ee49__0) 
                                                           | (((~ 
                                                                ((IData)(vlSelf->data) 
                                                                 >> 4U)) 
                                                               & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5171ac0e__0)) 
                                                              | (IData)(me7__DOT__two__DOT____VdfgTmp_he5f23ad2__0))))) 
                                                    << 0xaU) 
                                                   | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1c342157__0) 
                                                        | (IData)(me7__DOT__two__DOT____VdfgTmp_hc6383fdc__0)) 
                                                       << 9U) 
                                                      | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60ae9ad8__0) 
                                                           | (((~ 
                                                                ((IData)(vlSelf->data) 
                                                                 >> 4U)) 
                                                               & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h13ade830__0)) 
                                                              | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5499cb8d__0) 
                                                                 | (IData)(me7__DOT__two__DOT____VdfgTmp_hc6383fdc__0)))) 
                                                          << 8U) 
                                                         | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h1e156eb1__0) 
                                                              | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5499cb8d__0) 
                                                                 | (IData)(me7__DOT__two__DOT____VdfgTmp_h0dad6d82__0))) 
                                                             << 7U) 
                                                            | ((0x40U 
                                                                & ((((~ (IData)(vlSelf->data)) 
                                                                     & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h84cc0607__0)) 
                                                                    | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0) 
                                                                       | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0) 
                                                                          | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                             | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h71eca00a__0))))) 
                                                                   << 6U)) 
                                                               | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0) 
                                                                    | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h68b33184__0) 
                                                                       | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h47a1452d__0) 
                                                                          | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0) 
                                                                             | (IData)(me7__DOT__two__DOT____VdfgTmp_h0ce55c0c__0))))) 
                                                                   << 5U) 
                                                                  | ((0x10U 
                                                                      & (((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0) 
                                                                          | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h47a1452d__0) 
                                                                             | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h92ee800c__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0) 
                                                                                | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                                | (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5f4cce94__0))))))) 
                                                                         << 4U)) 
                                                                     | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                          | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0) 
                                                                             | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h5f4cce94__0) 
                                                                                | (((~ (IData)(vlSelf->data)) 
                                                                                & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h78a13ad2__0)) 
                                                                                | (IData)(me7__DOT__two__DOT____VdfgTmp_h62484482__0))))) 
                                                                         << 3U) 
                                                                        | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h68b33184__0) 
                                                                             | (IData)(me7__DOT__two__DOT____VdfgTmp_h50a4b07f__0)) 
                                                                            << 2U) 
                                                                           | ((((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                                | (((~ (IData)(vlSelf->data)) 
                                                                                & (IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h7d356b2e__0)) 
                                                                                | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__two__DOT____VdfgTmp_h50a4b07f__0)))) 
                                                                               << 1U) 
                                                                              | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__two__DOT____VdfgTmp_h0ce55c0c__0))))))))))))))));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1e156eb1__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0) 
           | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h15732fc1__0));
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hb2ac9dc4__0 
        = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0) 
           | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h92ee800c__0));
    me7__DOT__five__DOT____VdfgTmp_hc6383fdc__0 = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h37c9d5f5__0) 
                                                   | (((~ 
                                                        ((IData)(vlSelf->ascii) 
                                                         >> 4U)) 
                                                       & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h30b18abd__0)) 
                                                      | (IData)(me7__DOT__five__DOT____VdfgTmp_he5f23ad2__0)));
    me7__DOT__five__DOT____VdfgTmp_h50a4b07f__0 = ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h71eca00a__0) 
                                                   | (((~ (IData)(vlSelf->ascii)) 
                                                       & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h224682a9__0)) 
                                                      | (IData)(me7__DOT__five__DOT____VdfgTmp_h62484482__0)));
    vlSelf->xian4 = ((0x2000U & ((((~ ((IData)(vlSelf->ascii) 
                                       >> 4U)) & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hede0c227__0)) 
                                  | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0) 
                                     | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0) 
                                        | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                           | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h37c9d5f5__0))))) 
                                 << 0xdU)) | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0) 
                                                | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1c342157__0) 
                                                   | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hdd3649dd__0) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0) 
                                                         | (IData)(me7__DOT__five__DOT____VdfgTmp_h0dad6d82__0))))) 
                                               << 0xcU) 
                                              | ((0x800U 
                                                  & (((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hdd3649dd__0) 
                                                         | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h15732fc1__0) 
                                                            | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60ae9ad8__0) 
                                                               | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0) 
                                                                  | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                     | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1997ee49__0))))))) 
                                                     << 0xbU)) 
                                                 | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1e156eb1__0) 
                                                      | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0) 
                                                         | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1997ee49__0) 
                                                            | (((~ 
                                                                 ((IData)(vlSelf->ascii) 
                                                                  >> 4U)) 
                                                                & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5171ac0e__0)) 
                                                               | (IData)(me7__DOT__five__DOT____VdfgTmp_he5f23ad2__0))))) 
                                                     << 0xaU) 
                                                    | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1c342157__0) 
                                                         | (IData)(me7__DOT__five__DOT____VdfgTmp_hc6383fdc__0)) 
                                                        << 9U) 
                                                       | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60ae9ad8__0) 
                                                            | (((~ 
                                                                 ((IData)(vlSelf->ascii) 
                                                                  >> 4U)) 
                                                                & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h13ade830__0)) 
                                                               | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5499cb8d__0) 
                                                                  | (IData)(me7__DOT__five__DOT____VdfgTmp_hc6383fdc__0)))) 
                                                           << 8U) 
                                                          | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h1e156eb1__0) 
                                                               | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5499cb8d__0) 
                                                                  | (IData)(me7__DOT__five__DOT____VdfgTmp_h0dad6d82__0))) 
                                                              << 7U) 
                                                             | ((0x40U 
                                                                 & ((((~ (IData)(vlSelf->ascii)) 
                                                                      & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h84cc0607__0)) 
                                                                     | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0) 
                                                                        | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0) 
                                                                           | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                              | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h71eca00a__0))))) 
                                                                    << 6U)) 
                                                                | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0) 
                                                                     | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h68b33184__0) 
                                                                        | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h47a1452d__0) 
                                                                           | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0) 
                                                                              | (IData)(me7__DOT__five__DOT____VdfgTmp_h0ce55c0c__0))))) 
                                                                    << 5U) 
                                                                   | ((0x10U 
                                                                       & (((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0) 
                                                                           | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h47a1452d__0) 
                                                                              | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h92ee800c__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0) 
                                                                                | ((~ (IData)(vlSelf->me7__DOT__state)) 
                                                                                | (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5f4cce94__0))))))) 
                                                                          << 4U)) 
                                                                      | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                           | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0) 
                                                                              | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h5f4cce94__0) 
                                                                                | (((~ (IData)(vlSelf->ascii)) 
                                                                                & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h78a13ad2__0)) 
                                                                                | (IData)(me7__DOT__five__DOT____VdfgTmp_h62484482__0))))) 
                                                                          << 3U) 
                                                                         | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h68b33184__0) 
                                                                              | (IData)(me7__DOT__five__DOT____VdfgTmp_h50a4b07f__0)) 
                                                                             << 2U) 
                                                                            | ((((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h3e8bdc5b__0) 
                                                                                | (((~ (IData)(vlSelf->ascii)) 
                                                                                & (IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h7d356b2e__0)) 
                                                                                | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__five__DOT____VdfgTmp_h50a4b07f__0)))) 
                                                                                << 1U) 
                                                                               | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_hb2ac9dc4__0) 
                                                                                | ((IData)(vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e57f19f__0) 
                                                                                | (IData)(me7__DOT__five__DOT____VdfgTmp_h0ce55c0c__0))))))))))))))));
}

VL_ATTR_COLD void Vme7___024root___eval_stl(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vme7___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vme7___024root___dump_triggers__act(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ps2_clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vme7___024root___dump_triggers__nba(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ps2_clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vme7___024root___ctor_var_reset(Vme7___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme7__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme7___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->ps2_clk = 0;
    vlSelf->ps2_data = 0;
    vlSelf->data = 0;
    vlSelf->xian = 0;
    vlSelf->xian2 = 0;
    vlSelf->xian3 = 0;
    vlSelf->ascii = 0;
    vlSelf->xian4 = 0;
    vlSelf->me7__DOT__count = 0;
    vlSelf->me7__DOT__flag = 0;
    vlSelf->me7__DOT__state = 0;
    vlSelf->me7__DOT__next_state = 0;
    vlSelf->me7__DOT__one__DOT__count = 0;
    vlSelf->me7__DOT__one__DOT__ps2_clk_sync = 0;
    vlSelf->me7__DOT__one__DOT__buffer = 0;
    vlSelf->me7__DOT__one__DOT____Vlvbound_h1a91ade8__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hede0c227__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hf71681aa__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h34fc6167__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h37c9d5f5__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1c342157__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hdd3649dd__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h15732fc1__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h60ae9ad8__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1997ee49__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h1e156eb1__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5171ac0e__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h13ade830__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5499cb8d__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h84cc0607__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h406caffd__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h60dc900e__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h71eca00a__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h68b33184__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h47a1452d__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h92ee800c__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h3e8bdc5b__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h5f4cce94__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_hb2ac9dc4__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h78a13ad2__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h7d356b2e__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e57f19f__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e6a3af6__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h30b18abd__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h0e7e1c84__0 = 0;
    vlSelf->me7__DOT__two__DOT____VdfgTmp_h224682a9__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hede0c227__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hf71681aa__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h34fc6167__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h37c9d5f5__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1c342157__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hdd3649dd__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h15732fc1__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h60ae9ad8__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1997ee49__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h1e156eb1__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5171ac0e__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h13ade830__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5499cb8d__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h84cc0607__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h406caffd__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h60dc900e__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h71eca00a__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h68b33184__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h47a1452d__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h92ee800c__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h3e8bdc5b__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h5f4cce94__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_hb2ac9dc4__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h78a13ad2__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h7d356b2e__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e57f19f__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e6a3af6__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h30b18abd__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h0e7e1c84__0 = 0;
    vlSelf->me7__DOT__five__DOT____VdfgTmp_h224682a9__0 = 0;
    vlSelf->__Vdly__me7__DOT__one__DOT__ps2_clk_sync = 0;
    vlSelf->__Vdly__me7__DOT__one__DOT__count = 0;
    vlSelf->__Vtrigrprev__TOP__ps2_clk = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090010_exu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24090010_exu___024root.h"

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_static(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_initial(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ifu__DOT__next_pc 
        = vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ins 
        = vlSelf->ysyx_24090010_exu__DOT__ins;
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_final(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_triggers__stl(Vysyx_24090010_exu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__stl(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_stl(Vysyx_24090010_exu___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_settle(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_24090010_exu___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24090010_exu___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_exu.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_24090010_exu___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__stl(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24090010_exu___024root___stl_sequent__TOP__0(Vysyx_24090010_exu___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24090010_exu___024root___eval_stl(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_24090010_exu___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__ico(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__act(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] ysyx_24090010_exu.ifu.next_pc or [changed] ysyx_24090010_exu.ins)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__nba(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] ysyx_24090010_exu.ifu.next_pc or [changed] ysyx_24090010_exu.ins)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24090010_exu___024root___ctor_var_reset(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->ysyx_24090010_exu__DOT__imm = 0;
    vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0;
    vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0;
    vlSelf->ysyx_24090010_exu__DOT__csr_en_ = 0;
    vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0;
    vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 0;
    vlSelf->ysyx_24090010_exu__DOT__strb = 0;
    vlSelf->ysyx_24090010_exu__DOT__mtvec = 0;
    vlSelf->ysyx_24090010_exu__DOT__mcause = 0;
    vlSelf->ysyx_24090010_exu__DOT__mepc = 0;
    vlSelf->ysyx_24090010_exu__DOT__mstatus = 0;
    vlSelf->ysyx_24090010_exu__DOT__pc = 0;
    vlSelf->ysyx_24090010_exu__DOT__result_reg = 0;
    vlSelf->ysyx_24090010_exu__DOT__result_ram = 0;
    vlSelf->ysyx_24090010_exu__DOT__rdata1 = 0;
    vlSelf->ysyx_24090010_exu__DOT__ram_rdata = 0;
    vlSelf->ysyx_24090010_exu__DOT__ins = 0;
    vlSelf->ysyx_24090010_exu__DOT__ins_type = 0;
    vlSelf->ysyx_24090010_exu__DOT__ram_addr = 0;
    vlSelf->ysyx_24090010_exu__DOT__pc_jump = 0;
    vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc = 0;
    vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc = 0;
    vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__count = 0;
    vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[__Vi0] = 0;
    }
    vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag = 0;
    vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vfunc_vaddr_ifetch_v__0__Vfuncout = 0;
    vlSelf->__Vfunc_vaddr_read_v__11__Vfuncout = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    vlSelf->__Vtrigrprev__TOP__rst = 0;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ifu__DOT__next_pc = 0;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ins = 0;
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

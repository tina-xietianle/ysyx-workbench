// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme1.h for the primary calling header

#include "verilated.h"

#include "Vme1___024root.h"

VL_INLINE_OPT void Vme1___024root___ico_sequent__TOP__0(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ me1__DOT__i0__DOT__i0__DOT__lut_out;
    me1__DOT__i0__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ me1__DOT__i0__DOT__i0__DOT__hit;
    me1__DOT__i0__DOT__i0__DOT__hit = 0;
    // Body
    vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = (3U & ((IData)(vlSelf->a) >> 6U));
    vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = (3U & ((IData)(vlSelf->a) >> 4U));
    vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = (3U & ((IData)(vlSelf->a) >> 2U));
    vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = (3U & (IData)(vlSelf->a));
    me1__DOT__i0__DOT__i0__DOT__lut_out = ((- (IData)(
                                                      ((IData)(vlSelf->s) 
                                                       == 
                                                       vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                                       [0U]))) 
                                           & vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list
                                           [0U]);
    me1__DOT__i0__DOT__i0__DOT__hit = ((IData)(vlSelf->s) 
                                       == vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                       [0U]);
    me1__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(me1__DOT__i0__DOT__i0__DOT__lut_out) 
                                           | ((- (IData)(
                                                         ((IData)(vlSelf->s) 
                                                          == 
                                                          vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                                          [1U]))) 
                                              & vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list
                                              [1U]));
    me1__DOT__i0__DOT__i0__DOT__hit = ((IData)(me1__DOT__i0__DOT__i0__DOT__hit) 
                                       | ((IData)(vlSelf->s) 
                                          == vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                          [1U]));
    me1__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(me1__DOT__i0__DOT__i0__DOT__lut_out) 
                                           | ((- (IData)(
                                                         ((IData)(vlSelf->s) 
                                                          == 
                                                          vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                                          [2U]))) 
                                              & vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list
                                              [2U]));
    me1__DOT__i0__DOT__i0__DOT__hit = ((IData)(me1__DOT__i0__DOT__i0__DOT__hit) 
                                       | ((IData)(vlSelf->s) 
                                          == vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                          [2U]));
    me1__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(me1__DOT__i0__DOT__i0__DOT__lut_out) 
                                           | ((- (IData)(
                                                         ((IData)(vlSelf->s) 
                                                          == 
                                                          vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                                          [3U]))) 
                                              & vlSelf->me1__DOT__i0__DOT__i0__DOT__data_list
                                              [3U]));
    me1__DOT__i0__DOT__i0__DOT__hit = ((IData)(me1__DOT__i0__DOT__i0__DOT__hit) 
                                       | ((IData)(vlSelf->s) 
                                          == vlSelf->me1__DOT__i0__DOT__i0__DOT__key_list
                                          [3U]));
    vlSelf->y = ((IData)(me1__DOT__i0__DOT__i0__DOT__hit)
                  ? (IData)(me1__DOT__i0__DOT__i0__DOT__lut_out)
                  : 0U);
}

void Vme1___024root___eval_ico(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vme1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vme1___024root___eval_act(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___eval_act\n"); );
}

void Vme1___024root___eval_nba(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___eval_nba\n"); );
}

void Vme1___024root___eval_triggers__ico(Vme1___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme1___024root___dump_triggers__ico(Vme1___024root* vlSelf);
#endif  // VL_DEBUG
void Vme1___024root___eval_triggers__act(Vme1___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme1___024root___dump_triggers__act(Vme1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme1___024root___dump_triggers__nba(Vme1___024root* vlSelf);
#endif  // VL_DEBUG

void Vme1___024root___eval(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vme1___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vme1___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me1/vsrc/me1.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vme1___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vme1___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vme1___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me1/vsrc/me1.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vme1___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vme1___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me1/vsrc/me1.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vme1___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vme1___024root___eval_debug_assertions(Vme1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme1___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->s & 0xfcU))) {
        Verilated::overWidthError("s");}
}
#endif  // VL_DEBUG

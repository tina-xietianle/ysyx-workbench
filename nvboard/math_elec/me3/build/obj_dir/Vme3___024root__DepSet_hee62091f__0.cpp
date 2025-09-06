// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme3.h for the primary calling header

#include "verilated.h"

#include "Vme3___024root.h"

VL_INLINE_OPT void Vme3___024root___ico_sequent__TOP__0(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ me3__DOT__c;
    me3__DOT__c = 0;
    // Body
    me3__DOT__c = (0xfU & ((IData)(1U) + (~ (IData)(vlSelf->b))));
    if ((4U & (IData)(vlSelf->func))) {
        if ((2U & (IData)(vlSelf->func))) {
            if ((1U & (IData)(vlSelf->func))) {
                vlSelf->out = ((IData)(vlSelf->a) == (IData)(vlSelf->b));
                vlSelf->result = 0U;
                vlSelf->carry = 0U;
                vlSelf->overflow = 0U;
            } else {
                vlSelf->carry = (1U & (((IData)(vlSelf->a) 
                                        + (IData)(me3__DOT__c)) 
                                       >> 4U));
                vlSelf->result = (0xfU & ((IData)(vlSelf->a) 
                                          + (IData)(me3__DOT__c)));
                vlSelf->overflow = 0U;
                vlSelf->out = vlSelf->carry;
                vlSelf->result = 0U;
                vlSelf->carry = 0U;
            }
        } else if ((1U & (IData)(vlSelf->func))) {
            vlSelf->result = ((IData)(vlSelf->a) ^ (IData)(vlSelf->b));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->out = 0U;
        } else {
            vlSelf->result = ((IData)(vlSelf->a) | (IData)(vlSelf->b));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->out = 0U;
        }
    } else if ((2U & (IData)(vlSelf->func))) {
        if ((1U & (IData)(vlSelf->func))) {
            vlSelf->result = ((IData)(vlSelf->a) & (IData)(vlSelf->b));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->out = 0U;
        } else {
            vlSelf->result = (0xfU & (~ (IData)(vlSelf->a)));
            vlSelf->carry = 0U;
            vlSelf->overflow = 0U;
            vlSelf->out = 0U;
        }
    } else if ((1U & (IData)(vlSelf->func))) {
        vlSelf->carry = (1U & (((IData)(vlSelf->a) 
                                + (IData)(me3__DOT__c)) 
                               >> 4U));
        vlSelf->out = 0U;
        vlSelf->result = (0xfU & ((IData)(vlSelf->a) 
                                  + (IData)(me3__DOT__c)));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->a) 
                                    >> 3U)) == (1U 
                                                & ((IData)(me3__DOT__c) 
                                                   >> 3U))) 
                            & ((1U & ((IData)(vlSelf->result) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->a) 
                                                     >> 3U))));
    } else {
        vlSelf->result = (0xfU & ((IData)(vlSelf->a) 
                                  + (IData)(vlSelf->b)));
        vlSelf->carry = (1U & (((IData)(vlSelf->a) 
                                + (IData)(vlSelf->b)) 
                               >> 4U));
        vlSelf->overflow = (((1U & ((IData)(vlSelf->a) 
                                    >> 3U)) == (1U 
                                                & ((IData)(vlSelf->b) 
                                                   >> 3U))) 
                            & ((1U & ((IData)(vlSelf->result) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->a) 
                                                     >> 3U))));
        vlSelf->out = 0U;
    }
    vlSelf->zero = (0U == (IData)(vlSelf->result));
}

void Vme3___024root___eval_ico(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vme3___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vme3___024root___eval_act(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___eval_act\n"); );
}

void Vme3___024root___eval_nba(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___eval_nba\n"); );
}

void Vme3___024root___eval_triggers__ico(Vme3___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme3___024root___dump_triggers__ico(Vme3___024root* vlSelf);
#endif  // VL_DEBUG
void Vme3___024root___eval_triggers__act(Vme3___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme3___024root___dump_triggers__act(Vme3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vme3___024root___dump_triggers__nba(Vme3___024root* vlSelf);
#endif  // VL_DEBUG

void Vme3___024root___eval(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___eval\n"); );
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
        Vme3___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vme3___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me3/vsrc/me3.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vme3___024root___eval_ico(vlSelf);
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
            Vme3___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vme3___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me3/vsrc/me3.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vme3___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vme3___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/nvboard/math_elec/me3/vsrc/me3.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vme3___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vme3___024root___eval_debug_assertions(Vme3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme3___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->func & 0xf8U))) {
        Verilated::overWidthError("func");}
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090010_exu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24090010_exu___024root.h"

void Vysyx_24090010_exu___024root___ico_sequent__TOP__0(Vysyx_24090010_exu___024root* vlSelf);

void Vysyx_24090010_exu___024root___eval_ico(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vysyx_24090010_exu___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_24090010_exu___024root___eval_act(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_act\n"); );
}

void Vysyx_24090010_exu___024root___nba_sequent__TOP__0(Vysyx_24090010_exu___024root* vlSelf);
void Vysyx_24090010_exu___024root___nba_sequent__TOP__1(Vysyx_24090010_exu___024root* vlSelf);
void Vysyx_24090010_exu___024root___nba_sequent__TOP__2(Vysyx_24090010_exu___024root* vlSelf);

void Vysyx_24090010_exu___024root___eval_nba(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vysyx_24090010_exu___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_24090010_exu___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_24090010_exu___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vysyx_24090010_exu___024root___eval_triggers__ico(Vysyx_24090010_exu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__ico(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_24090010_exu___024root___eval_triggers__act(Vysyx_24090010_exu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__act(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__nba(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090010_exu___024root___eval(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vysyx_24090010_exu___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24090010_exu___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_exu.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vysyx_24090010_exu___024root___eval_ico(vlSelf);
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
            Vysyx_24090010_exu___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_24090010_exu___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_exu.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_24090010_exu___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24090010_exu___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_exu.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_24090010_exu___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_24090010_exu___024root___eval_debug_assertions(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

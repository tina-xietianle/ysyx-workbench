// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme6.h for the primary calling header

#include "verilated.h"

#include "Vme6__Syms.h"
#include "Vme6___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vme6___024root___dump_triggers__act(Vme6___024root* vlSelf);
#endif  // VL_DEBUG

void Vme6___024root___eval_triggers__act(Vme6___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vme6__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vme6___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vme6___024root___dump_triggers__act(vlSelf);
    }
#endif
}

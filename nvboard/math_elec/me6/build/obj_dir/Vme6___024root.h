// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vme6.h for the primary calling header

#ifndef VERILATED_VME6___024ROOT_H_
#define VERILATED_VME6___024ROOT_H_  // guard

#include "verilated.h"

class Vme6__Syms;

class Vme6___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(out,7,0);
    CData/*7:0*/ me6__DOT__x;
    CData/*0:0*/ me6__DOT__x8;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(h,13,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vme6__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vme6___024root(Vme6__Syms* symsp, const char* v__name);
    ~Vme6___024root();
    VL_UNCOPYABLE(Vme6___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

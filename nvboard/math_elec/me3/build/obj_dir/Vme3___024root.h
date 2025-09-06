// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vme3.h for the primary calling header

#ifndef VERILATED_VME3___024ROOT_H_
#define VERILATED_VME3___024ROOT_H_  // guard

#include "verilated.h"

class Vme3__Syms;

class Vme3___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(func,2,0);
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_OUT8(result,3,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(overflow,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(out,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vme3__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vme3___024root(Vme3__Syms* symsp, const char* v__name);
    ~Vme3___024root();
    VL_UNCOPYABLE(Vme3___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

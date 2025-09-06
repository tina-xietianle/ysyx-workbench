// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vme2.h for the primary calling header

#ifndef VERILATED_VME2___024ROOT_H_
#define VERILATED_VME2___024ROOT_H_  // guard

#include "verilated.h"

class Vme2__Syms;

class Vme2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i,7,0);
    VL_IN8(en,0,0);
    VL_OUT8(y,2,0);
    VL_OUT8(eno,0,0);
    VL_OUT8(h,6,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vme2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vme2___024root(Vme2__Syms* symsp, const char* v__name);
    ~Vme2___024root();
    VL_UNCOPYABLE(Vme2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

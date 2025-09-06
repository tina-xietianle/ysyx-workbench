// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdoubles.h for the primary calling header

#ifndef VERILATED_VDOUBLES___024ROOT_H_
#define VERILATED_VDOUBLES___024ROOT_H_  // guard

#include "verilated.h"

class Vdoubles__Syms;

class Vdoubles___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(f,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdoubles__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdoubles___024root(Vdoubles__Syms* symsp, const char* v__name);
    ~Vdoubles___024root();
    VL_UNCOPYABLE(Vdoubles___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

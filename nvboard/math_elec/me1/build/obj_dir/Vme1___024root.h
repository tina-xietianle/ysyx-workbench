// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vme1.h for the primary calling header

#ifndef VERILATED_VME1___024ROOT_H_
#define VERILATED_VME1___024ROOT_H_  // guard

#include "verilated.h"

class Vme1__Syms;

class Vme1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,7,0);
    VL_IN8(s,1,0);
    VL_OUT8(y,1,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*1:0*/, 4> me1__DOT__i0__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*1:0*/, 4> me1__DOT__i0__DOT__i0__DOT__data_list;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vme1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vme1___024root(Vme1__Syms* symsp, const char* v__name);
    ~Vme1___024root();
    VL_UNCOPYABLE(Vme1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

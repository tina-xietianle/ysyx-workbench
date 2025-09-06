// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspriled.h for the primary calling header

#ifndef VERILATED_VSPRILED___024ROOT_H_
#define VERILATED_VSPRILED___024ROOT_H_  // guard

#include "verilated.h"

class Vspriled__Syms;

class Vspriled___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(led,15,0);
    IData/*31:0*/ spriled__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vspriled__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspriled___024root(Vspriled__Syms* symsp, const char* v__name);
    ~Vspriled___024root();
    VL_UNCOPYABLE(Vspriled___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

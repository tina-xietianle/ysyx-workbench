// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdoubles.h for the primary calling header

#include "verilated.h"

#include "Vdoubles__Syms.h"
#include "Vdoubles___024root.h"

void Vdoubles___024root___ctor_var_reset(Vdoubles___024root* vlSelf);

Vdoubles___024root::Vdoubles___024root(Vdoubles__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdoubles___024root___ctor_var_reset(this);
}

void Vdoubles___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vdoubles___024root::~Vdoubles___024root() {
}

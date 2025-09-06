// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme2.h for the primary calling header

#include "verilated.h"

#include "Vme2__Syms.h"
#include "Vme2___024root.h"

void Vme2___024root___ctor_var_reset(Vme2___024root* vlSelf);

Vme2___024root::Vme2___024root(Vme2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vme2___024root___ctor_var_reset(this);
}

void Vme2___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vme2___024root::~Vme2___024root() {
}

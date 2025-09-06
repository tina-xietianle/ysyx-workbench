// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme7.h for the primary calling header

#include "verilated.h"

#include "Vme7__Syms.h"
#include "Vme7___024root.h"

void Vme7___024root___ctor_var_reset(Vme7___024root* vlSelf);

Vme7___024root::Vme7___024root(Vme7__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vme7___024root___ctor_var_reset(this);
}

void Vme7___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vme7___024root::~Vme7___024root() {
}

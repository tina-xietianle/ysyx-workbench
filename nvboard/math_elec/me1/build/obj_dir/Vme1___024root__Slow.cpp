// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme1.h for the primary calling header

#include "verilated.h"

#include "Vme1__Syms.h"
#include "Vme1___024root.h"

void Vme1___024root___ctor_var_reset(Vme1___024root* vlSelf);

Vme1___024root::Vme1___024root(Vme1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vme1___024root___ctor_var_reset(this);
}

void Vme1___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vme1___024root::~Vme1___024root() {
}

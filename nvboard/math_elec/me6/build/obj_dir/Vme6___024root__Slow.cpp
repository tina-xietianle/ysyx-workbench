// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme6.h for the primary calling header

#include "verilated.h"

#include "Vme6__Syms.h"
#include "Vme6___024root.h"

void Vme6___024root___ctor_var_reset(Vme6___024root* vlSelf);

Vme6___024root::Vme6___024root(Vme6__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vme6___024root___ctor_var_reset(this);
}

void Vme6___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vme6___024root::~Vme6___024root() {
}

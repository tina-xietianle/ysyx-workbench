// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspriled.h for the primary calling header

#include "verilated.h"

#include "Vspriled__Syms.h"
#include "Vspriled___024root.h"

void Vspriled___024root___ctor_var_reset(Vspriled___024root* vlSelf);

Vspriled___024root::Vspriled___024root(Vspriled__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vspriled___024root___ctor_var_reset(this);
}

void Vspriled___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vspriled___024root::~Vspriled___024root() {
}

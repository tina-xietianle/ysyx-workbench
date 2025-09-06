// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vme3.h for the primary calling header

#include "verilated.h"

#include "Vme3__Syms.h"
#include "Vme3___024root.h"

void Vme3___024root___ctor_var_reset(Vme3___024root* vlSelf);

Vme3___024root::Vme3___024root(Vme3__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vme3___024root___ctor_var_reset(this);
}

void Vme3___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vme3___024root::~Vme3___024root() {
}

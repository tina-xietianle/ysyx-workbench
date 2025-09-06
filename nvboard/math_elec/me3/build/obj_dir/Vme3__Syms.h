// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VME3__SYMS_H_
#define VERILATED_VME3__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vme3.h"

// INCLUDE MODULE CLASSES
#include "Vme3___024root.h"

// SYMS CLASS (contains all model state)
class Vme3__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vme3* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vme3___024root                 TOP;

    // CONSTRUCTORS
    Vme3__Syms(VerilatedContext* contextp, const char* namep, Vme3* modelp);
    ~Vme3__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

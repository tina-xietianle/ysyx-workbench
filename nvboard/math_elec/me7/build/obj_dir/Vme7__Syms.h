// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VME7__SYMS_H_
#define VERILATED_VME7__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vme7.h"

// INCLUDE MODULE CLASSES
#include "Vme7___024root.h"

// SYMS CLASS (contains all model state)
class Vme7__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vme7* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vme7___024root                 TOP;

    // CONSTRUCTORS
    Vme7__Syms(VerilatedContext* contextp, const char* namep, Vme7* modelp);
    ~Vme7__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

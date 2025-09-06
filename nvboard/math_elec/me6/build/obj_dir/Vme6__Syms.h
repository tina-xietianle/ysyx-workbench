// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VME6__SYMS_H_
#define VERILATED_VME6__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vme6.h"

// INCLUDE MODULE CLASSES
#include "Vme6___024root.h"

// SYMS CLASS (contains all model state)
class Vme6__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vme6* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vme6___024root                 TOP;

    // CONSTRUCTORS
    Vme6__Syms(VerilatedContext* contextp, const char* namep, Vme6* modelp);
    ~Vme6__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

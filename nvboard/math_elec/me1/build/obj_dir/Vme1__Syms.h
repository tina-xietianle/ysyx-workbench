// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VME1__SYMS_H_
#define VERILATED_VME1__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vme1.h"

// INCLUDE MODULE CLASSES
#include "Vme1___024root.h"

// SYMS CLASS (contains all model state)
class Vme1__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vme1* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vme1___024root                 TOP;

    // CONSTRUCTORS
    Vme1__Syms(VerilatedContext* contextp, const char* namep, Vme1* modelp);
    ~Vme1__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

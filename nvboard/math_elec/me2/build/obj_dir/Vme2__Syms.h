// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VME2__SYMS_H_
#define VERILATED_VME2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vme2.h"

// INCLUDE MODULE CLASSES
#include "Vme2___024root.h"

// SYMS CLASS (contains all model state)
class Vme2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vme2* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vme2___024root                 TOP;

    // CONSTRUCTORS
    Vme2__Syms(VerilatedContext* contextp, const char* namep, Vme2* modelp);
    ~Vme2__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

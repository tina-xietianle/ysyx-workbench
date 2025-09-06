// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDOUBLES__SYMS_H_
#define VERILATED_VDOUBLES__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdoubles.h"

// INCLUDE MODULE CLASSES
#include "Vdoubles___024root.h"

// SYMS CLASS (contains all model state)
class Vdoubles__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdoubles* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdoubles___024root             TOP;

    // CONSTRUCTORS
    Vdoubles__Syms(VerilatedContext* contextp, const char* namep, Vdoubles* modelp);
    ~Vdoubles__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

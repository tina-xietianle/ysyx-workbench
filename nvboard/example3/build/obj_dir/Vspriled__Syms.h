// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPRILED__SYMS_H_
#define VERILATED_VSPRILED__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vspriled.h"

// INCLUDE MODULE CLASSES
#include "Vspriled___024root.h"

// SYMS CLASS (contains all model state)
class Vspriled__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vspriled* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vspriled___024root             TOP;

    // CONSTRUCTORS
    Vspriled__Syms(VerilatedContext* contextp, const char* namep, Vspriled* modelp);
    ~Vspriled__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

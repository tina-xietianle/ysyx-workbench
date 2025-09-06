// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24090010_exu.h for the primary calling header

#ifndef VERILATED_VYSYX_24090010_EXU___024UNIT_H_
#define VERILATED_VYSYX_24090010_EXU___024UNIT_H_  // guard

#include "verilated.h"

class Vysyx_24090010_exu__Syms;

class Vysyx_24090010_exu___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vysyx_24090010_exu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24090010_exu___024unit(Vysyx_24090010_exu__Syms* symsp, const char* v__name);
    ~Vysyx_24090010_exu___024unit();
    VL_UNCOPYABLE(Vysyx_24090010_exu___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

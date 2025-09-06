// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vme6__Syms.h"
#include "Vme6.h"
#include "Vme6___024root.h"

// FUNCTIONS
Vme6__Syms::~Vme6__Syms()
{
}

Vme6__Syms::Vme6__Syms(VerilatedContext* contextp, const char* namep, Vme6* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

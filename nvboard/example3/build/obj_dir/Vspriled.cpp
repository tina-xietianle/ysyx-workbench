// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vspriled.h"
#include "Vspriled__Syms.h"

//============================================================
// Constructors

Vspriled::Vspriled(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vspriled__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vspriled::Vspriled(const char* _vcname__)
    : Vspriled(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vspriled::~Vspriled() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vspriled___024root___eval_debug_assertions(Vspriled___024root* vlSelf);
#endif  // VL_DEBUG
void Vspriled___024root___eval_static(Vspriled___024root* vlSelf);
void Vspriled___024root___eval_initial(Vspriled___024root* vlSelf);
void Vspriled___024root___eval_settle(Vspriled___024root* vlSelf);
void Vspriled___024root___eval(Vspriled___024root* vlSelf);

void Vspriled::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vspriled::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vspriled___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vspriled___024root___eval_static(&(vlSymsp->TOP));
        Vspriled___024root___eval_initial(&(vlSymsp->TOP));
        Vspriled___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vspriled___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vspriled::eventsPending() { return false; }

uint64_t Vspriled::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vspriled::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vspriled___024root___eval_final(Vspriled___024root* vlSelf);

VL_ATTR_COLD void Vspriled::final() {
    Vspriled___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vspriled::hierName() const { return vlSymsp->name(); }
const char* Vspriled::modelName() const { return "Vspriled"; }
unsigned Vspriled::threads() const { return 1; }

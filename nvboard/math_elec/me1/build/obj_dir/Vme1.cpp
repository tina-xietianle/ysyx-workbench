// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vme1.h"
#include "Vme1__Syms.h"

//============================================================
// Constructors

Vme1::Vme1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vme1__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vme1::Vme1(const char* _vcname__)
    : Vme1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vme1::~Vme1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vme1___024root___eval_debug_assertions(Vme1___024root* vlSelf);
#endif  // VL_DEBUG
void Vme1___024root___eval_static(Vme1___024root* vlSelf);
void Vme1___024root___eval_initial(Vme1___024root* vlSelf);
void Vme1___024root___eval_settle(Vme1___024root* vlSelf);
void Vme1___024root___eval(Vme1___024root* vlSelf);

void Vme1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vme1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vme1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vme1___024root___eval_static(&(vlSymsp->TOP));
        Vme1___024root___eval_initial(&(vlSymsp->TOP));
        Vme1___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vme1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vme1::eventsPending() { return false; }

uint64_t Vme1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vme1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vme1___024root___eval_final(Vme1___024root* vlSelf);

VL_ATTR_COLD void Vme1::final() {
    Vme1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vme1::hierName() const { return vlSymsp->name(); }
const char* Vme1::modelName() const { return "Vme1"; }
unsigned Vme1::threads() const { return 1; }

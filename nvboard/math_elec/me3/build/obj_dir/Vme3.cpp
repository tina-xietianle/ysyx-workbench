// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vme3.h"
#include "Vme3__Syms.h"

//============================================================
// Constructors

Vme3::Vme3(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vme3__Syms(contextp(), _vcname__, this)}
    , func{vlSymsp->TOP.func}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , result{vlSymsp->TOP.result}
    , zero{vlSymsp->TOP.zero}
    , overflow{vlSymsp->TOP.overflow}
    , carry{vlSymsp->TOP.carry}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vme3::Vme3(const char* _vcname__)
    : Vme3(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vme3::~Vme3() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vme3___024root___eval_debug_assertions(Vme3___024root* vlSelf);
#endif  // VL_DEBUG
void Vme3___024root___eval_static(Vme3___024root* vlSelf);
void Vme3___024root___eval_initial(Vme3___024root* vlSelf);
void Vme3___024root___eval_settle(Vme3___024root* vlSelf);
void Vme3___024root___eval(Vme3___024root* vlSelf);

void Vme3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vme3::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vme3___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vme3___024root___eval_static(&(vlSymsp->TOP));
        Vme3___024root___eval_initial(&(vlSymsp->TOP));
        Vme3___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vme3___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vme3::eventsPending() { return false; }

uint64_t Vme3::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vme3::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vme3___024root___eval_final(Vme3___024root* vlSelf);

VL_ATTR_COLD void Vme3::final() {
    Vme3___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vme3::hierName() const { return vlSymsp->name(); }
const char* Vme3::modelName() const { return "Vme3"; }
unsigned Vme3::threads() const { return 1; }

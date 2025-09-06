// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdoubles.h"
#include "Vdoubles__Syms.h"

//============================================================
// Constructors

Vdoubles::Vdoubles(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdoubles__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdoubles::Vdoubles(const char* _vcname__)
    : Vdoubles(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdoubles::~Vdoubles() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdoubles___024root___eval_debug_assertions(Vdoubles___024root* vlSelf);
#endif  // VL_DEBUG
void Vdoubles___024root___eval_static(Vdoubles___024root* vlSelf);
void Vdoubles___024root___eval_initial(Vdoubles___024root* vlSelf);
void Vdoubles___024root___eval_settle(Vdoubles___024root* vlSelf);
void Vdoubles___024root___eval(Vdoubles___024root* vlSelf);

void Vdoubles::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdoubles::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdoubles___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdoubles___024root___eval_static(&(vlSymsp->TOP));
        Vdoubles___024root___eval_initial(&(vlSymsp->TOP));
        Vdoubles___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdoubles___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdoubles::eventsPending() { return false; }

uint64_t Vdoubles::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdoubles::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdoubles___024root___eval_final(Vdoubles___024root* vlSelf);

VL_ATTR_COLD void Vdoubles::final() {
    Vdoubles___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdoubles::hierName() const { return vlSymsp->name(); }
const char* Vdoubles::modelName() const { return "Vdoubles"; }
unsigned Vdoubles::threads() const { return 1; }

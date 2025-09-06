// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vme2.h"
#include "Vme2__Syms.h"

//============================================================
// Constructors

Vme2::Vme2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vme2__Syms(contextp(), _vcname__, this)}
    , i{vlSymsp->TOP.i}
    , en{vlSymsp->TOP.en}
    , y{vlSymsp->TOP.y}
    , eno{vlSymsp->TOP.eno}
    , h{vlSymsp->TOP.h}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vme2::Vme2(const char* _vcname__)
    : Vme2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vme2::~Vme2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vme2___024root___eval_debug_assertions(Vme2___024root* vlSelf);
#endif  // VL_DEBUG
void Vme2___024root___eval_static(Vme2___024root* vlSelf);
void Vme2___024root___eval_initial(Vme2___024root* vlSelf);
void Vme2___024root___eval_settle(Vme2___024root* vlSelf);
void Vme2___024root___eval(Vme2___024root* vlSelf);

void Vme2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vme2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vme2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vme2___024root___eval_static(&(vlSymsp->TOP));
        Vme2___024root___eval_initial(&(vlSymsp->TOP));
        Vme2___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vme2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vme2::eventsPending() { return false; }

uint64_t Vme2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vme2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vme2___024root___eval_final(Vme2___024root* vlSelf);

VL_ATTR_COLD void Vme2::final() {
    Vme2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vme2::hierName() const { return vlSymsp->name(); }
const char* Vme2::modelName() const { return "Vme2"; }
unsigned Vme2::threads() const { return 1; }

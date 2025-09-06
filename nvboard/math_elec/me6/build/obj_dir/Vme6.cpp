// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vme6.h"
#include "Vme6__Syms.h"

//============================================================
// Constructors

Vme6::Vme6(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vme6__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , out{vlSymsp->TOP.out}
    , h{vlSymsp->TOP.h}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vme6::Vme6(const char* _vcname__)
    : Vme6(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vme6::~Vme6() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vme6___024root___eval_debug_assertions(Vme6___024root* vlSelf);
#endif  // VL_DEBUG
void Vme6___024root___eval_static(Vme6___024root* vlSelf);
void Vme6___024root___eval_initial(Vme6___024root* vlSelf);
void Vme6___024root___eval_settle(Vme6___024root* vlSelf);
void Vme6___024root___eval(Vme6___024root* vlSelf);

void Vme6::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vme6::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vme6___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vme6___024root___eval_static(&(vlSymsp->TOP));
        Vme6___024root___eval_initial(&(vlSymsp->TOP));
        Vme6___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vme6___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vme6::eventsPending() { return false; }

uint64_t Vme6::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vme6::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vme6___024root___eval_final(Vme6___024root* vlSelf);

VL_ATTR_COLD void Vme6::final() {
    Vme6___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vme6::hierName() const { return vlSymsp->name(); }
const char* Vme6::modelName() const { return "Vme6"; }
unsigned Vme6::threads() const { return 1; }

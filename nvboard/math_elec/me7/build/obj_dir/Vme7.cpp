// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vme7.h"
#include "Vme7__Syms.h"

//============================================================
// Constructors

Vme7::Vme7(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vme7__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ps2_clk{vlSymsp->TOP.ps2_clk}
    , rst{vlSymsp->TOP.rst}
    , ps2_data{vlSymsp->TOP.ps2_data}
    , data{vlSymsp->TOP.data}
    , ascii{vlSymsp->TOP.ascii}
    , xian{vlSymsp->TOP.xian}
    , xian2{vlSymsp->TOP.xian2}
    , xian3{vlSymsp->TOP.xian3}
    , xian4{vlSymsp->TOP.xian4}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vme7::Vme7(const char* _vcname__)
    : Vme7(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vme7::~Vme7() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vme7___024root___eval_debug_assertions(Vme7___024root* vlSelf);
#endif  // VL_DEBUG
void Vme7___024root___eval_static(Vme7___024root* vlSelf);
void Vme7___024root___eval_initial(Vme7___024root* vlSelf);
void Vme7___024root___eval_settle(Vme7___024root* vlSelf);
void Vme7___024root___eval(Vme7___024root* vlSelf);

void Vme7::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vme7::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vme7___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vme7___024root___eval_static(&(vlSymsp->TOP));
        Vme7___024root___eval_initial(&(vlSymsp->TOP));
        Vme7___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vme7___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vme7::eventsPending() { return false; }

uint64_t Vme7::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vme7::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vme7___024root___eval_final(Vme7___024root* vlSelf);

VL_ATTR_COLD void Vme7::final() {
    Vme7___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vme7::hierName() const { return vlSymsp->name(); }
const char* Vme7::modelName() const { return "Vme7"; }
unsigned Vme7::threads() const { return 1; }

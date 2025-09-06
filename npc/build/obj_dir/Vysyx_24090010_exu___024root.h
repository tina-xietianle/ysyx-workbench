// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24090010_exu.h for the primary calling header

#ifndef VERILATED_VYSYX_24090010_EXU___024ROOT_H_
#define VERILATED_VYSYX_24090010_EXU___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_24090010_exu__Syms;
class Vysyx_24090010_exu___024unit;


class Vysyx_24090010_exu___024root final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_24090010_exu___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_24090010_exu__DOT__reg_wen;
    CData/*0:0*/ ysyx_24090010_exu__DOT__csr_wen;
    CData/*1:0*/ ysyx_24090010_exu__DOT__csr_en_;
    CData/*0:0*/ ysyx_24090010_exu__DOT__ram_wen;
    CData/*0:0*/ ysyx_24090010_exu__DOT__is_b_jump;
    CData/*5:0*/ ysyx_24090010_exu__DOT__ins_type;
    CData/*0:0*/ ysyx_24090010_exu__DOT__ifu__DOT__count;
    CData/*0:0*/ ysyx_24090010_exu__DOT__idu__DOT__flag;
    CData/*0:0*/ ysyx_24090010_exu__DOT__reg1__DOT__flag;
    CData/*5:0*/ __Vtableidx1;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ ysyx_24090010_exu__DOT__imm;
    IData/*31:0*/ ysyx_24090010_exu__DOT__strb;
    IData/*31:0*/ ysyx_24090010_exu__DOT__mtvec;
    IData/*31:0*/ ysyx_24090010_exu__DOT__mcause;
    IData/*31:0*/ ysyx_24090010_exu__DOT__mepc;
    IData/*31:0*/ ysyx_24090010_exu__DOT__mstatus;
    IData/*31:0*/ ysyx_24090010_exu__DOT__pc;
    IData/*31:0*/ ysyx_24090010_exu__DOT__result_reg;
    IData/*31:0*/ ysyx_24090010_exu__DOT__result_ram;
    IData/*31:0*/ ysyx_24090010_exu__DOT__rdata1;
    IData/*31:0*/ ysyx_24090010_exu__DOT__ram_rdata;
    IData/*31:0*/ ysyx_24090010_exu__DOT__ins;
    IData/*31:0*/ ysyx_24090010_exu__DOT__ram_addr;
    IData/*31:0*/ ysyx_24090010_exu__DOT__pc_jump;
    IData/*31:0*/ ysyx_24090010_exu__DOT__ifu__DOT__next_pc;
    IData/*31:0*/ ysyx_24090010_exu__DOT__ifu__DOT__spc;
    IData/*31:0*/ ysyx_24090010_exu__DOT__reg1__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __Vfunc_vaddr_ifetch_v__0__Vfuncout;
    IData/*31:0*/ __Vfunc_vaddr_read_v__11__Vfuncout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ifu__DOT__next_pc;
    IData/*31:0*/ __Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ins;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_24090010_exu__DOT__reg1__DOT__R;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_24090010_exu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24090010_exu___024root(Vysyx_24090010_exu__Syms* symsp, const char* v__name);
    ~Vysyx_24090010_exu___024root();
    VL_UNCOPYABLE(Vysyx_24090010_exu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

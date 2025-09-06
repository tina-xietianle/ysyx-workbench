// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090010_exu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24090010_exu__Syms.h"
#include "Vysyx_24090010_exu___024unit.h"

extern "C" void ebreak();

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_ebreak_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    ebreak();
}

extern "C" void invalid_inst(int pc, int ins);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_invalid_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ ins) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_invalid_inst_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int ins__Vcvt;
    for (size_t ins__Vidx = 0; ins__Vidx < 1; ++ins__Vidx) ins__Vcvt = ins;
    invalid_inst(pc__Vcvt, ins__Vcvt);
}

extern "C" void set_npc_state(int state, int pc, int halt_ret);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_set_npc_state_TOP____024unit(IData/*31:0*/ state, IData/*31:0*/ pc, IData/*31:0*/ halt_ret) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_set_npc_state_TOP____024unit\n"); );
    // Body
    int state__Vcvt;
    for (size_t state__Vidx = 0; state__Vidx < 1; ++state__Vidx) state__Vcvt = state;
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int halt_ret__Vcvt;
    for (size_t halt_ret__Vidx = 0; halt_ret__Vidx < 1; ++halt_ret__Vidx) halt_ret__Vcvt = halt_ret;
    set_npc_state(state__Vcvt, pc__Vcvt, halt_ret__Vcvt);
}

extern "C" int vaddr_read_v(int addr, int len);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_read_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &vaddr_read_v__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_read_v_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int vaddr_read_v__Vfuncrtn__Vcvt;
    vaddr_read_v__Vfuncrtn__Vcvt = vaddr_read_v(addr__Vcvt, len__Vcvt);
    vaddr_read_v__Vfuncrtn = vaddr_read_v__Vfuncrtn__Vcvt;
}

extern "C" void vaddr_write_v(int addr, int len, int data);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_write_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_write_v_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    vaddr_write_v(addr__Vcvt, len__Vcvt, data__Vcvt);
}

extern "C" void load_reg(int regv, int i);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(IData/*31:0*/ regv, IData/*31:0*/ i) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit\n"); );
    // Body
    int regv__Vcvt;
    for (size_t regv__Vidx = 0; regv__Vidx < 1; ++regv__Vidx) regv__Vcvt = regv;
    int i__Vcvt;
    for (size_t i__Vidx = 0; i__Vidx < 1; ++i__Vidx) i__Vcvt = i;
    load_reg(regv__Vcvt, i__Vcvt);
}

extern "C" void reset_reg();

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_reset_reg_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_reset_reg_TOP____024unit\n"); );
    // Body
    reset_reg();
}

extern "C" void transfer_cpu(int pc, int next_pc, int inst);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_transfer_cpu_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ next_pc, IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_transfer_cpu_TOP____024unit\n"); );
    // Body
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    int next_pc__Vcvt;
    for (size_t next_pc__Vidx = 0; next_pc__Vidx < 1; ++next_pc__Vidx) next_pc__Vcvt = next_pc;
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    transfer_cpu(pc__Vcvt, next_pc__Vcvt, inst__Vcvt);
}

extern "C" int vaddr_ifetch_v(int addr, int len);

VL_INLINE_OPT void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_ifetch_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &vaddr_ifetch_v__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_ifetch_v_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int vaddr_ifetch_v__Vfuncrtn__Vcvt;
    vaddr_ifetch_v__Vfuncrtn__Vcvt = vaddr_ifetch_v(addr__Vcvt, len__Vcvt);
    vaddr_ifetch_v__Vfuncrtn = vaddr_ifetch_v__Vfuncrtn__Vcvt;
}

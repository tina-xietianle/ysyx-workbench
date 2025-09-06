// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_24090010_EXU__DPI_H_
#define VERILATED_VYSYX_24090010_EXU__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_idu.v:1:30
    extern void ebreak();
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_idu.v:2:30
    extern void invalid_inst(int pc, int ins);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_reg.v:1:30
    extern void load_reg(int regv, int i);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_reg.v:2:30
    extern void reset_reg();
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_idu.v:3:30
    extern void set_npc_state(int state, int pc, int halt_ret);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_ifu.v:2:30
    extern void transfer_cpu(int pc, int next_pc, int inst);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_ifu.v:3:29
    extern int vaddr_ifetch_v(int addr, int len);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_ram.v:1:29
    extern int vaddr_read_v(int addr, int len);
    // DPI import at /home/xietianle/ysyx-workbench/npc/vsrc/ysyx_24090010_ram.v:2:30
    extern void vaddr_write_v(int addr, int len, int data);

#ifdef __cplusplus
}
#endif

#endif  // guard

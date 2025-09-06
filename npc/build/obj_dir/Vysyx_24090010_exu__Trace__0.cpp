// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24090010_exu__Syms.h"


void Vysyx_24090010_exu___024root__trace_chg_sub_0(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_24090010_exu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_24090010_exu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090010_exu___024root*>(voidSelf);
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_24090010_exu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_24090010_exu___024root__trace_chg_sub_0(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_24090010_exu__DOT__imm),32);
        bufp->chgCData(oldp+1,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+2,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+3,((7U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                      >> 0xcU))),3);
        bufp->chgCData(oldp+4,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                         >> 7U))),5);
        bufp->chgBit(oldp+5,(vlSelf->ysyx_24090010_exu__DOT__reg_wen));
        bufp->chgBit(oldp+6,(vlSelf->ysyx_24090010_exu__DOT__csr_wen));
        bufp->chgCData(oldp+7,(vlSelf->ysyx_24090010_exu__DOT__csr_en_),2);
        bufp->chgBit(oldp+8,(vlSelf->ysyx_24090010_exu__DOT__ram_wen));
        bufp->chgBit(oldp+9,(vlSelf->ysyx_24090010_exu__DOT__is_b_jump));
        bufp->chgIData(oldp+10,(vlSelf->ysyx_24090010_exu__DOT__strb),32);
        bufp->chgIData(oldp+11,(vlSelf->ysyx_24090010_exu__DOT__result_reg),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_24090010_exu__DOT__result_ram),32);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_24090010_exu__DOT__rdata1),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_24090010_exu__DOT__ram_rdata),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_24090010_exu__DOT__ins),32);
        bufp->chgCData(oldp+16,(vlSelf->ysyx_24090010_exu__DOT__ins_type),6);
        bufp->chgIData(oldp+17,(vlSelf->ysyx_24090010_exu__DOT__ram_addr),32);
        bufp->chgIData(oldp+18,(vlSelf->ysyx_24090010_exu__DOT__pc_jump),32);
        bufp->chgBit(oldp+19,(vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag));
        bufp->chgIData(oldp+20,(vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+21,(vlSelf->ysyx_24090010_exu__DOT__mtvec),32);
        bufp->chgIData(oldp+22,(vlSelf->ysyx_24090010_exu__DOT__mcause),32);
        bufp->chgIData(oldp+23,(vlSelf->ysyx_24090010_exu__DOT__mepc),32);
        bufp->chgIData(oldp+24,(vlSelf->ysyx_24090010_exu__DOT__mstatus),32);
        bufp->chgIData(oldp+25,(vlSelf->ysyx_24090010_exu__DOT__pc),32);
        bufp->chgIData(oldp+26,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                [0xaU]),32);
        bufp->chgIData(oldp+27,(vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc),32);
        bufp->chgIData(oldp+28,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0]),32);
        bufp->chgIData(oldp+29,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[1]),32);
        bufp->chgIData(oldp+30,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[2]),32);
        bufp->chgIData(oldp+31,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[3]),32);
        bufp->chgIData(oldp+32,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[4]),32);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[5]),32);
        bufp->chgIData(oldp+34,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[6]),32);
        bufp->chgIData(oldp+35,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[7]),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[8]),32);
        bufp->chgIData(oldp+37,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[9]),32);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[10]),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[11]),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[12]),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[13]),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[14]),32);
        bufp->chgIData(oldp+43,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[15]),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[16]),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[17]),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[18]),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[19]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[20]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[21]),32);
        bufp->chgIData(oldp+50,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[22]),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[23]),32);
        bufp->chgIData(oldp+52,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[24]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[25]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[26]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[27]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[28]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[29]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[30]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[31]),32);
        bufp->chgBit(oldp+60,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag));
        bufp->chgIData(oldp+61,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+62,(vlSelf->clk));
    bufp->chgBit(oldp+63,(vlSelf->rst));
}

void Vysyx_24090010_exu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_cleanup\n"); );
    // Init
    Vysyx_24090010_exu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090010_exu___024root*>(voidSelf);
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}

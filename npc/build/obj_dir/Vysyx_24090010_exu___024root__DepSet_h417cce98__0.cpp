// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24090010_exu.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24090010_exu__Syms.h"
#include "Vysyx_24090010_exu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__ico(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090010_exu___024root___eval_triggers__ico(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24090010_exu___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_ifetch_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &vaddr_ifetch_v__Vfuncrtn);
void Vysyx_24090010_exu___024unit____Vdpiimwrap_set_npc_state_TOP____024unit(IData/*31:0*/ state, IData/*31:0*/ pc, IData/*31:0*/ halt_ret);
void Vysyx_24090010_exu___024unit____Vdpiimwrap_ebreak_TOP____024unit();
void Vysyx_24090010_exu___024unit____Vdpiimwrap_invalid_inst_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ ins);
extern const VlUnpacked<IData/*31:0*/, 64> Vysyx_24090010_exu__ConstPool__TABLE_h006007a8_0;
void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_read_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &vaddr_read_v__Vfuncrtn);

VL_INLINE_OPT void Vysyx_24090010_exu___024root___ico_sequent__TOP__0(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___ico_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__ins = 0U;
    } else {
        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_ifetch_v_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__pc, 4U, vlSelf->__Vfunc_vaddr_ifetch_v__0__Vfuncout);
        vlSelf->ysyx_24090010_exu__DOT__ins = vlSelf->__Vfunc_vaddr_ifetch_v__0__Vfuncout;
    }
    vlSelf->ysyx_24090010_exu__DOT__result_ram = vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
        [(0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                   >> 0x14U))];
    vlSelf->ysyx_24090010_exu__DOT__rdata1 = vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
        [(0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                   >> 0xfU))];
    vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
    vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
    vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
    vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
    vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
        vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
        vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
        vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
        vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
    } else {
        vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
        if (VL_LIKELY((0x80000000U <= vlSelf->ysyx_24090010_exu__DOT__pc))) {
            if ((0x100073U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                Vysyx_24090010_exu___024unit____Vdpiimwrap_set_npc_state_TOP____024unit(2U, vlSelf->ysyx_24090010_exu__DOT__pc, 
                                                                                vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                                [0xaU]);
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 6U;
                Vysyx_24090010_exu___024unit____Vdpiimwrap_ebreak_TOP____024unit();
            } else if ((0x73U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x25U;
            } else if ((IData)((0x13U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x67U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 3U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 7U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x3013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xaU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40005013U == (0xfc00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x11U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x12U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x13U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x16U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5013U == (0xfc00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x19U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1013U == (0xfc00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1bU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1fU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x20U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x23U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((3U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x24U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1073U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x26U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2073U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x27U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x17U == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (0xfffff000U & vlSelf->ysyx_24090010_exu__DOT__ins);
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 1U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x37U == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (0xfffff000U & vlSelf->ysyx_24090010_exu__DOT__ins);
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 4U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x6fU == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0x14U) 
                       | ((0xff000U & vlSelf->ysyx_24090010_exu__DOT__ins) 
                          | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                        >> 9U)) | (
                                                   (0x7e0U 
                                                    & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                         >> 0x14U))))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 2U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2023U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 5U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1023U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x10U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x23U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x17U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x33U == (0xfe00707fU 
                                          & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 8U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40000033U == (0xfe00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 9U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x3033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xdU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xeU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xfU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x14U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x15U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1eU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40005033U == (0xfe00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x21U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x22U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x30200073U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x28U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x63U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xbU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xcU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x18U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1aU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1cU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1dU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else {
                if ((1U & (~ (IData)(vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag)))) {
                    Vysyx_24090010_exu___024unit____Vdpiimwrap_invalid_inst_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__pc, vlSelf->ysyx_24090010_exu__DOT__ins);
                    vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 1U;
                }
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
            }
        } else {
            VL_WRITEF("\351\224\231\350\257\257\n");
        }
    }
    vlSelf->ysyx_24090010_exu__DOT__csr_en_ = ((0x341U 
                                                == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                ? 0U
                                                : (
                                                   (0x342U 
                                                    == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                    ? 1U
                                                    : 
                                                   ((0x300U 
                                                     == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                     ? 2U
                                                     : 
                                                    ((0x305U 
                                                      == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      ? 3U
                                                      : 0U))));
    vlSelf->__Vtableidx1 = vlSelf->ysyx_24090010_exu__DOT__ins_type;
    vlSelf->ysyx_24090010_exu__DOT__strb = Vysyx_24090010_exu__ConstPool__TABLE_h006007a8_0
        [vlSelf->__Vtableidx1];
    if ((0x20U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & ((~ ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                       >> 4U)) & ((8U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                   ? (IData)((0U == 
                                              (7U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))))
                                   : (IData)((5U == 
                                              (7U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : vlSelf->ysyx_24090010_exu__DOT__mepc)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                        : 0U))
                                                      : 0U)));
    } else if ((0x10U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                    >> 3U) & ((4U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                               ? ((~ ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                      >> 1U)) & ((1U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 
                                                 (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                  < vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                               : ((2U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                   ? ((~ (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
                                      & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                         >= vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                   : ((~ (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
                                      & VL_GTES_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (8U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))))
                                                    : 0U);
    } else {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                    >> 3U) & ((4U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                               ? (IData)(((0U == (3U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) 
                                          & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                             != vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                               : (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                   >> 1U) & ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                             & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                == vlSelf->ysyx_24090010_exu__DOT__result_ram))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (8U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (0xfffffffeU 
                                                       & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                          + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 0U)));
    }
    vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc 
        = (((2U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
            | ((3U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
               | (IData)(vlSelf->ysyx_24090010_exu__DOT__is_b_jump)))
            ? vlSelf->ysyx_24090010_exu__DOT__pc_jump
            : vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc);
    vlSelf->ysyx_24090010_exu__DOT__ram_addr = ((0x20U 
                                                 & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 0x80000000U
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 0x80000000U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0x80000000U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0x80000000U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm))))))
                                                 : 
                                                ((0x10U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 0x80000000U)
                                                    : 0x80000000U)
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 0x80000000U)
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)))))
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 0x80000000U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U))
                                                    : 0x80000000U))));
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__ram_rdata = 0U;
    } else {
        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_read_v_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__ram_addr, vlSelf->ysyx_24090010_exu__DOT__strb, vlSelf->__Vfunc_vaddr_read_v__11__Vfuncout);
        vlSelf->ysyx_24090010_exu__DOT__ram_rdata = vlSelf->__Vfunc_vaddr_read_v__11__Vfuncout;
    }
    vlSelf->ysyx_24090010_exu__DOT__result_reg = ((0x20U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((0x341U 
                                                         == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? vlSelf->ysyx_24090010_exu__DOT__mepc
                                                         : 
                                                        ((0x342U 
                                                          == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                          ? vlSelf->ysyx_24090010_exu__DOT__mcause
                                                          : 
                                                         ((0x300U 
                                                           == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                           ? vlSelf->ysyx_24090010_exu__DOT__mstatus
                                                           : 
                                                          ((0x305U 
                                                            == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                            ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                            : 0U))))
                                                        : 
                                                       ((0x341U 
                                                         == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? vlSelf->ysyx_24090010_exu__DOT__mepc
                                                         : 
                                                        ((0x342U 
                                                          == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                          ? vlSelf->ysyx_24090010_exu__DOT__mcause
                                                          : 
                                                         ((0x300U 
                                                           == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                           ? vlSelf->ysyx_24090010_exu__DOT__mstatus
                                                           : 
                                                          ((0x305U 
                                                            == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                            ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                            : 0U)))))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__pc
                                                        : 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->ysyx_24090010_exu__DOT__ram_rdata 
                                                                        >> 7U)))) 
                                                         << 8U) 
                                                        | (0xffU 
                                                           & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        | vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_24090010_exu__DOT__rdata1, 
                                                                      (0x1fU 
                                                                       & vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                                        : 
                                                       (0xffffU 
                                                        & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))))))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->ysyx_24090010_exu__DOT__ram_rdata 
                                                                        >> 0xfU)))) 
                                                         << 0x10U) 
                                                        | (0xffffU 
                                                           & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))
                                                        : 
                                                       (VL_LTS_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                         ? 1U
                                                         : 0U))
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        << 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        ^ vlSelf->ysyx_24090010_exu__DOT__imm))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        & vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        << 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__result_ram))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        & vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (0xffU 
                                                        & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_24090010_exu__DOT__rdata1, 
                                                                      (0x1fU 
                                                                       & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        | vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        ^ vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                         < vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : 
                                                       ((vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                         < vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? 1U
                                                         : 0U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        - vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        + vlSelf->ysyx_24090010_exu__DOT__result_ram))))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__ram_rdata
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((IData)(4U) 
                                                        + vlSelf->ysyx_24090010_exu__DOT__pc)
                                                        : 
                                                       ((IData)(4U) 
                                                        + vlSelf->ysyx_24090010_exu__DOT__pc))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                        + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        + vlSelf->ysyx_24090010_exu__DOT__imm)))))));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24090010_exu___024root___dump_triggers__act(Vysyx_24090010_exu___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24090010_exu___024root___eval_triggers__act(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__VactTriggered.at(1U) = ((vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc 
                                       != vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ifu__DOT__next_pc) 
                                      | (vlSelf->ysyx_24090010_exu__DOT__ins 
                                         != vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ins));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ifu__DOT__next_pc 
        = vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc;
    vlSelf->__Vtrigrprev__TOP__ysyx_24090010_exu__DOT__ins 
        = vlSelf->ysyx_24090010_exu__DOT__ins;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24090010_exu___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_write_v_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);

VL_INLINE_OPT void Vysyx_24090010_exu___024root___nba_sequent__TOP__0(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->ysyx_24090010_exu__DOT__ram_wen) {
        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_write_v_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__ram_addr, vlSelf->ysyx_24090010_exu__DOT__strb, vlSelf->ysyx_24090010_exu__DOT__result_ram);
    }
}

void Vysyx_24090010_exu___024unit____Vdpiimwrap_transfer_cpu_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ next_pc, IData/*31:0*/ inst);

VL_INLINE_OPT void Vysyx_24090010_exu___024root___nba_sequent__TOP__1(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___nba_sequent__TOP__1\n"); );
    // Body
    Vysyx_24090010_exu___024unit____Vdpiimwrap_transfer_cpu_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__pc, vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc, vlSelf->ysyx_24090010_exu__DOT__ins);
}

void Vysyx_24090010_exu___024unit____Vdpiimwrap_reset_reg_TOP____024unit();
void Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(IData/*31:0*/ regv, IData/*31:0*/ i);

VL_INLINE_OPT void Vysyx_24090010_exu___024root___nba_sequent__TOP__2(Vysyx_24090010_exu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v0;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v0 = 0;
    CData/*0:0*/ __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag;
    __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag = 0;
    IData/*31:0*/ __Vdly__ysyx_24090010_exu__DOT__mcause;
    __Vdly__ysyx_24090010_exu__DOT__mcause = 0;
    IData/*31:0*/ __Vdly__ysyx_24090010_exu__DOT__mtvec;
    __Vdly__ysyx_24090010_exu__DOT__mtvec = 0;
    IData/*31:0*/ __Vdly__ysyx_24090010_exu__DOT__mepc;
    __Vdly__ysyx_24090010_exu__DOT__mepc = 0;
    IData/*31:0*/ __Vdly__ysyx_24090010_exu__DOT__mstatus;
    __Vdly__ysyx_24090010_exu__DOT__mstatus = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v1;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v1 = 0;
    CData/*4:0*/ __Vdlyvdim0__ysyx_24090010_exu__DOT__reg1__DOT__R__v32;
    __Vdlyvdim0__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_24090010_exu__DOT__reg1__DOT__R__v32;
    __Vdlyvval__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v32;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 = 0;
    // Body
    __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag 
        = vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag;
    __Vdly__ysyx_24090010_exu__DOT__mstatus = vlSelf->ysyx_24090010_exu__DOT__mstatus;
    __Vdly__ysyx_24090010_exu__DOT__mcause = vlSelf->ysyx_24090010_exu__DOT__mcause;
    __Vdly__ysyx_24090010_exu__DOT__mepc = vlSelf->ysyx_24090010_exu__DOT__mepc;
    __Vdly__ysyx_24090010_exu__DOT__mtvec = vlSelf->ysyx_24090010_exu__DOT__mtvec;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v0 = 0U;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v1 = 0U;
    __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__unnamedblk1__DOT__i = 0x20U;
        Vysyx_24090010_exu___024unit____Vdpiimwrap_reset_reg_TOP____024unit();
        __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v0 = 1U;
        __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag = 0U;
        __Vdly__ysyx_24090010_exu__DOT__mcause = 0U;
        __Vdly__ysyx_24090010_exu__DOT__mtvec = 0U;
        __Vdly__ysyx_24090010_exu__DOT__mepc = 0U;
        __Vdly__ysyx_24090010_exu__DOT__mstatus = 0x1800U;
        __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v1 = 1U;
    } else if (((0U != (0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                 >> 7U))) & (IData)(vlSelf->ysyx_24090010_exu__DOT__reg_wen))) {
        if (vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag) {
            __Vdlyvval__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 
                = vlSelf->ysyx_24090010_exu__DOT__result_reg;
            __Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 = 1U;
            __Vdlyvdim0__ysyx_24090010_exu__DOT__reg1__DOT__R__v32 
                = (0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                            >> 7U));
        }
        __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag = 1U;
    } else if (vlSelf->ysyx_24090010_exu__DOT__csr_wen) {
        if ((0x25U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) {
            __Vdly__ysyx_24090010_exu__DOT__mepc = vlSelf->ysyx_24090010_exu__DOT__result_reg;
            __Vdly__ysyx_24090010_exu__DOT__mcause = 0xbU;
        } else if ((2U & (IData)(vlSelf->ysyx_24090010_exu__DOT__csr_en_))) {
            if ((1U & (IData)(vlSelf->ysyx_24090010_exu__DOT__csr_en_))) {
                __Vdly__ysyx_24090010_exu__DOT__mtvec 
                    = ((0x26U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                        ? vlSelf->ysyx_24090010_exu__DOT__rdata1
                        : (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                           | vlSelf->ysyx_24090010_exu__DOT__mtvec));
            } else {
                __Vdly__ysyx_24090010_exu__DOT__mstatus 
                    = ((0x26U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                        ? vlSelf->ysyx_24090010_exu__DOT__rdata1
                        : (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                           | vlSelf->ysyx_24090010_exu__DOT__mstatus));
            }
        } else if ((1U & (IData)(vlSelf->ysyx_24090010_exu__DOT__csr_en_))) {
            __Vdly__ysyx_24090010_exu__DOT__mcause 
                = ((0x26U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                    ? vlSelf->ysyx_24090010_exu__DOT__rdata1
                    : (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                       | vlSelf->ysyx_24090010_exu__DOT__mcause));
        } else {
            __Vdly__ysyx_24090010_exu__DOT__mepc = 
                ((0x26U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                  ? vlSelf->ysyx_24090010_exu__DOT__rdata1
                  : (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                     | vlSelf->ysyx_24090010_exu__DOT__mepc));
        }
    }
    vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag 
        = __Vdly__ysyx_24090010_exu__DOT__reg1__DOT__flag;
    vlSelf->ysyx_24090010_exu__DOT__mcause = __Vdly__ysyx_24090010_exu__DOT__mcause;
    vlSelf->ysyx_24090010_exu__DOT__mstatus = __Vdly__ysyx_24090010_exu__DOT__mstatus;
    vlSelf->ysyx_24090010_exu__DOT__mtvec = __Vdly__ysyx_24090010_exu__DOT__mtvec;
    vlSelf->ysyx_24090010_exu__DOT__mepc = __Vdly__ysyx_24090010_exu__DOT__mepc;
    if (__Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v0) {
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0U] = 0U;
    }
    if (__Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v1) {
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[1U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[2U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[3U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[4U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[5U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[6U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[7U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[8U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[9U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xaU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xbU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xcU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xdU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xeU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0xfU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x10U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x11U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x12U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x13U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x14U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x15U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x16U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x17U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x18U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x19U] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1aU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1bU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1cU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1dU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1eU] = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0x1fU] = 0U;
    }
    if (__Vdlyvset__ysyx_24090010_exu__DOT__reg1__DOT__R__v32) {
        vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[__Vdlyvdim0__ysyx_24090010_exu__DOT__reg1__DOT__R__v32] 
            = __Vdlyvval__ysyx_24090010_exu__DOT__reg1__DOT__R__v32;
    }
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc = 0x80000000U;
        vlSelf->ysyx_24090010_exu__DOT__pc = 0x80000000U;
    } else {
        vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc 
            = ((IData)(4U) + vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc);
        vlSelf->ysyx_24090010_exu__DOT__pc = vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc;
    }
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0U], 0U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [1U], 1U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [2U], 2U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [3U], 3U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [4U], 4U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [5U], 5U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [6U], 6U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [7U], 7U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [8U], 8U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [9U], 9U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xaU], 0xaU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xbU], 0xbU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xcU], 0xcU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xdU], 0xdU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xeU], 0xeU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0xfU], 0xfU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x10U], 0x10U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x11U], 0x11U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x12U], 0x12U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x13U], 0x13U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x14U], 0x14U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x15U], 0x15U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x16U], 0x16U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x17U], 0x17U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x18U], 0x18U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x19U], 0x19U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1aU], 0x1aU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1bU], 0x1bU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1cU], 0x1cU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1dU], 0x1dU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1eU], 0x1eU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(
                                                                       vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                       [0x1fU], 0x1fU);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__mstatus, 0x20U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__mtvec, 0x21U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__mepc, 0x22U);
    Vysyx_24090010_exu___024unit____Vdpiimwrap_load_reg_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__mcause, 0x23U);
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__ins = 0U;
    } else {
        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_ifetch_v_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__pc, 4U, vlSelf->__Vfunc_vaddr_ifetch_v__0__Vfuncout);
        vlSelf->ysyx_24090010_exu__DOT__ins = vlSelf->__Vfunc_vaddr_ifetch_v__0__Vfuncout;
    }
    vlSelf->ysyx_24090010_exu__DOT__result_ram = vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
        [(0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                   >> 0x14U))];
    vlSelf->ysyx_24090010_exu__DOT__rdata1 = vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
        [(0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                   >> 0xfU))];
    vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
    vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
    vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
    vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
    vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
        vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
        vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
        vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
        vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
        vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
    } else {
        vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
        if (VL_LIKELY((0x80000000U <= vlSelf->ysyx_24090010_exu__DOT__pc))) {
            if ((0x100073U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                Vysyx_24090010_exu___024unit____Vdpiimwrap_set_npc_state_TOP____024unit(2U, vlSelf->ysyx_24090010_exu__DOT__pc, 
                                                                                vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                                                                                [0xaU]);
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 6U;
                Vysyx_24090010_exu___024unit____Vdpiimwrap_ebreak_TOP____024unit();
            } else if ((0x73U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x25U;
            } else if ((IData)((0x13U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x67U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 3U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 7U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x3013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xaU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40005013U == (0xfc00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x11U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x12U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x13U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x16U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5013U == (0xfc00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x19U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1013U == (0xfc00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1bU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1fU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5003U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x20U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6013U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x23U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((3U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x24U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1073U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x26U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2073U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->ysyx_24090010_exu__DOT__ins 
                          >> 0x14U));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x27U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x17U == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (0xfffff000U & vlSelf->ysyx_24090010_exu__DOT__ins);
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 1U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x37U == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (0xfffff000U & vlSelf->ysyx_24090010_exu__DOT__ins);
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 4U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x6fU == (0x7fU & vlSelf->ysyx_24090010_exu__DOT__ins))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0x14U) 
                       | ((0xff000U & vlSelf->ysyx_24090010_exu__DOT__ins) 
                          | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                        >> 9U)) | (
                                                   (0x7e0U 
                                                    & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                         >> 0x14U))))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 2U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2023U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 5U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1023U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x10U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x23U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x17U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x33U == (0xfe00707fU 
                                          & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 8U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40000033U == (0xfe00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 9U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x3033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xdU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xeU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xfU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x14U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x15U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x2033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1eU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x40005033U == (0xfe00707fU 
                                                & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x21U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5033U == (0xfe00707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x22U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 1U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((0x30200073U == vlSelf->ysyx_24090010_exu__DOT__ins)) {
                vlSelf->ysyx_24090010_exu__DOT__imm = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x28U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x63U == (0x707fU & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xbU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x1063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0xcU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x5063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x18U;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x7063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1aU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x4063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1cU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else if ((IData)((0x6063U == (0x707fU 
                                            & vlSelf->ysyx_24090010_exu__DOT__ins)))) {
                vlSelf->ysyx_24090010_exu__DOT__imm 
                    = (((- (IData)((vlSelf->ysyx_24090010_exu__DOT__ins 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0x800U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                     << 4U)) | ((0x7e0U 
                                                 & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                                      >> 7U)))));
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x1dU;
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 0U;
            } else {
                if ((1U & (~ (IData)(vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag)))) {
                    Vysyx_24090010_exu___024unit____Vdpiimwrap_invalid_inst_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__pc, vlSelf->ysyx_24090010_exu__DOT__ins);
                    vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag = 1U;
                }
                vlSelf->ysyx_24090010_exu__DOT__reg_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ram_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__csr_wen = 0U;
                vlSelf->ysyx_24090010_exu__DOT__ins_type = 0x3fU;
            }
        } else {
            VL_WRITEF("\351\224\231\350\257\257\n");
        }
    }
    vlSelf->ysyx_24090010_exu__DOT__csr_en_ = ((0x341U 
                                                == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                ? 0U
                                                : (
                                                   (0x342U 
                                                    == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                    ? 1U
                                                    : 
                                                   ((0x300U 
                                                     == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                     ? 2U
                                                     : 
                                                    ((0x305U 
                                                      == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      ? 3U
                                                      : 0U))));
    vlSelf->__Vtableidx1 = vlSelf->ysyx_24090010_exu__DOT__ins_type;
    vlSelf->ysyx_24090010_exu__DOT__strb = Vysyx_24090010_exu__ConstPool__TABLE_h006007a8_0
        [vlSelf->__Vtableidx1];
    if ((0x20U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & ((~ ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                       >> 4U)) & ((8U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                   ? (IData)((0U == 
                                              (7U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))))
                                   : (IData)((5U == 
                                              (7U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : vlSelf->ysyx_24090010_exu__DOT__mepc)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                        : 0U))
                                                      : 0U)));
    } else if ((0x10U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                    >> 3U) & ((4U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                               ? ((~ ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                      >> 1U)) & ((1U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 
                                                 (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                  < vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                               : ((2U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                   ? ((~ (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
                                      & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                         >= vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                   : ((~ (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
                                      & VL_GTES_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (8U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))))
                                                    : 0U);
    } else {
        vlSelf->ysyx_24090010_exu__DOT__is_b_jump = 
            (1U & (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                    >> 3U) & ((4U & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                               ? (IData)(((0U == (3U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))) 
                                          & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                             != vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                               : (((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                   >> 1U) & ((IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type) 
                                             & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                == vlSelf->ysyx_24090010_exu__DOT__result_ram))))));
        vlSelf->ysyx_24090010_exu__DOT__pc_jump = (
                                                   (8U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 0U
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      (0xfffffffeU 
                                                       & (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                          + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                       : 
                                                      (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                       + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 0U)));
    }
    vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc 
        = (((2U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
            | ((3U == (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type)) 
               | (IData)(vlSelf->ysyx_24090010_exu__DOT__is_b_jump)))
            ? vlSelf->ysyx_24090010_exu__DOT__pc_jump
            : vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc);
    vlSelf->ysyx_24090010_exu__DOT__ram_addr = ((0x20U 
                                                 & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                 ? 
                                                ((0x10U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 0x80000000U
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 0x80000000U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0x80000000U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0x80000000U
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm))))))
                                                 : 
                                                ((0x10U 
                                                  & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                  ? 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 0x80000000U)
                                                    : 0x80000000U)
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 0x80000000U)
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 0x80000000U
                                                      : 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)))))
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 0x80000000U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                      + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                      : 0x80000000U))
                                                    : 0x80000000U))));
    if (vlSelf->rst) {
        vlSelf->ysyx_24090010_exu__DOT__ram_rdata = 0U;
    } else {
        Vysyx_24090010_exu___024unit____Vdpiimwrap_vaddr_read_v_TOP____024unit(vlSelf->ysyx_24090010_exu__DOT__ram_addr, vlSelf->ysyx_24090010_exu__DOT__strb, vlSelf->__Vfunc_vaddr_read_v__11__Vfuncout);
        vlSelf->ysyx_24090010_exu__DOT__ram_rdata = vlSelf->__Vfunc_vaddr_read_v__11__Vfuncout;
    }
    vlSelf->ysyx_24090010_exu__DOT__result_reg = ((0x20U 
                                                   & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                   ? 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((0x341U 
                                                         == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? vlSelf->ysyx_24090010_exu__DOT__mepc
                                                         : 
                                                        ((0x342U 
                                                          == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                          ? vlSelf->ysyx_24090010_exu__DOT__mcause
                                                          : 
                                                         ((0x300U 
                                                           == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                           ? vlSelf->ysyx_24090010_exu__DOT__mstatus
                                                           : 
                                                          ((0x305U 
                                                            == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                            ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                            : 0U))))
                                                        : 
                                                       ((0x341U 
                                                         == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? vlSelf->ysyx_24090010_exu__DOT__mepc
                                                         : 
                                                        ((0x342U 
                                                          == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                          ? vlSelf->ysyx_24090010_exu__DOT__mcause
                                                          : 
                                                         ((0x300U 
                                                           == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                           ? vlSelf->ysyx_24090010_exu__DOT__mstatus
                                                           : 
                                                          ((0x305U 
                                                            == vlSelf->ysyx_24090010_exu__DOT__imm)
                                                            ? vlSelf->ysyx_24090010_exu__DOT__mtvec
                                                            : 0U)))))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__pc
                                                        : 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->ysyx_24090010_exu__DOT__ram_rdata 
                                                                        >> 7U)))) 
                                                         << 8U) 
                                                        | (0xffU 
                                                           & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        | vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__result_ram)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_24090010_exu__DOT__rdata1, 
                                                                      (0x1fU 
                                                                       & vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                                        : 
                                                       (0xffffU 
                                                        & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))))))
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->ysyx_24090010_exu__DOT__ram_rdata 
                                                                        >> 0xfU)))) 
                                                         << 0x10U) 
                                                        | (0xffffU 
                                                           & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))
                                                        : 
                                                       (VL_LTS_III(32, vlSelf->ysyx_24090010_exu__DOT__rdata1, vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                         ? 1U
                                                         : 0U))
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        << 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U)))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        ^ vlSelf->ysyx_24090010_exu__DOT__imm))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        & vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        << 
                                                        (0x1fU 
                                                         & vlSelf->ysyx_24090010_exu__DOT__result_ram))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        & vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (0xffU 
                                                        & vlSelf->ysyx_24090010_exu__DOT__ram_rdata))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_24090010_exu__DOT__rdata1, 
                                                                      (0x1fU 
                                                                       & vlSelf->ysyx_24090010_exu__DOT__imm))
                                                        : 0U))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        | vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        ^ vlSelf->ysyx_24090010_exu__DOT__result_ram))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                         < vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                         ? 1U
                                                         : 0U)
                                                        : 0U))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : 
                                                       ((vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                         < vlSelf->ysyx_24090010_exu__DOT__imm)
                                                         ? 1U
                                                         : 0U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        - vlSelf->ysyx_24090010_exu__DOT__result_ram)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        + vlSelf->ysyx_24090010_exu__DOT__result_ram))))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? vlSelf->ysyx_24090010_exu__DOT__ram_rdata
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 0U
                                                        : vlSelf->ysyx_24090010_exu__DOT__imm))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       ((IData)(4U) 
                                                        + vlSelf->ysyx_24090010_exu__DOT__pc)
                                                        : 
                                                       ((IData)(4U) 
                                                        + vlSelf->ysyx_24090010_exu__DOT__pc))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->ysyx_24090010_exu__DOT__ins_type))
                                                        ? 
                                                       (vlSelf->ysyx_24090010_exu__DOT__pc 
                                                        + vlSelf->ysyx_24090010_exu__DOT__imm)
                                                        : 
                                                       (vlSelf->ysyx_24090010_exu__DOT__rdata1 
                                                        + vlSelf->ysyx_24090010_exu__DOT__imm)))))));
}

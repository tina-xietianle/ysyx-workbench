// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24090010_exu__Syms.h"


VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_init_sub__TOP__0(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->pushNamePrefix("ysyx_24090010_exu ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+2,"rs1", false,-1, 4,0);
    tracep->declBus(c+3,"rs2", false,-1, 4,0);
    tracep->declBus(c+4,"funct3", false,-1, 2,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBit(c+6,"reg_wen", false,-1);
    tracep->declBit(c+7,"csr_wen", false,-1);
    tracep->declBus(c+8,"csr_en_", false,-1, 1,0);
    tracep->declBit(c+9,"ram_wen", false,-1);
    tracep->declBit(c+10,"is_b_jump", false,-1);
    tracep->declBus(c+11,"strb", false,-1, 31,0);
    tracep->declBus(c+22,"mtvec", false,-1, 31,0);
    tracep->declBus(c+23,"mcause", false,-1, 31,0);
    tracep->declBus(c+24,"mepc", false,-1, 31,0);
    tracep->declBus(c+25,"mstatus", false,-1, 31,0);
    tracep->declBus(c+26,"pc", false,-1, 31,0);
    tracep->declBus(c+12,"result_reg", false,-1, 31,0);
    tracep->declBus(c+13,"result_ram", false,-1, 31,0);
    tracep->declBus(c+14,"rdata1", false,-1, 31,0);
    tracep->declBus(c+13,"rdata2", false,-1, 31,0);
    tracep->declBus(c+15,"ram_rdata", false,-1, 31,0);
    tracep->declBus(c+16,"ins", false,-1, 31,0);
    tracep->declBus(c+17,"ins_type", false,-1, 5,0);
    tracep->declBus(c+18,"ram_addr", false,-1, 31,0);
    tracep->declBus(c+19,"pc_jump", false,-1, 31,0);
    tracep->declBus(c+27,"r10", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+14,"rdata1", false,-1, 31,0);
    tracep->declBus(c+13,"rdata2", false,-1, 31,0);
    tracep->declBus(c+22,"mtvec", false,-1, 31,0);
    tracep->declBus(c+24,"mepc", false,-1, 31,0);
    tracep->declBus(c+23,"mcause", false,-1, 31,0);
    tracep->declBus(c+25,"mstatus", false,-1, 31,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+26,"pc", false,-1, 31,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+2,"rs1", false,-1, 4,0);
    tracep->declBus(c+17,"ins_type", false,-1, 5,0);
    tracep->declBus(c+15,"ram_rdata", false,-1, 31,0);
    tracep->declBus(c+12,"result_reg", false,-1, 31,0);
    tracep->declBus(c+8,"csr_en_", false,-1, 1,0);
    tracep->declBus(c+18,"ram_addr", false,-1, 31,0);
    tracep->declBus(c+19,"pc_jump", false,-1, 31,0);
    tracep->declBit(c+10,"is_b_jump", false,-1);
    tracep->declBus(c+11,"strb", false,-1, 31,0);
    tracep->declBus(c+13,"result_ram", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+26,"pc", false,-1, 31,0);
    tracep->declBus(c+27,"r10", false,-1, 31,0);
    tracep->declBus(c+16,"ins", false,-1, 31,0);
    tracep->declBus(c+1,"imm", false,-1, 31,0);
    tracep->declBus(c+2,"rs1", false,-1, 4,0);
    tracep->declBus(c+3,"rs2", false,-1, 4,0);
    tracep->declBus(c+4,"funct3", false,-1, 2,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+17,"ins_type", false,-1, 5,0);
    tracep->declBit(c+6,"reg_wen", false,-1);
    tracep->declBit(c+7,"csr_wen", false,-1);
    tracep->declBit(c+9,"ram_wen", false,-1);
    tracep->declBus(c+65,"addi", false,-1, 5,0);
    tracep->declBus(c+66,"auipc", false,-1, 5,0);
    tracep->declBus(c+67,"jal", false,-1, 5,0);
    tracep->declBus(c+68,"jalr", false,-1, 5,0);
    tracep->declBus(c+69,"lui", false,-1, 5,0);
    tracep->declBus(c+70,"sw", false,-1, 5,0);
    tracep->declBus(c+71,"ebreak_ins", false,-1, 5,0);
    tracep->declBus(c+72,"lw", false,-1, 5,0);
    tracep->declBus(c+73,"add", false,-1, 5,0);
    tracep->declBus(c+74,"sub", false,-1, 5,0);
    tracep->declBus(c+75,"sltiu", false,-1, 5,0);
    tracep->declBus(c+76,"beq", false,-1, 5,0);
    tracep->declBus(c+77,"bne", false,-1, 5,0);
    tracep->declBus(c+78,"sltu", false,-1, 5,0);
    tracep->declBus(c+79,"xor_", false,-1, 5,0);
    tracep->declBus(c+80,"or_", false,-1, 5,0);
    tracep->declBus(c+81,"sh", false,-1, 5,0);
    tracep->declBus(c+82,"srai", false,-1, 5,0);
    tracep->declBus(c+83,"lbu", false,-1, 5,0);
    tracep->declBus(c+84,"andi", false,-1, 5,0);
    tracep->declBus(c+85,"sll", false,-1, 5,0);
    tracep->declBus(c+86,"and_", false,-1, 5,0);
    tracep->declBus(c+87,"xori", false,-1, 5,0);
    tracep->declBus(c+88,"sb", false,-1, 5,0);
    tracep->declBus(c+89,"bge", false,-1, 5,0);
    tracep->declBus(c+90,"srli", false,-1, 5,0);
    tracep->declBus(c+91,"bgeu", false,-1, 5,0);
    tracep->declBus(c+92,"slli", false,-1, 5,0);
    tracep->declBus(c+93,"blt", false,-1, 5,0);
    tracep->declBus(c+94,"bltu", false,-1, 5,0);
    tracep->declBus(c+95,"slt", false,-1, 5,0);
    tracep->declBus(c+96,"lh", false,-1, 5,0);
    tracep->declBus(c+97,"lhu", false,-1, 5,0);
    tracep->declBus(c+98,"sra", false,-1, 5,0);
    tracep->declBus(c+99,"srl", false,-1, 5,0);
    tracep->declBus(c+100,"ori", false,-1, 5,0);
    tracep->declBus(c+101,"lb", false,-1, 5,0);
    tracep->declBus(c+102,"ecall", false,-1, 5,0);
    tracep->declBus(c+103,"csrrw", false,-1, 5,0);
    tracep->declBus(c+104,"csrrs", false,-1, 5,0);
    tracep->declBus(c+105,"mret", false,-1, 5,0);
    tracep->declBit(c+20,"flag", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+19,"pc_jump", false,-1, 31,0);
    tracep->declBit(c+10,"is_b_jump", false,-1);
    tracep->declBus(c+17,"ins_type", false,-1, 5,0);
    tracep->declBus(c+16,"ins", false,-1, 31,0);
    tracep->declBus(c+26,"pc", false,-1, 31,0);
    tracep->declBus(c+21,"next_pc", false,-1, 31,0);
    tracep->declBus(c+28,"spc", false,-1, 31,0);
    tracep->declBit(c+106,"count", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+11,"strb", false,-1, 31,0);
    tracep->declBus(c+18,"addr", false,-1, 31,0);
    tracep->declBus(c+13,"wdata", false,-1, 31,0);
    tracep->declBit(c+9,"we", false,-1);
    tracep->declBus(c+15,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("reg1 ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+17,"ins_type", false,-1, 5,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBit(c+6,"reg_wen", false,-1);
    tracep->declBit(c+7,"csr_wen", false,-1);
    tracep->declBus(c+8,"csr_en_", false,-1, 1,0);
    tracep->declBus(c+12,"write_reg_data", false,-1, 31,0);
    tracep->declBus(c+2,"rs1", false,-1, 4,0);
    tracep->declBus(c+3,"rs2", false,-1, 4,0);
    tracep->declBus(c+22,"mtvec", false,-1, 31,0);
    tracep->declBus(c+24,"mepc", false,-1, 31,0);
    tracep->declBus(c+23,"mcause", false,-1, 31,0);
    tracep->declBus(c+25,"mstatus", false,-1, 31,0);
    tracep->declBus(c+14,"read_reg_data1", false,-1, 31,0);
    tracep->declBus(c+13,"read_reg_data2", false,-1, 31,0);
    tracep->declBus(c+27,"r10", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+29+i*1,"R", true,(i+0), 31,0);
    }
    tracep->declBit(c+61,"flag", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+62,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->declBus(c+107,"n", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_init_top(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_init_top\n"); );
    // Body
    Vysyx_24090010_exu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24090010_exu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24090010_exu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_register(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_24090010_exu___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_24090010_exu___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_24090010_exu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_full_sub_0(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_24090010_exu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24090010_exu___024root*>(voidSelf);
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_24090010_exu___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_24090010_exu___024root__trace_full_sub_0(Vysyx_24090010_exu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24090010_exu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24090010_exu___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_24090010_exu__DOT__imm),32);
    bufp->fullCData(oldp+2,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+3,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+4,((7U & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                   >> 0xcU))),3);
    bufp->fullCData(oldp+5,((0x1fU & (vlSelf->ysyx_24090010_exu__DOT__ins 
                                      >> 7U))),5);
    bufp->fullBit(oldp+6,(vlSelf->ysyx_24090010_exu__DOT__reg_wen));
    bufp->fullBit(oldp+7,(vlSelf->ysyx_24090010_exu__DOT__csr_wen));
    bufp->fullCData(oldp+8,(vlSelf->ysyx_24090010_exu__DOT__csr_en_),2);
    bufp->fullBit(oldp+9,(vlSelf->ysyx_24090010_exu__DOT__ram_wen));
    bufp->fullBit(oldp+10,(vlSelf->ysyx_24090010_exu__DOT__is_b_jump));
    bufp->fullIData(oldp+11,(vlSelf->ysyx_24090010_exu__DOT__strb),32);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_24090010_exu__DOT__result_reg),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_24090010_exu__DOT__result_ram),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_24090010_exu__DOT__rdata1),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_24090010_exu__DOT__ram_rdata),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_24090010_exu__DOT__ins),32);
    bufp->fullCData(oldp+17,(vlSelf->ysyx_24090010_exu__DOT__ins_type),6);
    bufp->fullIData(oldp+18,(vlSelf->ysyx_24090010_exu__DOT__ram_addr),32);
    bufp->fullIData(oldp+19,(vlSelf->ysyx_24090010_exu__DOT__pc_jump),32);
    bufp->fullBit(oldp+20,(vlSelf->ysyx_24090010_exu__DOT__idu__DOT__flag));
    bufp->fullIData(oldp+21,(vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__next_pc),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_24090010_exu__DOT__mtvec),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_24090010_exu__DOT__mcause),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_24090010_exu__DOT__mepc),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_24090010_exu__DOT__mstatus),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_24090010_exu__DOT__pc),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R
                             [0xaU]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__spc),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[0]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[1]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[2]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[3]),32);
    bufp->fullIData(oldp+33,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[4]),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[5]),32);
    bufp->fullIData(oldp+35,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[6]),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[7]),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[8]),32);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[9]),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[10]),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[11]),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[12]),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[13]),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[14]),32);
    bufp->fullIData(oldp+44,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[15]),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[16]),32);
    bufp->fullIData(oldp+46,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[17]),32);
    bufp->fullIData(oldp+47,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[18]),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[19]),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[20]),32);
    bufp->fullIData(oldp+50,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[21]),32);
    bufp->fullIData(oldp+51,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[22]),32);
    bufp->fullIData(oldp+52,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[23]),32);
    bufp->fullIData(oldp+53,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[24]),32);
    bufp->fullIData(oldp+54,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[25]),32);
    bufp->fullIData(oldp+55,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[26]),32);
    bufp->fullIData(oldp+56,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[27]),32);
    bufp->fullIData(oldp+57,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[28]),32);
    bufp->fullIData(oldp+58,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[29]),32);
    bufp->fullIData(oldp+59,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[30]),32);
    bufp->fullIData(oldp+60,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__R[31]),32);
    bufp->fullBit(oldp+61,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__flag));
    bufp->fullIData(oldp+62,(vlSelf->ysyx_24090010_exu__DOT__reg1__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+63,(vlSelf->clk));
    bufp->fullBit(oldp+64,(vlSelf->rst));
    bufp->fullCData(oldp+65,(0U),6);
    bufp->fullCData(oldp+66,(1U),6);
    bufp->fullCData(oldp+67,(2U),6);
    bufp->fullCData(oldp+68,(3U),6);
    bufp->fullCData(oldp+69,(4U),6);
    bufp->fullCData(oldp+70,(5U),6);
    bufp->fullCData(oldp+71,(6U),6);
    bufp->fullCData(oldp+72,(7U),6);
    bufp->fullCData(oldp+73,(8U),6);
    bufp->fullCData(oldp+74,(9U),6);
    bufp->fullCData(oldp+75,(0xaU),6);
    bufp->fullCData(oldp+76,(0xbU),6);
    bufp->fullCData(oldp+77,(0xcU),6);
    bufp->fullCData(oldp+78,(0xdU),6);
    bufp->fullCData(oldp+79,(0xeU),6);
    bufp->fullCData(oldp+80,(0xfU),6);
    bufp->fullCData(oldp+81,(0x10U),6);
    bufp->fullCData(oldp+82,(0x11U),6);
    bufp->fullCData(oldp+83,(0x12U),6);
    bufp->fullCData(oldp+84,(0x13U),6);
    bufp->fullCData(oldp+85,(0x14U),6);
    bufp->fullCData(oldp+86,(0x15U),6);
    bufp->fullCData(oldp+87,(0x16U),6);
    bufp->fullCData(oldp+88,(0x17U),6);
    bufp->fullCData(oldp+89,(0x18U),6);
    bufp->fullCData(oldp+90,(0x19U),6);
    bufp->fullCData(oldp+91,(0x1aU),6);
    bufp->fullCData(oldp+92,(0x1bU),6);
    bufp->fullCData(oldp+93,(0x1cU),6);
    bufp->fullCData(oldp+94,(0x1dU),6);
    bufp->fullCData(oldp+95,(0x1eU),6);
    bufp->fullCData(oldp+96,(0x1fU),6);
    bufp->fullCData(oldp+97,(0x20U),6);
    bufp->fullCData(oldp+98,(0x21U),6);
    bufp->fullCData(oldp+99,(0x22U),6);
    bufp->fullCData(oldp+100,(0x23U),6);
    bufp->fullCData(oldp+101,(0x24U),6);
    bufp->fullCData(oldp+102,(0x25U),6);
    bufp->fullCData(oldp+103,(0x26U),6);
    bufp->fullCData(oldp+104,(0x27U),6);
    bufp->fullCData(oldp+105,(0x28U),6);
    bufp->fullBit(oldp+106,(vlSelf->ysyx_24090010_exu__DOT__ifu__DOT__count));
    bufp->fullIData(oldp+107,(0x24U),32);
}

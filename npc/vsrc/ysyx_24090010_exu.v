module ysyx_24090010_exu 
(
    input clk,
    input rst
);
    wire [31:0] imm;
    wire [4:0] rs1;
    wire [4:0] rs2;
    wire [2:0] funct3;
    wire [4:0] rd;
    wire reg_wen;
    wire csr_wen;
    wire [1:0] csr_en_;
    wire ram_wen;
    wire is_b_jump;
    wire [31:0] strb;
    wire [31:0] mtvec;
    wire [31:0] mcause;
    wire [31:0] mepc;
    wire [31:0] mstatus;
    wire [31:0] pc;
    wire [31:0] result_reg;
    wire [31:0] result_ram;
    wire [31:0] rdata1;
    wire [31:0] rdata2;
    wire [31:0] ram_rdata;
    wire [31:0] ins;
    wire [5:0] ins_type;
    wire [31:0] ram_addr;
    wire [31:0] pc_jump;
    wire [31:0] r10;
    ysyx_24090010_ifu ifu (
        .clk(clk),
        .rst(rst),
        .pc_jump(pc_jump),
        .is_b_jump(is_b_jump),
        .ins_type(ins_type),
        .ins(ins),
        .pc(pc)
    );
    ysyx_24090010_idu idu (
        .clk(clk),
        .rst(rst),
        .pc(pc),
        .r10(r10),
        .imm(imm),
        .ins(ins),
        .rs1(rs1),
        .rs2(rs2),
        .funct3(funct3),
        .rd(rd),
        .ins_type(ins_type),
        .reg_wen(reg_wen),
        .csr_wen(csr_wen),
        .ram_wen(ram_wen)
    );
    ysyx_24090010_alu alu (
        .rdata1(rdata1),
        .rdata2(rdata2),
        .mtvec(mtvec),
        .mepc(mepc),
        .mcause(mcause),
        .mstatus(mstatus),
        .imm(imm),
        .pc(pc),    
        .rd(rd),
        .rs1(rs1),
        .ins_type(ins_type),
        .ram_rdata(ram_rdata),
        .result_reg(result_reg),
        .csr_en_(csr_en_),
        .ram_addr(ram_addr),
        .pc_jump(pc_jump),
        .is_b_jump(is_b_jump),
        .strb(strb),
        .result_ram(result_ram)
    );
    ysyx_24090010_reg reg1 (
        .clk(clk),
        .rst(rst),
        .ins_type(ins_type),
        .rd(rd),
        .reg_wen(reg_wen),
        .csr_wen(csr_wen),
        .csr_en_(csr_en_),
        .write_reg_data(result_reg),
        .rs1(rs1),
        .rs2(rs2),
        .mtvec(mtvec),
        .mepc(mepc),
        .mcause(mcause),
        .mstatus(mstatus),
        .read_reg_data1(rdata1),
        .read_reg_data2(rdata2),
        .r10(r10)
    );
    ysyx_24090010_ram ram (
        .clk(clk),
        .rst(rst),
        .strb(strb),
        .addr(ram_addr),
        .wdata(result_ram),
        .we(ram_wen),
        .rdata(ram_rdata)
    );

endmodule

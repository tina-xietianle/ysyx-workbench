module ysyx_24090010_exu 
(
    input clk,
    input rst

);
    wire [31:0] imm;
    wire [4:0] rs1;
    wire [2:0] funct3;
    wire [4:0] rd;
    wire [6:0] opcode;
    wire [31:0] result;
    wire [31:0] R1;
    ysyx_24090010_idu idu (
        .clk(clk),
        .rst(rst),
        .imm(imm),
        .rs1(rs1),
        .funct3(funct3),
        .rd(rd),
        .opcode(opcode)
    );
    ysyx_24090010_alu alu (
        .rs1(rs1),
        .imm(imm),
        .result(result)
    );
    
    ysyx_24090010_reg reg2 (
        .rd(rd),
        .RD(result),
        .write_en(1),
        .rs1(rs1),
        .R1(R1)
    );
endmodule
module ysyx_24090010_alu
(
    input [4:0] rs1,
    input [31:0] imm,
    output [31:0] result
);
    wire [31:0] R1;
    wire [4:0] rd;
    wire [31:0] RD;
    assign result=imm+R1;
    ysyx_24090010_reg reg1 (
        .rd(rd),
        .RD(RD),
        .write_en(0),
        .rs1(rs1),
        .R1(R1)
    );
endmodule
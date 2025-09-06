import "DPI-C" function void ebreak();
module ysyx_24090010_idu
(
    input clk,
    input rst,
    output reg [31:0] imm,
    output [4:0] rs1,
    output [2:0] funct3,
    output [4:0] rd,
    output [6:0] opcode
);
    wire [31:0] ins;
    ysyx_24090010_ifu ifu (
        .clk(clk),
        .rst(rst),
        .ins(ins)
    );
    always @(*) begin
        if(ins[31:0]==32'b00000000000100000000000001110011) begin
            ebreak();
            imm=32'b0;
        end else begin
            imm[11:0]= ins[31:20];
            if(imm[11] == 1) begin
                imm[31:12] = 20'b111111111111;
            end
            else begin
                imm[31:12] = 20'b000000000000;
            end
        end
    end
    assign rs1 = ins[19:15];
    assign funct3 = ins[14:12];
    assign rd = ins[11:7];
    assign opcode = ins[6:0];


endmodule

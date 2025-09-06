module ysyx_24090010_ifu
(
    input clk,
    input rst,
    output [31:0] ins
        

);
    reg [31:0] pc;
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            pc <= 32'h80000000;
        end
        else begin
            pc <= pc + 4;
        end
    end
    ysyx_24090010_mem mem (
        .pc(pc),
        .ins(ins)
    );

endmodule
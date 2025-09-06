
import "DPI-C" function void transfer_cpu(input int pc,input int next_pc,input int inst);
import "DPI-C" function int vaddr_ifetch_v(input int addr, input int len);
module ysyx_24090010_ifu
(
    input clk,
    input rst,
    input [31:0] pc_jump,
    input is_b_jump,
    input [5:0] ins_type,
    output reg [31:0] ins,
    output reg [31:0] pc
);
    wire [31:0] next_pc;
    reg [31:0] spc;
    reg count;
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            spc <= 32'h80000000;
        end else 
            spc <= next_pc+4;
    end
    assign next_pc = (ins_type == 6'b000010 || ins_type == 6'b000011 || is_b_jump) ? pc_jump : spc;
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            pc <= 32'h80000000;
        end else 
            pc <= next_pc;
        //  $display("pc= 0x%h", pc);
    end
    always @(*) begin

        if(rst) begin
            ins = 32'h0;
        end else begin
            // $display("npc=0x%h", next_pc);
            ins = vaddr_ifetch_v(pc, 4);
        
        end
    end
    always @(ins or next_pc) begin
        transfer_cpu(pc,next_pc,ins);
    end
endmodule

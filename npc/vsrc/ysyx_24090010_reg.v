import "DPI-C" function void load_reg(input int regv,input int i);
import "DPI-C" function void reset_reg();
module ysyx_24090010_reg 
(   
    input clk,
    input rst,
    input [5:0] ins_type,
    input [4:0] rd,
    input reg_wen,
    input csr_wen,
    input [1:0] csr_en_,
    input [31:0] write_reg_data,
    input [4:0] rs1,
    input [4:0] rs2,
    output reg [31:0] mtvec,
    output reg [31:0] mepc,
    output reg [31:0] mcause,
    output reg [31:0] mstatus,
    output [31:0]  read_reg_data1,
    output [31:0]  read_reg_data2,
    output [31:0]  r10
);
    reg [31:0] R [31:0];
    reg flag;
    always @(posedge clk or posedge rst) begin 
        if(rst) begin
            for(int i=0; i<32; i=i+1) 
                R[i] <= 32'h0;
            reset_reg();
            flag<=0;
            mcause<=32'b0;
            mtvec<=32'b0;
            mepc<=32'b0;
            mstatus<=32'h1800;
        end else if(rd != 5'b0 && reg_wen) begin // 不写$0寄存器
            if(flag)
                R[rd] <= write_reg_data;
            flag<=1;
        end else if(csr_wen) begin
            //$display("mepc: %h, mcause: %h", mepc, mcause);
            if(ins_type == 6'b100101) begin
                mepc <= write_reg_data;
                mcause <= 32'hb;
              //  $display("mepc: %h, mcause: %h", mepc, mcause);
            end else begin
                case (csr_en_)
                    2'b00: mepc <= (ins_type == 6'b100110) ? read_reg_data1 : read_reg_data1 | mepc;
                    2'b01: mcause <= (ins_type == 6'b100110) ? read_reg_data1 : read_reg_data1 | mcause;
                    2'b10: mstatus <= (ins_type == 6'b100110) ? read_reg_data1 : read_reg_data1 | mstatus;
                    2'b11: mtvec <= (ins_type == 6'b100110) ? read_reg_data1 : read_reg_data1 | mtvec;
                    default: ;
                endcase
            end
        end
    end
    always @(*) begin
        for(int n=0;n<36;n=n+1) begin
            if(n==32)
                load_reg(mstatus,n);
            else if(n==33)
                load_reg(mtvec,n);
            else if(n==34)
                load_reg(mepc,n);
            else if(n==35)
                load_reg(mcause,n);
            else
                load_reg(R[n],n);
        end
    end
    assign r10=R[5'd10];
    assign read_reg_data1 = R[rs1];
    assign read_reg_data2 = R[rs2];
    
    
    
endmodule

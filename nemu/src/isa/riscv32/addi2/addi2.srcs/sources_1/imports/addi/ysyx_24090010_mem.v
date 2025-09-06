module ysyx_24090010_mem 
(
    input [31:0] pc,
    output [31:0] ins   
    
);
    reg [31:0] mem [100:0];
    initial begin
        mem[0]={12'b000000001001,5'b00000,3'b000,5'b00001,7'b0010011};
        mem[1]={12'b000000001001,5'b00010,3'b000,5'b00011,7'b0010011};
        mem[2]=32'b00000000000100000000000001110011;

    end
    assign ins=mem[(pc-32'h80000000)/4];


endmodule

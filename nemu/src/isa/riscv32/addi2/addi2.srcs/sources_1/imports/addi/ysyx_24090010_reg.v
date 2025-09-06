module ysyx_24090010_reg 
(   
    input [4:0] rd,
    input [31:0] RD,
    input write_en,
    input [4:0] rs1,
    output reg [31:0]  R1
);
    reg [31:0] R [31:0];
    initial begin
        R[0]={27'b0,5'b10000};
        R[1]=32'b0;
        R[2]={29'b0,3'b111};
        R[3]=32'b0;
    end
    
    always @(*) begin
        if(write_en) 
            R[rd] = RD;
        $display("R1= %d",R[1]);
        $display("R3= %d",R[3]);    
    end
    always @(*) begin
        if(~write_en)
            R1 = R[rs1];
    end
    
    
    
endmodule
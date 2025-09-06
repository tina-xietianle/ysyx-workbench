module me6 (
	input clk,
	input reset,
	output [7:0] out,
	output [13:0] h
);
	reg [7:0] x;
	reg x8;
	always@(posedge clk) begin
		if(reset)
			x=8'b00000001;
		else begin
			x8=x[0]^x[2]^x[3]^x[4];
			x ={x8,x[7:1]};
		end
	end
	assign out = x;
	bcd7seg seg0 (.b(out),.h(h));
endmodule


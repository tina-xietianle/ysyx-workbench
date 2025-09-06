import "DPI-C" function int vaddr_read_v(input int addr, input int len);
import "DPI-C" function void vaddr_write_v(input int addr, input int len, input int data);
module ysyx_24090010_ram (
	input clk,
	input rst,
	input [31:0] strb,
	input [31:0] addr,
	input [31:0] wdata,
	input we,
	output reg [31:0] rdata
);
	always @(*)begin
		if(rst)
			rdata = 32'b0;
		else
			rdata = vaddr_read_v(addr, strb);
	end

	always @(posedge clk) begin
		if(we)
			vaddr_write_v(addr, strb, wdata);
	end
endmodule
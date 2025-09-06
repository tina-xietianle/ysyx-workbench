module bcd7seg (
	input [2:0] b,
	input en,
	output reg [6:0] h
);
	assign h[6]=(~b[2]&~b[1]&~b[0])|(~b[2]&~b[1]&b[0])|(b[2]&b[1]&b[0])|(~en);
	assign h[5]=(~b[2]&~b[1]&b[0])|(~b[2]&b[1]&~b[0])|(~b[2]&b[1]&b[0])|(b[2]&b[1]&b[0])|(~en);
	assign h[4]=(~b[2]&~b[1]&b[0])|(~b[2]&b[1]&b[0])|(b[2]&~b[1]&~b[0])|(b[2]&~b[1]&b[0])|(b[2]&b[1]&b[0])|(~en);
	assign h[3]=(~b[2]&~b[1]&b[0])|(b[2]&~b[1]&~b[0])|(b[2]&b[1]&b[0])|(~en);
	assign h[2]=(~b[2]&b[1]&~b[0])|(~en);
	assign h[1]=(b[2]&~b[1]&b[0])|(b[2]&b[1]&~b[0])|(~en);
	assign h[0]=(~b[2]&~b[1]&b[0])|(b[2]&~b[1]&~b[0])|(~en);
endmodule


module me2 (
	input [7:0] i,
	input en,
	output reg [2:0] y,
	output reg eno,
	output reg [6:0] h
);
	bcd7seg a (.b(y),.en(en),.h(h));
	assign y[2]=((~i[7]&~i[6]&~i[5]&i[4])|(~i[7]&~i[6]&i[5])|(~i[7]&i[6])|(i[7]))&eno;
	assign y[1]=((i[7])|(~i[7]&i[6])|(~i[7]&~i[6]&~i[5]&~i[4]&i[3])|(~i[7]&~i[6]&~i[5]&~i[4]&~i[3]&i[2]))&eno;
	assign y[0]=((i[7])|(~i[7]&~i[6]&i[5])|(~i[7]&~i[6]&~i[5]&~i[4]&i[3])|(~i[7]&~i[6]&~i[5]&~i[4]&~i[3]&~i[2]&i[1]))&eno;
	assign eno= en? 1 :0;
endmodule	

module me3 (
	input [2:0] func, 
	input [3:0] a,
	input [3:0] b,
	output reg [3:0] result,
	output reg zero, //led15
	output reg overflow,  //led8
	output reg carry,  //led5
	output reg out   //led11
);
	reg [3:0] c;
	
	always @(*) begin
		c = ~b+1;
		case (func)
			3'b000: begin //add
				{carry,result} = a+b;
				overflow = ((a[3]==b[3])&&(result[3]!=a[3]));
				out=0;
			end
			3'b001:	begin //subtract
				{carry,result} = a+c;
				overflow = ((a[3]==c[3])&&(result[3]!=a[3]));
				out =0;
			end
			3'b010: begin //not
				result = ~a;
				carry = 0;
				overflow = 0;
				out=0;
			end   
			3'b011: begin //and
				result = a&b;
				carry = 0;
				overflow = 0;
				out=0;
			end
			3'b100: begin //or
				result = a|b;
				carry = 0;
				overflow = 0;
				out=0;
			end
			3'b101: begin //xor
				result = a^b;
				carry = 0;
				overflow = 0;
				out=0;
			end
			3'b110: begin //compare
				{carry,result} = a+c;
				out = (carry==1);
				result = 4'b0000;
				carry = 0;
				overflow=0;
			end
			3'b111: begin //equal
				out = (a==b);
				result = 4'b0000;
				carry =0;
				overflow = 0;
			end
			default: begin
				out = 0;
				result = 4'b0000;
				carry =0;
				overflow = 0;
			end
		endcase
		zero = (result==4'b0000);
	end
endmodule
				

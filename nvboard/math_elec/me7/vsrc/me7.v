module me7 (
	input clk,
	input rst,
	input ps2_clk,
	input ps2_data,
	output [7:0] data,
	output reg [13:0] xian,
	output [13:0] xian2,
	output [13:0] xian3,
	output [7:0] ascii,
	output reg [13:0] xian4
);
	reg [7:0] count;
	reg flag;
	parameter loos=0,push=1;
	reg state,next_state;
	 initial begin
	 count =8'b0;
	 state=loos;
	 flag=0;
	end

	ps2_keyboard one (.clk(clk),.resetn(~rst),.ps2_clk(ps2_clk),.ps2_data(ps2_data),.out(data));//调用这个函数的到8为键盘码给data
		always @(posedge ps2_clk) begin
		if(data[7:0]==8'b11110000)begin//如果是f0
			
			next_state=loos;//下一个状态是松（0）状态
			flag=1;
		end
		else begin
			if(flag)begin//接收f0下一个码，这个和f0一起的所以还是松，但是flag变成0
				next_state=loos;
				flag=0;
			end else begin
			
			next_state=push;//按下状态（1）
			end
		end
		if(state==1 &&next_state==0)
			count=count+1;//即我松开后才计数
		else
			count=count;
		if(count[3:0]==4'b1010) begin//计数变成10进制，显而易见一些
			count[7:4]=count[7:4]+1;
			count[3:0]=4'b0000;
		end
		else
			count=count;
		$display("state: %x next_state: %x", state,next_state);//打印状态

	end
	always @(posedge ps2_clk) begin
		state = next_state;//状态传递
	end
	bcd7seg two (.b(data[7:0]),.h(xian),.state(state));//数码管显示键盘码
	bcd7seg three (.b(count),.h(xian2),.state(1));//数码管显示计数
	assign xian3=14'b11111111111111;//让前两个数码管熄灭
	scan_to_ascii four (.scan_code(data),.ascii_code(ascii));//转换为ASCII码
	bcd7seg five (.b(ascii),.h(xian4),.state(state));//数码管显示ASCII码
endmodule

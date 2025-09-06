module ps2_keyboard(clk,resetn,ps2_clk,ps2_data,out);
    input clk,resetn,ps2_clk,ps2_data;

	output reg [7:0] out;
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;

    reg [9:0] buffer;        // ps2_data bits
    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};//减少ps2clk的亚稳态错误，ps2clk到这个数组尾部
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];//当【2】是 1,【1】是0时，sampling就是1,即sampling是判断是否为下降沿的

    always @(posedge clk) begin
        if (resetn == 0) begin // reset异步复位
            count <= 0;
        end
        else begin
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit开始位，逻辑0
                    (ps2_data)       &&  // stop bit停止位，逻辑1
                    (^buffer[9:1])) begin      // odd  parity缩减异或，奇偶校验
                    $display("receive %x", buffer[8:1]);//打印接收到的键盘扫描符
					out<=buffer[8:1];//给输出
                end
                count <= 0;     // for next清零
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data将键盘的码一个一个放入，直到符合标准10个
                count <= count + 3'b1;
				
              end
            end
        end
    end

endmodule

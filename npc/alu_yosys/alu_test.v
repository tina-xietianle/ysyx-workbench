module alu_test(
    input [7:0] a, b,  // 使用8位简化分析
    input [2:0] op,
    output reg [7:0] result
);
    always @(*) begin
        case(op)
            3'b000: result = a + b;     // 加法
            3'b001: result = a - b;     // 减法
            // 3'b010: result = a < b;     // 比较
            3'b011: result = a << b[2:0]; // 左移
            3'b100: result = a >> b[2:0]; // 右移
            3'b101: result = a >>> b[2:0]; // 算术右移
            default: result = 0;
        endcase
    end
endmodule
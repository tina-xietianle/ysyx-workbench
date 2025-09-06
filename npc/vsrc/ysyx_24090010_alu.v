// import "DPI-C" function int isa_raise_intr(input int NO,input int epc); 
module ysyx_24090010_alu
(
    input [31:0] rdata1,
    input [31:0] rdata2,
    input [31:0] mtvec,
    input [31:0] mepc,
    input [31:0] mcause,
    input [31:0] mstatus,
    input [31:0] imm,
    input [31:0] pc,
    input [4:0] rd,
    input [4:0] rs1,
    input [5:0] ins_type,
    input [31:0] ram_rdata,
    output reg [31:0] result_reg,
    output reg [1:0] csr_en_,
    output reg [31:0] ram_addr,
    output reg [31:0] pc_jump,
    output reg is_b_jump,
    output reg [31:0] strb,
    output reg [31:0] result_ram
);
    always @(*) begin
        case(ins_type)
            6'b000000: result_reg = rdata1 + imm;  // addi
            6'b000001: result_reg = pc + imm ; // auipc
            6'b000010: result_reg = pc + 4; // jal
            6'b000011: result_reg = pc + 4; // jalr
            6'b000100: result_reg = imm; // lui
            6'b000111: result_reg = ram_rdata; // lw
            6'b001000: result_reg = rdata1 + rdata2; // add
            6'b001001: result_reg = rdata1 - rdata2; // sub
            6'b001010: result_reg = (rdata1 < imm) ? 32'b1 : 32'b0; // sltiu
            6'b001101: result_reg = (rdata1 < rdata2) ? 32'b1 : 32'b0; // sltu
            6'b001110: result_reg = rdata1 ^ rdata2; // xor
            6'b001111: result_reg = rdata1 | rdata2; // or
            6'b010001: result_reg = $signed(rdata1) >>> imm[4:0];//result_reg = (({32{rdata1[31]}}<<(5'd31-imm[4:0]+5'b1)) | (rdata1>>imm)); // srai
            6'b010010: result_reg = {24'b0,ram_rdata[7:0]}; // lbu
            6'b010011: result_reg = rdata1 & imm; // andi
            6'b010100: result_reg = rdata1 << rdata2[4:0]; // sll
            6'b010101: result_reg = rdata1 & rdata2; // and
            6'b010110: result_reg = rdata1 ^ imm; // xori
            6'b011001: result_reg = rdata1 >> imm[4:0]; // srli
            6'b011011: result_reg = rdata1 << imm[4:0]; // slli
            6'b011110: result_reg = ($signed(rdata1) < $signed(rdata2)) ? 32'b1 : 32'b0; // slt
            6'b011111: result_reg = {{16{ram_rdata[15]}}, ram_rdata[15:0]}; // lh
            6'b100000: result_reg = {16'b0, ram_rdata[15:0]}; // lhu
            6'b100001: result_reg = $signed(rdata1) >>> rdata2[4:0]; // sra
            6'b100010: result_reg = rdata1 >> rdata2[4:0]; // srl
            6'b100011: result_reg = rdata1 | imm; // ori
            6'b100100: result_reg = {{24{ram_rdata[7]}}, ram_rdata[7:0]}; // lb
            6'b100101: result_reg = pc; //ecall
            6'b100110: begin            //csrrw
                case (imm)
                    32'h341: result_reg = mepc;
                    32'h342: result_reg = mcause;
                    32'h300: result_reg = mstatus;
                    32'h305: result_reg = mtvec;
                    default: result_reg = 32'b0;
                endcase
            end
            6'b100111: begin            //csrrs
                case (imm)
                    32'h341: result_reg = mepc;
                    32'h342: result_reg = mcause;
                    32'h300: result_reg = mstatus;
                    32'h305: result_reg = mtvec;
                    default: result_reg = 32'b0;
                endcase
            end
            default: result_reg = 32'b0; // default case
        endcase
        //  $display("result_reg: %h", result_reg);
        //  $display("pc: %h", pc);
        //  $display("imm: %h", imm);
    end

    always @(*) begin
        case(ins_type)
            6'b000101: ram_addr = rdata1 + imm; // sw
            6'b000111: ram_addr = rdata1 + imm; // lw
            6'b010000: ram_addr = rdata1 + imm; // sh
            6'b010010: ram_addr = rdata1 + imm; // lbu
            6'b010111: ram_addr = rdata1 + imm; // sb
            6'b011111: ram_addr = rdata1 + imm; // lh
            6'b100000: ram_addr = rdata1 + imm; // lhu
            6'b100100: ram_addr = rdata1 + imm;  // lb
            default: ram_addr = 32'h80000000; // default case，这样才不会报out of bound的错误
        endcase
    end

    always @(*) begin
        case (imm)
            32'h341: csr_en_ = 2'b00;
            32'h342: csr_en_ = 2'b01;
            32'h300: csr_en_ = 2'b10;
            32'h305: csr_en_ = 2'b11;
            default: csr_en_ = 2'b0;
        endcase
    end

    always @(*) begin
        case(ins_type)
            6'b000010: begin pc_jump = pc + imm; /*print_func(pc, pc_jump,0); */end // jal
            6'b000011: begin pc_jump = (rdata1 + imm)&(32'hfffffffe); /*print_func(pc, pc_jump, (rd==0 && rs1 == 5'd1) ? 1 : 0);*/ end // jalr
            6'b001011: pc_jump = pc+imm; // beq
            6'b001100: pc_jump = pc+imm; // bne
            6'b011000: pc_jump = pc+imm; // bge
            6'b011010: pc_jump = pc+imm; // bgeu
            6'b011100: pc_jump = pc+imm; // blt
            6'b011101: pc_jump = pc+imm; // bltu
            6'b100101: pc_jump = mtvec; // mret
            6'b101000: pc_jump = mepc; // mret
            default: pc_jump = 32'b0; // default case
        endcase
        // $display("pc_jump= 0x%h", pc_jump);
    end
    always @(*)begin
        case(ins_type)
            6'b001011: is_b_jump = (rdata1 == rdata2);//beq
            6'b001100: is_b_jump = (rdata1 != rdata2);//bne
            6'b011000: is_b_jump = ($signed(rdata1) >= $signed(rdata2));//bge
            6'b011010: is_b_jump = (rdata1 >= rdata2);//bgeu
            6'b011100: is_b_jump = ($signed(rdata1) < $signed(rdata2));//blt
            6'b011101: is_b_jump = (rdata1 < rdata2);//bltu
            6'b100101: is_b_jump = 1'b1; // ecall
            6'b101000: is_b_jump = 1'b1; // mret
            default: is_b_jump = 1'b0;  // default case
        endcase
    end
    always @(*) begin
        case(ins_type)
            6'b000101:  strb=32'd4; // sw
            6'b000111:  strb=32'd4; // lw
            6'b010000:  strb=32'd2; // sh
            6'b010010:  strb=32'd1; // lbu
            6'b010111:  strb=32'd1; // sb
            6'b011111:  strb=32'd2; // lh
            6'b100000:  strb=32'd2; // lhu
            6'b100100:  strb=32'd1; // lb
            default: strb=32'd4; // default case
        endcase
    end
    assign result_ram=rdata2;
endmodule

import "DPI-C" function void ebreak();
import "DPI-C" function void invalid_inst(input int pc,input int ins);
import "DPI-C" function void set_npc_state(input int state,input int pc,input int halt_ret);
module ysyx_24090010_idu
(
    input clk,
    input rst,
    input [31:0] pc,
    input [31:0] r10,
    input [31:0] ins,
    output reg [31:0] imm,
    output [4:0] rs1,
    output [4:0] rs2,
    output [2:0] funct3,
    output [4:0] rd,
    output reg [5:0] ins_type,
    output reg reg_wen,
    output reg csr_wen,
    output reg ram_wen

);
    parameter 
        addi=6'b000000,auipc=6'b000001,jal=6'b000010, 
        jalr=6'b000011, lui=6'b000100,sw=6'b000101,
        ebreak_ins=6'b000110,lw=6'b000111,add=6'b001000,
        sub=6'b001001,sltiu=6'b001010,beq=6'b001011,
        bne=6'b001100,sltu=6'b001101,xor_=6'b001110,
        or_=6'b001111,sh=6'b010000,srai=6'b010001,
        lbu=6'b010010,andi=6'b010011,sll=6'b010100,
        and_=6'b010101,xori=6'b010110,sb=6'b010111,
        bge=6'b011000,srli=6'b011001,bgeu=6'b011010,
        slli=6'b011011,blt=6'b011100,bltu=6'b011101,
        slt=6'b011110,lh=6'b011111,lhu=6'b100000,
        sra=6'b100001,srl=6'b100010,ori=6'b100011,
        lb=6'b100100,ecall=6'b100101,csrrw=6'b100110,
        csrrs=6'b100111,mret=6'b101000;
    reg flag;
    always @(*) begin
        imm = 32'b0;
        ins_type = 6'b111111;
        flag = 0;
        reg_wen = 0;
        ram_wen = 0;
        csr_wen=0;
        if (rst) begin
            imm=32'b0;
            ins_type=6'b111111;
            flag=0;
            reg_wen=0;
            ram_wen=0;
            csr_wen=0;
        end else begin
            flag=0;
            if(pc>=32'h80000000) begin
                // $display("pc2= 0x%h", pc);
                if(ins[31:0]==32'b00000000000100000000000001110011) begin
                    set_npc_state(2,pc,r10);
                    ebreak();
                    imm=32'b0;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                    ins_type=ebreak_ins; // ebreak instruction
                end else if(ins[31:0]==32'b000000000000_00000_000_00000_11100_11) begin
                    imm=32'b0;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=1;
                    flag=0;
                    ins_type=ecall;

                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b000 )begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=addi;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100111 && ins[14:12]==3'b000)begin  //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=jalr;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0000011 && ins[14:12]==3'b010) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=lw;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b011) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=sltiu;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b101 && ins[31:26]==6'b010000) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=srai;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0000011 && ins[14:12]==3'b100) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=lbu;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b111) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=andi;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b100) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=xori;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b101 && ins[31:26]==6'b000000) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=srli;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b001 && ins[31:26]==6'b000000) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=slli;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0000011 && ins[14:12]==3'b001 ) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=lh;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0000011 && ins[14:12]==3'b101 ) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=lhu;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0010011 && ins[14:12]==3'b110 ) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=ori;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0000011 && ins[14:12]==3'b000 ) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=lb;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                // end else if(ins[31:0]==32'b000000000000_00000_000_00000_1110011) begin //i
                //     imm=32'b0;
                //     ins_type=ecall;
                //     reg_wen=0;
                //     ram_wen=0;
                //     csr_wen=1;
                //     $display("ecall");
                //     flag=0;
                end else if(ins[6:0]==7'b1110011 && ins[14:12]==3'b001) begin //i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=csrrw;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=1;
                    flag=0;
                end else if(ins[6:0]==7'b1110011 && ins[14:12]==3'b010) begin//i
                    imm={{20{ins[31]}},ins[31:20]};
                    ins_type=csrrs;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=1;
                    flag=0;


                end else if(ins[6:0]==7'b0010111) begin //u
                    imm={ins[31:12],12'b0};
                    ins_type=auipc;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                    // $display("auipc");
                end else if(ins[6:0]==7'b0110111) begin //u
                    imm={ins[31:12],12'b0};
                    ins_type=lui;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;


                end else if(ins[6:0]==7'b1101111)begin  //j
                    imm={{12{ins[31]}},ins[19:12],ins[20],ins[30:25],ins[24:21],1'b0};
                    ins_type=jal;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
            

                end else if(ins[6:0]==7'b0100011 && ins[14:12]==3'b010) begin //s
                    imm={{20{ins[31]}},ins[31:25],ins[11:7]};
                    ins_type=sw;
                    reg_wen=0;
                    ram_wen=1;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0100011 && ins[14:12]==3'b001) begin //s
                    imm={{20{ins[31]}},ins[31:25],ins[11:7]};
                    ins_type=sh;
                    reg_wen=0;
                    ram_wen=1;
                    csr_wen=0;
                    flag=0;
                end else if (ins[6:0]==7'b0100011 && ins[14:12]==3'b000) begin //s
                    imm={{20{ins[31]}},ins[31:25],ins[11:7]};
                    ins_type=sb;
                    reg_wen=0;
                    ram_wen=1;
                    csr_wen=0;
                    flag=0;

                    
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b000 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=add;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b000 && ins[31:25]==7'b0100000) begin//r
                    imm=32'b0;
                    ins_type=sub;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b011 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=sltu;
                    reg_wen=1;
                    ram_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b100 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=xor_;
                    reg_wen=1;
                    ram_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b110 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=or_;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b001 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=sll;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b111 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=and_;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b010 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=slt;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b101 && ins[31:25]==7'b0100000) begin //r
                    imm=32'b0;
                    ins_type=sra;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b0110011 && ins[14:12]==3'b101 && ins[31:25]==7'b0000000) begin //r
                    imm=32'b0;
                    ins_type=srl;
                    reg_wen=1;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[31:0]==32'b0011000_00010_00000_000_00000_11100_11) begin //r
                    imm=32'b0;
                    ins_type=mret;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;

                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b000) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=beq;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b001) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=bne;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b101) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=bge;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b111) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=bgeu;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b100) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=blt;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;
                end else if(ins[6:0]==7'b1100011 && ins[14:12]==3'b110) begin //b
                    imm={{20{ins[31]}},ins[7],ins[30:25],ins[11:8],1'b0};
                    ins_type=bltu;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    flag=0;


                end else begin
                    if(!flag) begin
                        flag=1;
                        invalid_inst(pc,ins);
                    end
                    imm=imm;
                    reg_wen=0;
                    ram_wen=0;
                    csr_wen=0;
                    ins_type=6'b111111; 
                end
            end else
                $display("错误");
        end

    end
    assign rs1 = ins[19:15];
    assign rs2 = ins[24:20];
    assign funct3 = ins[14:12];
    assign rd = ins[11:7];

endmodule

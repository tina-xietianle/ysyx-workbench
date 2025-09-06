#include <stdint.h>
#include <stdio.h>

#define NREG 4//寄存器的大小4
#define NMEM 16//内存的大小16

// 定义指令格式
typedef union {
  struct { uint8_t rs : 2, rt : 2, op : 4; } rtype;//寄存器类型的指令格式，rs、rt两个寄存器都是2位宽，op是4位的操作码
  struct { uint8_t addr : 4      , op : 4; } mtype;//内存类型的指令格式，addr是4位的地址，op是4位的操作码
  uint8_t inst;//指令
} inst_t;

#define DECODE_R(inst) uint8_t rt = (inst).rtype.rt, rs = (inst).rtype.rs//宏，即DECODE_R(inst),就是将inst中的两个寄存器的类型分别给、目标寄存器rt、源寄存器rs
#define DECODE_M(inst) uint8_t addr = (inst).mtype.addr//宏，即DECODE_R(inst)，就是将inst中的addr给addr

uint8_t pc = 0;       // PC, C语言中没有4位的数据类型, 我们采用8位类型来表示
uint8_t R[NREG] = {}; // 寄存器
uint8_t M[NMEM] = {   // 内存, 其中包含一个计算z = x + y的程序
  0b11100110,  // load  6#     | R[0] <- M[y]           op=0b1110  addr=0110
  0b00000100,  // mov   r1, r0 | R[1] <- R[0]           op=0b0000  rt=01 rs=00
  0b11100101,  // load  5#     | R[0] <- M[x]
  0b00010001,  // add   r0, r1 | R[0] <- R[0] + R[1]
  0b11110111,  // store 7#     | M[z] <- R[0]
  0b00010000,  // x = 16
  0b00100001,  // y = 33
  0b00000000,  // z = 0
};

int halt = 0; // 结束标志，0就是未结束，1在主函数会结束

// 执行一条指令
void exec_once() {
  inst_t this;
  this.inst = M[pc]; // 取指，将内存pc指向位置的东西给inst，即inst为待执行的东西
  switch (this.rtype.op) {
  //  操作码译码       操作数译码           执行
    case 0b0000: { DECODE_R(this); R[rt]   = R[rs];   break; }//将源寄存器的东西给目标寄存器
    case 0b0001: { DECODE_R(this); R[rt]  += R[rs];   break; }//将目标寄存器的东西加上源寄存器的东西
    case 0b1110: { DECODE_M(this); R[0]    = M[addr]; break; }//寄存器第0位为内存对应的位置的数，将内存的数值加载到寄存器
    case 0b1111: { DECODE_M(this); M[addr] = R[0];    break; }//将寄存器的数值存储到内存
    default:
      printf("Invalid instruction with opcode = %x, halting...\n", this.rtype.op);
      halt = 1;//即没有操作码匹配了，即结束了，将halt制1
      break;
  }
  pc ++; // 更新PC，往后执行
}

int main() {
  while (1) {
    exec_once();
    if (halt) break;
  }
  printf("The result of 16 + 33 is %d\n", M[7]);
  return 0;
}


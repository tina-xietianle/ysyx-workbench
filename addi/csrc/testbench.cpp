#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vysyx_24090010_exu.h" // Verilator生成的头文件

int finish=0;
uint32_t ins[100]={
    0b0000000'00001'00001'000'00001'00100'11, // addi ,一号寄存器加1存到一号寄存器，即自加
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
    0b0000000'00001'00001'000'00001'00100'11, 
  
    0b0000000'00001'00000'000'00000'11100'11, // ebreak
};
int ins_num=0;

int main(int argc, char **argv, char **env) {
   
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vysyx_24090010_exu* top = new Vysyx_24090010_exu;

    // 初始化波形生成
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    // 初始化信号
    top->clk = 0;
    top->rst = 1;
    
    // 复位
    for (int i = 0; i < 2; i++) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(i);
    }
    top->rst = 0;

    // 模拟时钟周期
    for (int i = 0; i >-1; i++) {
        top->clk = !top->clk;
        if(top->clk==1){//clk为上升沿时，读取指令
            top->ins=ins[ins_num];
            ins_num++;
        }
        
        if(finish==1){//用一个全局变量在ebreak出现时，改变他的数值，然后在主函数中判断，结束仿真
            printf("break\n");
            break;
            tfp->close();//结束波形生成
            top->final();//结束仿真
            delete top;//释放内存
            delete tfp;//释放内存
        }

        top->eval();
        tfp->dump(2 + i);
    }

    // 关闭波形生成
    top->final();
    tfp->close();
    delete top;
    delete tfp;
    return 0;
}
extern "C" void ebreak()
{

	Verilated::gotFinish(true);	
	finish=1;
}

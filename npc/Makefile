all:$(BIN)
BIN = $(BUILD_DIR)/$(TOPNAME)
TOPNAME= ysyx_24090010_exu#顶层模块名称
VERILATOR=verilator#verilator别称
INC_PATH ?=$(NPC_HOME)/include $(NPC_HOME)/include/cpu $(NPC_HOME)/include/memory $(NPC_HOME)/include/generated \
$(NPC_HOME)/csrc/monitor/sdb $(NPC_HOME)/csrc/isa/riscv32/include $(NPC_HOME)/csrc/isa/riscv32/local-include /usr/lib/llvm-14/include 
# $(info inc_path = $(INC_PATH))
VERILATOR_CFLAGS += -MMD  --build -cc --trace -O2 --x-assign fast --x-initial fast --noassert -I$(NPC_HOME)/vsrc #-Wall#verilator编译verilog生成c++对象的选项
BUILD_DIR=$(NPC_HOME)/build#verilator编译的obj所在之处
# $(info BIN = $(BIN))
OBJ_DIR = $(BUILD_DIR)/obj_dir
VSRCS = $(shell find $(NPC_HOME)/vsrc -name "*.v")
# $(info vsrc = $(VSRCS))
#CXXSRCS =  $(wildcard $(NPC_HOME)/csrc/utils/*.cc) $(wildcard $(NPC_HOME)/csrc/utils/*.c) $(wildcard $(NPC_HOME)/csrc/*.c ) $(wildcard $(NPC_HOME)/csrc/monitor/sdb/*.c) $(wildcard $(NPC_HOME)/csrc/monitor/*.c) $(wildcard $(NPC_HOME)/csrc/isa/riscv32/*.c ) $(wildcard $(NPC_HOME)/csrc/isa/riscv32/difftest/*.c ) $(wildcard $(NPC_HOME)/csrc/isa/riscv32/system/*.c ) $(wildcard $(NPC_HOME)/csrc/engine/interpreter/*.c ) $(wildcard $(NPC_HOME)/csrc/cpu/difftest/*.c) $(wildcard $(NPC_HOME)/csrc/memory/*.c) #testbench
CXXSRCS =	$(wildcard $(NPC_HOME)/csrc/utils/*.cc) $(wildcard $(NPC_HOME)/csrc/utils/*.c) \
			$(wildcard $(NPC_HOME)/csrc/*.c ) \
			$(wildcard $(NPC_HOME)/csrc/monitor/sdb/*.c) $(wildcard $(NPC_HOME)/csrc/monitor/*.c) \
			$(wildcard $(NPC_HOME)/csrc/isa/riscv32/*.c ) $(wildcard $(NPC_HOME)/csrc/isa/riscv32/difftest/*.c ) \
			$(wildcard $(NPC_HOME)/csrc/isa/riscv32/system/*.c ) \
			$(wildcard $(NPC_HOME)/csrc/engine/*.c) \
			$(wildcard $(NPC_HOME)/csrc/cpu/*.c) $(wildcard $(NPC_HOME)/csrc/cpu/difftest/*.c) \
			$(wildcard $(NPC_HOME)/csrc/memory/*.c)
# $(info cxxsrcs = $(CXXSRCS))
INCFLAGS = $(addprefix -I, $(INC_PATH))#verilator加路径
CXXFLAGS += $(INCFLAGS) -std=c++14   -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -O2 

# -D__STDC_FORMAT_MACROS  # 这是正常解析filelist之后手动加的宏，但是加上之后说是重复定义了所以先注释掉，后续有问题就加上
LDFLAGS += -lreadline -lLLVM-14#动态库链接

$(shell mkdir -p $(BUILD_DIR))#创建build文件夹如果存在就不创建切不报错-p的用处
# 定义如何生成最终的可执行文件 $(BIN)
override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt #将一些信息写入日志文件，以免命令行出现过多log的信息。
$(BIN): $(VSRCS) $(CXXSRCS)
	@rm -rf $(OBJ_DIR)  
	$(VERILATOR) $(VERILATOR_CFLAGS) --top-module $(TOPNAME) $(VSRCS) --exe  $(NPC_HOME)/csrc/npc_main.c $(CXXSRCS)  $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) --Mdir $(OBJ_DIR) -o $(BIN)

all:$(BIN)

run: $(BIN)
	@$(BIN) $(ARGS) $(IMG) 
.PHONY:all clean run

gdb:
	$(call git_commit, "gdb NPC")
	gdb -s $(BIN) --args $(BIN) $(ARGS) $(IMG)
clean:
	rm -rf $(BUILD_DIR)
	-@rm -f ./*.vcd

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
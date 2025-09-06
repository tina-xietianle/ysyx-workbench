all:$(BIN)
BIN = $(BUILD_DIR)/$(TOPNAME)
TOPNAME= ysyx_24090010_exu#顶层模块名称
INC_PATH ?=
VERILATOR=verilator#verilator别称
VERILATOR_CFLAGS += -MMD --build -cc -trace -O3 --x-assign fast --x-initial fast --noassert#verilator编译verilog生成c++对象的选项
BUILD_DIR=./build#verilator编译的obj所在之处
OBJ_DIR = $(BUILD_DIR)/obj_dir
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")#verilog源文件列表
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")#testbench,以及nvborad的调用
INCFLAGS = $(addprefix -I, $(INC_PATH))#verilator加路径
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""# 添加包含路径标志到 C++ 编译标志中，并定义顶层模块的名称 

$(shell mkdir -p $(BUILD_DIR))#创建build文件夹如果存在就不创建切不报错-p的用处
# 定义如何生成最终的可执行文件 $(BIN)
$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)  # 在每次构建之前，删除对象目录
	$(VERILATOR) $(VERILATOR_CFLAGS) --top-module $(TOPNAME) $^ $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) --Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

run: $(BIN)
	@$^
.PHONY:all clean run
clean:
	rm -rf $(BUILD_DIR)
	-@rm -f ./wave.vcd
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!





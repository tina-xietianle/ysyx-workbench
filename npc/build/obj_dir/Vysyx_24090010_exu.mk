# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vysyx_24090010_exu.mk

default: /home/xietianle/ysyx-workbench/npc/build/ysyx_24090010_exu

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vysyx_24090010_exu
# Module prefix (from --prefix)
VM_MODPREFIX = Vysyx_24090010_exu
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-I/home/xietianle/ysyx-workbench/npc/include \
	-I/home/xietianle/ysyx-workbench/npc/include/cpu \
	-I/home/xietianle/ysyx-workbench/npc/include/memory \
	-I/home/xietianle/ysyx-workbench/npc/include/generated \
	-I/home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb \
	-I/home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/include \
	-I/home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/local-include \
	-I/usr/lib/llvm-14/include \
	-std=c++14 \
	-fno-exceptions \
	-D_GNU_SOURCE \
	-D__STDC_CONSTANT_MACROS \
	-O2 \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-lreadline \
	-lLLVM-14 \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	cpu-exec \
	dut_cpu \
	ref \
	engine \
	hostcall \
	dut_isa \
	init \
	logo \
	reg \
	intr \
	mmu \
	paddr \
	vaddr \
	ftrace \
	monitor \
	expr \
	sdb \
	watchpoint \
	npc_main \
	disasm \
	log \
	state \
	timer \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	/home/xietianle/ysyx-workbench/npc/csrc \
	/home/xietianle/ysyx-workbench/npc/csrc/cpu \
	/home/xietianle/ysyx-workbench/npc/csrc/cpu/difftest \
	/home/xietianle/ysyx-workbench/npc/csrc/engine \
	/home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32 \
	/home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/difftest \
	/home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/system \
	/home/xietianle/ysyx-workbench/npc/csrc/memory \
	/home/xietianle/ysyx-workbench/npc/csrc/monitor \
	/home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb \
	/home/xietianle/ysyx-workbench/npc/csrc/utils \


### Default rules...
# Include list of all generated classes
include Vysyx_24090010_exu_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

cpu-exec.o: /home/xietianle/ysyx-workbench/npc/csrc/cpu/cpu-exec.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
dut_cpu.o: /home/xietianle/ysyx-workbench/npc/csrc/cpu/difftest/dut_cpu.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
ref.o: /home/xietianle/ysyx-workbench/npc/csrc/cpu/difftest/ref.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
engine.o: /home/xietianle/ysyx-workbench/npc/csrc/engine/engine.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
hostcall.o: /home/xietianle/ysyx-workbench/npc/csrc/engine/hostcall.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
dut_isa.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/difftest/dut_isa.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
init.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/init.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
logo.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/logo.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
reg.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/reg.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
intr.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/system/intr.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
mmu.o: /home/xietianle/ysyx-workbench/npc/csrc/isa/riscv32/system/mmu.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
paddr.o: /home/xietianle/ysyx-workbench/npc/csrc/memory/paddr.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
vaddr.o: /home/xietianle/ysyx-workbench/npc/csrc/memory/vaddr.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
ftrace.o: /home/xietianle/ysyx-workbench/npc/csrc/monitor/ftrace.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
monitor.o: /home/xietianle/ysyx-workbench/npc/csrc/monitor/monitor.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
expr.o: /home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb/expr.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
sdb.o: /home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb/sdb.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
watchpoint.o: /home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb/watchpoint.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_main.o: /home/xietianle/ysyx-workbench/npc/csrc/npc_main.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
disasm.o: /home/xietianle/ysyx-workbench/npc/csrc/utils/disasm.cc
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
log.o: /home/xietianle/ysyx-workbench/npc/csrc/utils/log.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
state.o: /home/xietianle/ysyx-workbench/npc/csrc/utils/state.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
timer.o: /home/xietianle/ysyx-workbench/npc/csrc/utils/timer.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
/home/xietianle/ysyx-workbench/npc/build/ysyx_24090010_exu: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-

#ifndef NPC_H__
#define NPC_H__

#include <klib-macros.h>

#include ISA_H // 通过 CFLAGS 定义的宏，展开为 "riscv/riscv.h"

// RISC-V 32E 的 trap 定义
// ebreak 指令在 32E 中与 32I 相同
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

// 设备基址定义
#define DEVICE_BASE 0xa0000000
#define MMIO_BASE 0xa0000000

// 设备地址映射
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
#define FB_ADDR         (MMIO_BASE   + 0x1000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)

// 内存配置
extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)  // 可根据需要调整
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define NPC_PADDR_SPACE \
  RANGE(&_pmem_start, PMEM_END), \
  RANGE(FB_ADDR, FB_ADDR + 0x200000), \
  RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc, screen, keyboard */

// 页表项定义
typedef uintptr_t PTE;
#define PGSIZE    4096

// RISC-V 32E 特有的定义 - 如果需要
#define RV32E_MAX_REG   16  // RISC-V 32E 只有 16 个寄存器 (x0-x15)

#endif
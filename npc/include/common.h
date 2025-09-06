/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/
//头文件及宏定义，变量类型
#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#include </home/xietianle/ysyx-workbench/npc/include/generated/autoconf.h>
#include </home/xietianle/ysyx-workbench/npc/include/macro.h>

#ifdef CONFIG_TARGET_AM
#include <klib.h>
#else
#include <assert.h>
#include <stdlib.h>
#endif

#if CONFIG_MBASE + CONFIG_MSIZE > 0x100000000ul
#define PMEM64 1
#endif

typedef uint32_t word_t;
typedef int32_t sword_t;
#define FMT_WORD "0x%08" PRIx32

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08" PRIx32
typedef uint16_t ioaddr_t;

#include </home/xietianle/ysyx-workbench/npc/include/debug.h>

#endif

#ifndef NEMU_HOME
#define NEMU_HOME "/home/xietianle/ysyx-workbench/nemu"  // 根据实际路径调整
#endif

#define NEMU_SO NEMU_HOME "/build/riscv32-nemu-interpreter-so"

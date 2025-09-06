/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;//如果定义了那个宏，就用malloc分配内存
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};//否则就用静态数组，且使用PG_ALIGN对齐
#endif
                                                            //0x80000000
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }//将客机地址偏移到主机内存的相应位置
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }//将主机内存地址偏移到客机内存的相应位置

void trace_read (paddr_t addr, int len )
{
  printf("read:  " FMT_PADDR "  len: %d\n", addr, len);//FMT_PADDR是一个宏定义，用于格式化输出paddr_t类型的数据,约等于“0x%08x”（32位）或“0x%016x”（64位） 
}
void trace_write (paddr_t addr, int len, word_t data)
{
  printf("write: " FMT_PADDR "  len: %d  data: %u\n", addr, len, data); 
}
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);//将addr强制转换为host地址，然后根据len强制转换addr的类型  
  IFDEF(CONFIG_MTRACE , trace_read(addr, len));
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE,trace_write(addr, len, data));
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("nemu: address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_MTRACE , trace_read(addr, len));
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_MTRACE,trace_write(addr, len, data));//前面return了，所以这里不会执行，所以在pmem_write里面加了trace_write，其实也可以在pmem_write前面一点点加上
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

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

#include <memory/host.h>
#include <memory/paddr.h>
//#include <device/mmio.h>
#include <isa.h>
#include <difftest.h>
// #include <am.h>
#include <sys/time.h>

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
paddr_t reg_addr = 0;
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);//将addr强制转换为host地址，然后根据len强制转换addr的类型  
  if(addr!=reg_addr)
    IFDEF(CONFIG_MTRACE , trace_read(addr, len));
  reg_addr = addr;
  // printf("read:%0x\t%0x\n",addr,ret);

  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  
  IFDEF(CONFIG_MTRACE,trace_write(addr, len, data));
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}
// static uint64_t boot_us = 0;
void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  // memset(pmem, 0, CONFIG_MSIZE);
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
  // struct timeval tv;
  // gettimeofday(&tv, NULL);
  // boot_us = (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec; 
}

int i=0;
word_t paddr_read(paddr_t addr, int len) {
  //printf("0x%08x\n",addr);
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  //IFDEF(CONFIG_MTRACE , trace_read(addr, len));
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
  if (addr == 0xa00003f8) {
    return 0;
  }
  if (addr == 0xa0000048 || addr == 0xa000004c)
     {
          uint64_t us = get_time();
          uint32_t result;
          if (addr == 0xa0000048)
               result = (uint32_t)us;
          else
               result = (uint32_t)(us >> 32);
          
          // 添加RTC外设访问追踪
          // log_device_access("RTC", addr, result, 0);
          return result;
     }
  // if (addr == 0xa0000048) {
  //   struct timeval tv;
  //   gettimeofday(&tv, NULL);
  //   uint64_t now_us = (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
  //   uint64_t uptime_us = now_us - boot_us;
  //   return (uint32_t)uptime_us; // 低32位
  // }
  // if (addr == 0xa000004c) {
  //   struct timeval tv;
  //   gettimeofday(&tv, NULL);
  //   uint64_t now_us = (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
  //   uint64_t uptime_us = now_us - boot_us;
  //   return (uint32_t)(uptime_us >> 32); // 高32位
  // }
  if(i>2)
    out_of_bound(addr);
  i++;
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (addr == 0xa00003f8) {
    putchar((char)data); // 输出一个字符到终端
    fflush(stdout);

    return;
  }
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
 // IFDEF(CONFIG_MTRACE,trace_write(addr, len, data));//前面return了，所以这里不会执行，所以在pmem_write里面加了trace_write，其实也可以在pmem_write前面一点点加上
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
  out_of_bound(addr);
}

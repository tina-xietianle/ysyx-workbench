#ifndef FTRACE_H
#define FTRACE_H

#include </home/xietianle/ysyx-workbench/nemu/include/common.h>
#include <elf.h>
#include <stdint.h>

extern int symtab_num;
extern Elf32_Sym *symtab;
extern char *strtab;
extern int print_depth;

void print_func(vaddr_t addr, vaddr_t next, int is_ret);
void treat_elf(const char *elf_file);

#endif
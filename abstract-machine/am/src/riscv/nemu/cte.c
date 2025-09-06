#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    // printf("Context dump:\n");
    // for (int i = 0; i < NR_REGS; i++) {
      // printf("gpr[%d] = 0x%x\n", i, c->gpr[i]);
    // }
    // printf("gpr[10] = 0x%x\n", c->gpr[10]);
    // printf("mepc    = 0x%x\n", c->mepc);
    // printf("mcause  = 0x%x\n", c->mcause);
    // printf("mstatus = 0x%x\n", c->mstatus);
    if (c->mcause == 0xb) { // ecall
      c->mepc += 4;         // 跳过 ecall 指令
    }
    Event ev = {0};
    // printf("mcause:%x\n", c->mcause);
    switch (c->mcause) {
      case 0xb: ev.event = EVENT_YIELD; break;   
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *ctx = (Context *)(kstack.end - sizeof(Context));
  
  memset(ctx, 0, sizeof(Context));
  
  ctx->mepc = (uintptr_t)entry;
  
  ctx->gpr[10] = (uintptr_t)arg; 
  
  ctx->mstatus = 0x1800;
  return ctx;
  // return NULL;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}

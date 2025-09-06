#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  uint32_t size = inl(VGACTL_ADDR); // 读取屏幕大小寄存器
  int w = size >> 16;
  int h = size & 0xffff;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (int i = 0; i < w * h; i++) fb[i] = 0;
  outl(SYNC_ADDR, 1);

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t size = inl(VGACTL_ADDR); // 读取屏幕大小寄存器
  uint16_t width = size >> 16;
  uint16_t height = size & 0xffff;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
  
}
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  uint32_t *pix = ctl->pixels;
  
  if (pix != NULL && w > 0 && h > 0) {
    uint32_t data = inl(VGACTL_ADDR);
    int W = data >> 16;
    int H = data & 0xffff;

    for (int j = 0; j < h; j++) {
      for (int i = 0; i < w; i++) {
        if ((x + i < W) && (y + j < H)) {
          fb[ ( j + y ) * W + ( i + x )] = pix[j * w + i];
        }
      }
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}

#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define FPS            30//一秒30帧图像
#define CPS             5
#define CHAR_W          8
#define CHAR_H         16
#define NCHAR         128
#define COL_WHITE    0xeeeeee
#define COL_RED      0xff0033
#define COL_GREEN    0x00cc33
#define COL_PURPLE   0x2a0a29

enum { WHITE = 0, RED, GREEN, PURPLE };
struct character {
  char ch;
  int x, y, v, t;//x横坐标，纵坐标，速度，消失计时器（0为正常在下落，其他表示，还有多久消失）
} chars[NCHAR];

int screen_w, screen_h, hit, miss, wrong;
uint32_t texture[3][26][CHAR_W * CHAR_H], blank[CHAR_W * CHAR_H];
          //存储每个字母的像素数据，支持三种颜色。  //清除字符显示区域的像素块
int min(int a, int b) {
  return (a < b) ? a : b;
}

int randint(int l, int r) {
  return l + (rand() & 0x7fffffff) % (r - l + 1);//用于打字游戏中产生随机字母、随机位置和速度，l到r的随机数
}

void new_char() {
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (!c->ch) {//在 chars 数组中找到一个空闲位置（c->ch == 0），用于生成新字符
      c->ch = 'A' + randint(0, 25);//随机生成一个大写字母（A~`Z`）
      c->x = randint(0, screen_w - CHAR_W);//随机生成字符的横坐标，使其不会超出屏幕边界
      c->y = 0;//纵坐标设为 0，表示从屏幕顶端开始下落
      c->v = (screen_h - CHAR_H + 1) / randint(FPS * 3 / 2, FPS * 2);
      c->t = 0;//状态计时器 t 清零，表示新生成
      return;
    }
  }
}

void game_logic_update(int frame) {
  if (frame % (FPS / CPS) == 0) new_char();//定期生成新的下落字符，随机位置和速度
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (c->ch) {
      if (c->t > 0) {  //已经是要准备消失的字符
        if (--c->t == 0) {
          c->ch = '\0';
        }
      } else {        //正常在下落的字符
        c->y += c->v;  //让他以速度为步长下落
        if (c->y < 0) {  //不正常情况的一种解决
          c->ch = '\0';
        }
        if (c->y + CHAR_H >= screen_h) {//判断是否到达底部（miss）
          miss++;
          c->v = 0;
          c->y = screen_h - CHAR_H;
          c->t = FPS;
        }
      }
    }
  }
}

void render() {
  static int x[NCHAR], y[NCHAR], n = 0;

  for (int i = 0; i < n; i++) {//清除上一帧所有字符显示区域
    io_write(AM_GPU_FBDRAW, x[i], y[i], blank, CHAR_W, CHAR_H, false);
  }

  n = 0;
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (c->ch) {
      x[n] = c->x; y[n] = c->y; n++;
      int col = (c->v > 0) ? WHITE : (c->v < 0 ? GREEN : RED);//速度大于0，下落为白色，等于0则字符已经到达底部，红色，小于0,字符被击中后向上弹回，绿色。
      io_write(AM_GPU_FBDRAW, c->x, c->y, texture[col][c->ch - 'A'], CHAR_W, CHAR_H, false);//绘制字符
    }
  }
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
  for (int i = 0; i < 40; i++) putch('\b');//用退格符清除上一帧的分数统计输出
  printf("Hit: %d; Miss: %d; Wrong: %d", hit, miss, wrong);//最后显示分数统计。
}

void check_hit(char ch) {
  int m = -1;
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (ch == c->ch && c->v > 0 && (m < 0 || c->y > chars[m].y)) {
      m = i;                       //如果有多个匹配的字符，选择纵坐标最大的那个
    }
  }
  if (m == -1) {//循环配对，若没有配对到，则m为初始数值，即-1,则是wrong，反之hit
    wrong++;
  } else {
    hit++;
    chars[m].v = -(screen_h - CHAR_H + 1) / (FPS);//计算的是让字符在 1 秒内刚好弹回到屏幕顶端的速度
  }
}


void video_init() {
  screen_w = io_read(AM_GPU_CONFIG).width;//获取屏幕宽高
  screen_h = io_read(AM_GPU_CONFIG).height;

  extern char font[];
  for (int i = 0; i < CHAR_W * CHAR_H; i++)
    blank[i] = COL_PURPLE;                  // 初始化一个字符区域的背景为紫色

  uint32_t blank_line[screen_w];
  for (int i = 0; i < screen_w; i++)      // 初始化一行的背景为紫色
    blank_line[i] = COL_PURPLE;

  for (int y = 0; y < screen_h; y ++)
    io_write(AM_GPU_FBDRAW, 0, y, blank_line, screen_w, 1, false); // 用紫色填满整个屏幕，逐行写入

  for (int ch = 0; ch < 26; ch++) {// 生成所有字母的三种颜色的像素纹理
    char *c = &font[CHAR_H * ch];
    for (int i = 0, y = 0; y < CHAR_H; y++)
      for (int x = 0; x < CHAR_W; x++, i++) {
        int t = (c[y] >> (CHAR_W - x - 1)) & 1;
        texture[WHITE][ch][i] = t ? COL_WHITE : COL_PURPLE;
        texture[GREEN][ch][i] = t ? COL_GREEN : COL_PURPLE;
        texture[RED  ][ch][i] = t ? COL_RED   : COL_PURPLE;
      }
  }
}

char lut[256] = {
  [AM_KEY_A] = 'A', [AM_KEY_B] = 'B', [AM_KEY_C] = 'C', [AM_KEY_D] = 'D',
  [AM_KEY_E] = 'E', [AM_KEY_F] = 'F', [AM_KEY_G] = 'G', [AM_KEY_H] = 'H',
  [AM_KEY_I] = 'I', [AM_KEY_J] = 'J', [AM_KEY_K] = 'K', [AM_KEY_L] = 'L',
  [AM_KEY_M] = 'M', [AM_KEY_N] = 'N', [AM_KEY_O] = 'O', [AM_KEY_P] = 'P',
  [AM_KEY_Q] = 'Q', [AM_KEY_R] = 'R', [AM_KEY_S] = 'S', [AM_KEY_T] = 'T',
  [AM_KEY_U] = 'U', [AM_KEY_V] = 'V', [AM_KEY_W] = 'W', [AM_KEY_X] = 'X',
  [AM_KEY_Y] = 'Y', [AM_KEY_Z] = 'Z',
};

int main() {
  ioe_init();
  video_init();

  panic_on(!io_read(AM_TIMER_CONFIG).present, "requires timer");
  panic_on(!io_read(AM_INPUT_CONFIG).present, "requires keyboard");

  printf("Type 'ESC' to exit\n");

  int current = 0, rendered = 0;
  uint64_t t0 = io_read(AM_TIMER_UPTIME).us;//游戏开始时的微秒数
  while (1) {
    int frames = (io_read(AM_TIMER_UPTIME).us - t0) / (1000000 / FPS);//用已经运行的微秒数除以每帧的微秒数，得到已经经过了多少帧

    for (; current < frames; current++) {
      game_logic_update(current);//更新所有字符的位置和状态
    }

    while (1) {
      AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
      if (ev.keycode == AM_KEY_NONE) break;//键盘没有任何输入，即只需要正常显示字符下落即可，跳出死循环
      if (ev.keydown && ev.keycode == AM_KEY_ESCAPE) halt(0);//如果按下ESC则退出
      if (ev.keydown && lut[ev.keycode]) {//如果按下A-Z则判断是否击中下落的字符
        check_hit(lut[ev.keycode]);   //检查集中了哪个字符
      }
    };

    if (current > rendered) {
      render();//调用render()刷新屏幕，显示所有字符和分数
      rendered = current;
    }
  }
}

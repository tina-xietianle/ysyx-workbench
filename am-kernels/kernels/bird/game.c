#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define FPS         30
#define PIPE_NUM     3
#define PIPE_W      20
#define GAP_H       60
#define PIPE_DIST  120
#define BIRD_W      16
#define BIRD_H      16
#define COL_BIRD  0xffcc00
#define COL_PIPE  0x33cc33
#define COL_BG    0x87ceeb
#define COL_GROUND 0x228B22

struct bird_t {
  int x, y;
  int v;
  int alive;
} bird;

struct pipe_t {
  int x;
  int gap_y;
} pipes[PIPE_NUM];

int screen_w, screen_h, score, game_over;

uint32_t bird_tex[BIRD_W * BIRD_H];
uint32_t *pipe_tex = NULL;
uint32_t bg_line[1024];

int randint(int l, int r) {
  return l + (rand() & 0x7fffffff) % (r - l + 1);
}

void video_init() {
  screen_w = io_read(AM_GPU_CONFIG).width;
  screen_h = io_read(AM_GPU_CONFIG).height;

  // 小鸟像素块
  for (int i = 0; i < BIRD_W * BIRD_H; i++)
    bird_tex[i] = COL_BIRD;

  // 柱子像素块
  if (pipe_tex) free(pipe_tex); // 防止重复分配
  pipe_tex = malloc(PIPE_W * screen_h * sizeof(uint32_t));
  for (int i = 0; i < PIPE_W * screen_h; i++)
    pipe_tex[i] = COL_PIPE;

  // 背景一行
  for (int i = 0; i < screen_w; i++)
    bg_line[i] = COL_BG;
}

void reset_game() {
  bird.x = screen_w / 8;
  bird.y = (screen_h - 8 - BIRD_H) / 2; // 保证小鸟在安全区域
  bird.v = 0;
  bird.alive = 1;
  score = 0;
  game_over = 0;

  for (int i = 0; i < PIPE_NUM; i++) {
    pipes[i].x = screen_w + i * PIPE_DIST;
    pipes[i].gap_y = randint(GAP_H / 2, screen_h - GAP_H / 2); // 修正缝隙范围
  }
}

void draw_ground() {
  static uint32_t ground_line[1024];
  for (int i = 0; i < screen_w; i++)
    ground_line[i] = COL_GROUND;
  for (int y = screen_h - 8; y < screen_h; y++)
    io_write(AM_GPU_FBDRAW, 0, y, ground_line, screen_w, 1, false);
}

void render() {
  // 清屏
  for (int y = 0; y < screen_h; y++)
    io_write(AM_GPU_FBDRAW, 0, y, bg_line, screen_w, 1, false);

  // 画柱子
  for (int i = 0; i < PIPE_NUM; i++) {
    int px = pipes[i].x;
    int gap_top = pipes[i].gap_y - GAP_H / 2;
    int gap_bot = pipes[i].gap_y + GAP_H / 2;
    // 上柱子
    if (gap_top > 0)
      io_write(AM_GPU_FBDRAW, px, 0, pipe_tex, PIPE_W, gap_top, false);
    // 下柱子
    if (gap_bot < screen_h)
      io_write(AM_GPU_FBDRAW, px, gap_bot, pipe_tex, PIPE_W, screen_h - gap_bot, false);
  }

  // 画小鸟
  if (bird.alive)
    io_write(AM_GPU_FBDRAW, bird.x, bird.y, bird_tex, BIRD_W, BIRD_H, false);

  draw_ground();

  // 刷新
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);

  // 分数和提示
  for (int i = 0; i < 40; i++) putch('\b');
  if (game_over)
    printf("Game Over! Score: %d   Press R to restart", score);
  else
    printf("Score: %d", score);
}

void game_logic_update(int frame) {
  if (!bird.alive) return;

  // 小鸟下落
//   bird.v = 1; // 重力
  bird.y += bird.v;

  // 柱子移动
  for (int i = 0; i < PIPE_NUM; i++) {
    pipes[i].x -= 3;
    // 柱子移出屏幕，重置到最右侧
    if (pipes[i].x + PIPE_W < 0) {
  		pipes[i].x = screen_w;
  		pipes[i].gap_y = randint(GAP_H / 2, screen_h - GAP_H / 2); // 修正
  		score++;
    }
  }

  // 碰撞检测
  for (int i = 0; i < PIPE_NUM; i++) {
    int px = pipes[i].x;
    int gap_top = pipes[i].gap_y - GAP_H / 2;
    int gap_bot = pipes[i].gap_y + GAP_H / 2;
    // 判断小鸟是否在柱子范围内
    if (bird.x + BIRD_W > px && bird.x < px + PIPE_W) {
      if (bird.y < gap_top || bird.y + BIRD_H > gap_bot) {
        bird.alive = 0;
        game_over = 1;
      }
    }
  }
  // 地面和顶部
  if (bird.y < 0 || bird.y + BIRD_H > screen_h - 8) {
    bird.alive = 0;
    game_over = 1;
  }
  if (bird.v < 1) bird.v++;
  else bird.v = 1;
}

int main() {
  ioe_init();
  video_init();
  reset_game();

  panic_on(!io_read(AM_TIMER_CONFIG).present, "requires timer");
  panic_on(!io_read(AM_INPUT_CONFIG).present, "requires keyboard");

  printf("Press SPACE to fly, R to restart, ESC to exit\n");

  int current = 0, rendered = 0;
  uint64_t t0 = io_read(AM_TIMER_UPTIME).us;
  while (1) {
    int frames = (io_read(AM_TIMER_UPTIME).us - t0) / (1000000 / FPS);

    for (; current < frames; current++) {
      game_logic_update(current);
    }

    while (1) {
      AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
      if (ev.keycode == AM_KEY_NONE){
		bird.v=1;
		break;
	  }
      if (ev.keydown && ev.keycode == AM_KEY_ESCAPE) halt(0);
      if (ev.keydown && ev.keycode == AM_KEY_SPACE && bird.alive) {
        bird.v = -8; // 跳跃
      }
      if (ev.keydown && ev.keycode == AM_KEY_R && game_over) {
        reset_game();
        t0 = io_read(AM_TIMER_UPTIME).us;
        current = rendered = 0;
      }
    };

    if (current > rendered) {
      render();
      rendered = current;
    }
  }
}
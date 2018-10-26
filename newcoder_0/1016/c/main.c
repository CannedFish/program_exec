#include <stdio.h>

#define CLK_TCK 100

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int tick = (int)((float)(b - a)/CLK_TCK + 0.5);
  int t[3];
  for(int i = 2; i >= 0; --i) {
    t[i] = tick % 60;
    tick = tick / 60;
  }
  printf("%02d:%02d:%02d\n", t[0], t[1], t[2]);
  return 0;
}

#include <stdio.h>

int main() {
  int sc[101] = {0}, N, i, d;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) {
    scanf("%d", &d);
    ++sc[d];
  }
  scanf("%d", &N);
  for(i = 0; i < N-1; ++i) {
    scanf("%d", &d);
    printf("%d ", sc[d]);
  }
  scanf("%d", &d);
  printf("%d\n", sc[d]);
  return 0;
}

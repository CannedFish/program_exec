#include <stdio.h>

int main() {
  int N, r, i, j;
  char C;
  scanf("%d %c", &N, &C);
  r = (int)(N/2.0 + 0.5);
  for(i = 0; i < N; ++i) {
    printf("%c", C);
  }
  printf("\n");
  for(i = 0; i < r-2; ++i) {
    printf("%c", C);
    for(j = 0; j < N-2; ++j) {
      printf(" ");
    }
    printf("%c\n", C);
  }
  for(i = 0; i < N; ++i) {
    printf("%c", C);
  }
  printf("\n");
  return 0;
}

#include <stdio.h>

int main() {
  char c, s[128] = {0};
  int i, sum = 0, sum2 = 0;
  while((c = getchar()) != '\n') {
    ++s[c-0];
  }
  while((c = getchar()) != '\n') {
    --s[c-0];
  }
  for(i = 0; i < 128; ++i) {
    if(s[i] < 0) sum += s[i];
    else sum2 += s[i];
  }
  sum == 0 ? printf("Yes %d\n", sum2) : printf("No %d\n", -sum);
  return 0;
}

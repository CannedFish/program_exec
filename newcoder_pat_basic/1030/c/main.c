#include <stdio.h>

int main() {
  int i, pn=0;
  long long total = 0, a = 0;
  char c;
  for(i = 0; (c = getchar()) != EOF; ++i) {
    if(c == 'P') {
      ++pn;
    } else if(c == 'A') {
      a += pn;
    } else if(c == 'T') {
      total += a;
    } else {
      continue;
    }
  }
  printf("%lld\n", total % 1000000007);
  return 0;
}

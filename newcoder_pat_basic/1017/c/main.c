#include <stdio.h>

int main() {
  int n, ns[500], num = 0, b;
  char c;
  scanf("%d %c", &n, &c);
  b = (n+1) % 2;
  n = (n+1) / 2;
  for(; n > 0; ++num) {
    ns[num] = 2*num+1;
    n -= ns[num];
  }
  if(n < 0) {
    --num;
  }
  for(int i = num-1; i >= 0; --i) {
    for(int j = 0; j < (ns[num-1]-ns[i])/2; ++j) {
      printf(" ");
    }
    for(int j = 0; j < ns[i]; ++j) {
      printf("%c", c);
    }
    printf("\n");
  }
  for(int i = 1; i < num; ++i) {
    for(int j = 0; j < (ns[num-1]-ns[i])/2; ++j) {
      printf(" ");
    }
    for(int j = 0; j < ns[i]; ++j) {
      printf("%c", c);
    }
    printf("\n");
  }
  if(n < 0) {
    printf("%d\n", 2*(n+ns[num]) + b);
  } else {
    printf("%d\n", b);
  }
  return 0 ;
}


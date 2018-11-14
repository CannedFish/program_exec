#include <stdio.h>

void calc(int *a, int *b, int *c) {
  c[2] = a[2]+29-b[2];
  c[1] = a[1]+17-1-b[1]+c[2]/29;
  c[0] = a[0]-1-b[0]+c[1]/17;
}

int main() {
  int p[3], a[3], r[3], sign = 0;
  scanf("%d.%d.%d", &p[0], &p[1], &p[2]);
  scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
  if(p[0] > a[0] 
      || (p[0] == a[0] && p[1] > a[1]) 
      || (p[0] == a[0] && p[1] == a[1] && p[2] > a[2])) {
    sign = 1;
  }
  sign == 1 ? calc(p, a, r) : calc(a, p, r);
  if(sign == 1) printf("-");
  printf("%d.%d.%d\n", r[0], r[1]%17, r[2]%29);
  return 0;
}

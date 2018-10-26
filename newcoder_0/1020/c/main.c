#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return (*(int *)a) - (*(int *)b);
}

int main() {
  int p, N, nums[100000], max = 0, l;
  scanf("%d %d", &N, &p);
  if(N <= 0) {
    printf("0\n");
    return 0;
  }
  for(int i = 0; i < N; ++i) {
    scanf("%d", &nums[i]);
  }
  qsort(nums, N, sizeof(int), cmp);
  l = 1;
  for(int i = 0, j = i+1, m = nums[i]; j < N; ++j) {
    if(nums[j] > m*p) {
      if(l > max) max = l;
      while(nums[j] > m*p) {
        m = nums[++i];
        --l;
      }
    }
    ++l;
  }
  if(l > max) max = l;
  printf("%d\n", max);
  return 0;
}


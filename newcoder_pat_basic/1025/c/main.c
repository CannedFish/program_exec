#include <stdio.h>

void insert(int *a, int n) {
  int i, j, t = a[n];
  for(i = 0; i < n; ++i) {
    if(t < a[i]) break;
  }
  for(j = n; j > i; --j) {
    a[j] = a[j-1];
  }
  a[i] = t;
}

void merge(int *a, int N, int n) {
  int i, j, _n = 2*n;
  for(i = 0; i < N; i += _n) {
    for(j = i+n; j < i+_n && j < N; ++j) {
      insert(&a[i], j-i);
    }
  }
}

int is_merge(int *b, int N, int n) {
  if(n > N/2) {
    printf("Insertion Sort\n");
    return 0;
  }
  int i, j;
  for(i = n; i < N; i += n) {
    for(j = i+1; j < i+n && j < N; ++j) {
      if(b[j] < b[j-1]) {
        printf("Insertion Sort\n");
        return 0;
      }
    }
  }
  printf("Merge Sort\n");
  return 1;
}

int main() {
  int N, a[100], b[100], num_sorted = 1, i;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  for(i = 0; i < N; ++i) {
    scanf("%d", &b[i]);
  }
  for(; num_sorted < N; ++num_sorted) {
    if(b[num_sorted] < b[num_sorted-1]) break;
  }
  if(is_merge(b, N, num_sorted) == 1) {
    merge(b, N, num_sorted);
  } else {
    insert(b, num_sorted);
  }
  for(i = 0; i < N-1; ++i) {
    printf("%d ", b[i]);
  }
  printf("%d\n", b[N-1]);
  return 0;
}

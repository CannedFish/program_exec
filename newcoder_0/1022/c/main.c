#include <stdio.h>

int main() {
  int N, no, score, ss[100001] = {0}, max = 0, m_i = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d", &no, &score);
    ss[no] += score;
    if(ss[no] > max) {
      max = ss[no];
      m_i = no;
    }
  }
  printf("%d %d\n", m_i, max);
  return 0;
}


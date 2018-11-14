#include <stdio.h>

typedef struct Node {
  int value;
  int next;
} Node_t;

int main() {
  Node_t nodes[100000];
  int head, N, K, addr, v, n;
  Node_t _head;
  Node_t *h = &_head;
  scanf("%d %d %d", &head, &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d %d", &addr, &v, &n);
    nodes[addr].value = v;
    nodes[addr].next = n;
    if(addr == head) {
      h->next = addr;
    }
  }
  if(K > 1) {
    Node_t *t = h, *q1, *q2;
    while(N >= K) {
      q1 = &nodes[t->next];
      q2 = &nodes[q1->next];
      for(int i = 0; i < K-1; ++i) {
        addr = q1->next;
        q1->next = q2->next;
        q2->next = t->next;
        t->next = addr;
        q2 = &nodes[q1->next];
      }
      t = q1;
      N -= K;
    }
  }
  int _a = h->next;
  for(; nodes[_a].next != -1; _a = nodes[_a].next) {
    printf("%05d %d %05d\n", _a, nodes[_a].value, nodes[_a].next);
  }
  printf("%05d %d %d\n", _a, nodes[_a].value, nodes[_a].next);
  return 0;
}

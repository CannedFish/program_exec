#include <stdio.h>

#define MAX 10

int main() {
  char s[123];
  sprintf(s, "%0*d", MAX, 15);
  printf("%s\n", s);
  return 0;
}

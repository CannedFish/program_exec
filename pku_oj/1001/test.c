#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"

int main() {
  char a[126] = "2269042670616168937363978068644011201";
  /* char b[126] = "567869252041"; */
  char c[126];
  memset(c, '\0', 126);
  _mul(a, a, strlen(a), strlen(a), c);
  printf("test: %s\n", c);
  /* _mul(c, b, strlen(c), strlen(b), a); */
  /* printf("test mul: %s\n", a); */
  return 0;
}

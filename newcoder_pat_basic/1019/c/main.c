#include <stdio.h>
#include <string.h>

int main() {
  char in[81], out[81], show[60], cur;
  memset(show, 0, 92);
  scanf("%s\n%s\n", in, out);
  for(char *p = in, *q = out; *p != 0; ++p) {
    if(*p == *q) {
      ++q;
    } else {
      if(*p >= 'a' && *p <= 'z') {
        cur = *p - 32;
      } else {
        cur = *p;
      }
      if(show[cur-' '] == 0) {
        show[cur-' '] = 1;
        printf("%c", cur);
      }
    }
  }
  printf("\n");
  return 0;
}


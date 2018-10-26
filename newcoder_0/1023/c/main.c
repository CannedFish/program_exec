#include <stdio.h>

int main() {
  char broken[129] = {0}, c;
  do {
    scanf("%c", &c);
    broken[(int)(c)] = 1;
    if(c >= 'A' && c <= 'Z') broken[c+32] = 1;
  } while(c != '\n');
  do {
    scanf("%c", &c);
    if(broken[(int)(c)] == 1) continue;
    if(c >= 'A' && c <= 'Z' && broken[(int)('+')] == 1) continue;
    printf("%c", c);
  } while(c != '\n');
  printf("\n");
  return 0;
}

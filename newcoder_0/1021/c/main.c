#include <stdio.h>

int main() {
  int N, w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}, sum;
  char s[19], n = 0, _n
    , M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s", s);
    sum = 0;
    _n = 0;
    for(int j = 0; j < 17; ++j) {
      if(s[j] < '0' || s[j] > '9') {
        _n = 1;
        break;
      }
      sum += w[j]*(s[j]-'0');
    }
    if(_n == 1 || s[17] != M[sum % 11]) {
      printf("%s\n", s);
      n = 1;
    }
  }
  if(n == 0) {
    printf("All passed\n");
  }
  return 0;
}

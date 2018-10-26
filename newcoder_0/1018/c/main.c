#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OLDEST 200

int main() {
  int today[3] = {2014, 9, 6}, o_day[3] = {2014, 9, 6}, y_day[3] = {0, 0, 0};
  int N, y, m, d, num = 0;
  char name[6], o_name[6], y_name[6];
  memset(name, 0, 6);
  int y_d, m_d, d_d;
  scanf("%d\n", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s %d/%d/%d\n", name, &y, &m, &d);
    y_d = today[0] - y;
    m_d = today[1] - m;
    d_d = today[2] - d;
    if(y_d > OLDEST ||
        (y_d == OLDEST && m_d > 0) ||
        (y_d == OLDEST && m_d == 0 && d_d > 0)) {
      continue;
    } else if(y > today[0] ||
        (y == today[0] && m > today[1]) ||
        (y == today[0] && m == today[1] && d > today[2])) {
      continue;
    } else {
      ++num;
      if(y < o_day[0] ||
          (y == o_day[0] && m < o_day[1]) ||
          (y == o_day[0] && m == o_day[1] && d < o_day[2])) {
        o_day[0] = y;
        o_day[1] = m;
        o_day[2] = d;
        memcpy(o_name, name, strlen(name)+1);
      }
      if(y > y_day[0] ||
          (y == y_day[0] && m > y_day[1]) ||
          (y == y_day[0] && m == y_day[1] && d > y_day[2])) {
        y_day[0] = y;
        y_day[1] = m;
        y_day[2] = d;
        memcpy(y_name, name, strlen(name)+1);
      }
    }
  }
  printf("%d %s %s\n", num, o_name, y_name);
  return 0;
}

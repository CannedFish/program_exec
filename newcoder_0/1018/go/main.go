package main

import "fmt"

func main() {
	OLDEST := 200
	var N, y, m, d, y_d, m_d, d_d int
	num := 0
	today := []int{2014, 9, 6}
	o_day := []int{2014, 9, 6}
	y_day := []int{0, 0, 0}
	var name, o_name, y_name string
	fmt.Scanf("%d\n", &N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%s %d/%d/%d\n", &name, &y, &m, &d)
		y_d = today[0] - y
		m_d = today[1] - m
		d_d = today[2] - d
		if y_d > OLDEST ||
				(y_d == OLDEST && m_d > 0) ||
				(y_d == OLDEST && m_d == 0 && d_d > 0) {
			continue
		} else if y > today[0] ||
        (y == today[0] && m > today[1]) ||
        (y == today[0] && m == today[1] && d > today[2]) {
      continue
    } else {
			num++
      if y < o_day[0] ||
          (y == o_day[0] && m < o_day[1]) ||
          (y == o_day[0] && m == o_day[1] && d < o_day[2]) {
        o_day[0] = y;
        o_day[1] = m;
        o_day[2] = d;
				o_name = name
      }
      if y > y_day[0] ||
          (y == y_day[0] && m > y_day[1]) ||
          (y == y_day[0] && m == y_day[1] && d > y_day[2]) {
        y_day[0] = y;
        y_day[1] = m;
        y_day[2] = d;
        y_name = name
      }
		}
	}
	fmt.Printf("%d %s %s\n", num, o_name, y_name)
}

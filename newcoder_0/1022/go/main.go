package main

import "fmt"

func main() {
	ss := make(map[int]int)
	var N, no, score int
	max := 0
	m_i := 0
	fmt.Scanf("%d", &N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &no, &score)
		ss[no] += score
		if ss[no] > max {
			max = ss[no]
			m_i = no
		}
	}
	fmt.Printf("%d %d\n", m_i, max)
}

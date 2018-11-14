package main

import "fmt"

func main() {
	var sc [101]int
	var N, i, d int
	fmt.Scanf("%d", &N)
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &d)
		sc[d]++
	}
	fmt.Scanf("%d", &N)
	for i = 0; i < N-1; i++ {
		fmt.Scanf("%d", &d)
		fmt.Printf("%d ", sc[d])
	}
	fmt.Scanf("%d", &d)
	fmt.Printf("%d\n", sc[d])
}

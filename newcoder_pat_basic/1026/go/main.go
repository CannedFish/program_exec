package main

import "fmt"

func main() {
	var N, r, i, j int
	var C rune
	fmt.Scanf("%d %c", &N, &C)
	r = (int)((float32)(N)/2.0 + 0.5)
	for i = 0; i < N; i++ {
		fmt.Printf("%c", C)
	}
	fmt.Printf("\n")
	for i = 0; i < r-2; i++ {
		fmt.Printf("%c", C)
		for j = 0; j < N-2; j++ {
			fmt.Printf(" ")
		}
		fmt.Printf("%c\n", C)
	}
	for i = 0; i < N; i++ {
		fmt.Printf("%c", C)
	}
	fmt.Printf("\n")
}

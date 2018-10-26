package main

import "fmt"

func main() {
	var n, b int
	var ns [500]int
	num := 0
	var c rune
	fmt.Scanf("%d %c", &n, &c)
	b = (n+1) % 2
	n = (n+1) / 2
	for ; n > 0; num++ {
		ns[num] = 2*num + 1
		n -= ns[num]
	}
	if n < 0 {
		num--
	}
	for i := num-1; i >= 0; i-- {
		for j := 0; j < (ns[num-1]-ns[i])/2; j++ {
			fmt.Printf(" ")
		}
		for j := 0; j < ns[i]; j++ {
			fmt.Printf("%c", c)
		}
		fmt.Printf("\n");
	}
	for i := 1; i < num; i++ {
		for j := 0; j < (ns[num-1]-ns[i])/2; j++ {
			fmt.Printf(" ")
		}
		for j := 0; j < ns[i]; j++ {
			fmt.Printf("%c", c)
		}
		fmt.Printf("\n")
	}
	if n < 0 {
		fmt.Printf("%d\n", 2*(n+ns[num]) + b)
	} else {
		fmt.Printf("%d\n", b)
	}
}

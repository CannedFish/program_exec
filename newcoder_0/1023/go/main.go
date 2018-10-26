package main

import "fmt"

func main() {
	var broken [129]bool
	var c byte
	for ; c != '\n'; {
		fmt.Scanf("%c", &c)
		broken[(int)(c)] = true
		if c >= 'A' && c <= 'Z' {
			broken[c+32] = true
		}
	}
	for c = 0; c != '\n'; {
		fmt.Scanf("%c", &c)
		if broken[c] || (c >= 'A' && c <= 'Z' && broken[(int)('+')]) {
			continue
		}
		fmt.Printf("%c", c)
	}
	fmt.Printf("\n")
}

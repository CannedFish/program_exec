package main

import "fmt"

func main() {
	var i, sum, sum2 int
	var s [128]int
	var ss string
	fmt.Scanf("%s", &ss)
	for i = 0; i < len(ss); i++ {
		s[ss[i]-0]++
	}
	fmt.Scanf("%s", &ss)
	for i = 0; i < len(ss); i++ {
		s[ss[i]-0]--
	}
	for i = 0; i < 128; i++ {
		if s[i] < 0 {
			sum += (int)(s[i])
		} else {
			sum2 += (int)(s[i])
		}
	}
	if sum == 0 {
		fmt.Printf("Yes %d\n", sum2)
	} else {
		fmt.Printf("No %d\n", -sum)
	}
}

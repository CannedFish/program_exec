package main

import "fmt"

func calc(a, b, c []int) {
	c[2] = a[2]+29-b[2]
	c[1] = a[1]+17-1-b[1]+c[2]/29
	c[0] = a[0]-1-b[0]+c[1]/17
}

func main() {
	var p, a, r [3]int
	sign := 0
	fmt.Scanf("%d.%d.%d", &p[0], &p[1], &p[2])
	fmt.Scanf("%d.%d.%d", &a[0], &a[1], &a[2])
	if p[0] > a[0] || (p[0] == a[0] && p[1] > a[1]) || (p[0] == a[0] && p[1] == a[1] && p[2] > a[2]) {
		sign = 1
	}
	if sign == 1 {
		calc(p[0:], a[0:], r[0:])
		fmt.Printf("-")
	} else {
		calc(a[0:], p[0:], r[0:])
	}
	fmt.Printf("%d.%d.%d\n", r[0], r[1]%17, r[2]%29)
}

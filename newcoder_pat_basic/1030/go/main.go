package main

import "fmt"

func main() {
	var i, pn, an, a_i, t_i int
	var total int64
	var a, t [100000]int64
	var s string
	fmt.Scanf("%s", &s)
	for i = 0; i < len(s); i++ {
		if s[i] == 'P' {
			pn++
		} else if s[i] == 'A' {
			an++
			a[a_i] = (int64)(pn)
			a_i++
		} else if s[i] == 'T' {
			t[t_i] = (int64)(an)
			t_i++
		} else {
			continue
		}
	}
	for i = 1; i < a_i; i++ {
		a[i] += a[i-1]
	}
	for i = 0; i < t_i; i++ {
		if t[i] > 0 {
			total += a[t[i]-1]
		}
	}
	fmt.Printf("%d\n", total % 1000000007)
}

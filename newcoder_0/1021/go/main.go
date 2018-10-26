package main

import "fmt"

func main() {
	var N, sum int
	w := [...]int{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}
	var n, _n bool
	M := [...]byte{'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'}
	var s string
	fmt.Scanf("%d", &N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &s)
		sum = 0
		_n = false
		for j := 0; j < 17; j++ {
			if s[j] < '0' || s[j] > '9' {
				_n = true
				break
			}
			sum += w[j]*(int)(s[j]-'0')
		}
		if _n || s[17] != M[sum % 11] {
			fmt.Printf("%s\n", s)
			n = true
		}
	}
	if !n {
		fmt.Printf("All passed\n")
	}
}

package main

import "fmt"

func insert(a []int, n int) {
	var i, j, t int
	t = a[n]
	for i = 0; i < n; i++ {
		if t < a[i] {
			break
		}
	}
	for j = n; j > i; j-- {
		a[j] = a[j-1]
	}
	a[i] = t
}

func merge(a []int, N, n int) {
	var i, j, _n int
	_n = 2*n
	for i = 0; i < N; i += _n {
		for j = i+n; j < i+_n && j < N; j++ {
			insert(a[i:], j-i)
		}
	}
}

func is_merge(b []int, N, n int) bool {
	if n > N/2 {
		fmt.Println("Insertion Sort")
		return false
	}
	var i, j int
	for i = n; i < N; i+=n {
		for j = i+1; j < i+n && j < N; j++ {
			if b[j] < b[j-1] {
				fmt.Println("Insertion Sort")
				return false
			}
		}
	}
	fmt.Println("Merge Sort")
	return true
}

func main() {
	var N, num_sorted, i int
	var a, b [100]int
	fmt.Scanf("%d", &N)
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &b[i])
	}
	for num_sorted = 1; num_sorted < N; num_sorted++ {
		if b[num_sorted] < b[num_sorted-1] {
			break
		}
	}
	if is_merge(b[0:], N, num_sorted) {
		merge(b[0:], N, num_sorted)
	} else {
		insert(b[0:], num_sorted)
	}
	for i = 0; i < N-1; i++ {
		fmt.Printf("%d ", b[i])
	}
	fmt.Printf("%d\n", b[N-1])
}

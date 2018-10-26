package main

import (
	"fmt"
	"sort"
)

type Data []int

func (d Data) Len() int {return len(d)}
func (d Data) Swap(i, j int) {d[i], d[j] = d[j], d[i]}
func (d Data) Less(i, j int) bool {return d[i] < d[j]}

func main() {
	var N, p, max, l int
	fmt.Scanf("%d %d", &N, &p)
	if N <= 0 {
		fmt.Printf("0\n")
		return
	}
	nums := make(Data, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &nums[i])
	}
	sort.Sort(nums)
	l = 1
	i := 0
	j := i+1
	m := nums[i]
	for ; j < N; j++ {
		if nums[j] > m*p {
			if l > max {
				max = l
			}
			for ; nums[j] > m*p; {
				i++
				m = nums[i]
				l--
			}
		}
		l++
	}
	if l > max {
		max = l
	}
	fmt.Printf("%d\n", max)
}

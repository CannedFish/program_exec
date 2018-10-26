package main

import "fmt"

func main() {
	CLK_TCK := 100
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	tick := (int)((float32)(b-a)/(float32)(CLK_TCK) + 0.5)
	var t [3]int
	for i := 2; i >= 0; i-- {
		t[i] = tick % 60
		tick = tick / 60
	}
	fmt.Printf("%02d:%02d:%02d\n", t[0], t[1], t[2])
}

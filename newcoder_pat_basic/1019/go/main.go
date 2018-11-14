package main

import "fmt"

func main() {
	var in, out string
	var show [60]byte
	var cur byte
	fmt.Scanf("%s\n%s\n", &in, &out)
	for i, j := 0, 0; i < len(in); i++ {
		if j < len(out) && in[i] == out[j] {
			j++
		} else {
			if in[i] >= 'a' && in[i] <= 'z' {
				cur = in[i] - 32
			} else {
				cur = in[i]
			}
			if show[cur-' '] == 0 {
				show[cur-' '] = 1
				fmt.Printf("%c", cur)
			}
		}
	}
	fmt.Printf("\n")
}

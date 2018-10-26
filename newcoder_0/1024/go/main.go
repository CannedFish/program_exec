package main

import "fmt"

type Rnum struct {
	bottom, top1, top2, z, gcd int64
}

func gcd(a, b int64) int64 {
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	var t int64
	for ; b != 0; {
		t = b
		b = a % b
		a = t
	}
	return a
}

func norm(r *Rnum) {
	r.gcd = gcd(r.top1, r.bottom)
	r.top1 /= r.gcd
	r.bottom /= r.gcd
	r.z = r.top1 / r.bottom
	r.top2 = r.top1 % r.bottom
}

func print_rational(r *Rnum) {
	if r.z != 0 {
		if r.z < 0 {
			fmt.Printf("(%d", r.z)
		} else {
			fmt.Printf("%d", r.z)
		}
		if r.top2 < 0 {
			r.top2 = -r.top2
		}
		if r.bottom < 0 {
			r.bottom = -r.bottom
		}
		if r.top2 != 0 {
			fmt.Printf(" %d/%d", r.top2, r.bottom)
		}
		if r.z < 0 {
			fmt.Printf(")")
		}
	} else {
		if (r.top2 < 0 && r.bottom < 0) || (r.top2 > 0 && r.bottom < 0) {
			r.top2 = -r.top2
			r.bottom = -r.bottom
		}
		if r.top2 < 0 {
			fmt.Printf("(")
		}
		if r.top2 != 0 {
			fmt.Printf("%d/%d", r.top2, r.bottom)
		} else {
			fmt.Printf("0")
		}
		if r.top2 < 0 {
			fmt.Printf(")")
		}
	}
}

func calc(a, b, c *Rnum, op byte) {
	print_rational(a)
	fmt.Printf(" %c ", op)
	print_rational(b)
	switch op {
	case '+':
		c.top1 = a.top1*b.bottom + b.top1*a.bottom
	case '-':
		c.top1 = a.top1*b.bottom - b.top1*a.bottom
	case '*':
		c.top1 = a.top1 * b.top1
	case '/':
		if b.top1 == 0 {
			fmt.Printf(" = Inf\n")
			return
		} else {
			c.top1 = a.top1 * b.bottom
			c.bottom = a.bottom * b.top1
		}
	default:
		fmt.Printf("Unknown op!")
		return
	}
	norm(c)
	fmt.Printf(" = ")
	print_rational(c)
	fmt.Printf("\n")
}

func main() {
	var a, b ,c Rnum
	fmt.Scanf("%d/%d %d/%d", &a.top1, &a.bottom, &b.top1, &b.bottom)
	norm(&a)
	norm(&b)
	c.bottom = a.bottom * b.bottom

	calc(&a, &b, &c, '+')
	calc(&a, &b, &c, '-')
	calc(&a, &b, &c, '*')
	calc(&a, &b, &c, '/')
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

var a [20]int

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	l, w, h := scanInt(), scanInt(), scanInt()
	n := scanInt()
	for i := 0; i < n; i++ {
		x, y := scanInt(), scanInt()
		a[x] += y
	}
	fmt.Fprintln(wr, solve(l, w, h))
}

func solve(l, w, h int) int {
	if l == 0 || w == 0 || h == 0 {
		return 0
	}
	ret := 1
	var i int
	for i = 19; i >= 0; i-- {
		if a[i] == 0 {
			continue
		}
		len := 1 << i
		if len > l || len > w || len > h {
			continue
		}
		a[i]--
		x, y, z := solve(l, w, h-len), solve(l, w-len, len), solve(l-len, len, len)
		if x == -1 || y == -1 || z == -1 {
			return -1
		}
		ret += x + y + z
		break
	}
	if i == -1 {
		return -1
	}
	return ret
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

func scanWord() string {
	sc.Scan()
	return sc.Text()
}

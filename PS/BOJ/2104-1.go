package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n := scanInt()
	a := make([]int, n+2)
	psum := make([]int, n+2)
	for i := 1; i <= n; i++ {
		a[i] = scanInt()
		psum[i] = psum[i-1] + a[i]
	}
	type p struct {
		x, y int
	}
	st := make([]p, 0, n)
	ans := 0
	for i := 1; i <= n+1; i++ {
		for len(st) > 0 && st[len(st)-1].x > a[i] {
			t := st[len(st)-1]
			st = st[:len(st)-1]
			pidx := 0
			if len(st) != 0 {
				pidx = st[len(st)-1].y
			}
			ans = max(ans, (psum[i-1] - psum[pidx]) * t.x)
		}
		st = append(st, p{a[i], i})
	}
	fmt.Fprintln(wr, ans)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
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

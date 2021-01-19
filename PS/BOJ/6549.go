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
	a := make([]int, 100001)
	for {
		n := scanInt()
		if n == 0 {
			break
		}
		for i := 0; i < n; i++ {
			a[i] = scanInt()
		}
		a[n] = -1
		type p struct {
			x, y int
		}
		st := make([]p, 0, n+1)
		st = append(st, p{-1, -1})
		st = append(st, p{a[0], 0})
		ans := 0
		for i := 1; i <= n; i++ {
			for st[len(st)-1].x > a[i] {
				h := st[len(st)-1].x
				st = st[:len(st)-1]
				w := i - 1 - st[len(st)-1].y
				ans = max(ans, h*w)
			}
			st = append(st, p{a[i], i})
		}
		fmt.Fprintln(wr, ans)
	}
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

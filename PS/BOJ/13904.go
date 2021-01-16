package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

type p struct {
	d, w int
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n := scanInt()
	a := make([]p, n)
	for i := 0; i < n; i++ {
		a[i] = p{scanInt(), scanInt()}
	}
	sort.Slice(a, func(i, j int) bool {
		if a[i].w == a[j].w {
			return a[i].d > a[j].d
		}
		return a[i].w > a[j].w
	})
	d := make([]bool, 1001)
	ans := 0
	for i := 0; i < n; i++ {
		for j := a[i].d; j > 0; j-- {
			if !d[j] {
				ans += a[i].w
				d[j] = true
				break
			}
		}
	}
	fmt.Fprintln(wr, ans)
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

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

type item struct {
	w, v int
}

var a []item
var d [][]int

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, k := scanInt(), scanInt()
	a = make([]item, n)
	for i := 0; i < n; i++ {
		a[i] = item{scanInt(), scanInt()}
	}
	d = make([][]int, n)
	for i := 0; i < n; i++ {
		d[i] = make([]int, k+1)
	}
	d[0][0] = 0
	if k >= a[0].w {
		d[0][a[0].w] = a[0].v
	}
	for i := 1; i < n; i++ {
		for j := 0; j <= k; j++ {
			d[i][j] = d[i-1][j]
			if j-a[i].w >= 0 {
				d[i][j] = max(d[i][j], d[i-1][j-a[i].w]+a[i].v)
			}
		}
	}
	ans := 0
	for i := 0; i <= k; i++ {
		ans = max(ans, d[n-1][i])
	}
	fmt.Fprintln(wr, ans)
}

func max(l ...int) int {
	ret := 0
	for _, x := range l {
		if ret < x {
			ret = x
		}
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

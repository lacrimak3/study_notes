package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)
var n int
var a []int

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n = scanInt()
	a = make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}
	fmt.Fprintln(wr, solve(0, n-1))
}

func solve(i, j int) int {
	if i == j {
		return a[i] * a[i]
	}
	mid := (i + j) >> 1
	ret := max(solve(i, mid), solve(mid+1, j))
	sum := a[mid]
	tm := a[mid]
	x, y := mid, mid
	for x > i || y < j{
		if x > i && (y == j || a[x-1] > a[y+1]) {
			x--
			sum += a[x]
			tm = min(tm, a[x])
		} else {
			y++
			sum += a[y]
			tm = min(tm, a[y])
		}
		ret = max(sum * tm, ret)
	}
	return ret
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
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

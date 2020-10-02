package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)
var n, c, w int
var tree = make([]int, 50)

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, c, w = scanInt(), scanInt(), scanInt()
	for i := 0; i < n; i++ {
		tree[i] = scanInt()
	}
	maxv := -987654321
	for i := 1; i <= 10000; i++ {
		v := 0
		for j := 0; j < n; j++ {
			m := tree[j] / i * c
			if tree[j]%i == 0 {
				m -= c
			}
			p := tree[j] / i * w
			if p*i-m > 0 {
				v += p*i - m
			}
		}
		if maxv < v {
			maxv = v
		}
	}
	fmt.Fprintln(wr, maxv)
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

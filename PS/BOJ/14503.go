package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

var n, m int
var r, c, d int
var g [51][51]int
var v [51][51]bool
var dx = []int{-1, 0, 1, 0}
var dy = []int{0, 1, 0, -1}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, m = scanInt(), scanInt()
	r, c, d = scanInt(), scanInt(), scanInt()
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			g[i][j] = scanInt()
		}
	}
	fmt.Fprintln(wr, solve(r, c, d))
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

func solve(r, c, d int) int {
	ret := 0
	if !v[r][c] {
		v[r][c] = true
		ret++
	}
	for i := 0; i < 4; i++ {
		d = (d + 3) % 4
		nr := r + dx[d]
		nc := c + dy[d]
		if nr < 0 || nc < 0 || nr >= n || nc >= m {
			continue
		}
		if g[nr][nc] == 1 || v[nr][nc]{
			continue
		}
		return ret + solve(nr, nc, d)
	}
	nr := r - dx[d]
	nc := c - dy[d]
	if nr < 0 || nc < 0 || nr >= n || nc >= m || g[nr][nc] == 1{
		return ret
	}
	return ret + solve(nr, nc, d)
}

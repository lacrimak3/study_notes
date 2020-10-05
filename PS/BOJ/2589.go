package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

var ma [51][]byte
var v [51][51]int
var vc int
var n, m int
var dx = [...]int{-1, 1, 0, 0}
var dy = [...]int{0, 0, -1, 1}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, m = scanInt(), scanInt()
	for i := 0; i < n; i++ {
		sc.Scan()
		ma[i] = []byte(sc.Text())
	}
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if ma[i][j] == 'L' {
				ans = max(ans, bfs(i, j))
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

func bfs(x, y int) int {
	ret := 0
	vc++
	type pair struct {
		x, y, z int
	}
	q := make([]pair, 0, 2500)
	q = append(q, pair{x, y, 0})
	v[x][y] = vc
	for len(q) > 0 {
		x, y, dist := q[0].x, q[0].y, q[0].z
		q = q[1:]
		ret = max(ret, dist)
		for i := 0; i < 4; i++ {
			nx := x + dx[i]
			ny := y + dy[i]
			if nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == vc {
				continue
			}
			if ma[nx][ny] == 'W' {
				continue
			}
			q = append(q, pair{nx, ny, dist + 1})
			v[nx][ny] = vc
		}
	}
	return ret
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

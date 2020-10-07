package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

type pair struct {
	x, y int
}

var n, s, e int
var g [100001][]pair
var p [100001]pair

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, s, e = scanInt(), scanInt(), scanInt()
	for i := 0; i < n-1; i++ {
		u, v, c := scanInt(), scanInt(), scanInt()
		g[u] = append(g[u], pair{v, c})
		g[v] = append(g[v], pair{u, c})
		p[i+1].x = -1
	}
	p[n].x = -1
	q := make([]int, 0)
	q = append(q, s)
	p[s].x = 0
Loop:
	for len(q) > 0 {
		x := q[0]
		q = q[1:]
		for _, nxt := range g[x] {
			nx := nxt.x
			c := nxt.y
			if p[nx].x != -1 {
				continue
			}
			p[nx].x = x
			p[nx].y = c
			if nx == e {
				break Loop
			}
			q = append(q, nx)
		}
	}
	maxv := 0
	ans := 0
	for i := e; i != 0; i = p[i].x {
		ans += p[i].y
		if maxv < p[i].y {
			maxv = p[i].y
		}
	}
	fmt.Fprintln(wr, ans - maxv)
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

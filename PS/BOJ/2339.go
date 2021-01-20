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
var g [][]int

// https://www.acmicpc.net/problem/2339
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n := scanInt()
	g = make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			g[i][j] = scanInt()
		}
	}
	ans := solve(0, 0, n-1, n-1, true) + solve(0, 0, n-1, n-1, false)
	if ans == 0 {
		ans = -1
	}
	fmt.Fprintln(wr, ans)
}

func solve(sx, sy, ex, ey int, dir bool) int {
	if chkBoard(sx, sy, ex, ey) {
		return 1
	}
	ret := 0
	dx, dy := 1, 0
	if dir {
		dx, dy = 0, 1
	}
	for i, j := sx+dx, sy+dy; i <= ex-dx && j <= ey-dy; i, j = i+dx, j+dy {
		if isJewel(i, j, i+(ex-sx)*(1-dx), j+(ey-sy)*(1-dy)) {
			continue
		}
		if dir {
			if !isJewel(sx, sy, ex, j-1) || !isJewel(sx, j+1, ex, ey) {
				continue
			}
			ret += solve(sx, sy, ex, j-1, !dir) * solve(sx, j+1, ex, ey, !dir)
		} else {
			if !isJewel(sx, sy, i-1, ey) || !isJewel(i+1, sy, ex, ey) {
				continue
			}
			ret += solve(sx, sy, i-1, ey, !dir) * solve(i+1, sy, ex, ey, !dir)
		}
	}
	return ret
}

func chkBoard(sx, sy, ex, ey int) bool {
	je, ma := 0, 0
	for i := sx; i <= ex; i++ {
		for j := sy; j <= ey; j++ {
			if g[i][j] == 2 {
				je++
			}
			if g[i][j] == 1 {
				ma++
			}
		}
	}
	if je != 1 || ma != 0 {
		return false
	}
	return true
}

func isJewel(sx, sy, ex, ey int) bool {
	for i := sx; i <= ex; i++ {
		for j := sy; j <= ey; j++ {
			if g[i][j] == 2 {
				return true
			}
		}
	}
	return false
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

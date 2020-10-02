package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int = 19
var a [21][21]int
var dx = [...]int{0, 1, -1, 1}
var dy = [...]int{1, 1, 1, 0}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			fmt.Fscanf(reader, "%d ", &a[i][j])
		}
		fmt.Fscanf(reader, "%d")
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if a[i][j] != 0 && checkWin(i, j) {
				fmt.Fprintln(writer, a[i][j])
				fmt.Fprintln(writer, i, j)
				return
			}
		}
	}

	fmt.Fprintln(writer, 0)
}

func checkWin(x, y int) bool {
	d := a[x][y]
	for i := 0; i < 4; i++ {
		px := x - dx[i]
		py := y - dy[i]
		if a[px][py] == d {
			continue
		}
		nx := x
		ny := y
		for j := 0; j < 6; j++ {
			if j == 5 {
				if a[nx][ny] != d {
					return true
				}
			}
			if a[nx][ny] != d {
				break
			}
			nx += dx[i]
			ny += dy[i]
		}
	}
	return false
}

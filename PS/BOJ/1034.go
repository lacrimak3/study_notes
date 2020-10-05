package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

var a [51]string
var n, m, k int

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, m = scanInt(), scanInt()
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i] = sc.Text()
	}
	k = scanInt()
	ans := -1
	for i := 0; i < n; i++ {
		tmp := 0
		cnt := 0
		for j := 0; j < m; j++ {
			if a[i][j] == '0' {
				cnt++
			}
		}
		if cnt <= k && (k-cnt)%2 == 0 {
			for j := 0; j < n; j++ {
				if a[i] == a[j] {
					tmp++
				}
			}
		}
		if ans < tmp {
			ans = tmp
		}
	}

	fmt.Fprintln(wr, ans)
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

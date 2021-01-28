package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n := scanInt()
	k := scanInt()
	s, e := 0, int(1e9)+1
	for s < e {
		m := (s + e) >> 1
		if chkLast(m, n, k) {
			e = m
		} else {
			s = m + 1
		}
	}
	fmt.Fprintln(wr, e)
}

func chkLast(last, n, k int) bool {
	cnt := 0
	for i := 1; i <= n; i++ {
		t := last / i
		if t > n {
			t = n
		}
		cnt += t
	}
	if cnt >= k {
		return true
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

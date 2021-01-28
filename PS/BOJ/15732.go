package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

type rule struct {
	a, b, c int
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, k, d := scanInt(), scanInt(), scanInt()
	a := make([]rule, k)
	for i := 0; i < k; i++ {
		a[i] = rule{scanInt(), scanInt(), scanInt()}
	}
	s, e := 1, n
	for s < e {
		m := (s + e) >> 1
		if chkLastBox(k, d, m, a) {
			e = m
		} else {
			s = m + 1
		}
	}
	fmt.Fprintln(wr, e)
}

func chkLastBox(k, d, last int, a []rule) bool {
	cnt := 0
	for i := 0; i < k; i++ {
		if last < a[i].a {
			continue
		}
		e := last
		if e > a[i].b {
			e = a[i].b
		}
		cnt += (e - a[i].a) / a[i].c + 1
	}
	if cnt >= d {
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

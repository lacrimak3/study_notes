package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

type hero struct {
	t, a, h int
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	n, hAtk := scanInt(), scanInt()
	a := make([]hero, n)
	for i := 0; i < n; i++ {
		a[i].t, a[i].a, a[i].h = scanInt(), scanInt(), scanInt()
	}
	s, e := 0, int(1e18)+1
	for s < e {
		m := (s + e) >> 1
		if chkClear(n, hAtk, m, a) {
			e = m
		} else {
			s = m + 1
		}
	}
	fmt.Fprintln(wr, e)
}

func chkClear(n, hAtk, hMaxHP int, a []hero) bool {
	hCurHP := hMaxHP
	for i := 0; i < n; i++ {
		switch a[i].t {
		case 1:
			cnt := a[i].h / hAtk
			if a[i].h%hAtk != 0 {
				cnt++
			}
			hCurHP -= (cnt - 1) * a[i].a
			if hCurHP <= 0 {
				return false
			}
		case 2:
			hAtk += a[i].a
			hCurHP += a[i].h
			if hCurHP > hMaxHP {
				hCurHP = hMaxHP
			}
		}
	}
	return true
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

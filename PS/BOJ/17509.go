package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	d := []int{}
	v := 0
	for i := 0; i < 11; i++ {
		x, y := scanInt(), scanInt()
		d = append(d, x)
		v += y
	}
	ans := v * 20
	sort.Ints(d)
	sum := 0
	for i := 0; i < 11; i++ {
		sum += d[i]
		ans += sum
	}
	fmt.Fprintln(wr, ans)
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

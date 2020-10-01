package main

import (
	"bufio"
	"fmt"
	"os"
)

func max(a *[10]int) int {
	maxv := a[0]
	for _, i := range a {
		if maxv < i {
			maxv = i
		}
	}
	return maxv
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var a [10]int
	var s string
	fmt.Fscanln(reader, &s)
	for _, c := range s {
		if c == '9' || c == '6' {
			if a[6] < a[9] {
				a[6]++
			} else {
				a[9]++
			}
		} else {
			a[c-'0']++
		}
	}
	fmt.Fprintln(writer, max(&a))
}

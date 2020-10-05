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
	sc.Buffer(make([]byte, 510000), 510000)
	defer wr.Flush()
	n, k := scanInt(), scanInt()
	sc.Scan()
	s := sc.Bytes()
	var ans []byte
	for i := 0; i < n; i++ {
		for k > 0 && len(ans) > 0 && ans[len(ans) - 1] < s[i] {
			ans = ans[:len(ans) - 1]
			k--
		}
		ans = append(ans, s[i])
	}
	if k > 0 {
		for i := 0; i <= 9; i++ {
			c := byte(i + '0')
			j := 0
			for j = 0; j < len(ans); j++ {
				if ans[j] == c {
					ans[j] = '.'
					k--
					if k == 0 {
						break
					}
				}
			}
			if j != n {
				break
			}
		}
	}
	for i := 0; i < len(ans); i++ {
		if ans[i] == '.' {
			continue
		}
		fmt.Fprintf(wr, "%c", ans[i])
	}
}

func scanInt() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

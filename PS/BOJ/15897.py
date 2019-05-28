import sys
import collections
from math import floor, ceil, log2, log
#sys.stdin = open('input.txt', 'r')
inp = lambda: sys.stdin.readline().strip()

n = int(inp())
i = 1
ans = 0
while i <= n:
    cnt = (n - 1) // i
    if cnt == 0:
        len = 1
    else:
        len = (n - 1) // cnt - i + 1
    ans += (cnt + 1) * len
    i = i + len
print(ans)
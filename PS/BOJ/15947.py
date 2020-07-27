import random
import sys
# sys.stdin = open("input.txt", "r")

inp = lambda: sys.stdin.readline().strip()

bs = ["baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"]
n = int(inp())
n -= 1
cnt = n // len(bs)
idx = n % len(bs)
turu = [3, 7, 11]
tururu = [2, 6, 10]

if idx in turu:
    if cnt >= 4:
        print(f"tu+ru*{cnt+1}")
    else:
        print(f"turu{'ru'*(cnt)}")
elif idx in tururu:
    if cnt >= 3:
        print(f"tu+ru*{cnt+2}")
    else:
        print(f"tururu{'ru'*cnt}")
else:
    print(bs[idx])

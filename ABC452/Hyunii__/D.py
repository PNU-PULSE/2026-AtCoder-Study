import sys
input = sys.stdin.readline
from collections import deque, defaultdict
from bisect import bisect_left

s = input().rstrip()
t = input().rstrip()

total = len(s)*(len(s)+1) // 2

pos = defaultdict(list)
for idx, c in enumerate(s):
    pos[c].append(idx)

# print(pos)
sub = 0
for i in range(len(s)):
    start = i
    check = True

    for c in t:
        arr = pos[c]
        idx = bisect_left(arr, start)
        if idx == len(arr):
            check = False
            break
        
        start = arr[idx] + 1

    if check:
        end = start - 1
        sub += len(s) - end
    
    # print(i, end, sub)

ans = total - sub
print(ans)

"""
start, end

abrakadabra     11*12 // 2 = 66
aba

1: 4 ~ 11 = 8
2: 11 = 1
3: 11 = 1
... 
8: 11 = 1
=> 8 + 7 = 15


"""

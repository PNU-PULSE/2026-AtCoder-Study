import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
from collections import deque

n = int(input())
arr = list(map(int, input().split()))

cds = []
def dfs(idx, cur, cnt):
    if idx == n:
        cds.append(cnt)
        return cnt
    
    for i in [1, -1]:
        nxt = cur + (i * arr[idx])

        if cur > 0 and nxt < 0 or cur < 0 and nxt > 0:
            dfs(idx+1, nxt, cnt+1)
        else:
            dfs(idx+1, nxt, cnt)

dfs(0, 0.5, 0)
print(max(cds))
    


"""
5
2 5 2 2 1
 
"""
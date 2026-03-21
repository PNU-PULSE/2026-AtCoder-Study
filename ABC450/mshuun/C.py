import sys
from collections import deque

input = sys.stdin.readline
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def bfs(sr, sc):
    q = deque([(sr, sc)])
    S[sr][sc] = "#"
    
    while q:
        cr, cc = q.popleft()
        
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]

            if 0 <= nr < H and 0 <= nc < W:
                if S[nr][nc] == ".":
                    S[nr][nc] = "#"
                    q.append((nr, nc))

for i in range(W):
    if S[0][i] == ".":
        bfs(0, i)
    if S[H-1][i] == ".":
        bfs(H-1, i)
        
for i in range(H):
    if S[i][0] == ".":
        bfs(i, 0)
    if S[i][W-1] == ".":
        bfs(i, W-1)

cnt = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == ".":
            cnt += 1
            bfs(i, j)

print(cnt)
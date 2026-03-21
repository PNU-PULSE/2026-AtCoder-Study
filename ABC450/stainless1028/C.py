import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip("\n")
print = lambda *s: sys.stdout.write(" ".join(map(str, s)) + "\n")
mi = lambda: map(int, input().split())

h, w = mi()
grid = [list(input()) for _ in range(h)]
cnt = 0


dr = [0, 0, -1, 1]
dc = [-1, 1, 0, 0]
for r in range(h):
    for c in range(w):
        if grid[r][c] == ".":
            grid[r][c] = "v"
            q = deque([(r, c)])
            border = False
            while q:
                cur_r, cur_c = q.popleft()
                if cur_r == 0 or cur_r == h - 1 or cur_c == 0 or cur_c == w - 1:
                    border = True
                for i in range(4):
                    nr = cur_r + dr[i]
                    nc = cur_c + dc[i]
                    if not (0 <= nr < h and 0 <= nc < w):
                        continue
                    if grid[nr][nc] != ".":
                        continue
                    grid[nr][nc] = "v"
                    q.append((nr, nc))
            if not border:
                cnt += 1

print(cnt)

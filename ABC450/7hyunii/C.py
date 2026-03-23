import sys
input = sys.stdin.readline
from collections import deque
dxdy = [(1,0), (0,1), (-1,0), (0,-1)]

h, w = map(int, input().split())
board = [list(input().strip()) for _ in range(h)]
#print(board)

def BFS(x, y):
	check = False
	if x == 0 or x == h-1  or y == 0 or y == w-1:   
		check = True

	Q = deque()
	Q.append((x, y))
	board[x][y] = "#"
	
	while Q:
		x, y = Q.popleft()
		for i in range(4):
			nx = x + dxdy[i][0]
			ny = y + dxdy[i][1]
			if 0 <= nx < h and 0 <= ny < w and board[nx][ny] == ".":
				board[nx][ny] = "#"
				if nx == 0 or nx == h-1 or ny == 0 or ny == w-1:
					check = True
				Q.append((nx, ny))
				
	return check

ans = 0
for i in range(h):
	for j in range(w):
		if board[i][j] == ".":			
			if not BFS(i, j):
				ans += 1

print(ans)
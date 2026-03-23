import sys
input = sys.stdin.readline

n = int(input())
C = [[0]*n for _ in range(n)]

for i in range(n-1):
	arr = list(map(int, input().split()))
	for idx in range(len(arr)):
		C[i][i+idx+1] = arr[idx]
#print(C)

for a in range(n):
	for b in range(a+1, n):
		for c in range(b+1, n):
			if C[a][b] + C[b][c] < C[a][c]:
				print("Yes")
				sys.exit(0)

print("No")
import sys
input = sys.stdin.readline

n = int(input())
C = [[*map(int, input().split())] for _ in range(n-1)]

for a in range(n-2):
    for b in range(a+1, n-1):
        for c in range(b+1, n):
            if C[a][b-a-1] + C[b][c-b-1] < C[a][c-a-1]:
                print("Yes")
                exit()

print("No")
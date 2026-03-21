import sys
input = lambda: sys.stdin.readline().rstrip("\n")
print = lambda *s: sys.stdout.write(" ".join(map(str, s)) + "\n")
mi = lambda: map(int, input().split())

n = int(input())
cost = [[] for _ in range(n + 1)]
for i in range(1, n):
    cost[i] = [0] * (i + 1) + [*mi()]

for a in range(1, n - 1):
    for b in range(a + 1, n):
        for c in range(b + 1, n + 1):
            if cost[a][b] + cost[b][c] < cost[a][c]:
                print("Yes")
                sys.exit(0)
print("No")

import sys
input = lambda: sys.stdin.readline().rstrip("\n")
mi = lambda: map(int, input().split())

n = int(input())
print(*range(n, 0, -1), sep=",")
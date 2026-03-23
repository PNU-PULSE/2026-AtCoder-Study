import sys
input = sys.stdin.readline

n = int(input())
print(",".join(str(i) for i in range(n, 0, -1)))

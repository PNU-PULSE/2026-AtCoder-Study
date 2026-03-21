import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = sorted([int(x) % K for x in input().split()])

if N == 1:
    print(0)
else:
    mini = A[-1] - A[0]
    for i in range(N - 1):
        diff = A[i] + K - A[i+1]
        if diff < mini:
            mini = diff
    print(mini)
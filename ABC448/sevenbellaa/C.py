import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
A = list(map(int, input().split()))
ai = [(i+1, v) for i, v in enumerate(A)]
ai.sort(key=lambda x: x[1])

for _ in range(Q):
    K = int(input())
    B = set(map(int, input().split()))
    for i, v in ai:
        if (i not in B):
            print(v)
            break
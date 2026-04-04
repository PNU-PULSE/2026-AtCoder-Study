import sys
import math
import heapq
from collections import deque, defaultdict, Counter
from itertools import permutations, combinations, product
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(int(1e6))
inf = math.inf
input = lambda: sys.stdin.readline().rstrip("\n")

MOD = int(1e9 + 7)

drc = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def init():

    return

def solve():
    M, D = map(int, input().split())
    if M == 1:
        if D == 7:
            print("Yes")
        else:
            print("No")
    elif M % 2 == 1 and M == D and M <= 9:
        print("Yes")
    else:
        print("No")
    return 

if __name__ == "__main__":
    init()
    t = 1
    # t = int(input())
    while t:
        t -= 1
        solve()
        
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
    n = input()
    s = input()
    t = input()
    flag = True
    for i in range(len(s)):
        if s[i] != t[i] and t[i] != '*':
            flag = False

    if flag:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    init()
    t = 1
    #t = int(input())
    while t:
        t -= 1
        solve()
        
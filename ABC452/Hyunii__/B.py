import sys
input = sys.stdin.readline
from collections import deque

h, w = map(int, input().split())


for i in range(h):
    row = []
    for j in range(w):
        if i == 0 or i == h-1 or j == 0 or j == w-1:
            row.append("#")
        else:
            row.append(".")
            
    print(*row, sep="")


"""

"""

import sys
input = sys.stdin.readline
from collections import deque

t, x = map(int, input().split())
arr = list(map(int, input().split()))

last = arr[0]
for i in range(t+1):
    if i == 0:
        print(i, arr[i])
    
    else:
        if abs(last - arr[i]) >= x:
            print(i, arr[i])
            last = arr[i]


"""

      
"""
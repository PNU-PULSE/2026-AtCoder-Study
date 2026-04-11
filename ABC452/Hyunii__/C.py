import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))

m = int(input())
words = []
for _ in range(m):
    s = input().rstrip()
    words.append(s)

availables = []
for a, b in arr:
    help = set()
    for word in words:
        if len(word) == a:
            help.add(word[b-1])
    availables.append(help)
# print(availables)

for word in words:
    No = False
    if len(word) == n:
        for i in range(len(word)):
            if word[i] not in availables[i]:
                No = True
                break
    else:
        No = True

    if No:
        print("No")
    else:
        print("Yes")
    

"""
availables?     a, b -- words 

1 (t, r, c)
2 (e, h, t)
3 (t, c, r)
4 (r, c, i)
5 (o, s)

retro   OOOOO
chris   OOOOO
itchy   X
X
X
X
X

TLE == ?


"""

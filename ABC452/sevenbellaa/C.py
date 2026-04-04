import sys
input = sys.stdin.readline

N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]

M = int(input())
S = [input().rstrip() for _ in range(M)]
Sdict = {}

for i in S:
    if len(i) in Sdict: Sdict[len(i)].append(i)
    else: Sdict[len(i)] = [i]

spine = set()
for i, (a, b) in enumerate(AB):
    for s in Sdict[a]:
        spine.add((i, s[b-1]))

for s in S:
    if len(s) != N:
        print("No")
        continue
    
    flag = True
    for i, v in enumerate(s):
        if (i, v) not in spine:
            flag = False
            break
    if flag: print("Yes")
    else: print("No")
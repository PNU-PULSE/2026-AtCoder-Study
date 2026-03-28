import sys
input = sys.stdin.readline

n, k = map(int, input().split())
A = list(map(int, input().split()))

case = []
for i in A:
    case.append(i % k)
case.sort()
#print(case)

check = []
for i in range(n-1):
    check.append(case[i+1] - case[i])
check.append(case[0] + k - case[-1])
#print(check)

print(k - max(check))


# +10
# 3: 3 13 23 33 => mod: 3
# 21: 21 31 41 51 => mod: 1
# 9: 9 19 29 39 => mod: 9

# 1 3 9 1(+10)
# 2 6 2 => max: 3~9
# -> 9 11 13

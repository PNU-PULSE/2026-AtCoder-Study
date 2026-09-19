N = int(input())
S = input()
T = input()
for i in range(N):
    if T[i] == '*':
        continue
    if T[i] != S[i]:
        print("No")
        break
else:
    print("Yes")

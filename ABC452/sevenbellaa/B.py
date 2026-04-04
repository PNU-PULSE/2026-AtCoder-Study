n, m = map(int, input().split())
print("#" * m)
for _ in range(n-2):
    print("#" + "."*(m-2) + "#")
print("#" * m)
N = int(input())
ns = [set() for _ in range(10)] 

for i in range(30):
    n = 2**i
    ns[len(str(n))].add(n)

for tar in range(2, 10):
    for cur in range(1, tar // 2 + 1):
        for a in ns[cur]:
            for b in ns[tar - cur]:
                ns[tar].add(int(str(a) + str(b)))
                ns[tar].add(int(str(b) + str(a)))


ans = sorted(set().union(*ns))
print(ans[N - 1])
from collections import deque
N = int(input())
A = list(map(int, input().split()))
queue = deque(A[3:])
top = sorted(A[:3], reverse=True)
print(top[2])
if N > 3:
    for i in range(4, N+1):
        target = queue.popleft()
        #case 1 target이 제일 크거나 0번이랑 같아
        if target >= top[0]:
            top = [target, top[0], top[1], top[2]]
        #case 2 target이 0번보단 작은데 1번보다 크거나 같아
        elif target < top[0] and target >= top[1]:
            top = [top[0], target, top[1], top[2]]
        #case 3 target이 1번보단 작은데 2번보다 크거나 같아
        elif target < top[1] and target >= top[2]:
            top = [top[0], top[1], target, top[2]]
        else:
            top.append(target)
        #case 4 target이 2번보다 작아 -> 그대로
        print(top[2])
        top.pop()
        


    

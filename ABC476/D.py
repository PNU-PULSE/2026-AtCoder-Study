N,M,K = map(int, input().split())
X, Y = map(int, input().split())
A = list(map(int,input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()
#살 수 있는 상품의 수
quantity = 0


for price in B:
    totMoney = K * Y
    if price > totMoney:
        break
    #Y를 계속 줄여갈겁니다
    quantity += 1
    #딱 떨어진다면
    if price % K == 0:
        #내야 하는 값 만큼 내고 Y를 줄인다
        Y -= price // K
    #딱 떨어지지 못했어!
    else:
        #잔돈 게산용
        temp = (price // K) * K
        #1달러 갯수를 계산
        X += price - temp
        Y -= price // K + 1

for price in A:
    kTotMoney = K * Y
    #난 상품을 못사
    if price > (kTotMoney + X):
        break
    #X와 Y 둘다 줄여갈겁니다
    quantity += 1
    #만약에 내가 k지패로만 이걸 살수 있다
    if price <= kTotMoney:
        #딱 떨어진다면
        if price % K == 0:
            #내야 하는 값 만큼 내고 Y를 줄인다
            Y -= price // K
        #딱 떨어지지 못했어!
        else:
            #잔돈 게산용
            temp = (price // K) * K
            #1달러 갯수를 계산
            X += price - temp
            Y -= price // K + 1
    #아니야, 나는 이걸 k 지패로만은 못사
    else:
        #일단 k 지패로 낼 수 있는 만큼은 내
        price -= kTotMoney
        #난 이제 k 지패는 없어
        Y = 0
        #1달러로 이제 내
        X -= price

print(quantity)

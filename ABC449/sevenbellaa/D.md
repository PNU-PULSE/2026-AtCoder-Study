Edited D.cpp
Viewed D.cpp:29-43

네, 정확하게 짚으셨습니다! 이 방식은 **1차원 누적합을 2차원으로 확장하면서 포함-배제의 원리(Inclusion-Exclusion Principle)를 대수학적으로 매우 우아하게 적용한 것**입니다.

왜 `sx * sy`로 곱하기만 하면 모든 부호가 알아서 딱딱 맞아떨어지는지, 수식을 통해 차근차근 설명해 드릴게요.

---

### 1. 1차원에서의 원리 먼저 이해하기
어떤 함수 $f(x)$가 있을 때, 구간 $[A, B]$의 합을 구한다고 해보겠습니다.
이 합을 0부터 $X$까지의 합인 `Prefix(X)`를 이용해서 나타내면, 우리가 작성한 `get_ranges`가 리턴하는 `(X, sx)` 쌍들의 합으로 표현됩니다.

$$ \sum_{x=A}^B f(x) = \sum_{(X, sx)} \Big( sx \times \text{Prefix}(X) \Big) $$

* **양수 구간 (예: $A=2, B=5$):** `Prefix(5) - Prefix(1)` 이므로 $sx$는 각각 `+1, -1`이 됩니다.
* **0을 걸치는 구간 (예: $A=-2, B=3$):** `Prefix(3) + Prefix(2) - Prefix(0)` 이므로 $sx$는 `+1, +1, -1`이 됩니다.

즉, **구간이 어떻게 생겼든 무조건 위 시그마 공식 하나로 1차원 합이 계산됩니다.**

---

### 2. 2차원으로의 확장 (대입법)
우리가 구하고 싶은 것은 2차원 사각형 안의 합입니다.
$$ \text{Total} = \sum_{x=L}^R \left( \sum_{y=D}^U f(x, y) \right) $$

먼저 안쪽에 있는 $y$에 대한 1차원 합을 위의 공식으로 바꿔보겠습니다.
여기서 `PrefixY(x, Y)`는 특정한 $x$ 위치에서 $y$가 $0 \sim Y$까지일 때의 합입니다.

$$ \sum_{y=D}^U f(x, y) = \sum_{(Y, sy)} \Big( sy \times \text{PrefixY}(x, Y) \Big) $$

이걸 원래 식에 대입해 봅니다.
$$ \text{Total} = \sum_{x=L}^R \left( \sum_{(Y, sy)} sy \times \text{PrefixY}(x, Y) \right) $$

$sy$는 $x$랑 무관한 상수이므로 바깥으로 뺄 수 있습니다.
$$ \text{Total} = \sum_{(Y, sy)} \left( sy \times \sum_{x=L}^R \text{PrefixY}(x, Y) \right) $$

이제 안쪽에 남은 $\sum_{x=L}^R \text{PrefixY}(x, Y)$ 부분에 대해 **다시 한번 1차원 $x$ 공식을 적용**합니다!
$$ \sum_{x=L}^R \text{PrefixY}(x, Y) = \sum_{(X, sx)} \Big( sx \times \text{countAll}(X, Y) \Big) $$
*(여기서 `countAll(X,Y)`는 $x$방향 누적합까지 한 최종 2차원 누적합입니다)*

이걸 그대로 최종 식에 대입하면 마법처럼 식이 정리됩니다.
$$ \text{Total} = \sum_{(Y, sy)} \left( sy \times \sum_{(X, sx)} \Big( sx \times \text{countAll}(X, Y) \Big) \right) $$
$$ \mathbf{Total} = \sum_{(X, sx)} \sum_{(Y, sy)} \Big( (sx \times sy) \times \text{countAll}(X, Y) \Big) $$

---

### 3. 직관적인 예시 (기본적인 2차원 누적합)
만약 사각형이 전부 양수라서 $L > 0, D > 0$ 이라면
`X_ranges` = `{(R, +1), (L-1, -1)}`
`Y_ranges` = `{(U, +1), (D-1, -1)}` 입니다.

저 이중 `for`문이 4바퀴를 돌면서 $sx \times sy$를 곱하게 되죠.
1. `x = R, y = U` ➜ `(+1) * (+1)` = `+1` ➜ `+ countAll(R, U)`
2. `x = R, y = D-1` ➜ `(+1) * (-1)` = `-1` ➜ `- countAll(R, D-1)`
3. `x = L-1, y = U` ➜ `(-1) * (+1)` = `-1` ➜ `- countAll(L-1, U)`
4. `x = L-1, y = D-1` ➜ `(-1) * (-1)` = `+1` ➜ `+ countAll(L-1, D-1)`

이걸 쭉 나열하면 우리가 알고 있는 **2차원 누적 합(포함-배제)의 기본 공식**과 완벽하게 일치합니다!
$S(R, U) - S(R, D-1) - S(L-1, U) + S(L-1, D-1)$

### 4. 이 코드가 진짜 강력한 이유
만약 $X$ 구간도 0을 걸치고 $Y$ 구간도 0을 걸치면 어떻게 될까요?
`X_ranges`가 3개, `Y_ranges`가 3개가 나옵니다.
이걸 일일이 사각형 쪼개기로 구현하려면 $3 \times 3 = 9$개의 하위 직사각형에 대해 포함-배제를 일일이 `if`문으로 타이핑해야 합니다. 매우 고통스럽고 버그가 나기 쉽죠.

하지만 이 코드에서는 **분배법칙에 의해 $(sx \times sy)$가 9개의 조각에 대해 각각 알맞은 부호(+1 또는 -1)를 알아서 결정**해주기 때문에, 그냥 곱해서 더하기만 하면 모든 엣지 케이스가 완벽하게 계산되는 것입니다.
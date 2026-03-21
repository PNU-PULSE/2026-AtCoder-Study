#include <bits/stdc++.h>
#include <linux/limits.h>
using namespace std;

using ll = long long;

string X, Y;
int Q, N;
ll fibo[100];

void init() {
  cin >> X >> Y;
  fibo[0] = X.length();
  fibo[1] = Y.length();
  for (int i = 2; i < 100; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
    if (fibo[i] >= 1e18) {
      N = i;
      break;
    }
  }

  cin >> Q;
}

void solve(ll l, ll r, char c) { return; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  while (Q--) {
    ll l, r;
    char c;
    cin >> l >> r >> c;
    solve(l, r, c);
  }
}

// X랑 Y의 알파벳 개수 누적합 배열을 만들고 prefix_sum[26][length()],
// 쿼리의 L, R이 피보나치 수의 어떤 구간에 속하는지
// 찾아서(분할정복? or 이분탐색?) 누적합 배열 이용해서 계산하면 될듯..

// X, Y, Y/X, YX/Y, YXY/YX, YXYYX/YXY, ...
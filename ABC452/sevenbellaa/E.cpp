#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N_MAX = 500005, M_MAX = 500005, DIV = 998244353;

int N, M;
ll ans, A[N_MAX + M_MAX], B[M_MAX];

void init() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i] = (A[i] + A[i - 1]) % DIV;
  }
  for (int i = 1; i <= M; i++) {
    cin >> B[i];
    B[i] = (B[i] + B[i - 1]) % DIV;
  }
  for (int i = N + 1; i <= N + M; i++) A[i] = A[i - 1];
}

void solve() {
  for (int i = 1; i <= N; i++) {
    ans += B[M] * i % DIV * (A[i] - A[i - 1] + DIV) % DIV;
    ans %= DIV;
  }

  for (int j = 1; j <= M; j++) {
    for (int i = j; i <= N; i += j) {
      ans -= j * (B[j] - B[j - 1]) % DIV  //
             * (A[i + j - 1] - A[i - 1] + DIV) % DIV * (i / j) % DIV;
      ans = (ans + DIV) % DIV;
    }
  }
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  solve();
}
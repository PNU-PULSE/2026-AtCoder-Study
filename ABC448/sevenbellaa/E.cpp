#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll DIV = 10007 * 9;

ll power(ll n, ll k) {
  ll res = 1;
  n %= DIV;

  while (k) {
    if (k & 1) res = (res * n) % DIV;
    n = (n * n) % DIV;
    k /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll K, M;
  cin >> K >> M;
  DIV *= M;

  vector<pair<ll, ll>> v;
  vector<ll> pfs(K + 1);
  for (int i = 0; i < K; i++) {
    ll c, l;
    cin >> c >> l;
    v.emplace_back(c, l);
  }

  for (int i = K - 1; i >= 0; i--) {
    pfs[i] = v[i].second + pfs[i + 1];
  }

  ll ans = 0;
  for (int i = 0; i < K; i++) {
    auto [c, l] = v[i];
    ans = (ans + c * (power(10, l) - 1) % DIV * power(10, pfs[i] - l) % DIV) % DIV;
  }
  cout << ans / 9 / M;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count_quadrant(ll x, ll y) {
  if (x < 0 || y < 0) return 0;

  ll t = min(x, y) / 2;
  ll res = (t * 4 + 2) * t / 2 + min(x, y) * (max(x, y) / 2 - t);

  return 1 + (x / 2) + (y / 2) + res;
}

// {i, sign}, i -> 구간[0, i]
vector<pair<ll, ll>> get_ranges(ll A, ll B) {
  if (A >= 0) return {{B, 1}, {A - 1, -1}};
  if (B <= 0) return {{-A, 1}, {-B - 1, -1}};
  return {{B, 1}, {-A, 1}, {0, -1}};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll L, R, D, U, ans = 0;
  cin >> L >> R >> D >> U;

  for (auto [x, sx] : get_ranges(L, R)) {
    for (auto [y, sy] : get_ranges(D, U)) ans += sx * sy * count_quadrant(x, y);
  }

  cout << ans;
}
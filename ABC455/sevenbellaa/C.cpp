#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, ll> m;
int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    m[t] += t;
  }

  vector<ll> v;
  for (auto [i, j] : m) v.push_back(j);
  sort(v.begin(), v.end());
  ll ans = 0;

  for (int i = 0; i < (int)v.size() - k; i++) {  // size_t - int -> overflow
    ans += v[i];
  }
  cout << ans;
}
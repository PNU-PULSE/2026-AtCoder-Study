#include <bits/stdc++.h>
using namespace std;

int t, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t >> x;
  vector<int> v(t + 1), s, idx;
  for (int& i : v) cin >> i;
  s.push_back(v[0]);
  idx.push_back(0);

  for (int i = 1; i <= t; i++) {
    if (abs(v[i] - s.back()) < x) continue;
    s.push_back(v[i]);
    idx.push_back(i);
  }
  for (int i = 0; i < s.size(); i++) println("{} {}", idx[i], s[i]);
}
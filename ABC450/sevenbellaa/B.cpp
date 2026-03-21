#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, dist[101][101];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) cin >> dist[i][j + 1];
  }
}

string solve() {
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i + 1; k < j; k++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) return "Yes";
      }
    }
  }
  return "No";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  cout << solve();
}
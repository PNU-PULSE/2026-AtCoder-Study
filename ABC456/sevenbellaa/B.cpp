#include <bits/stdc++.h>
using namespace std;

int t, cnt[3][7];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> t;
      cnt[i][t]++;
    }
  }

  double ans = 0;
  ans += cnt[0][4] * cnt[1][5] * cnt[2][6];
  ans += cnt[0][4] * cnt[1][6] * cnt[2][5];
  ans += cnt[0][5] * cnt[1][4] * cnt[2][6];
  ans += cnt[0][5] * cnt[1][6] * cnt[2][4];
  ans += cnt[0][6] * cnt[1][5] * cnt[2][4];
  ans += cnt[0][6] * cnt[1][4] * cnt[2][5];

  print("{:.10f}", ans / 216);
}
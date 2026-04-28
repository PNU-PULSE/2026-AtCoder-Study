#include <bits/stdc++.h>
using namespace std;

char board[11][11];

bool isSym(int si, int sj, int ei, int ej) {
  for (int i = 0; i <= (ei - si); i++) {
    for (int j = 0; j <= (ej - sj) / 2; j++) {
      if (board[si + i][sj + j] != board[ei - i][ej - j]) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> board[i][j];
  }

  int ans = 0;
  for (int si = 0; si < n; si++) {
    for (int ei = si; ei < n; ei++) {
      for (int sj = 0; sj < m; sj++) {
        for (int ej = sj; ej < m; ej++)
          if (isSym(si, sj, ei, ej)) ans++;
      }
    }
  }
  cout << ans;
}

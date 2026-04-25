#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 300003;
int N, Q, parent[N_MAX], pile[N_MAX];
bool notleaf[N_MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> Q;
  iota(parent, parent + N + 1, 0);
  while (Q--) {
    int c, p;
    cin >> c >> p;
    parent[c] = p;
  }

  auto dfs = [&](auto& self, int cur, int cnt) -> void {
    if (cur == parent[cur])
      pile[cur] += cnt;
    else
      self(self, parent[cur], cnt + 1);
  };

  for (int i = 1; i <= N; i++) {
    if (i != parent[i]) notleaf[parent[i]] = true;
  }
  for (int i = 1; i <= N; i++) {
    if (!notleaf[i]) dfs(dfs, i, 1);
  }
  for (int i = 1; i <= N; i++) cout << pile[i] << ' ';
}
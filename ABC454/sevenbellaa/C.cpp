#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 300001;

bool vis[N_MAX];
vector<int> graph[N_MAX];
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  queue<int> Q;
  Q.push(1);
  vis[1] = true;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int nxt : graph[cur]) {
      if (!vis[nxt]) {
        vis[nxt] = true;
        Q.push(nxt);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (vis[i]) ans++;
  }
  cout << ans;
}
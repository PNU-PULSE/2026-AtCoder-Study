#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 200002;

int N, A[N_MAX], vis[N_MAX];
vector<int> graph[N_MAX];
set<int> s;

void dfs(int cur, int prev) {
  vis[cur] = true;
  for (int nxt : graph[cur]) {
    if (nxt == prev || s.find(A[nxt]) != s.end()) continue;
    s.insert(A[nxt]);
    dfs(nxt, cur);
    s.erase(A[nxt]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  s.insert(A[1]);
  dfs(1, 0);

  for (int i = 1; i <= N; i++) {
    if (vis[i])
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}
#include <bits/stdc++.h>
using namespace std;

int N, M, A[1002], ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i];
  while (N--) {
    int a, b;
    cin >> a >> b;

    ans += min(A[a], b);
    A[a] -= min(A[a], b);
  }
  cout << ans;
}
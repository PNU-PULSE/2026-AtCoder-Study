#include <bits/stdc++.h>
using namespace std;

vector<char> direct{'L', 'D', 'U', 'R'};
vector<int> dx{0, 1, -1, 0};
vector<int> dy{-1, 0, 0, 1};

void solve() {
  int N, A, B; cin >> N >> A >> B;
  if (N & 1 || (((A-1) & 1) == ((B-1) & 1))) {
    cout << "No\n";
    return;
  }

  string ans = "";
  vector<vector<int>> arr(N+1, vector<int>(N+1, 0));
  arr[A][B] = true;
  arr[1][1] = true;
  int x = 1, y = 1;
  while (!(x == N && y == N)) {
    for (int dir=0 ; dir<4 ; dir++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (nx <= 0 || ny <= 0 || nx > N || ny > N || arr[nx][ny]) continue;
      arr[nx][ny] = true;
      x = nx;
      y = ny;
      ans += direct[dir];
      break;
    }
  }

  cout << "YES\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) solve();

}
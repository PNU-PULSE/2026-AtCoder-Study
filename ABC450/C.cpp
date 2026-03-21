#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> arr(1000, vector<int>(1000, 0));
vector<vector<bool>> vis(1000, vector<bool>(1000, false));
vector<int> dx{-1, 1, 0, 0};
vector<int> dy{0, 0, -1, 1};

void dfs(int x, int y) {
  vis[x][y] = true;

  for (int dir=0 ; dir<4 ; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
    if (vis[nx][ny] || !arr[nx][ny]) continue;
    dfs(nx, ny);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> H >> W;
  for (int i=0 ; i<H ; i++) {
    for (int j=0 ; j<W ; j++) {
      char ch;
      cin >> ch;
      if (ch == '.') arr[i][j] = 1;
    }
  }

  for (int i=0 ; i<W ; i++) {
    if (arr[0][i] && !vis[0][i]) dfs(0, i);
    if (arr[H-1][i] && !vis[H-1][i]) dfs(H-1, i);
  }
  
  for (int i=0 ; i<H ; i++) {
    if (arr[i][0] && !vis[i][0]) dfs(i, 0);
    if (arr[i][W-1] && !vis[i][W-1]) dfs(i, W-1);
  }

  int answer = 0;
  for (int i=0 ; i<H ; i++) {
    for (int j=0 ; j<W ; j++) {
      if (!vis[i][j] && arr[i][j]) {
        answer++;
        dfs(i, j);
      }
    }
  }

  cout << answer;
}
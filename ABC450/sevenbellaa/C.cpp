#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char board[1001][1001];
bool vis[1001][1001];
int H, W, ans;

void init() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> board[i][j];
  }
}

void bfs(int x, int y) {
  queue<pair<int, int>> Q;
  Q.push({x, y});
  vis[x][y] = true;

  bool isOut = false;
  while (!Q.empty()) {
    auto [curX, curY] = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
        isOut = true;
        continue;
      }
      if (vis[nx][ny] || board[nx][ny] == '#') continue;

      vis[nx][ny] = true;
      Q.push({nx, ny});
    }
  }

  if (!isOut) ans++;
}

void solve() {
  for (int i = 1; i < H - 1; i++) {
    for (int j = 1; j < W - 1; j++) {
      if (vis[i][j] || board[i][j] == '#') continue;
      bfs(i, j);
    }
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
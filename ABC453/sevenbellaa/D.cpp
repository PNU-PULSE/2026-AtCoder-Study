// # 아예못감
// . 들어왔다나갔다 자유 들어왔다가 다른 아무점이나 갈수있음
// o 들어온 방향대로만 나갈수있음
// x 방향 바꿔서만 나갈수있음
// S 시작점, 자유 / G 끝점, 자유

#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
char board[1001][1001];
int dist[1001][1001][4];  // [x][y][dir]
pair<int, int> st, en;
tuple<int, int, int> parent[1001][1001][4];  // {x, y, dir}

void init() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'S') st = {i, j};
      if (board[i][j] == 'G') en = {i, j};
    }
  }

  fill(&dist[0][0][0], &dist[N - 1][M - 1][4], -1);
  for (int dir = 0; dir < 4; dir++) dist[st.first][st.second][dir] = 0;
}

void bfs() {
  queue<tuple<int, int, int>> Q;  // {x, y, dir}
  Q.push({st.first, st.second, -1});

  while (!Q.empty()) {
    auto [curX, curY, curD] = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      if (board[curX][curY] == 'o' && curD != dir) continue;
      if (board[curX][curY] == 'x' && curD == dir) continue;

      int nx = curX + dx[dir], ny = curY + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#' ||
          dist[nx][ny][dir] != -1)
        continue;

      Q.push({nx, ny, dir});
      dist[nx][ny][dir] = dist[curX][curY][curD] + 1;
      parent[nx][ny][dir] = {curX, curY, curD};
    }
  }
}

void solve() {
  if (*max_element(&dist[en.first][en.second][0],
                   &dist[en.first][en.second][4]) == -1) {
    cout << "No";
    return;
  }
  cout << "Yes\n";

  char d2c[] = {'D', 'R', 'U', 'L'};
  for (int dir = 0; dir < 4; dir++) {
    auto [ex, ey] = en;
    int ed = dir;
    if (dist[ex][ey][dir] == -1) continue;

    stack<char> s;
    while (true) {
      if (ex == st.first && ey == st.second) break;

      s.push(d2c[ed]);
      auto [nx, ny, nd] = parent[ex][ey][ed];
      ex = nx;
      ey = ny;
      ed = nd;
    }
    while (!s.empty()) {
      cout << s.top();
      s.pop();
    }
    break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  bfs();
  solve();
}
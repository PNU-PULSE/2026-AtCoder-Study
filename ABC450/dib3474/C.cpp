#include <bits/stdc++.h>
using namespace std;

int h, w;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<char>> board;
vector<vector<int>> visited;

int ans = 0;

void solve(int y, int x) {
    if (visited[y][x] || board[y][x] == '#') return ;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    bool isSurround = true;

    while(!q.empty()) {
        auto [curr_y, curr_x] = q.front(); q.pop();

        if (curr_y == 0 || curr_y == h - 1 || curr_x == 0 || curr_x == w - 1) isSurround = false;;

        for (int i = 0; i < 4; i++) {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
    
            if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w) {
                if (!visited[next_y][next_x] && board[next_y][next_x] == '.') {
                    visited[next_y][next_x] = 1;
                    q.push({next_y, next_x});
                }
            }
        }
    }

    if (isSurround) ans++;
}

int main() {
    cin >> h >> w;
    board.assign(h, vector<char>(w));
    visited.assign(h, vector<int>(w, 0));
    for (auto& row : board) {
        for (auto& col : row) {
            cin >> col;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            solve(i, j);
        }
    }

    cout << ans;
}
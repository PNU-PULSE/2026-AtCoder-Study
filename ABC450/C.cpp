#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w, 0));
    vector<vector<int>> visited(h, vector<int>(w, 0));
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    for(int r=0; r<h; ++r){
        for(int c=0; c<w; ++c){
            cin >> v[r][c];
            if(v[r][c] == '.')
                q.emplace(r, c);
        }
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ans = 0;
    while(!q.empty()){
        int r = q.front().first; int c = q.front().second;
        if(visited[r][c]){
            q.pop();
            continue;
        }
        visited[r][c] = 1;

        q2.emplace(r, c);
        bool flag = false;
        while(!q2.empty()){
            int r2 = q2.front().first; int c2 = q2.front().second;
            visited[r2][c2] = 1;
            for(int i=0; i<4; ++i){
                if(r2+dx[i] < 0 || r2+dx[i] >= h || c2+dy[i] < 0 || c2+dy[i] >= w){
                    flag = true;
                    break;
                }
                else if(v[r2+dx[i]][c2+dy[i]] == '.' && !visited[r2+dx[i]][c2+dy[i]]){
                    q2.emplace(r2+dx[i], c2+dy[i]);
                }
            }
            q2.pop();
            if(!flag && q2.empty())
                ans++;
        }
        q.pop();
        
    }
    cout << ans;
    
}
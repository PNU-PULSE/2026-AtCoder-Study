#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int h, w;
vector<vector<int>> visited;
vector<vector<char>> table;
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(int x, int y){
    
    visited[y][x] = 1;
    queue<pair<int,int>> pos;
    pos.push({x,y});
    int cumul = 1;
    while(!pos.empty()){
        auto cur = pos.front();
        pos.pop();
        for(int i=0;i<dir.size();++i){
            int nx = cur.first + dir[i].first;
            int ny = cur.second + dir[i].second;
            
            if(nx<0 || ny<0 || ny>=h || nx>=w){
                cumul -= 99999;
                continue;
            }
            if(visited[ny][nx]==1 || table[ny][nx]=='#' ) continue;
            
            visited[ny][nx] = 1;
            pos.push({nx, ny});
        }
    }
    
    return cumul;
}

int main()
{
    cin >> h >> w;
    table.assign(h+1,vector<char>(w+1,'.'));
    visited.assign(h+1, vector<int>(w+1, 0));
    for(int i=0;i<h;++i){
        string input;
        cin >> input;
        for(int j=0;j<w;++j){
            table[i][j] = input[j];
        }
    }
    
    int cnt = 0;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            //cout << i << ' ' << j << ' ' << dfs(j, i) << '\n';
            if(table[i][j]=='.' && visited[i][j]==0 && dfs(j, i)>0){
                //cout << i << ' ' << j << '\n';
                cnt++;
            }
        }
    }
    
    cout << cnt;
    return 0;
}
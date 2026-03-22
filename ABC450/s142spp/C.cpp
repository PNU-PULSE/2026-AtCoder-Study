#include <bits/stdc++.h>
using namespace std;


int main(void){
    int h, w; cin >> h >> w;
    vector<vector<char>> cells(h,vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){ 
            cin >> cells[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(i!=0 && i!=h-1 && j!=0 && j!=w-1) continue;
            if(cells[i][j]=='#') continue;
            bool visited[1001][1001] = {};
            queue<pair<int,int>> q; 
            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()){
                auto f = q.front(); q.pop();
                cells[f.first][f.second] = '#';
                pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto d : dir){
                    int x = f.first+d.first;
                    int y = f.second+d.second;
                    if(x<0||x>h-1||y<0||y>w-1) continue;
                    if(visited[x][y] || cells[x][y]=='#') continue;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }   
        }
    }
    //for(int i=0; i<h; i++){
    //    for(int j=0; j<w; j++) cout << cells[i][j] <<  " "; cout << "\n";
    //}

    int ans = 0;
    bool visited[1001][1001] = {};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(visited[i][j]) continue;
            if(cells[i][j] == '#') continue;
            queue<pair<int,int>> q; 
            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()){
                auto f = q.front(); q.pop();
                pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto d : dir){
                    int x = f.first+d.first;
                    int y = f.second+d.second;
                    if(x<0||x>h-1||y<0||y>w-1) continue;
                    if(visited[x][y] || cells[x][y]=='#') continue;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }  
            ans ++; 
        }
    }
    cout << ans;
}

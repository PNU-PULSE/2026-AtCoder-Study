#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs_delete(int H, int W, char map[1000][1000], int x, int y){
    if(x < 0 || x >= H || y < 0 || y >= W) return;
    if(map[x][y] == '.') {
        map[x][y] = '#';
        for(int i = 0; i < 4; i++){
            dfs_delete(H, W, map, x+dx[i], y+dy[i]);
        }
    }
    else return;
}

int main(){
    int H, W; 
    char map[1000][1000];
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i == 0 || i == H-1 || j == 0 || j == W-1){
                if(map[i][j] == '.') dfs_delete(H, W, map, i, j);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(map[i][j] == '.') {
                count++;
                dfs_delete(H, W, map, i, j);
            }
        }
    }
    
    cout << count << '\n';

    return 0;
}
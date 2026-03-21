#include<bits/stdc++.h>

#define endl "\n"
#define int long long

using namespace std;

using vi = vector<int>; 
using vvi = vector<vi>;
using pii = pair<int, int>;

vector<string> S;
int H, W;

vector<pii> drc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int row, int col){
    if(row < 0 || col < 0 || row > H - 1|| col > W - 1){
        return ;
    }
    if(S[row][col] == '.'){
        S[row][col] = '#';
        for(const auto &[dr, dc]: drc){
            dfs(row + dr, col + dc);
        }
    }else{
        return ;
    }
    return ;
}
void solve(){
    cin >> H >> W;
    S.resize(H);
    for(auto &i: S){
        cin >> i;
    }
    int ans = 0;
    for(auto row = 0; row < H; ++row){
        if(S[row][0] == '.'){
            dfs(row, 0);
        }
        if(S[row][W - 1] == '.'){
            dfs(row, W - 1);
        }
    }
    for(auto col = 0; col < W; ++col){
        if(S[0][col] == '.'){
            dfs(0, col);
        }
        if(S[H - 1][col] == '.'){
            dfs(H - 1, col);
        }
    }

    for(auto i = 0; i < H; ++i){
        for(auto j = 0; j < W; ++j){
            if(S[i][j] == '.'){
                dfs(i, j);
                ans++;
                // cout << i << " " << j << endl;
                
            }
        }
    }

    cout << ans << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }


    return 0;
}
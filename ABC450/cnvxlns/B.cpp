#include<bits/stdc++.h>

#define endl "\n"
#define int long long

using namespace std;

using vi = vector<int>; 
using vvi = vector<vi>;

void solve(){
    int N;
    cin >> N;
    vvi C(N + 1, vi(N + 1));

    for(auto i = 1; i < N; ++i){
        for(auto j = i + 1; j <= N; ++j){
            cin >> C[i][j];
        }
    }

    bool ans = false;
    for(auto i = 1; i < N; ++i){
        for(auto j = i + 2; j <= N; ++j){
            for(auto k = i + 1; k < j; ++k){
                if(C[i][j] > C[i][k] + C[k][j]){
                    ans = true;
                    break;
                }
            }
        }
    }
    // cout << ans ? "Yes" : "No" << endl;
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
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
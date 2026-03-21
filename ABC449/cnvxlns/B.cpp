#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define endl "\n"



void solve(){
    int H, W, Q;
    cin >> H >> W >> Q;
    int left = 1, right = W, up = 1, down = H;
    while(Q--){
        int q, query;
        cin >> q >> query;
        if(q == 1){
            if(query > down){
                cout << 0 << endl;
                continue;
            }else{
                cout << query * (right - left + 1) << endl;
                down = down - query;
            }
        }else{
            if(query > right){
                cout << 0 << endl;
                continue;
            }else{
                cout << (down - up + 1) * query << endl;
                right = right - query;
            }
        }
    }

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;

}
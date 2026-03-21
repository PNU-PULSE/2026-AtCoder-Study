#include<bits/stdc++.h>

#define endl "\n"
#define int long long

using namespace std;

using vi = vector<int>; 
using vvi = vector<vi>;
using pii = pair<int, int>;

vector<pii> drc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(){
    int N, K;
    cin >> N >> K;
    vi a(N);
    for(auto &i: a){
        cin >> i;
    }
    for(auto &i: a){
        i %= K;
    }
    ranges::sort(a);
    int ans = a.back() - a.front();
    for(int i = 0; i < N - 1; ++i){
        ans = min(ans, (a[i] + K) - a[i + 1]);
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
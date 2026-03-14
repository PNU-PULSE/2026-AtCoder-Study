#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define endl "\n"
#define int long long

void solve(){
    int N, L, R;
    string S;
    cin >> N >> L >> R;
    cin >> S;
    vi cnt(26, 0);
    int ans = 0;
    for(auto i = 0; i < N; ++i){
        if(i - L >= 0)
            cnt[S[i - L] - 'a']++;
        if(i - R - 1 >= 0) {
            cnt[S[i - R - 1] - 'a']--;
        }
        ans += cnt[S[i] - 'a'];
    }
    cout << ans << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;

}
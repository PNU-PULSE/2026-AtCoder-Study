#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M, K; cin >> N >> M >> K;
    ll X, Y; cin >> X >> Y;
    vector<ll> A(N), B(M);
    for (auto &i : A) cin >> i;
    for (auto &i : B) cin >> i;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> sum(N+1, 0);
    for (int i=1 ; i<=N ; i++) {
        sum[i] = sum[i-1] + A[i-1];
    }

    auto dessert_cnt = [&](ll x, ll y){
        x += K * y;
        auto it = upper_bound(sum.begin(), sum.end(), x);
        return (int)(it - sum.begin() - 1);
    };

    int answer = dessert_cnt(X, Y);
    for (int i=0 ; i<M ; i++) {
        ll x = (B[i] % K == 0 ? B[i] / K : (B[i] / K) + 1);
        if (Y >= x) {
            X += (K*x) - B[i];
            Y -= x;
            answer = max(answer, dessert_cnt(X, Y) + i + 1);
        } else break;
    }

    cout << answer;
}
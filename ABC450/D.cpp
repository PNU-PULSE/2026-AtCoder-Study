#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  ll gap = 0;
  ll a; cin >> a;
  for (int i=1 ; i<N ; i++) {
    ll b;
    cin >> b;

    ll c = abs(a - b) % K;
    if (c == 0) continue;
    c = min(c, K-c);
    gap = max(gap, c);
  }

  cout << gap;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
map<ll, int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  vector<ll> arr(N), sum(N, 0);
  for (auto &i : arr) cin >> i;
  sort(arr.begin(), arr.end());

  int counter = 0;
  
  for (const auto& i : arr) {
    if (m.find(i) == m.end()) m[i] = counter++;
    sum[m[i]] += i;
  }

  priority_queue<ll, vector<ll>, less<>> pq;
  for (const auto& i : sum) pq.push(i);

  for (int i=0 ; i<K ; i++) {
    if (!pq.empty()) pq.pop();
  }

  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans;
}
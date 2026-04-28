#include <bits/stdc++.h>
using namespace std;

vector<int> idx[26];
int N, L, R;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> L >> R >> S;
  for (int i = 0; i < N; i++) idx[S[i] - 'a'].push_back(i);

  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    for (int pos : idx[i]) {
      auto lower = lower_bound(idx[i].begin(), idx[i].end(), pos + L);
      auto upper = upper_bound(idx[i].begin(), idx[i].end(), pos + R);
      ans += (upper - lower);
    }
  }

  cout << ans;
}
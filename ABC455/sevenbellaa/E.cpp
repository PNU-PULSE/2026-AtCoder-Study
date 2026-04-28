#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
string S;

int cnt[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;
  for (int i = 0, j = 0; i < N && j < N; j++) {
    cnt[S[j] - 'A']++;
    if (cnt[0] != cnt[1] && cnt[1] != cnt[2] && cnt[2] != cnt[0]) {
      ans++;
      while (i < j) {
        cnt[S[i++] - 'A']--;
        if (cnt[0] != cnt[1] && cnt[1] != cnt[2] && cnt[2] != cnt[0]) {
          ans++;
          break;
        }
      }
    }
  }
  cout << ans;
}
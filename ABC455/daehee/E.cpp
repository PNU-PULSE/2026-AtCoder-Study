#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int dp[200010][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;
  for (int i=1 ; i<S.length() ; i++) {
    dp[i][0] = dp[i-1][0];
    dp[i][1] = dp[i-1][1];
    dp[i][2] = dp[i-1][2];
    ++dp[i][S[i-1] - 'A'];
  }
  dp[S.length()][0] = dp[S.length()-1][0];
  dp[S.length()][1] = dp[S.length()-1][1];
  dp[S.length()][2] = dp[S.length()-1][2];
  ++dp[S.length()][S[S.length()-1] - 'A'];

  int ans = 0;
  for (int len=1 ; len<=S.length() ; len++) {
    for (int s=0 ; s+len-1<S.length() ; s++) {
      int e = s+len-1;
      int a = dp[e+1][0] - dp[s][0];
      int b = dp[e+1][1] - dp[s][1];
      int c = dp[e+1][2] - dp[s][2];
      if (a != b && b != c && a != c) ++ans;
    }
  }

  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;

string S, T;
int lcs(int s1, int s2, int t2, vector<vector<int>>& memo) {
  if (s2 < s1|| t2 < 0) return 0;
  int& ret = memo[s2][t2];
  if (ret != -1) return ret;
  if (S[s2] == T[t2]) {
    return ret = lcs(s1, s2-1, t2-1, memo) + 1;
  }

  return ret = max(lcs(s1, s2-1, t2, memo), lcs(s1, s2,t2-1, memo));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S >> T;
  int ret = 0;

  for (int i=0 ; i<S.size() ; i++) {
    vector<vector<int>> memo(S.size(), vector<int>(T.size(), -1));
    for (int j=i ; j<S.size() ; j++) {
      ++ret;
      if (lcs(i, j, T.size()-1, memo) == T.size()) {
        --ret;
      }
    }
  }

  cout << ret;
}
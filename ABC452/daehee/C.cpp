#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N;
  vector<vector<set<char>>> isExist(11, vector<set<char>>(11, set<char>()));
  vector<pair<int, int>> arr;
  for (int i=0 ; i<N ; i++) {
    int a, b; cin >> a >> b;
    arr.push_back({a, b});
  }

  int M; cin >> M;
  vector<vector<pair<string, int>>> cand(20, vector<pair<string, int>>());
  vector<int> ans(M, false);
  for (int i=0 ; i<M ; i++) {
    string s; cin >> s;
    cand[s.size()].push_back({s, i});
    for (int j=0 ; j<s.size() ; j++) {
      isExist[s.size()][j].insert(s[j]);
    }
  }

  for (int i=0 ; i<cand[N].size() ; i++) {
    auto now = cand[N][i].first;
    bool flag = true;
    for (int j=0 ; j<arr.size() ; j++) {
      auto [a, b] = arr[j];
      if (isExist[a][b-1].find(now[j]) == isExist[a][b-1].end()) {
        flag = false;
        break;
      }
    }

    ans[cand[N][i].second] = flag;
  }

  for (auto i : ans) {
    if (i) cout << "Yes\n";
    else cout << "No\n";
  }
}
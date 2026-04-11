#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;
  string answer = "";
  for (auto &ch : s) {
    if (ch == 'o') continue;
    answer += ch;
  }

  cout << answer;
}
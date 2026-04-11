#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, idx = 0;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'o')
      idx++;
    else
      break;
  }
  cout << s.substr(idx, n);
}
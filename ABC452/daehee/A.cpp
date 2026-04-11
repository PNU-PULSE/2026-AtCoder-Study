#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> arr{{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9}};
  int m, d; cin >> m >> d;

  for (auto x : arr) {
    if (x[0] == m && x[1] == d) {
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";

}
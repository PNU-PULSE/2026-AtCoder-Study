#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> f(n), clothes(m);
  for (int &i : f) {
    cin >> i;
    clothes[i - 1]++;
  }

  bool flag1 = true, flag2 = true;
  for (int i : clothes) {
    if (i > 1) flag1 = false;
    if (i == 0) flag2 = false;
  }

  cout << ((flag1) ? "Yes" : "No") << '\n';
  cout << ((flag2) ? "Yes" : "No");
}
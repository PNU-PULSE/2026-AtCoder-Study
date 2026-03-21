#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a = 1, b = 1, cnt = 0;
  while (a < 1e18) {
    long long c = a + b;
    a = b;
    b = c;
    cnt++;
  }
  cout << cnt;  // 87
}
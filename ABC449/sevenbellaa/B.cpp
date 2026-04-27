#include <bits/stdc++.h>
using namespace std;

int H, W, Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> W >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      println("{}", W * b);
      H -= b;
    } else {
      println("{}", H * b);
      W -= b;
    }
  }
}
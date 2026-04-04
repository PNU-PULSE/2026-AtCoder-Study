#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W; cin >> H >> W;
  for (int i=0 ; i<H ; i++) {
    for (int j=0 ; j<W ; j++) {
      if (i == 0 || j == 0 || i == H-1 || j == W-1) cout << "#";
      else cout << ".";
    }
    cout << "\n";
  }
}
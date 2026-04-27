#include <bits/stdc++.h>
using namespace std;

int H, W;
int arr[20][20];

bool check(int h1, int h2, int w1, int w2) {
  for (int i=h1 ; i<=h2 ; i++) {
    for (int j=w1 ; j<=w2 ; j++) {
      if (arr[i][j] != arr[h1+h2-i][w1+w2-j]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> W;
  for (int i=1 ; i<=H ; i++) {
    for (int j=1 ; j<=W ; j++) {
      char ch; cin >> ch;
      if (ch == '#') arr[i][j] = 1;
    }
  }

  int ans = 0;
  for (int a=1 ; a<=H ; a++) {
    for (int b=1 ; b<=H ; b++) {
      for (int c=1 ; c<=W ; c++) {
        for (int d=1 ; d<=W ; d++) {
          if (a <= b && c <= d) {
            if (check(a, b, c, d)) ans++;
          }
        }
      }
    }
  }

  cout << ans;
}
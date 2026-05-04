#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, X, A;
  cin >> N >> X;
  while (N--) {
    cin >> A;
    if (A < X) {
      cout << "1\n";
      X = A;
    } else {
      cout << "0\n";
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double n;
  cin >> n;
  n /= 2.0;
  n *= n;
  print("{:.10f}", PI * n);
}
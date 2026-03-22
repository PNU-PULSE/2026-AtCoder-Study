#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  while (n) {
    cout << n ;
    if(n>1) cout << ",";
    n--;
  }
}
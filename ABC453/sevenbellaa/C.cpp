#include <bits/stdc++.h>
using namespace std;

int n, arr[21], mx;

void backtrack(double prev, int cnt, int idx) {
  if (idx == n) {
    mx = max(mx, cnt);
    return;
  }

  if ((prev < 0 && prev + arr[idx] > 0) || (prev > 0 && prev + arr[idx] < 0))
    backtrack(prev + arr[idx], cnt + 1, idx + 1);
  else
    backtrack(prev + arr[idx], cnt, idx + 1);

  if ((prev < 0 && prev - arr[idx] > 0) || (prev > 0 && prev - arr[idx] < 0))
    backtrack(prev - arr[idx], cnt + 1, idx + 1);
  else
    backtrack(prev - arr[idx], cnt, idx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  backtrack(0.5, 0, 0);
  cout << mx;
}
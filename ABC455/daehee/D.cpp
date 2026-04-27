#include <bits/stdc++.h>
using namespace std;

int N, Q;
int arr[300010];
int ans[300010];

void move(int c, int p) {
  arr[c] = p;
}

int find(int a) {
  return arr[a] = arr[a] == a ? a : find(arr[a]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> Q;
  for (int i=1 ; i<=N ; i++) arr[i] = i;
  for (int i=1 ; i<=Q ; i++) {
    int c, p; cin >> c >> p;
    move(c, p);
  }

  for (int i=1 ; i<=N ; i++) find(i);
  for (int i=1 ; i<=N ; i++) {
    ans[find(i)]++;
  }

  for (int i=1 ; i<=N ; i++) cout << ans[i] << " ";
}
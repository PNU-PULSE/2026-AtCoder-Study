#include <bits/stdc++.h>
using namespace std;

int N;
const int INF = 0x3f3f3f3f;
vector<vector<int>> arr(101, vector<int>(101, INF));

bool solve() {
  for (int k=1 ; k<N ; k++) {
    for (int i=1 ; i<=N ; i++) {
      for (int j=i+1 ; j<=N ; j++) {
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  for (int i=1 ; i<=N ; i++) {
    for (int j=i+1 ; j<=N ; j++) {
      int cost; cin >> cost;
      arr[i][j] = cost;
    }
  }

  if (solve()) cout << "Yes";
  else cout << "No";

}
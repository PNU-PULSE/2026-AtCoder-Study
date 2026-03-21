#include <bits/stdc++.h>
using namespace std;

int N, K, arr[200005], ans;

void init() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];
}

// 0 <= min(max(A) - min(A)) <= K-1
void solve() {
  for (int i = 0; i < N; i++) arr[i] %= K;
  sort(arr, arr + N);
  ans = arr[N - 1] - arr[0];
  for (int i = 1; i < N; i++) ans = min(ans, arr[i - 1] + K - arr[i]);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}

// 수열을 변형해보자. K를 적절한 횟수로 빼서
// 수열의 모든 원소를 0 ~ K-1로 만들 수 있다.

// ans = min_{0 <= i < N-1}(ans, a_i + K - a_i+1)
// 결국 ans가 변하는건 이웃한 두 원소의 차로 결정가능.
// 각 원소를 a_i %= K 한 후에 정렬하고 ans값 갱신해주면 끝.
// sort -> O(N log N), a_i %= K -> O(N), ans값 갱신 -> O(N)
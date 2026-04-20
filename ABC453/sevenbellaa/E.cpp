#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N_MAX = 200002, MOD = 998244353;

ll ans, fact[N_MAX], inv_fact[N_MAX];
int N, a[N_MAX], both[N_MAX];

ll power(ll n, ll k) {
  ll res = 1;
  while (k) {
    if (k & 1) res = res * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return res;
}

ll comb(ll n, ll r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

void init() {
  fact[0] = 1;
  for (int i = 1; i < N_MAX; i++) fact[i] = fact[i - 1] * i % MOD;
  inv_fact[N_MAX - 1] = power(fact[N_MAX - 1], MOD - 2);
  for (int i = N_MAX - 2; i >= 0; i--)
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;

    int bl = max(l, N - r), br = min(r, N - l);
    if (bl <= br) {
      both[bl]++;
      both[br + 1]--;
    }
  }

  for (int i = 1; i < N; i++) {
    a[i] += a[i - 1];
    both[i] += both[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  for (int i = 1; i < N; i++) {
    int free = both[i], must_a = a[i] - both[i], must_b = a[N - i] - both[i];
    if (must_a + must_b + free != N || must_a > i || must_b > N - i || a[i] < i)
      continue;

    int need = i - (a[i] - both[i]);
    ans = (ans + comb(free, need)) % MOD;  // 여기 MOD 빼먹어서 WA
  }
  cout << ans;
}

//  998244353
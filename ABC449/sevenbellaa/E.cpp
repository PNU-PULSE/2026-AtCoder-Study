#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll INF = 1e18 + 2003;

struct Query {
  int ksize;
  ll x;
  int qid;
};

int N, M, Q;
vector<int> A;
vector<pair<int, int>> cnt;  // {cnt(i), i | 1 <= i <= M}

vector<ll> pfs;  // 배열 A 사이즈 누적합

void init() {
  cin >> N >> M;

  A.resize(N);
  vector<int> tmp(M + 1);  // A_i 등장 횟수
  for (int& i : A) {
    cin >> i;
    tmp[i]++;
  }
  for (int i = 1; i <= M; i++) cnt.emplace_back(tmp[i], i);

  ranges::sort(cnt);  // cnt 작은순으로, cnt 같으면 i 작은 순으로

  pfs.resize(M + 1);
  pfs[0] = N;
  for (ll i = 1; i < M; i++) {
    pfs[i] = pfs[i - 1] + i * (cnt[i].first - cnt[i - 1].first);
  }
  pfs[M] = INF;
}

// pfs에서 x (x > N)번째를 포함하는 최초의 구간 찾기
int find_pos(ll x) {
  int lo = 0, hi = M;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (pfs[mid] >= x)
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

void solve() {
  cin >> Q;
  vector<int> ans(Q);
  vector<Query> queries;

  for (int id = 0; id < Q; id++) {
    ll x;
    cin >> x;

    if (x <= N) {
      ans[id] = A[x - 1];
      continue;
    }

    int pos = find_pos(x);
    ll rem = (x - pfs[pos - 1] - 1) % pos;
    queries.push_back({pos, rem, id});
  }
  ranges::sort(queries, {}, &Query::ksize);

  ordered_set os;
  int idx = 0;
  for (auto& q : queries) {
    while (idx < q.ksize) os.insert(cnt[idx++].second);
    ans[q.qid] = *os.find_by_order(q.x);
  }

  for (int& i : ans) println("{}", i);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
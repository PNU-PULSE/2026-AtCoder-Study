#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;

auto range(auto start, auto end){
    return std::views::iota(start, end);
}

auto range(auto end){
    return std::views::iota(decltype(end){0}, end);
}

constexpr int inf = 4e18;
constexpr int MOD = 1e9 + 7;

const vpii drc = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pii operator+(pii A, pii B){
    return {A.first + B.first, A.second + B.second};
}
pii operator-(pii A, pii B){
    return {A.first - B.first, A.second - B.second};
}

void init(){

}

void solve(){
    int N;
    cin >> N;
    vi A(N);
    for(auto &i: A){
        cin >> i;
    }
    priority_queue<int, vi, greater<int>> pq;
    for(auto i: range(3)){
        pq.push(A[i]);
    }
    cout << pq.top() << endl;
    for(auto i: range(3, N)){
        pq.push(A[i]);
        pq.pop();
        cout << pq.top() << endl;
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    init();
    int t = 1;
    // cin >> t;
    for(auto i: range(t)){
        solve();
    }
    return 0;
}

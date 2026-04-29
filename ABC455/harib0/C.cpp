#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    map<long long, long long> m;
    for (int i=0; i<n; ++i){
        long long tmp;
        cin >> tmp;
        m[tmp] += tmp;
    }

    vector<pair<long long, long long>> v = {m.begin(), m.end()};
    sort(v.begin(), v.end(), [](auto& a, auto& b){
        return a.second > b.second;
    });

    long long ans = 0;
    for (int i=k; i<v.size(); ++i){
        ans += v[i].second;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k; cin >> n >> k;
    set<int> s;
    for(int i=0; i<n; i++){
        int c; cin >> c;
        s.insert(c%k);
        
    }
    vector<int> v;
    for(auto a : s) v.push_back(a);
    sort(v.begin(),v.end(),less());
    n = v.size();
    s.clear();
    for(int i=1; i<n; i++){
        s.insert(min(v[i]-v[0],v[0]+k-v[i]));
    }
    if(n>1) cout << *max_element(s.begin(),s.end());
    else cout << 0;
}
/*
7 7
0 1 2 3 4 5 6
1 2 3 3 2 1 0

4 6
0 4 4 5
6-4
6-5, 5-4, 
*/
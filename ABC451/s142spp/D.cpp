#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<long long> twos;
    int n; cin >> n;
    for(int i=0; i<100; i++){
        long long t = pow(2,i);
        if(t>1e9) break;
        twos.push_back((long long)t);
    }
    priority_queue<long long,vector<long long>,greater<>> pq;
    unordered_map<long long,int> m;
    for(auto t : twos) {
        pq.push(t);
        m[t]++;        
    }
    int cnt = 0;
    while(!pq.empty()){
        long long f = pq.top(); pq.pop();
        //cout << cnt << " "<<  f << "\n";
        cnt ++; if(cnt == n){
            cout << f; break;
        }
        for(auto t : twos){
            long long n = 1;
            while(n<=t) n*=10;
            if(f*n+t > 1e9) break;
            if(m[f*n+t]>0) continue;
            m[f*n+t]++;
            pq.push(f*n+t);
        }
    }
    return 0;
}
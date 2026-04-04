#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int Q; cin >> Q;
    priority_queue<int,vector<int>,greater<>> pq;
    while(Q--){
        int c, i; cin >> c >> i;
        if(c==1){
            pq.push(i);
        }else{
            while(!pq.empty()&&pq.top()<=i) pq.pop();
        }
        cout << pq.size() << "\n";
    }
}
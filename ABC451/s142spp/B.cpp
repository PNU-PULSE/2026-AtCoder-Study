#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m; cin >> n >> m;
    vector<int> A(m+1);
    vector<int> B(m+1);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        A[a]++; B[b]++;
    }
    for(int i=1; i<=m; i++){
        cout << B[i]-A[i] << "\n";
    }
}
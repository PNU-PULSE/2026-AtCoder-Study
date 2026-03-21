#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int N;
    cin >> N;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = N; i > 1; i--){
        cout << i << ",";
    }
    cout << 1 << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int N, C[101][101];
    cin >> N;
    
    for(int i = 1; i <= N-1; i++){
        for(int j = i + 1; j <= N; j++){
            cin >> C[i][j];
        }
    }

    for(int a = 1; a <= N-2; a++){
        for(int b = a+1;b <= N-1; b++){
            for(int c = b+1; c <= N; c++){
                if (C[a][b] + C[b][c] < C[a][c]) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";

    return 0;
}
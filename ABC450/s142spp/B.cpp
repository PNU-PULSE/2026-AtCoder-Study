#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<vector<int>> s(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cin >> s[i][j];
        }
    }
    for(int i=0; i<n-2; i++){
        for(int j=i+2; j<n; j++){
            for(int k=i+1; k<j; k++){
                if(s[i][k]+s[k][j] < s[i][j]){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}
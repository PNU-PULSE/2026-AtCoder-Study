//환승이 직통보다 싸냐
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i=n; i>0; --i){
        for(int j=0; j<i-1; ++j){
            cin >> v[n-i][j];
        }
    }

    for(int i=0; i<=n-2; ++i){
        for(int j=0; j<=n-2-i; ++j){
            if(v[i][0] + v[i+1][j] < v[i][j+1]){
                cout << "Yes";
                return 0;
            }
        }
    }
    
    cout << "No";
        
}
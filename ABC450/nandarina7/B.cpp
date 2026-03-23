#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            cin >> table[i][j];
        }
    }
    
    int flag = 0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int k=j+1;k<=n;++k){
                //cout << table[i][j] + table[j][k] << ' ' << table[i][k] << '\n';
                if(table[i][j] + table[j][k] < table[i][k]){
                    flag = 1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    
    if(flag==1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
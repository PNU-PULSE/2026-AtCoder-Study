#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> dep(m+1, {0,0});
    for(int i=0;i<n;++i){
        int a, b;
        cin >> a >> b;
        dep[a].first++;
        dep[b].second++;
    }
    
    for(int i=1;i<=m;++i){
        cout << dep[i].second - dep[i].first << '\n';
    }
    return 0;
}
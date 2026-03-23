#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k;
    map<long long, long long> check;
    cin >> n >> k;
    
    for(int i=0;i<n;++i){
        long long num;
        cin >> num;
        if(check[num%k]>0){
            if(check[num%k] < num){
                check[num%k] = num;
            }
        }else{
            check[num%k] = num;
        }
    }
    
    vector<long long> table;
    for(auto c : check){
        table.push_back(c.second);
    }
    
    sort(table.begin(), table.end());
    long long mx_v = table[table.size()-1];
    long long mn_v = table[0];
    //cout << mx_v << ' ' << mn_v;
    
    long long diff = 10000000000000;
    
    while(true){
        int remain = (mx_v - mn_v)/k;
        if(remain==0){
            table[0] += 1*k;
        }else{
            table[0] += (remain)*k;
        }
        sort(table.begin(), table.end());
        mx_v = table[table.size()-1];
        mn_v = table[0];
        
        if(mx_v - mn_v >= diff){
            break;
        }else{
            diff = mx_v - mn_v;
        }
    }
    
    cout << diff;
    
    return 0;
}
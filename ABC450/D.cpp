#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    vector<int> v(n), v2(n);
    int maxi = -1;
    for(int& i : v){
        cin >> i;
        if(i > maxi)
            maxi = i;
    }

    v2 = v;
    for(int& i : v){
        while(abs(maxi - i) >= (k/2)){//
            i += k;
        }
    }
    for(int& i : v2){
        while(abs(maxi - i) > (k/2)){//
            i += k;
        }
    }
    
    int v_max = *max_element(v.begin(), v.end());
    int v_min = *min_element(v.begin(), v.end());
    int v2_max = *max_element(v2.begin(), v2.end());
    int v2_min = *min_element(v2.begin(), v2.end());
    cout << min(v_max-v_min, v2_max-v2_min);
}
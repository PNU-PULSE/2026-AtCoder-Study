#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    vector<char> letter;

    cin >> n >> l >> r;
    while(n--){
        char c;
        cin >> c;
        letter.emplace_back(c);
    }
        
    int ans = 0;
    for(auto it = letter.begin(); it!=letter.end(); ++it){
        int gap = it - letter.begin();
        for(auto i=letter.begin()+gap+l; i!=letter.begin()+gap+r+1; ++i){
            if(i == letter.end()) break;
            if(*it == *i) ans++;
        }
    }

    cout << ans;
}
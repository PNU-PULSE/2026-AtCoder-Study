#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    while(q--){
        int type, num;
        cin >> type >> num;
        
        if(type == 1){
            cout << w*num << endl;
            h -= num;
        }
        else{
            cout << h*num << endl;
            w -= num;
        }
    }
}
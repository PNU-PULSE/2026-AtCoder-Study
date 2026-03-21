#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int h, w, q;
    cin >> h >> w >> q;
    for(int i=0;i<q;++i){
        int cmd, v;
        cin >> cmd >> v;
        if(cmd == 1){
            cout << w*v << '\n';
            h -= v;
        }else{
            cout << h*v << '\n';
            w -= v;
        }
    }
    return 0;
}

/*

7x9

4*7 = 28


*/
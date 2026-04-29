#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w));
    for (int i=0; i<h; ++i){
        for (char& c : v[i])
            cin >> c;
    }

    int ans = 0;
    for (int h1=0; h1<h; ++h1){
        for (int h2=h1; h2<h; ++h2){
            for (int w1=0; w1<w; ++w1){
                for (int w2=w1; w2<w; ++w2){
                    bool isSym = true;
                    for (int i=h1; i<=h2; ++i){
                        for (int j=w1; j<=w2; ++j){
                            if (v[i][j] != v[h1+h2-i][w1+w2-j]){
                                isSym = false;
                                break;
                            }
                        }
                        if (!isSym) break;
                    }
                    if (isSym){
                        ans++;
                        //cout << h1 << " " << h2 << " " << w1 << " " << w2 << endl;
                    }
                }
            }
        }
    }
    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    string s, t; cin >> s >> t;
    bool flag = false;
    for (int i=0 ; i<N ; i++) {
        if (t[i] == '*') continue;
        else if (t[i] == s[i]) continue;
        else flag = true;
    }

    if (flag) cout << "No";
    else cout << "Yes";
}
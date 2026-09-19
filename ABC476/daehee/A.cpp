#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    int n = s.length();
    if (s[n-1] == 'e') cout << s << "r";
    else cout << s << "er";
}
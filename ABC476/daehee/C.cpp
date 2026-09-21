#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> arr;
    int a, b; cin >> a >> b;
    arr.push_back(a);
    arr.push_back(b);
    for (int i=3 ; i<=N ; i++) {
        int c; cin >> c;
        arr.push_back(c);
        sort(arr.begin(), arr.end(), greater<>());
        if (arr.size() > 3) arr.pop_back();
        cout << arr[2] << "\n";
    }
}
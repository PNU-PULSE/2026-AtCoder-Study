#include <bits/stdc++.h>
using namespace std;

vector<int> before, after;

int main() {
    int n, m;
    cin >> n >> m;

    before.assign(m + 1, 0);
    after.assign(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int b, a;
        cin >> b >> a;

        before[b]++;
        after[a]++;
    }

    for (int i = 1; i <= m; i++) {
        cout << after[i] - before[i] << '\n';
    }
}
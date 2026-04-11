#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<pair<int, int>> board(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        board[i] = {a, b};
    }

    int m;
    cin >> m;

    vector<int> result(m, 0);
    vector<int> candidates;
    vector<string> str(m);

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        str[i] = s;
        if (s.size() == n) {
            candidates.push_back(i);
        }
    }

    for (auto candidate : candidates) {
        int all = 0;
        for (int i = 0; i < n; i++) {
            char start = str[candidate][i];
            auto [len, idx] = board[i];
            int part = 0;
            for (int j = 0; j < m; j++) {
                // cout << len << ' ' << idx << ' ' << str[j] << ' ' << start << endl; 
                if (str[j].size() == len && str[j][idx - 1] == start) {
                    part = 1;
                    break;
                }
            }
            if (part) {
                all++;
            }
        }
        if (all == n) {
            result[candidate] = 1;
        }
    }

    for (auto e : result) {
        if (e) cout << "Yes\n";
        else   cout << "No\n";
    }
}
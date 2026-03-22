#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> station;

int n;

bool isSatisfy() {
    for (int a = 1; a <= n - 2; a++) {
        for (int b = a + 1; b <= n - 1; b++) {
            for (int c = b + 1; c <= n; c++) {
                
                // cost index = end - start - 1
                int cost_ab = station[a][b - a - 1];
                int cost_bc = station[b][c - b - 1];
                int cost_ac = station[a][c - a - 1];

                if (cost_ab + cost_bc < cost_ac) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    station.assign(n + 1, vector<int>());

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int c;
            cin >> c;
            station[i].push_back(c);
        }
    }

    if (isSatisfy()) cout << "Yes\n";
    else             cout << "No\n";
}
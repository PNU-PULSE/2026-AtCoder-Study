#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> festivals[] = {{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9}};

    int m, d;
    cin >> m >> d;

    int found = 0;
    for (auto e : festivals) {
        if (e.first == m && e.second == d) {
            found = 1;
        }
    }

    if (found) cout << "Yes";
    else       cout << "No";
}
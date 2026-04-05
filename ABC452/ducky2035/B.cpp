#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c; cin >> r >> c;
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (x == 0 || x == c-1 || y == 0 || y == r-1)
                cout << "#";
            else
                cout << ".";
        }
        cout << "\n";
    }
    return 0;
}
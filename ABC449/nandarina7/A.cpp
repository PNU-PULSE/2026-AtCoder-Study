#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double n;
    cin >> n;
    cout << fixed << setprecision(10) << (n/2)*(n/2)*3.141592653589793;
    return 0;
}
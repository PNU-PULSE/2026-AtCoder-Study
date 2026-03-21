#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main()
{
    double D;
    cin >> D;

    double area = PI * pow(D / 2, 2);

    cout << fixed;
    cout.precision(10);

    cout << area << endl;

    return 0;
}
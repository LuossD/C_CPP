#include <iostream>
#include <iomanip>
using namespace std;
#define One 1
int main()
{
    double a, b, sum;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    sum = a * (1 + b / 100);
    cout << fixed << setprecision(2) << sum << endl;
    cout << One << endl;
    return 0;
}
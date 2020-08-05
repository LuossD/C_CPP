#include <iostream>
#include "zyrandom.h" //用双引号
using namespace std;
int main()
{
    int i;
    Randomize();
    for(i = 0; i < 8; i++)
    {
        int t = GenerateRandomNumber(10, 90);
        cout << t << ";";
    }
    cout << endl;
    for(i = 0; i < 8; i++)
    {
        double t = GenerateRandomReal(10.0, 90.0);
        cout << t << ";";
    }
    cout << endl;
}
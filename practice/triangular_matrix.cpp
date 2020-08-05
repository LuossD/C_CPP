#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, m, i, j;
    cout << "Please enter the number of lines:";
    cin >> n;
    while(n < 1)
    {
        cout << "Please enter again:";
        cin >> n;
    }
    cout << "Please enter the number of spaces";
    cin >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = i; j < n ; j++)
        {
            cout << " ";
        }
        for(j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << setw(m) << " ";
        for(j = 1; j <= 2 * (n - i) + 1; j++)
        {
            cout << "*";
        } 
        cout << endl;
    } 
    return 0;
}
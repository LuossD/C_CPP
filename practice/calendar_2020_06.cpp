#include <iostream>
#include <iomanip>

using namespace std;

typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } WEEKDAY;

int main()
{
    int date;
    const WEEKDAY date_1 = MON;
    //WEEKDAY weekday;
    cout << "The program gets a date (1-31), and prints a calendar.\n";
    cout << "Calendar 2020-06\n";
    cout << "..........................\n";
    cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";
    cout << "..........................\n";
    for(date = 1; date < 31; date++)
    {
        //weekday = WEEKDAY((date + (int)date_1 - 1) % 7);
        if(date == 1)
            cout << setw(4 * (int)date_1 + 2) << date;
        else if(date % 7 != 0)
            cout << setw(4) << date;
        else
        {
            cout << endl;
            cout << setw(2) << date;
        }
        
    }
    return 0;
}
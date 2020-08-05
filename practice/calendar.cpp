#include <iostream>
#include <iomanip>

using namespace std;

typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } WEEKDAY;

int main()
{
    int date;
    const WEEKDAY date_1 = FRI;
    WEEKDAY weekday;
    cout << "The program gets a date (1-31), and prints a calendar.\n";
    cout << "The date:";
    cin >> date;
    if( date < 1 || date > 31 )
    {
        cout << "Date error!\n";
        return 1;
    }
    weekday = WEEKDAY((date + (int)date_1 - 1) % 7);
    cout << "Calendar 2006-12\n";
    cout << "..........................\n";
    cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";
    cout << "..........................\n";
    switch (weekday)
    {
    case SUN:
        cout << setw(2) << date;
        break;
    case MON:
        cout << setw(6) << date;
        break;
    case TUE:
        cout << setw(10) << date;
        break;
    case WED:
        cout << setw(14) << date;
        break;
    case THU:
        cout << setw(18) << date;
        break;
    case FRI:
        cout << setw(22) << date;
        break;
    case SAT:
        cout << setw(26) << date;
        break;
    default:
        break;
    }
    //如果没有break语句，进入相应的switch语句执行完后会继续往下执行；如果开始
    //进入的是case SAT，则不会继续执行了，因为它是最后一条语句了。
    //cout << "\n";
    cout << "\n..........................\n";
    return 0;
}
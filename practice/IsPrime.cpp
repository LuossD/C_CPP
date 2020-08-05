#include <iostream>
#include <math.h>
using namespace std;
void IsPrime(int n);
void welcome();
int UserInput();
int main()
{
    int a;
    welcome();
    a = UserInput();
    //return IsPrime(n);
    IsPrime(a);
    return 0;
}
void welcome()
{
    cout << "The program determines whether a number is prime.\n";
    return;
}
int UserInput()
{
    int n;
    cout << "Please enter a positive integer greater than two:";
    cin >> n;
    while(n <= 2)
    {
        cout << "Please enter again:";
        cin >> n;
    }
    return n;
}
void IsPrime(int n)
{
    unsigned int i, j;
    //sqrt接受的是一个double类型的浮点数，返回值还是一个double类型的浮点数；无符号整型为非负数
    //比较浮点数对我们没有意义，对我们来说实际上是一个整数，要把sqrt的结果转为unsigned int,结果会将数值的小数部分砍掉
    //以前的计算机sqrt(121)浮点数在计算机中表示的时候可能会被表示为10.9999，这样转为整型后为10，出现判断错误，所以把循环上限加一就好
    //现在的计算机完全平方数开根号后面的小数点都是0，非常精确，上限可以不必加一
    //另外应该把sqrt(n)计算出来的值放在循环外面做一次就好，因为这个数是固定的，如果放在循环里每次都要计算浪费计算时间
    //for循环也可用while代替，初始化也更简单：unsigned int i = 3,t = (unsigned int)sqrt(n) + 1
    //用while循环也更简单，因为这个判断过程不用一个接一个用for循环，先把偶数排除，再while这样递增步长为2
    //写出一个算法后看看怎样优化使计算效率更高
    j = (unsigned int)sqrt(n) + 1;
    for(i = 2; i <= j; i++)
    {
        if(n % 2 == 0)
        {
            cout << "Your number is not a prime.";
            return;
        }
    }
    cout << "Your number is a prime.";
    return;
}
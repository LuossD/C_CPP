#include <iostream>
#include "static_test.h"
using namespace std;

int main()
{
    void * p, *q;
    cout << p << endl;
    __int64 a = 0x123;
    cout << &a << endl;
    q = &a;
    p = (void*)a;
    Example e(3);
    cout << e.scd << "\n" << e.ci << "\n" << e.si << endl;
    //printf("%d\n", (long p);
    cout << (intptr_t)p << endl;
    cout << &a << "\n" << p << "\n" << sizeof(void *) << "\n" << sizeof(a) <<endl;
    //cout << *q; //得转换后才能解引用
    return 0;
}
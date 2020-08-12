#include <string>
using namespace std;

class Example{
public:
    //Example(int a);
    Example(int a):ci(a) {}
public:
    static int si;
    const int ci;	//常成员变量，在构造函数的初始化列表中初始化
    static constexpr double scd = 1.01;
    //static const int sci;
    static const string scs;	//类类型的静态常量，必须在类外初始化
};
//初始化得写在源文件中
//Example::Example(int a) : ci(a) {}
//int Example::si = 20;
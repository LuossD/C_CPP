# 21天学通C++习题答案

## 第一章.绪论

### 1.解释器和编译器有何不同？

答案：解释器是一种对代码（或字节码）进行解释并执行相应操作的工具，**它每转译一行程序叙述就立刻运行，然后再转译下一行，再运行，如此不停地进行下去**（百度加的）；编译器将代码作为输入，并生成目标文件。就 C++而言，编译和链接后，将得到一个可执行文件，处理器可直接执行它，而无需做进一步解释。

他们最大的区别是程序运行时需要解释器边解释边执行，而编译器则在运行时是完全不需要的；

解释器的优点是比较容易让用户实现自己跨平台的代码，比如java，php等，同一套代码可以在几乎所有的操作系统上执行，而无需根据操作系统做修改；

编译器的目的就是生成目标代码再由链接器生成可执行的机器码，这样的话**需要根据不同的操作系统编制代码**，虽然有像Qt这样的源代码级跨平台的编程工具库，但在不同的平台上仍然需要重新编译连接成可执行文件，但其执行效率要远远高于解释运行的程序。

> 补充：机器码与字节码
>
> **1.机器码**
>
> 学名**机器语言指令，有时也被称为原生码**（Native Code），是电脑CPU直接读取运行的数据，运行速度最快，但是非常晦涩难懂，同时也比较难编写；
>
> 用机器语言编写程序，编程人员要首先熟记所用计算机的全部指令代码和代码的涵义。手编程序时，程序员得自己处理每条指令和每一数据的存储分配和输入输出，还得记住编程过程中每步所使用的工作单元处在何种状态。这是一件十分繁琐的工作，编写程序花费的时间往往是实际运行时间的几十倍或几百倍。而且，编出的程序全是些0和1的指令代码，直观性差，还容易出错。现在，除了计算机生产厂家的专业人员外，绝大多数的程序员已经不再去学习机器语言了。
>
> **2.字节码**
>
> 字节码是一种中间状态的（中间码）的二进制代码（文件），字节码（Bytecode）是一种**包含执行程序、由一序列 op 代码/数据对组成的二进制文件**。**字节码是一种中间码，它比机器码更抽象，需要直译器转译后才能成为机器码**；字节码通常情况下它是已经经过编译，但与特定机器码无关。字节码通常不像源码一样可以让人阅读，而是编码后的数值常量，引用，指令等构成的序列。字节码与特定的硬件环境无关；字节码的实现方式是通过编译器和虚拟机器。编译器将源码编译成字节码，特定平台上的虚拟机器将字节码转译为可以直接执行的指令。字节码的典型应用为Java bytecode
>
> **3.对比字节码与机器码**
>
> 机器码就是说计算机能读懂的代码,简单点说就是给计算机执行的二进制代码.
> 字节码,是JAVA语言专有的,它是让JVM来执行的二进制代码
> **虽然都是二进制代码,但是由于执行它的环境不一样,所以它们存在一些指令集上的区别**
>
> 一，机器码，完全依附硬件而存在～并且不同硬件由于内嵌指令集不同，即使相同的0 1代码 意思也可能是不同的～换句话说，根本不存在跨平台性～比如～不同型号的CPU,你给他个指令10001101，他们可能会解析为不同的结果～
> 二，我们知道JAVA是跨平台的，为什么呢？因为他有一个jvm,不论那种硬件，只要你装有jvm,那么他就认识这个JAVA字节码～～～～至于底层的机器码，咱不用管，有jvm搞定，他会把字节码再翻译成所在机器认识的机器码～～～
>
> 编译型语言：把做好的源程序全部编译成二进制代码的可执行程序。然后，可直接运行这个程序。 
> 解释型语言：把做好的源程序翻译一句，然后执行一句，直至结束！要在计算机上执行脚本，必须安装解释器。在运行段，解释器在微处理器和代码之间充当翻译，因此性能通常会受到影响。
>
> 个人认为，java是解释型的语言，因为虽然java也需要编译，编译成.class文件，但是并不是机器可以识别的语言，而是字节码，最终还是需要 jvm的解释，才能在各个平台执行，这同时也是java跨平台的原因。所以可是说java即是编译型的，也是解释型，但是假如非要归类的话，从概念上的定义，恐怕java应该归到解释型的语言中。 换句话说，**java虚拟机这个名字其实只是一个误导，java虚拟机和java没啥关系，其实更应该叫做 Class文件虚拟机**。因为其他语言， 只要有对应的编译器，输出结果就可以运行在java虚拟机上，所以时至今日,涌现Clojure、Groovy、JRuby、Jython、Scala一批运行在java虚拟机上的语言。
>
> **4.关于c++的跨平台问题**
>
> **C++跨不了平台是指C++最终生成的可执行程序没法跨平台**，还有一些和系统相关的调用在不同平台的代码可能不一样，有时会处理起来还比较麻烦。但是如果只是简单的代码，比如打印一个HelloWorld，拿着代码去不同平台编译出来，都能跑，并且跑出来结果一致。只不过和Python不同的是要先编译，然后运行的是编译出来的那个可执行程序。
>
> Python能跨平台是指Python代码写好去任何平台上执行命令python test.py都能运行，但是在不同平台都需要先安装对应平台的解释器，Python程序运行的时候不用编译，而是直接用python命令去执行代码文件，给人感觉就是写好代码，在任何平台都可以用同样的操作去运行，感觉上和平台无关了。
>
> 具体原因有很多，这里只简单拿别人写的比较好理解的话放在这里。再附上一个总体说的比较好的知乎答案
>
> 作者：建辰二九（华中科技大学光学工程博士）
> 链接：https://www.zhihu.com/question/386866683/answer/1144972027
>
> <font color='00aaee'>所有的程序不管是编译型的还是解释型的，最后都要以各种形式落实到机器语言上。</font>
>
> 首先，不同的CPU结构，设计理念不同，同一份机器语言，对应的功能可能就不一样，就像基本的与门和或门，都是2个输入1个输出，那么你输入1和0，这两个结构输出的结果是不一样的。当然这里有相关的指令集来做一次抽象，使得没有那么需要关心太具体的细节，但是不同架构之间的指令集往往也是不同的。
>
> 其次，操作系统是你程序编译、运行的直接载体，你的程序运行时，并不是简单的只有你写的那些代码。例如，很多东西涉及到在屏幕显示（printf、cout等），这个显示，最后肯定要落实到具体每个屏幕像素值什么怎么计算相关的东西，这部分程序你没写吧，那还能跑起来的原因是，操作系统提前写了很多东西，你的程序编译的时候编译器会帮你去找这些已经写好的内容。这个不同操作系统，对于硬件的操作、封装的内容也是不同的。
>
> 最后，编译器就是一个程序，并不是在C/C++程序里。编译器是个独立的程序，你写的程序就是个文本文件，你每次编译的时候，就是运行这个程序，把你写的程序文本“翻译”成机器语言，显然翻译的这个过程，**首先编译器要考虑操作系统里面的规范，按规定翻译，其次操作系统要考虑其管理的硬件的规范**。现代主流操作系统Windows、MacOS、Linux以及一些Unix，都会兼容很多架构的CPU以及相关硬件，但是这兼容可以理解为，操作系统预先有这些架构CPU的处理的代码，检测到啥就用啥，检测不到的就给你报错。最差的情况下M个操作系统，N个硬件，要有M*N个编译器。
>
> C/C++这种能够操作底层的语言，平台相关的特点表现的会非常明显。你在windows下写的代码，不一定能在linux上通过编译，你在windows下编译、能成功运行的程序，不一定能在linux能用，就是上面这些原因。
>
> Java、Python这些解释型语言，能够跨平台，不涉及UI库时跨平台表现一致的原因是，他们的运行基于一个虚拟机，这个虚拟机在操作系统之上由抽象出了一个“操作系统”，暂且不谈编译和解释的区别，就执行时那些脏活累活，一个不少，只是这个虚拟机替你做了而已，在不同平台的虚拟机的内部实现是不同的，因此这也是大部分时候，解释型语言执行效率比编译型慢不少的原因（JIT另说），一层又一层。

### 2.链接器的作用是什么？

编译器将 C++源代码文件作为输入，并生成一个使用机器语言（二进制）的目标文件。通常，您的代码依赖于库和其他代码文件中的函数。链接器负责建立这些链接，并生成一个可执行文件，它集成了您指定的所有直接或间接依存关系。

### 3.正常的开发周期包括哪些步骤？

编写代码；通过编译创建目标文件；通过链接创建可执行文件；执行应用程序以便进行测试；调试；修复代码中的错误并重复这些步骤。

## 第三章.使用变量和常量

### 知识点

#### 1.命名约定

您可能注意到了，在函数名 MultiplyNumbers()中，每个单词的首字母都大写，这被称为 Pascal 拼写法，而在变量名 firstNumber、secondNumber 和 multiplicationResult 中，第一个单词的首字母采用小写，这被称为骆驼拼写法。本书遵循这样的命名约定，即对于变量名，采用骆驼拼写法，而对于诸如函数名等其他元素，采用 Pascal 拼写法。

### 习题

#### 1．有符号整型和无符号整型有何不同？

有符号整型变量的最高有效位（MSB）用作符号位，指出了整数值是正还是负，0表示正，1表示负，而无符号整型变量只能存储正整数。

#### 2．为何不应使用#define 来声明常量？

\#define 是一个预处理器编译指令，让编译器对定义的值进行文本替换。然而，**它不是类型安全的**，是一种原始的常量定义方式，应避免使用。

#### 3．为何要对变量进行初始化？

确保变量包含非随机的确定值。

#### 4．下述变量名有何问题？

int Integer = 0; 

这个**变量名不具描述性**，并重复地指出了变量的类型。这种代码虽然能够通过编译，但**难以理解和维护，应避免**。声明变量时，**应使用能揭示其用途的名称**，如：int age = 0。

## 第四章.管理数组和字符串

### 知识点

#### 1.静态数组

要定义一个包含 5 个字符的数组，可以这样做：

char myCharacters [5]; 

这样的数组被称为静态数组，**因为在编译阶段，它们包含的元素数以及占用的内存量都是固定的**。

初始化静态数组

1.利用初始={0}赋值为0 

```c++
int manyNumbers [50] = {0}; // 全部初始化为0
int manyNumbers [50] = {1}; // 第一个为1，后面全为0
```

2.用memset赋值为0

```c++
int a [50]；
memset(a, 0 , sizeof(a));
// memset可赋值为全0或全-1
```

两者的比较：

两者速度一样，都是0.0000sec；c
赋值为0，建议使用int c[100]={0};不用写头文件<cstring>，而且写代码速度更快，只需要一行；
赋值为-1，只能使用memset(c, -1, sizeof(int)*100);

特别注意：

1）全局变量和静态变量初始化时会自动被设置为0。如果们声明全局变量，那么他在运行前会变成全0。

```c++
int arr[1024]; // This is global
int main(void)
{ //statements}
```

2）对于局部数组我们还有**简写的初始化语法**。如果一个数组被**部分初始化，没有被初始化的元素会被自动设置为相应类型的0**。**这是编译器自动完成的**，可以这样写：

```c++
int main()
{ int arr[1024] = {0}; // This will make all ZERO 
 // statements
}
// 变长数组（柔性数组）不可用。
```

3）你还可以用memset函数在程序开始时初始化数组。**这条命令这在你已经修改了数组之后又想将它重置为全0特别有用。（变长数组适用）**

#### 2.C风格字符串

C 风格字符串是一种特殊的字符数组。您在前面编写代码时使用过字符串字面量，它们就是 C 风格字符串：

std::cout << "Hello World"; 

这与下面使用数组的方式等价：

char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; 

std::cout << sayHello << std::endl; 

这种 C 风格字符串是特殊的字符数组，因为总是在最后一个字符后加上空字符‘\0’。您**在代码中使用字符串字面量时，编译器将负责在它后面添加‘\0’**。

**在数组中间插入‘\0’并不会改变数组的长度，而只会导致将该数组作为输入的字符串处理将到这个位置结束**，如下程序演示了这一点。

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: char sayHello[] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'}; 
 6: cout << sayHello << endl; 
 7: cout << "Size of array: " << sizeof(sayHello) << endl; 
 8: 
 9: cout << "Replacing space with null" << endl; 
10: sayHello[5] = '\0'; 
11: cout << sayHello << endl; 
12: cout << "Size of array: " << sizeof(sayHello) << endl; 
13: 
14: return 0; 
15: }

输出如下：
Hello World 
Size of array: 12 
Replacing space with null 
Hello 
Size of array: 12
// 第 10 行将“Hello World”中的空格替换为终止空字符。这样，该数组包含两个终止空字符，但只有第一个发挥了作用，导致第 11 行显示字符串时将其截短为 Hello。第 7 和 12 行的 sizeof( )的输出表明，数组的长度没变，虽然显示的字符串发生了很大变化。
```

注意：如果在第 5 行声明并**初始化字符数组时忘记添加‘\0’，则打印该数组时，Hello World 后面将出现垃圾字符**，这是因为 std::cout 只有遇到空字符后才会停止打印，即便**这将跨越数组的边界。在有些情况下，这种错误可能导致程序崩溃，进而影响系统的稳定性**。

C 风格字符串充斥着危险，看如下程序

```c++
 0: #include<iostream> 
 1: #include<string.h> 
 2: using namespace std; 
 3: int main() 
 4: { 
 5: cout << "Enter a word NOT longer than 20 characters:" << endl; 
 6: 
 7: char userInput [21] = {'\0'}; 
 8: cin >> userInput; 
 9: 
10: cout << "Length of your input was: " << strlen (userInput) << " " << sizeof(userInput) << endl; 
11: 
12: return 0; 
13: }
// 
Enter a word NOT longer than 20 characters: 
Don'tUseThisProgram 
Length of your input was: 19 21
// 第 10 行使用了 strlen 来计算该字符串的长度。strlen遍历该字符数组，直到遇到表示字符串末尾的终止空字符，并计算遍历的字符数。cin 在用户输入的末尾插入终止空字符。strlen 的这种行为非常危险，因为如果用户输入的文本长度超过了指定的上限，strlen将跨越字符数组的边界
```

注意：

当输入字符串时，运算符“>>”的作用是跳过空白，读入后面的非空白字符，直到遇到另一个空白字符为止，并在串尾放一个字符‘\0’。也就是说在你输入实际字符前的空格它跳过，输入实际字符后再遇到空格提取就截止了，比如：

```c++
  heisa cute
Length of your input was: 5
// 字符前有两个空格都跳过了
```

解决方法：

```c++
void getstring()
{  cout<<“请输入字符串：”<<endl;
   gets(str);
}
当键入的字符串为:
Object_Oriented Programming!
   结果是:
   str指向的字符串为：
   “Object_Oriented Programming!”
注：也可以使用cin.getline()，但gets（）更简单。
// 代码貌似有问题
```

另外：字符串数组初始化的时候全初始化为'\0'，即空字符，要判断是否初始化为空字符了，可以输出其ASCII码int(userInput[1])看看其值是否为0，测试表示是的。

**提醒**：这些 C 风格字符串作为输入的函数非常危险，因为它们寻找终止空字符，如果程序员没有在字符数组末尾添加空字符，这些函数将跨越字符数组的边界。

总结：C 风格字符串是特殊的 char 数组，用终止空字符‘\0’标识末尾。任何优秀的程序员都应避免使用 C 风格字符串。

#### 3.C++字符串：使用 std::string

无论是处理文本输入，还是执行拼接等字符串操作，使用 C++标准字符串都是更高效、更安全的方式。不同于字符数组（C 风格字符串实现），std::string 是动态的，在需要存储更多数据时其容量将增大。

> 1）文件cstring，和string.h对应，c++版本的头文件，包含比如strcpy之类的字符串处理函数
> 2）文件string.h，和cstring对应，c版本的头文件，包含比如strcpy之类的字符串处理函数
> 3）文件string，包含std::string的定义，属于STL范畴
> 4）CString，MFC里的的字符串类

```c++
 1: #include <string> 
 2: 
 3: using namespace std; 
 4：
 5: int main() 
 6: { 
 7: string greetString ("Hello std::string!"); 
 8: cout << greetString << endl; 
 9: 
10: cout << "Enter a line of text: " << endl; 
11: string firstLine; 
12: getline(cin, firstLine); 
13: 
14: cout << "Enter another: " << endl; 
15: string secondLine; 
16: getline(cin, secondLine); 
17: 
18: cout << "Result of concatenation: " << endl; 
19: string concatString = firstLine + " " + secondLine; 
20: cout << concatString << endl; 
21: 
22: cout << "Copy of concatenated string: " << endl; 
23: string aCopy; 
24: aCopy = concatString; 
25: cout << aCopy << endl; 
26: 
27: cout << "Length of concat string: " << concatString.length() << endl; 
28: 
29: return 0; 
30: }
```

```c++
Hello std::string! 
Enter a line of text: 
I love 
Enter another: 
C++ strings 
Result of concatenation: 
I love C++ strings 
Copy of concatenated string: 
I love C++ strings 
Length of concat string: 18
```

### 习题

1.如果忘记在 C 风格字符串末尾添加终止空字符，使用它的结果将如何？

这取决于您如何使用它。如果将其用于 cout 语句，将不断读取字符，直到遇到终止空字符。这将跨越数组边界，可能导致应用程序崩溃。

2.声明一个表示国际象棋棋盘的数组；该数组的类型应为枚举，**该枚举定义了可能出现在棋盘方格中的棋子**。

提示：这个枚举包含枚举量 Rook、Bishop 等，从而限制了数组元素的取值范围。另外，别忘了棋盘方格也可能为空！

下面是一种可能的解决方案，这里只初始化了包含“车”的棋盘方格，但足以让您明白其中的

要点：

```c++
int main() 
{ 
 enum Square 
 { 
 Empty = 0, 
 Pawn, // 兵
 Rook, // 车
 Knight, // 马
 Bishop, // 象
 King, 
 Queen 
 }; 
 Square chessBoard[8][8]; 

 // Initialize the squares containing rooks 
 chessBoard[0][0] = chessBoard[0][7] = Rook; 
 chessBoard[7][0] = chessBoard[7][7] = Rook; 
 return 0; 
} 
```

## 第五章.使用表达式、语句和运算符

### 知识点

从本质上说，程序是一组按顺序执行的命令。**这些命令为表达式和语句，使用运算符执行特定的计算或操作。**

#### 1.递增运算符的前缀与后缀

```c++
int num2 = num1++; // Postfix increment operator 
int num2 = ++num1; // Prefix increment operator
```

首先需要理解前缀和后缀之间的差别，这样才能选择合适的方式。使用后缀运算符时，**先将右值赋给左值，再将右值递增或递减**。这意味着在上述所有使用后缀运算符的代码中，num2 都为 num1 的旧值（执行递增或递减前的值）。前缀运算符的行为完全相反，即**先将右值递增或递减，再将结果赋给左值**。

在下面的**语句**中，使用前缀还是后缀运算符对结果没有影响：

```c++
startValue++; // Is the same as…

++startValue; 
```

这是因为没有将原来的值赋给其他变量，这两种情形的最终结果都是将startValue 递增。

注意：

您经常会听到前缀运算符的性能更高还是后缀运算符性能更高的争论。换句话说，++startValue 优于 startValue++。

至少从理论上说确实如此，**因为使用后缀运算符时，编译器需要临时存储初始值，以防需要将其赋给其他变量**。就整型变量而言，这对性能的影响几乎可以忽略不计，但对某些类来说，这种争论也许有意义。聪明的编译器可能通过优化消除这种差异。

#### 2.关系表达式中输出布尔类型变量

输出时布尔值 false 显示为 0，而布尔值 true 显示为 1。实际上bool型变量占用了 1 个字节的内存，当值为 false 的时候，实际上zhi存储的是 0x00,
为ture时实际上存储的是 0x01。因此，可以认为bool类型做为整型用时为true=1，false=0。

如果使用c++中iostream来输出的话可以用std::boolalpha 来控制，默认情况下使用整数0,1来代表bool值的。如果想输出true或false，则应写成这样：

```c++
bool test = true;
cout << "the output is number " << test << endl;
cout << "the output is bool(use boolalpha) " << boolalpha << test << endl;
cout << "the output is number(use noboolalpha) " << noboolalpha << test << endl;
```

#### 3.使用 C++逻辑运算 NOT（!）、AND（&&）和 OR（||）

如果明天下雨且没有公交车，我就不能去上班

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: cout << "Use boolean values(0 / 1) to answer the questions" << endl; 
 6: cout << "Is it raining? "; 
 7: bool isRaining = false; 
 8: cin >> isRaining; 
 9: 
10: cout << "Do you have buses on the streets? "; 
11: bool busesPly = false; 
12: cin >> busesPly; 
13: 
14: // Conditional statement uses logical AND and NOT 
15: if (isRaining && !busesPly) 
16: cout << "You cannot go to work" << endl; 
17: else 
18: cout << "You can go to work" << endl; 
19: 
20: if (isRaining && busesPly) 
21: cout << "Take an umbrella" << endl; 
22: 
23: if ((!isRaining) && busesPly) 
24: cout << "Enjoy the sun and have a nice day" << endl; 
25: 
26: return 0; 
27: }
```

#### 4.按位运算符 NOT（～）、AND（&）、OR（|）和 XOR（^）

逻辑运算符和按位运算符之前的差别在于，**按位运算符返回的并非布尔值，而是对操作数对应位执行指定运算的结果**。C++让您能够执行按位 NOT、OR、AND 和 XOR（异或）运算，它们分别使用～将每位取反、使用 | 对相应位执行 OR 运算、使用 & 对相应位执行 AND 运算、使用 ^ 对相应位执行 XOR运算。其中后三个运算符对变量与选择的数字（通常是位掩码）执行相应的运算。

#### 5.按位右移运算符（>>）和左移运算符（<<）

移位运算符将整个位序列向左或向右移动，其用途之一是将数据乘以或除以 2n。

```c++
下面的移位运算符使用示例将变量乘以 2：
int doubledValue = num << 1; // shift bits one position left to double value 
下面的的移位运算符使用示例将变量除以 2：
int halvedValue = num >> 1; // shift bits one position right to halve value
```

#### 6.使用运算符 sizeof 确定变量占用的内存量

这个运算符指出特定类型或变量占用的内存量，单位为字节。sizeof 的用法如下：

```c++
sizeof (variable); 
或
sizeof (type); 
```

注意：sizeof(…)看起来像函数调用，但它并不是函数，而是运算符。有趣的是，程序员不能定义这个运算符，因此不能重载它。

#### 7.运算符优先级

务必使用括号让代码和表达式易于理解。不要编写必须依靠运算符优先级表才能理解的复杂表达式；应确保代码对人来说也易于理解。

务必使用正确的变量类型，确保它不会溢出。

所有的左值（如变量）都可用作右值，但并非所有的右值都可用作左值（如“Hello World”），务必要明白这一点。

### 习题

#### 1.既然 unsigned short 占用的内存更少，为何有些程序还使用 unsigned int？

unsigned short 变量的最大取值通常为 65535（占用16位内存，2个字节），如果这种变量的值已经是 65535，再递增将溢出，变成零。为避免这种行为，设计良好的程序在不能确定变量的取值远低于 65535 时，应将其数据类型声明为 unsigned int。

## 第六章.控制程序流程

### 知识点

避免使用 goto，可防止代码不直观难以理解且难以维护。

#### 1.for循环

初始化语句、条件表达式（检查退出条件）以及修改变量（变量更新）的语句都是可选的，for 语句可以不包含这些部分。

使用 for 循环（省略了修改变量的语句）根据用户的请求重复执行计算

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: // without loop expression (third expression missing) 
 6: for(char userSelection = 'm'; (userSelection != 'x');) 
 7: { 
 8: cout << "Enter the two integers: " << endl; 
 9: int num1 = 0, num2 = 0; 
10: cin >> num1; 
11: cin >> num2; 
12: 
13: cout << num1 << " x " << num2 << " = " << num1 * num2 << endl; 
14: cout << num1 << " + " << num2 << " = " << num1 + num2 << endl; 
15: 
16: cout << "Press x to exit or any other key to recalculate" << endl; 
17: cin >> userSelection; 
18: } 
19: 
20: cout << "Goodbye!" << endl; 
21: 
22: return 0; 
23: }
```

注意：

在 for 循环的初始化表达式中，可初始化多个变量。对于程序清单 6.11 所示的 for 循环，

如果在其中初始化多个变量，将类似于下面这样：

```c++
for (int counter1 = 0, counter2 = 5; // initialize 
 counter1 < ARRAY_LENGTH; // check 
 ++counter1, --counter2) // increment, decrement 
```

注意到新增的变量 counter2 被初始化为 5。有趣的是，还可使用**循环表达式**（第三个表达式）在每次循环时都将其递减。

所以，for循环内部可以总结为三个表达式：初始化表达式，条件表达式，循环表达式。

#### 2.基于范围的for循环

C++11 引入了一种新的 for 循环，让对一系列值（如数组包含的值）进行操作的代码更容易编写和理解。

基于范围的 for 循环也使用关键字 for：

```c++
for (VarType varName : sequence) 
{ 
 // Use varName that contains an element from sequence 
} 
```

```c++
例如，给定一个整型数组 someNums，可像下面这样使用基于范围的 for 循环来读取其中的元素：
int someNums[] = { 1, 101, -1, 40, 2040 }; 
for (int aNum : someNums) // range based for 
	cout << "The array elements are " << aNum << endl;
```

通过使用关键字 auto 来自动推断变量的类型，可编写一个通用的 for 循环，对任何类型的数组 elements 进行处理，从而进一步简化前面的 for 语句：

```c++
for (auto anElement : elements) // range based for
	cout << "Array elements are " << anElement << endl;
```

这种简洁性让基于范围的 for 循环成了最受欢迎的 C++新功能之一。

特别的，无限for循环：for(;;)。

#### 3.continue与break

C++ 中的 **continue** 语句有点像 **break** 语句。但它不是强迫终止，continue 会**跳过当前循环中的代码，强迫开始下一次循环**。

对于 **for** 循环，**continue** 语句会导致执行条件测试和循环增量部分。对于 **while** 和 **do...while** 循环，**continue** 语句会导致程序控制回到条件测试上。（即重新评估循环条件，如果为 true，则重新进入循环块）

![img](https://www.runoob.com/wp-content/uploads/2014/09/c-continue-statement-works.jpg)

注意：程序员通常的预期是，如果循环条件满足，将执行循环中的所有代码。contiune 和 break改变了这种行为，可能导致代码不直观。因此，应尽量少用 continue 和 break。不要不分青红皂白地使用 continue 和 break。除非万不得已，否则不要编写使用 break 来结束的无限循环。

#### 4.嵌套循环

使用嵌套循环计算斐波纳契数列

著名的斐波纳契数列以 0 和 1 打头，随后的每个数字都是前两个数字之和。因此斐波纳契数列的开头类似于下面这样：

0, 1, 1, 2, 3, 5, 8, … and so on

```c++
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: const int numsToCalculate = 5; 
 6: cout << "This program will calculate " << numsToCalculate \ 
 7: << " Fibonacci Numbers at a time" << endl; 
 8: 
 9: int num1 = 0, num2 = 1; 
10: char wantMore = '\0'; 
11: cout << num1 << " " << num2 << " "; 
12: 
13: do 
14: { 
15: for (int counter = 0; counter < numsToCalculate; ++counter) 
16: { 
17: cout << num1 + num2 << " ";
18: 
19: int num2Temp = num2; 
20: num2 = num1 + num2; 
21: num1 = num2Temp; 
22: } 
23: 
24: cout << endl << "Do you want more numbers (y/n)? "; 
25: cin >> wantMore; 
26: }while (wantMore == 'y'); 
27: 
28: cout << "Goodbye!" << endl; 
29: 
30: return 0; 
31: }
// 这个程序将一次计算5个斐波那契数。部 do…while 循环基本上是一个询问循环，询问用户是否要生成更多的数字。
```

### 习题

#### 1.我通过复制并粘贴将 do…while(exp);改成了 while(exp);，这会导致问题吗？

会出大问题！while(exp);合法，却是一个空 while 循环，因为 while 后面是一条空语句（分号），即便后面有语句块亦如此。后面的语句块将执行一次，但它位于循环外面。复制并粘贴代码时务必小心。

#### 2.编写一个 switch-case 结构，指出用户选择的颜色是否出现在彩虹中。请使用枚举常量

```c++
#include <iostream> 
using namespace std; 
int main() 
{ 
 enum Colors 
 { 
 Violet = 0, 
 Indigo, 
 Blue, 
 Green, 
 Yellow, 
 Orange, 
 Red, 
 Crimson, 
 Beige, 
 Brown, 
 Peach, 
 Pink, 
 White, 
 }; 
 cout << "Here are the available colors: " << endl; 
 cout << "Violet: " << Violet << endl; 
 cout << "Indigo: " << Indigo << endl; 
 cout << "Blue: " << Blue << endl; 
 cout << "Green: " << Green << endl; 
 cout << "Yellow: " << Yellow << endl;
 cout << "Red: " << Red << endl; 
 cout << "Crimson: " << Crimson << endl; 
 cout << "Beige: " << Beige << endl; 
 cout << "Brown: " << Brown << endl; 
 cout << "Peach: " << Peach << endl; 
 cout << "Pink: " << Pink << endl; 
 cout << "White: " << White << endl; 
 cout << "Choose one by entering code: "; 
 int YourChoice = Blue; // initial 
 cin >> YourChoice; 
 switch (YourChoice) 
 { 
 case Violet: 
 case Indigo: 
 case Blue: 
 case Green: 
 case Yellow: 
 case Orange: 
 case Red: 
 	cout << "Bingo, your choice is a Rainbow color!" << endl; 
 	break; 
 default: 
 	cout << "The color you chose is not in the rainbow" << endl; 
 	break; 
 } 
 return 0; 
}
// 可以看到多个case的语句相同时可以放在最后只写一个
```

#### 3.查错：下面的代码有何错误？

```c++
int loopCounter = 0; 
while(loopCounter <5); 
{ 
 cout << loopCounter << " "; 
 loopCounter++; 
}
```

在 while 语句后面是一条空语句（;），因此无法实现预期的循环。另外，由于控制 while 的loopCounter 永远不会递增，**因此 while 循环永远不会结束，它后面的语句不会执行。**

## 第七章.使用函数组织代码

### 知识点

1.要么将有默认值的参数放在列表末尾（否则将出现编译错误），要么给所有参数都指定默认值。

2.大多数较新的 C++编译器都提供了各种性能优化选项。有些提供了优化大小或速度的选项，如 Microsoft C++编译器。为内存弥足金贵的设备和外设开发软件时，优化代码的大小至关重要。优化代码大小时，编译器可能拒绝众多的内联请求，因为这会让代码急剧膨胀。**优化速度时，编译器通常会寻找并利用合理的内联机会，为您完成内联工作，即便您没有显式地请求这做**。

3.关键字 auto，使用它可让编译器根据赋给变量的初始值来推断变量的类型。**从 C++14起，这种做法也适用于函数**：使用 auto 让编译器根据您返回的值来推断函数的返回类型，而不直接指定返回类型。

**注意**：对于依赖于返回类型自动推断的函数，必须先定义（即实现）再调用。这是因为调用函数时，编译器必须知道其返回类型。如果这种函数包含多条 return 语句，必须确保根据它们推断出的返回类型都相同。另外，在递归调用后面，至少得有一条 return 语句。

### 习题

#### 1.如果递归函数不终止，结果将如何？

程序将不断执行下去。程序不断执行下去也许不是坏事，因为 while(true)和 for(;;)循环也会导致这种后果。然而，**递归函数调用将占用越来越多的栈空间，而栈空间有限，终将耗尽。最终，应用程序将因栈溢出而崩溃**。

## 第八章.指针和引用

### 知识点

#### 1.指针

1）内存单元地址通常使用十六进制表示法。十六进制是一种位权为 16 的幂的数字表示法，即使用 16 个不同的符号（0-9 和 A-F）来表示数字。

2）与大多数变量一样，除非对指针进行初始化，否则它包含的值将是随机的。您不希望访问随机的内存地址，因此将指针初始化为 NULL。NULL 是一个可以检查的值，且不会是内存地址：

```c++
PointedType * PointerVariableName = NULL; // initializing value 
因此，声明 int 指针的代码如下：
int *pointsToInt = NULL; 
```

注意：与您学过的所有数据类型一样，除非对指针进行初始化，否则它包含的将是垃圾值。对指针来说，这种垃圾值非常危险，因为指针包含的值被视为地址。**未初始化的指针可能导致程序访问非法内存单元，进而导致程序崩溃**。

> 赋为 NULL 值的指针被称为**空**指针。
>
> NULL 指针是一个定义在标准库中的值为零的常量。请看下面的程序：
>
> ```c++
> #include <iostream>
> 
> using namespace std;
> 
> int main ()
> {
>    int  *ptr = NULL;
> 
>    cout << "ptr 的值是 " << ptr ;
>  
>    return 0;
> }
> // 输出
> ptr 的值是 0
> ```

C++11中引入关键字nullptr作为空指针，建议都用这个。

```c++
#include <iostream>
using namespace std;

void func(void* t)
{
    cout << "func1" << endl;
}

void func(int i)
{
    cout << "func2" << endl;
}

int main()
{
    func(NULL);
    func(nullptr);
    return 0;
}
// 输出
func2
func1
```

看起来NULL和nullptr都是代表空指针，但是NULL在重载函数的时候却匹配到了参数为int的那个版本。

要区分nullptr和NULL，首先要明白NULL的含义：

NULL是一个宏定义，在c和c++中的定义不同，c中NULL为（void*)0,而c++中NULL为整数0。

```c++
//C语言中NULL定义
#define NULL (void*)0                //c语言中NULL为void类型的指针，但允许将NULL定义为0

//c++中NULL的定义
#ifndef NULL
#ifdef _cpluscplus//用于判定是c++类型还是c类型，详情看上一篇blog
#define NULL 0                         //c++中将NULL定义为整数0
#else
#define NULL ((void*)0)             //c语言中NULL为void类型的指针
#endif
#endif
```

```c++
_cpluscplus是c++中的定义，而c中没有该定义
1.用来判定代码是c类型还是c++类型
2._cplusplus的类型是"long int"，__cpluscplus宏定义C++版本号，比如C++03标准中__cplusplus的值被预定为199711L，在C++11标准中__cplusplus的值被预定为201103L。
    
int main()
{
#ifdef _cplusplus
printf("This is c++ program");
#else
printf("This is c program");
}
```

```c++
#include<iostream>
using namespace std;
int main(){
	cout<<__cplusplus<<endl;
	return 0;
}
```

所以在c++中int *p=NULL; 实际表示将指针P的值赋为0，而c++中当一个指针的值为0时，认为指针为空指针，**不指向任何内存**；

然后理解nullptr:

nullptr是一个字面值常量，类型为std::nullptr_t,空指针常数可以转换为任意类型的指针类型。

那么问题又来了，我们从一开始学习C++的时候就被告诫C++是兼容C的，为什么对于NULL，C++却不完全兼容C呢？通过查找维基百科，才发现这其中的原因。简单地说，C++之所以做出这样的选择，根本原因和C++的函数重载机制有关。

在c++中（void *）不能转换为任意类型的指针，即 int * p=(void*)是错误的，但int *p=nullptr是正确的，原因对于函数重载：若c++中 （void *）支持任意类型隐式转换，函数重载时将出现问题下列代码中fun(NULL)将不能判断调用哪个函数。**如果C++让NULL也支持void *的隐式类型转换，这样编译器就不知道应该调用哪一个函数**。

```c++
void fun(int i){cout<<"1";};
void fun(char *p){cout<<"2";};
int main()
{
fun(NULL);  //输出1，c++中NULL为整数0
fun(nullptr);//输出2，nullptr 为空指针常量。是指针类型
}
```

如果你写char *p = (void *)0；编译时报错：

cannot convert from 'void *' to 'char *'
Conversion from 'void *' to pointer to non-'void' requires an explicit cast（显示类型转换）

#### 2.动态内存分配

您使用 new 来分配新的内存块。通常情况下，如果成功，**new 将返回指向一个指针，指向分配的内存，否则将引发异常**。使用 new 时，需要指定要为哪种数据类型分配内存：

```c++
Type* Pointer = new Type; // request memory for one element 
需要为多个元素分配内存时，还可指定要为多少个元素分配内存：
Type* Pointer = new Type[numElements]; // request memory for numElements 
因此，如果需要给整型分配内存，可使用如下语法：
int* pointToAnInt = new int; // get a pointer to an integer 
int* pointToNums = new int[10]; // pointer to a block of 10 integers
// New返回一个指针，因此将其赋给了一个指针变量
```

**注意**：**new 表示请求分配内存，并不能保证分配请求总能得到满足**，因为这取决于系统的状态以及内存资源的可用性。

**警告**：不能将运算符 delete 用于任何包含地址的指针，而只能用于 new 返回的且未使用 delete释放的指针。

注意：**运算符** new 和 delete 分配和释放自由存储区中的内存。自由存储区是一种内存抽象，表现为一个内存池，应用程序可分配（预留）和释放其中的内存。

**特别注意**：将指针递增或递减的结果

将指针递增或递减时，其包含的地址将增加或减少指向的数据类型的 sizeof（并不一定是 1 字节）。这样，**编译器将确保指针不会指向数据的中间或末尾，而只会指向数据的开头**。

如果声明了如下指针：

Type* pType = Address; 

则执行++pType 后，pType 将包含（指向）Address + sizeof(Type)。

<div style=text-align:center>使用偏移量和运算符来递增和递减指针</div>

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: cout << "How many integers you wish to enter? "; 
 6: int numEntries = 0; 
 7: cin >> numEntries; 
 8: 
 9: int* pointsToInts = new int [numEntries]; 
10: 
11: cout << "Allocated for " << numEntries << " integers" << endl; 
12: for(int counter = 0; counter < numEntries; ++counter) 
13: { 
14: cout << "Enter number "<< counter << ": "; 
15: cin >> *(pointsToInts + counter); 
16: } 
17: 
18: cout << "Displaying all numbers entered: " << endl; 
19: for(int counter = 0; counter < numEntries; ++counter) 
20: 	cout << *(pointsToInts++) << " "; 
21: // 这里不加括号也可以，因为后缀++优先级高于*
22: cout << endl; 
23: 
24: // return pointer to initial position 
25: pointsToInts -= numEntries; 
26: 
27: // done with using memory? release 
28: delete[] pointsToInts; 
29: 
30: return 0; 
31: }
```

这个程序演示了两种递增指针的方法：一是使用偏移量，如第 15 行所示，它使用偏移量变量 counter 将用户输入直接存储到内存单元中；二是使用运算符++，如第 20 行所示，它将指针包含的地址递增，让指针指向下一个元素。**调用 delete[]来释放内存时，必须指定分配内存时 new 返回的指针地址。这个值最初存储在pointsToInts 中**，但第 20 行的运算符++修改了 pointsToInts，因此第 25 行使用运算符-=让 pointsToInts重新指向原来的地址，再在第 28 行对这个地址调用 delete[]。

这里再补充一下前缀++与后缀++的区别：

```c++
int i = 0, n = 0;
int test = ++i;
//此时，test等于1，i也等于1
test = n++;
//此时，test等于0，n等于1
```

因此，要说本质区别就是：前缀加加返回自增后的自己，而后缀加加是返回自增前的值。

所以cout << a++；，输出的值是a自增前的值（a++是先取值后自增）。

```c++
int b = 1;
cout << b++; // 输出1
cout << b++ << b << endl;// 输出1、1
// cout << b << ' ' << b++ << endl; 输出2、1
cout << b;// 输出2
// ++是运算符，但是a++是表达式（表达式是由运算符和操作数组合而成的式子，它产生一个值）
```

> a = 5 和 a = 5; 有什么不一样吗？ 当然不仅仅是多了一个分号而已，这是两个不同的概念，前者是赋值表达式，而后者是赋值语句。
>
> 表达式是由运算符和操作数组合而成的式子，这个式子通过运算最终会得到一个结果，单独的这个结果是无法构成 c++ 的指令的，比如你在代码中写个单独占一行不加分号的 2+3 ，编译就会出错。这个表达式的运算结果必须和其他运算结合起来才有意义，比如用来给变量赋值，或者用来作为 if 或者 while 的条件，所以 a=5; 或者 if(a=5) ....; 就不会有问题，**这种由表达式构成的 c++ 语句我们就称为表达式语句，其典型的特征是结尾的分号**，因为分号是 c++ 语句的结束符。 
>
> 也就是说：**语句是可以单独执行的、能够产生实际效果的代码；而表达式则是包含在语句中，根据某种条件计算出一个值或得出某种结果，然后由语句去判断和处理的代码。**

这里又get到一个知识点：

cout的输出顺序有如下规律：

计算顺序：自右至左

输出顺序：自左至右

2）将指针传递给函数

指针是一种将内存空间传递给函数的有效方式，其中可包含函数完成其工作所需的数据，也可包含操作结果。将指针作为函数参数时，确保函数只能修改您希望它修改的参数很重要。例如，如果函数根据以指针方式传入的半径计算圆的面积，就不应允许它修改半径。为控制函数可修改哪些参数以及不能修改哪些参数，可使用关键字 const。

关于是指针常量还是常量指针，看书写顺序其实很好看出：

```c++
const int * p；// 从左往右读，const int 然后*，即常量指针，指向常量的指针；类似于字符指针，指向字符的指针
int * const p; // 从左往右读，先*后const，即指针常量，指针指向的地址是常量，指针不可修改；类似于字符常量，字符不可修改
```

在计算圆面积的函数中使用关键字 const 

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: void CalcArea(const double* const ptrPi, // const pointer to const data 
 4: const double* const ptrRadius, // i.e. no changes allowed 
 5: double* const ptrArea) // can change data pointed to 
 6: { 
 7: // check pointers for validity before using! 
 8: if (ptrPi && ptrRadius && ptrArea) 
 9: 	*ptrArea = (*ptrPi) * (*ptrRadius) * (*ptrRadius); 
10: } 
11: 
12: int main() 
13: { 
14: const double Pi = 3.1416; 
15: 
16: cout << "Enter radius of circle: "; 
17: double radius = 0; 
18: cin >> radius; 
19: 
20: double area = 0; 
21: CalcArea (&Pi, &radius, &area); 
22: 
23: cout << "Area is = " << area << endl; 
24: 
25: return 0; 
26: }
```

ptrArea 显然是用于存储输出的参数，因为不能修改该指针的值（地址），但可修改它指向的数据。第 8 行在使用函数的指针参数前检查其有效性。在调用者不小心将这三个参数之一设置为 NULL 指针时，您不希望函数计算面积，因为这种非法访问将导致应用程序崩溃。

3）数组和指针的类似之处

数组是指向其第一个元素的指针。

由于数组变量就是指针，因此也可将用于指针的解除引用运算符（*）用于数组。同样，可将数组运算符（[]）用于指针。

换句话说，数组类似于在固定内存范围内发挥作用的指针。可将数组赋给指针，但不能将指针赋给数组，因为数组是静态的，数组名是常量，不能用作左值。

> 再补充一下知识点：
>
> char c[5]={};
>
> 1.数值名`c`是一个地址常量，表示数组首元素的地址
> 2.`&c[0]`也表示数组首元素的地址
> 3.但`&c`表示的是整个数组的首地址。
> 这三者的地址值是相同的，但第3与1、2含义却不一样，1与2不管是地址值还是含义都是一样的。
>
> ![在这里插入图片描述](https://img-blog.csdnimg.cn/20190705210748495.PNG)
>
> ![在这里插入图片描述](https://img-blog.csdnimg.cn/20190705210756408.PNG)
>
> 可以看到，c+1和&c[0]+1是以一个char型大小为单位增加的，而`&c+1`是以整个数组大小为单位增加的。

当您声明下面的 int 数组时：

int myNumbers[5]; 

编译器将分配固定数量的内存，用于存储 5 个整数；同时向您提供一个指向数组中第一个元素的指针，而指针由您指定的数组名标识。换句话说，myNumbers 是一个指针，指向第一个元素（myNumber[0]）。

#### 3.使用指针时常犯的编程错误

1）确保应用程序释放其分配的所有内存是程序员的职责。绝不能让下面这样的情形发生：

```c++
int* pointToNums = new int[5]; // initial allocation 
// use pointToNums 
... 
// forget to release using delete[] pointToNums; 
... 
// make another allocation and overwrite 
pointToNums = new int[10]; // leaks the previously allocated memory
```

2）指针指向无效的内存单元

使用运算符*对指针解除引用，以访问指向的值时，务必确保指针指向了有效的内存单元，否则程序要么崩溃，要么行为不端。这看起来合乎逻辑，但一个非常常见的导致应用程序崩溃的原因就是无效指针。指针无效的原因很多，**但主要归结于糟糕的内存管理**。

下面演示了一种导致指针无效的典型情形。

在存储布尔值的程序中错误地使用指针

```c++
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: // uninitialized pointer (bad) 
 6: bool* isSunny; 
 7: 
 8: cout << "Is it sunny (y/n)? "; 
 9: char userInput = 'y'; 
10: cin >> userInput; 
11: 
12: if (userInput == 'y') 
13: { 
14: isSunny = new bool; 
15: *isSunny = true; 
16: } 
17: 
18: // isSunny contains invalid value if user entered 'n'
19: cout << "Boolean flag sunny says: " << *isSunny << endl; 
20: 
21: // delete being invoked also when new wasn't 
22: delete isSunny; 
23: 
24: return 0; 
25: }
```

```c++
Is it sunny (y/n)? y 
Boolean flag sunny says: 1 
再次运行的输出：
Is it sunny (y/n)? n 
<CRASH!>
```

这个程序的问题很多，有些已通过注释指出了。第 14 行分配内存并将其赋给指针，但这行代码仅在用户按 y（表示 yes）时才会执行。用户提供其他输入时，该 if 块都不会执行，因此指针 isSunny 无效。第二次运行时，用户按 n，导致应用程序崩溃。因为 isSunny **包含无效的内存地址**，而第 19 行对这个无效的指针解除引用，导致应用程序崩溃。

同样，**第 22 行对这个指针调用 delete，但并未使用 new 分配这个指针**，这也是大错特错。如果有指针的多个拷贝，只需对其中一个调用 delete（应避免指针拷贝满天飞）。

要让这个程序更好，更安全，更稳定，应对指针进行初始化，**确定指针有效后再使用并只释放指针一次**（且仅当指针有效时才释放）

指针释放的含义：释放掉的指针变量表示的是该**指针变量指向的内存空间已经不由该程序占用，系统可以将其回收并用做他途**。指针变量指向的内存地址当然是不变的，只是它已经不会再被这个程序使用。当然可以通过new重新分配，但此时指针变量的值（即指针指向的地址）会发生改变。

3）**悬浮指针**（也叫迷途或失控指针）

当指针指向的内存释放了，这时该指针就是迷途的。

**使用 delete 释放后，任何有效指针都将无效。不应再使用。**虽然指针已经无效，但在很多机器上仍然保存着(已经释放了的)动态内存的地址。在delete之后，指针就变成了人们所说的空悬指针，**即指向一块曾经保存数据对象但现在已经无效的内存的指针**。

为避免这种问题，很多程序员在初始化指针或释放指针后将其设置为 NULL，并在使用运算符*对指针解除引用前检查它是否有效（将其与 NULL 比较）。

对前面的代码进行修正

更安全的指针编程

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: cout << "Is it sunny (y/n)? "; 
 6: char userInput = 'y'; 
 7: cin >> userInput; 
 8: 
 9: // declare pointer and initialize 
10: bool* const isSunny = new bool;
11: *isSunny = true; 
12: 
13: if (userInput == 'n') 
14: 	*isSunny = false; 
15: 
16: cout << "Boolean flag sunny says: " << *isSunny << endl; 
17: 
18: // release valid memory 
19: delete isSunny; 
20: 
21: return 0; 
22: }
```

做了细微的修改，使得无论用户如何输入，代码都更安全。注意到在第 10 行声明指针的同时，让它指向了一个有效的内存地址。我们使用了 const 来确保指针指向的数据是可以修改的，但指针的值（包含的地址）是固定的（不可修改）。我们还将指针指向的值初始化为 true，如第 11 行所示。这种数据初始化并不能提高程序的稳定性，但可提高输出的可读性。这些步骤确保不管用户如何输入，这个指针在程序运行期间始终有效，可在第 19 行安全地将其释放。

4）检查使用 new 发出的分配请求是否得到满足

在前面的代码中，我们都假定 new 将返回一个指向内存块的有效指针。事实上，除非请求分配的内存量特大，或系统处于临界状态，可供使用的内存很少，否则 new 一般都能成功。有些应用程序需要请求分配大块的内存（如数据库应用程序），因此最好不要假定内存分配能够成功。C++提供了两种确认指针有效的方法，默认方法是使用异常（这也是前面一直使用的方法），即如果内存分配失败，将引发 std::bad_alloc 异常。这导致应用程序中断执行，除非您提供了异常处理程序，否则应用程序将崩溃，并显示一条类似于“异常未处理”的消息。

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: // remove the try-catch block to see this application crash 
 4: int main() 
 5: {
 6: try 
 7: { 
 8: // Request a LOT of memory! 
 9: int* pointsToManyNums = new int [0x1fffffff]; 
10: // Use the allocated memory 
11: 
12: delete[] pointsToManyNums; 
13: } 
14: catch (bad_alloc) 
15: { 
16: cout << "Memory allocation failed. Ending program" << endl; 
17: } 
18: return 0; 
19: }
```

当内存分配导致程序无法正常执行时，try-catch 异常处理结构让程序能够向用户指出这一点，再正常退出。

不想依赖于异常的程序员可使用 new 变种 **new(nothrow)**，这个变种在内存分配失败时不引发异常，而返回 NULL，让您能够在使用指针前检查其有效性

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: int main() 
 4: { 
 5: // Request LOTS of memory space, use nothrow
 6: int* pointsToManyNums = new(nothrow) int [0x1fffffff]; 
 7: 
 8: if (pointsToManyNums) // check pointsToManyNums != NULL 
 9: { 
10: // Use the allocated memory 
11: delete[] pointsToManyNums; 
12: } 
13: else 
14: cout << "Memory allocation failed. Ending program" << endl; 
15: 
16: return 0; 
17: }
// 输出
Memory allocation failed. Ending program
```

总结：指针编程最佳实践

指针不同于引用，可能为 NULL 或无效，因此使用前必须核实它们是有效的。

**应该** 

务必初始化指针变量，否则它将包含垃圾值。

这些垃圾值被解读为地址，但您的应用程序并未获得访问这些地方的授权。如果不能将指针初始化为new 返回的有效地址，可将其初始化为 NULL。

务必仅在指针有效时才使用它，否则程序可能崩溃。

对于使用 new 分配的内存，一定要记得使用delete 进行释放，否则应用程序将泄露内存，进而降低系统的性能。

**不应该**

使用 delete 释放内存块或指针后，不要访问它。

不要对同一个内存地址调用 delete 多次。

使用完动态分配的内存块后，别忘了对其调用delete，以免泄露内存。

> 补充：将整数直接赋给了指针，这将把指针包含的内存地址改为相应的整数值（16进制形式）

#### 4.引用

引用是变量的别名。声明引用时，需要将其初始化为一个变量，因此引用只是另一种访问相应变量存储的数据的方式。

1）是什么让引用很有用

引用让您能够访问相应变量所在的内存单元，这使得编写函数时引用很有用。第 7 章介绍过，典型的函数声明类似于下面这样：

```c++
ReturnType DoSomething(Type parameter); 

调用函数 DoSomething( )的代码类似于下面这样：

ReturnType Result = DoSomething(argument); // function call 
```

上述代码导致将 argument 的值复制给 Parameter，再被函数 DoSomething( )使用。如果 argument占用了大量内存，这个复制步骤的开销将很大。同样，当 DoSomething( )返回值时，这个值被复制给Result。**如果能避免这些复制步骤，让函数直接使用调用者栈中的数据就太好了**。为此，可使用引用。

可避免复制步骤的函数版本类似于下面这样：

ReturnType DoSomething(Type& parameter); // note the reference& 

调用该函数的代码类似于下面这样：

ReturnType Result = DoSomething(argument); 

2）将关键字const用于引用

可能需要禁止通过引用修改它指向的变量的值，为此可在声明引用时使用关键字 const：

```c++
int original = 30; 
const int& constRef = original; 
constRef = 40; // Not allowed: constRef can’t change value in original 
int& ref2 = constRef; // Not allowed: ref2 is not const
const int& constRef2 = constRef; // OK
```

3）按引用向函数传递参数

让被调用的函数直接使用调用函数栈时，确保被调用函数不能修改调用函数中的变量很重要。为此，可将引用声明为 const，const 引用参数不能用作左值，因此试图给它们赋值将无法通过编译。

```c++
0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: void GetSquare(const int& number, int& result) 
 4: { 
 5: result = number*number; 
 6: } 
 7: 
 8: int main() 
 9: { 
10: cout << "Enter a number you wish to square: "; 
11: int number = 0; 
12: cin >> number; 
13: 
14: int square = 0; 
15: GetSquare(number, square); 
16: cout << number << "^2 = " << square << endl; 
17: 
18: return 0; 
19: }
```

这里使用了两个参数，一个用于接受输入，另一个用于存储运算结果。为禁止修改传入的值，必须使用关键字 const 将其声明为 const 引用，如第 3 行所示。这让 number 自动变为输入参数—其值不能修改的参数。

您可以尝试修改第 5 行，传一个参数的做法那样返回平方值：

number *= number; 

这将导致编译错误，指出 const 值不能修改。**这说明 const 引用将参数标识为输入参数，并禁止对其进行修改**。乍一看，这可能微不足道，但在多名程序员合作编程时，编写第一个版本的人和改进的人可能不同，**通过使用 const 引用可提高编程质量**。

总结：将参数传递给函数时，引用可很好地替代指针，因为引用总是有效的。学习了 const 指针和 const 引用，知道声明函数时应尽可能提高参数的 const 程度。

#### 5.野指针

> 网上查找到的补充一下
>
> 野指针指的是还没有初始化的指针。严格地说，编程语言中每个指针在初始化前都是野指针。
>
> **“野指针”**的成因主要有：
>
> 1）指针变量没有被初始化。任何指针变量刚被创建时不会自动成为NULL指针，它的缺省值是随机的，它会乱指一气。所以，指针变量在创建的同时应当被初始化，要么将指针设置为NULL，要么让它指向合法的内存。
>
> ```c++
> char *p; //此时p为野指针
> ```
>
> 2）指针p被free或者delete之后，没有置为NULL，让人误以为p是个合法的指针.（这个应该叫悬浮指针、迷途指针等，参照上一节）
>
> ```c++
> char *p=new char[10];  //指向堆中分配的内存首地址，p存储在栈区
> cin>> p;
> delete []p; //p重新变为野指针
> ```
>
> 3）指针操作超越了变量的作用范围。（这应该说是一种访问错误，但是指针本身不是定义所说的野指针）     
>
> ```c++
> char *p=new char[10]; //指向堆中分配的内存首地址
> cin>> p;
> cout<<*(p+10); //可能输出未知数据
> ```
>
> **重点**：delete一个指针之后，只是回收指针指向位置的空间（即清空这块内存），**而指针本身的值不变，还是指向原来的单元（所以它不是释放指针本身），但若访问这个单元，结果是无法预料的**。你需要手工将其赋值为NULL，避免无效指针的二次访问。

### 习题

#### 1.我声明了两个指针：

int* pointToAnInt = new int; 

int* pCopy = pointToAnInt; 

为了释放内存，是否需要对它们都调用 delete？

答：这样做是错误的。对 new 返回的地址，只能调用 delete 一次。另外，**最好避免让两个指针指向相同的地址，因为对其中一个调用 delete 将导致另一个无效**。另外，编写程序时，应避免使用有效性不确定的指针。

#### 2.下面是我编写的面积计算函数的两个版本，请问哪个版本更好？

void CalculateArea (const double* const ptrRadius, double* const 

ptrArea); 

void CalculateArea (const double& radius, double& area); 

答：使用引用的版本更好，因为引用不可能无效，而指针可能无效。另外，第二个版本也更简单。

#### 3.我编写了如下代码，我知道，由于 const 声明，我不能使用指针 pointToAnInt 来修改变量 number 的值。我可以将pointToAnInt 赋给一个非 const 指针，再使用该指针来操纵变量 number 的值吗？

int number = 30; 

const int* pointToAnInt = &number; 

答：不能，**您不能修改指针的 const 程度**：

int* pAnother = pointToAnInt; // cannot assign pointer to const to a non-const 

另外，如果编译器允许这样做，将能轻松地突破 const 引用的限制：不能修改它指向的数据。

#### 4.为何要按引用向函数传递值？

答：可以不这样做，只要对程序性能影响不大。然而，如果函数接受非常大的对象，则按值传递的开销将非常大，通过使用引用，**可极大地提高函数调用的效率**。别忘了将 const 用于引用参数，除非函数需要将结果存储在参数中。

#### 5.下面的两个声明有何不同？

int myNumbers[100]; 

int* myArrays[100]; 

答：myNumbers 是一个 int 数组，它指向这样的内存单元的开头，即其中存储了 100 个整数。它是静态的，可替换如下代码：

```c++
int* myNumbers = new int [100]; // dynamically allocated array use myNumbers 

delete[] myNumbers; 
```

而 myArrays 是一个包含 100 个元素的指针数组，其中的每个指针都可指向 int 或 int 数组。

6.查错：下面的代码有何错误？

```c++
#include <iostream> 
using namespace std; 
int main() 
{ 
 int pointToAnInt = new int; 
 int* pNumberCopy = pointToAnInt; 
 *pNumberCopy = 30; 
 cout << *pointToAnInt; 
 delete pNumberCopy; 
 delete pointToAnInt; 
 return 0; 
}
```

1）第一句，"int*"类型的值不能用于初始化"int"类型的实体；

2）第二句，"int"类型的值不能用于初始化"int*"类型的实体；

3）"*"的操作数必须是指针

4）第二个delete不行，释放的必须是对象类型的指针；如果两个指针指向同一个内存区域，不能对该内存地址调用 delete 两次。

> 补充new的用法：
>
> new int;//开辟一个存放整数的存储空间，返回一个指向该存储空间的地址(即指针) 
> new int(100);//开辟一个存放整数的空间，并指定该整数的初值为100，返回一个指向该存储空间的地址 　　
> new char[10];//开辟一个存放字符数组(包括10个元素)的空间，返回首元素的地址 　　
> new int [5] [4];//开辟一个存放二维整型数组(大小为5*4)的空间，返回首元素的地址 　　
> float *p=new float (3.14159);//开辟一个存放单精度数的空间，并指定该实数的初值为3.14159，将返回的该空间的地址赋给指针变量p 　　
> new运算符使用的一般格式为：new 类型(初值)。**用new分配数组空间时不能指定初值**。

## 第九章.类和对象

### 知识点

**三种关键字出现的次数和先后次序都没有限制。成员变量的可访问范围由离它前面最近的那个访问范围说明符决定。**

1）封装指的是将数据以及使用它们的函数进行逻辑编组，这是面向对象编程的重要特征。

2）类相当于蓝图（ 一个详细的、各部分完全协调的计划或行动规划。），仅声明类并不会对程序的执行产生影响。在程序执行阶段，对象是类的化身。要使用类的功能，通常需要创建其实例—对象，并通过对象访问成员方法和属性。

3）就像可以为其他类型（如 int）动态分配内存一样，也可使用 new 为 Human 对象动态地分配内存：

```c++
int* pointsToNum = new int; // an integer allocated dynamically 

delete pointsToNum; // de-allocating memory when done using 

Human* firstWoman = new Human(); // dynamically allocated Human 
// 注意后面有个括号
delete firstWoman; // de-allocating memory 
```

4）实例化对象时，我们声明一个类型为相应类的变量。因此，对于对象名，我们采用前面一直用于变量名的骆驼拼写法，如 firstMan。

5）如果对象是使用 new 在自由存储区中实例化的，或者有指向对象的指针，则可使用指针运算符（->）来访问成员属性和方法。->由一个连字符和大于号组成，也称**箭头成员运算符**，**创建动态结构（或类）时，不能将成员运算符句点用于结构名，因为这种结构（或类）没有名称**，只是知道它的地址。为此，c++专门为这种情况提供了这么一个运算符。

6）构造函数可在类声明中实现，也可在类声明外实现。在类声明中实现（定义）构造函数的代码类似于下面这样：

```c++
class Human 
{ 
public: 
 Human() 
 { 
 // constructor code here 
 }
 };
```

```c++
class Human 
{ 
public: 
 Human(); // constructor declaration 
}; 
// constructor implementation (definition) 
Human::Human() 
{ 
 // constructor code here 
}
```

::被称为作用域（名）解析运算符。例如，Human::dateOfBirth 指的是在 Human 类中声明的变量 dateOfBirth，而::dateOfBirth 表示全局作用域中的变量 dateOfBirth。

7）**默认构造函数是调用时可不提供参数的构造函数，而并不一定是不接受任何参数的构造函数**。因此，下面的构造函数虽然有两个参数，但它们都有默认值，因此也是默认构造函数：

```c++
class Human 
{ 
private: 
 string name; 
 int age; 
public: 
 // default values for both parameters 
 Human(string humansName = "Adam", int humansAge 
= 25) 
 {
 name = humansName; 
 age = humansAge; 
 cout << "Overloaded constructor creates "; 
 cout << name << " of age " << age; 
 } 
};
因为实例化 Human 对象时仍可不提供任何参数：
Human adam; // Human takes default name "Adam", 
age 25
```

> 补充：
>
> 在一个类中定义了全部是默认参数的构造函数后，不能再定义重载构造函数。例：
>
> ```c++
> Box(int =10,int =10,int =10);        1
> 
> Box();                               2
> 
> Box(int,int);                        3
> ```
>
> 若有以下定义语句：
>
> Box box1;                 //是调用上面的第一个默认参数的构造函数，还是第二个默认构造函数
>
> Box box2(15,30);          //是调用上面的第一个默认参数的构造函数，还是第三个构造函数
>
> 调用时就产生了歧义，不知道调用哪个。
>
> 系统提供的默认构造函数无参数代码为空，不做任何初始化工作。

8）初始化列表由包含在括号中的**参数声明后面的冒号标识**，**冒号后面列出了各个成员变量及其初始值**。初始值可以是参数（如 humansName），**也可以是固定的值**。使用特定参数调用基类的构造函数时，初始化列表也很有用，这将在第 10 章讨论。

下面的程序中，Human 类包含一个带初始化列表的默认构造函数，该默认构造函数的参数都有默认值

```c++
0: #include <iostream> 
 1: #include <string> 
 2: using namespace std; 
 3: 
 4: class Human 
 5: { 
 6: private: 
 7: int age; 
 8: string name; 
 9:
 10: public: 
11: Human(string humansName = "Adam", int humansAge = 25) 
12: :name(humansName), age(humansAge) 
13: { 
14: cout << "Constructed a human called " << name; 
15: cout << ", " << age << " years old" << endl; 
16: } 
17: }; 
18: 
19: int main() 
20: { 
21: Human adam; 
22: Human eve("Eve", 18); 
23: 
24: return 0; 
25: }
```

注意：也可使用关键字 constexpr 将构造函数定义为常量表达式。在有助于提高性能的情况下，可在构造函数的声明中使用这个关键字，如下所示：

```c++
class Sample 
{ 
const char* someString; 
public: 
 constexpr Sample(const char* input) 
 :someString(input) 
 { // constructor code } 
}; 
```

#### 9）析构函数

每当对象不再在作用域内或通过 delete 被删除进而被销毁时，都将调用析构函数。这使得析构函数成为重置变量以及释放动态分配的内存和其他资源的理想场所。

使用 char*缓冲区时，您必须自己管理内存分配和释放，因此本书建议不要使用它们，而使用std::string。std::string 等工具都是类，它们充分利用了构造函数和析构函数，还有将在第 12 章介绍的运算符，让您无需考虑分配和释放等内存管理工作。

接下来的程序所示的类 MyString 在构造函数中为一个字符串分配内存，并在析构函数中释放它。

一个简单的类，它封装了字符缓冲区并通过析构函数释放它

```c++
 0: #include <iostream> 
 1: #include <string.h> 
 2: using namespace std; 
 3: class MyString 
 4: { 
 5: private: 
 6: char* buffer;
  7: 
 8: public: 
 9: MyString(const char* initString) // constructor 
10: { 
11: if(initString != NULL) 
12: { 
13: buffer = new char [strlen(initString) + 1]; 
14: strcpy(buffer, initString); 
15: } 
16: else 
17: 	buffer = NULL; 
18: } 
19: 
20: ~MyString() 
21: { 
22: cout << "Invoking destructor, clearing up" << endl; 
23: if (buffer != NULL) 
24: 	delete [] buffer; 
25: } 
26: 
27: int GetLength() 
28: { 
29: return strlen(buffer); 
30: } 
31: 
32: const char* GetString() 
33: { 
34: return buffer; 
35: } 
36: }; 
37: 
38: int main() 
39: { 
40: MyString sayHello("Hello from String Class"); 
41: cout << "String buffer in sayHello is " << sayHello.GetLength(); 
42: cout << " characters long" << endl; 
43: 
44: cout << "Buffer contains: " << sayHello.GetString() << endl; 
45: }
```

```c++
// 输出
String buffer in sayHello is 23 characters long 
Buffer contains: Hello from String Class 
Invoking destructor, clearing up
```

这个类封装了一个 C 风格字符串（MyString::buffer），让您使用字符串时无需分配和释放内存。

注意到在 main( )中，程序员无需调用 new 和 delete。MyString 类不仅对程序员隐藏了内存管理实现，还正确地释放了分配的内存。**main( )执行完毕时，将自动调用析构函数～MyString( )，输出证明了这一点—其中包含析构函数中 cout 语句的输出**。

类更好地处理了字符串，这是析构函数的众多用途之一。在更智能地使用指针方面，析构函数也扮演了重要角色，第 26 章将演示这一点。

**注意**：析构函数不能重载，每个类都只能有一个析构函数。如果您忘记了实现析构函数，编译器将创建一个伪（dummy）析构函数并调用它。伪析构函数为空，即不释放动态分配的内存。

#### 10）复制构造函数

```c++
54: void UseMyString(MyString str) 
55: { 
56: cout << "String buffer in MyString is " << str.GetLength(); 
57: cout << " characters long" << endl; 
58: 
59: cout << "buffer contains: " << str.GetString() << endl; 
60: return; 
61: }
```

```c++
复制构造函数确保下面的函数调用进行深复制：

MyString sayHello("Hello from String Class"); 

UseMyString(sayHello); 

然而，如果您通过赋值进行复制时，结果如何呢？

MyString overwrite("who cares? "); 

overwrite = sayHello; 
```

由于您没有提供复制赋值运算符 operator=，编译器提供的默认复制赋值运算符将导致浅复制。

复制赋值运算符将在第 12 章深入讨论。程序清单 12.8 是改进后的 MyString，它实现了复制赋值运算符：

```c++
MyString::operator= (const MyString& copySource) 
{ 
 //... copy assignment operator code 
} 
```

注意：通过在复制构造函数声明中使用 const，可确保复制构造函数不会修改指向的源对象。另外，复制构造函数的参数必须按引用传递，否则复制构造函数将不断调用自己，直到耗尽系统的内存为止。

**终于理解为啥不能直接传对象了**：将对象sayHello传给函数形参的时候，这个时候要调用拷贝构造函数去构造String str这个对象，这个时候如果拷贝构造函数里的参数是对象而不是引用，调用这个构造函数的时候sayHello又要传给拷贝构造函数的形参，这样又得调用拷贝构造函数，这样就会形成无限调用，直到内存耗尽；如果传的是引用，引用是别名，不产生拷贝动作。

注意事项：

- 类包含原始指针成员（char *等）时，务必编写复制构造函数和复制赋值运算符。

- 编写复制构造函数时，务必将接受源对象的参数声明为 const 引用。

- 声明构造函数时务必考虑使用关键字 explicit，以避免隐式转换。

- 务必将类成员声明为 std::string 和智能指针类（而不是原始指针），因为它们实现了复制构造函数，可减少您的工作量。
- 除非万不得已，不要类成员声明为原始指针。

MyString类包含原始指针成员char* buffer，这里使用它旨在阐述为何需要复制构造函数。如果您编写类时需要包含字符串成员，用于存储姓名等，应使用 std::string 而不是 char*。**在没有使用原始指针的情况下，您都不需要编写复制构造函数。这是因为编译器添加的默认复制构造函数将调用成员对象（如 std::string）的复制构造函数**。

#### 11）不允许复制的类：

```c++
假设您需要模拟国家的政体。一个国家只能有一位总统，而 President 类面临如下风险：
President ourPresident; 
DoSomething(ourPresident); // duplicate created in passing by value 
President clone; 
clone = ourPresident; // duplicate via assignment
```

要禁止类对象被复制，可声明一个私有的复制构造函数。这确保函数调用DoSomething(OurPresident)无法通过编译。为禁止赋值，可声明一个私有的赋值运算符。

无需给私有复制构造函数和私有赋值运算符提供实现，只需将它们声明为私有的就足以实现您的目标：确保 President 的对象是不可复制的。

#### 12）只能有一个实例的单例类（单子模式）

```c++
//前面讨论的 President 类很不错，但存在一个缺陷：无法禁止通过实例化多个对象来创建多名总统：
President One, Two, Three;
```

它使用私有构造函数、私有赋值运算符和静态实例成员。要创建单例类，关键字 static 必不可少。

单例类 President，它禁止复制、赋值以及创建多个实例

```c++
 0: #include <iostream>
 1: #include <string> 
 2: using namespace std; 
 3: 
 4: class President 
 5: { 
 6: private: 
 7: President() {}; // private default constructor 
 8: President(const President&); // private copy constructor 
 9: const President& operator=(const President&); // assignment operator 
10: 
11: string name; 
12: 
13: public: 
14: static President& GetInstance() 
15: { 
16: // static objects are constructed only once 
17: static President onlyInstance; 
18: return onlyInstance; 
19: } 
20: 
21: string GetName() 
22: { return name; } 
23: 
24: void SetName(string InputName) 
25: { name = InputName; } 
26: }; 
27: 
28: int main() 
29: { 
30: President& onlyPresident = President::GetInstance(); 
31: onlyPresident.SetName("Abraham Lincoln"); 
32: 
33: // uncomment lines to see how compile failures prohibit duplicates 
34: // President second; // cannot access constructor 
35: // President* third= new President(); // cannot access constructor 
36: // President fourth = onlyPresident; // cannot access copy constructor 
37: // onlyPresident = President::GetInstance(); // cannot access operator= 
38: 
39: cout << "The name of the President is: "; 
40: cout << President::GetInstance().GetName() << endl; 
41: 
42: return 0; 
43: }
```

注解：这里使用了C++11里提供的静态初始化器，即构造静态对象

```c++
Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}
```

它使用静态变量 onlyInstance 确保有且只有一个 President 实例。

为更好地理解这一点，可以认为第 17 行只执行一次（静态初始化），因此 GetInstance( )返回唯一一个President 实例，而不管您如何频繁地调用 President:: GetInstance( )。

#### 13）禁止在栈中实例化的类

栈空间通常有限。如果您要编写一个数据库类，其内部结构包含数 TB 数据，**可能应该禁止在栈上实例化它，而只允许在自由存储区中创建其实例**。为此，关键在于将析构函数声明为私有的：

```c++
class MonsterDB 
{ 
private: 
 ~MonsterDB(); // private destructor 
 //... members that consume a huge amount of data 
}; 
通过声明私有的析构函数，可禁止像下面这样创建实例：
int main() 
{ 
 MonsterDB myDatabase; // compile error 
 // … more code 
 return 0; 
}
```

上述代码试图在栈上创建实例。退栈时，将弹出栈中的所有对象，因此编译器需要在 main( )末尾调用析构函数～MonsterDB()，但这个析构函数是私有的，即不可用，因此上述语句将导致编译错误。

将析构函数声明为私有的并不能禁止在堆中实例化：

```c++
int main() 
{ 
 MonsterDB* myDatabase = new MonsterDB(); // no error 
 // … more code 
 return 0; 
}
```

上述代码将导致内存泄露。由于在 main 中不能调用析构函数，因此也不能调用 delete。为了解决这种问题，需要在 MonsterDB 类中提供一个销毁实例的静态公有函数（作为类成员，它能够调用析构函数），如下程序所示。

数据库类 MonsterDB，只能使用 new 在自由存储区中创建其对象

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: class MonsterDB 
 4: { 
 5: private: 
 6: ~MonsterDB() {}; // private destructor prevents instances on stack 
 7: 
 8: public: 
 9: static void DestroyInstance(MonsterDB* pInstance) 
10: { 
11: delete pInstance; // member can invoke private destructor 
12: } 
13: 
14: void DoSomething() {} // sample empty member method 
15: }; 
16: 
17: int main() 
18: { 
19: MonsterDB* myDB = new MonsterDB(); // on heap 
20: myDB->DoSomething(); 
21: 
22: // uncomment next line to see compile failure 
23: // delete myDB; // private destructor cannot be invoked 
24: 
25: // use static member to release memory 
26: MonsterDB::DestroyInstance(myDB); 
27: 
28: return 0; 
29: }
```

14）使用构造函数进行类型转换

前面介绍过，可给类提供重载的构造函数，**即接受一个或多个参数的构造函数。这种构造函数常用于进行类型转换**（貌似都是单参数的，没见过多参数的形式）。请看下面的 Human 类，它包含一个将整数作为参数的重构构造函数：

```c++
class Human 
{ 
 int age; 
public: 
 Human(int humansAge): age(humansAge) {} 
}; 
// Function that takes a Human as a parameter 
void DoSomething(Human person) 
{ 
 cout << "Human sent did something" << endl; 
 return; 
}
```

这个构造函数让您能够执行下面的转换：

```c++
Human kid(10); // convert integer in to a Human 

DoSomething(kid); 
```

这样的转换构造函数让您能够执行隐式转换：

```c++
Human anotherKid = 11; // int converted to Human 

DoSomething(10); // 10 converted to Human! 
```

函数 DoSothing(Human person)被声明为接受一个 Human（而不是 int）参数！前面的代码为何可行呢？这是因为编译器知道 Human 类包含一个将整数作为参数的构造函数，进而替您执行了隐式转换：将您提供的整数作为参数发送给这个构造函数，从而创建一个Human 对象。

为避免隐式转换，可在声明构造函数时使用关键字 explicit：

```c++
class Human 
{ 
 int age; 
public: 
 explicit Human(int humansAge): age(humansAge) {} 
}; 
```

并非必须使用关键字 explicit，但在很多情况下，这都是一种良好的编程实践。

注意：运算符也存在隐式转换的问题，也可在运算符中使用关键字 explicit 来禁止隐式转换。编写第 12 章将介绍的运算符时，请注意使用关键字 explicit。

15）this指针。调用静态方法时，不会隐式地传递 this 指针，因为静态函数不与类实例相关联，而由所有实例共享。要在静态函数中使用实例变量，应显式地声明一个形参，并将实参设置为 this 指针。

16）将 sizeof( )用于类及其对象时，结果相同。**类占用的字节数在编译阶段就已确定**。用于类时，sizeof( )不考虑成员函数及其定义的局部变量。

#### 17）共用体

共用体是一种特殊的类，每次只有一个非静态数据成员处于活动状态。因此，共用体与类一样，可包含多个数据成员，但不同的是只能使用其中的一个。

声明共用体：

要声明共用体，可使用关键字 union，再在这个关键字后面指定共用体名称，然后在大括号内指定其数据成员：

```c++
union UnionName 
{ 
 Type1 member1; 
 Type2 member2; 
…
 TypeN memberN; 
};
```

要实例化并使用共用体，可像下面这样做：

```c++
UnionName unionObject; 

unionObject.member2 = value; // choose member2 as the active member 
```

注意：与结构类似，**共用体的成员默认也是公有的，但不同的是，共用体不能继承**。另外，将 sizeof()用于共用体时，结果总是为共用体最大成员的长度，即便该成员并不处于活动状态。

## 第十章.继承

### 知识点

#### 1）protected

将属性声明为 protected时，相当于允许派生类和友元类访问它，但禁止在继承层次结构外部（包括 main( )）访问它。

类成员的访问权限由高到低依次为 public --> protected --> private。再来补充一下 protected。**protected 成员和 private 成员类似，也不能通过对象访问**。但是当存在继承关系时，protected 和 private 就不一样了：基类中的 protected 成员可以在派生类中使用，而基类中的 private 成员不能在派生类中使用，下面是详细讲解。

- 继承方式中的 public、protected、private 是用来指明基类成员在派生类中的最高访问权限的。

- 如果希望基类的成员能够被派生类继承并且毫无障碍地使用，那么这些成员只能声明为 public 或 protected；**只有那些不希望在派生类中使用的成员才声明为 private**。

- 如果希望基类的成员既不向外暴露（不能通过对象访问），还能在派生类中使用，那么只能声明为 protected。

**注意**：我们这里说的是基类的 private 成员不能在派生类中使用，并没有说基类的 private 成员不能被继承。**实际上，基类的 private 成员是能够被继承的，并且（成员变量）会占用派生类对象的内存，它只是在派生类中不可见，导致无法使用罢了**。private 成员的这种特性，能够很好的对派生类隐藏基类的实现，以体现面向对象的封装性。

由于 private 和 protected 继承方式会改变基类成员在派生类中的访问权限，导致继承关系复杂，所以实际开发中我们一般使用 public。

#### 2）基类初始化——向基类传递参数

如果基类包含重载的构造函数，需要在实例化时给它提供实参，该如何办呢？创建派生对象时将如何实例化这样的基类？**方法是使用初始化列表**，并**通过派生类的构造函数调用合适的基类构造函数**，如下面的代码所示：

```c++
class Base 
{ 
public: 
 Base(int someNumber) // overloaded constructor 
 { 
 // Use someNumber 
 } 
}; 
Class Derived: public Base 
{
public: 
 Derived(): Base(25) // instantiate Base with argument 25 
 { 
 // derived class constructor code 
 } 
};
```

> 补充：关于子类是否继承父类的构造函数
>
> **百度知道**：在C++中，构造函数不会自动继承，只是如果子类没有写构造函数，那么系统会这个类自动添加一个默认构造函数，是一个空函数体，所以什么也没有做，接着就会调用父类的构造函数，所以你觉得是继承了父类的构造函数。
>
> 子类和父类的构造函数的调用顺序:
>
> ```c++
> class B:public A
> B b1;
> ```
>
> 　　那么构造函数的调用顺序是:A(),B()
>
> 　　如果不想调用基类的构造函数，那么就应该在子类中写一个构造函数。
>
> **C语言中文网**：基类的成员函数可以被继承，可以通过派生类的对象访问，但这仅仅指的是普通的成员函数，类的构造函数不能被继承。构造函数不能被继承是有道理的，**因为即使继承了，它的名字和派生类的名字也不一样，不能成为派生类的构造函数，当然更不能成为普通的成员函数**。
>
> 在设计派生类时，对继承过来的成员变量的初始化工作也要由派生类的构造函数完成，但是大部分基类都有 private 属性的成员变量，它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。
>
> 这种矛盾在[C++](http://c.biancheng.net/cplus/)继承中是普遍存在的，解决这个问题的思路是：**在派生类的构造函数中调用基类的构造函数**。

#### 3）调用基类中被覆盖的方法

派生类 Tuna 通过实现 Swim( )覆盖了 Fish 类的 Swim( )函数，其结果如下：

```c++
Tuna myDinner; 

myDinner.Swim(); // will invoke Tuna::Swim() 
```

如果要在 main( )中调用 Fish::Swim( )，需要使用作用域解析运算符（::），如下所示：

```c++
myDinner.Fish::Swim(); // invokes Fish::Swim() using instance of Tuna 
```

#### 4）在派生类中调用隐藏的基类方法

覆盖的一种极端情形是，Tuna::Swim( )可能隐藏 Fish::Swim( )的所有重载版本，使得调用这些重载版本会导致编译错误（因此称为被隐藏）。

Tuna::Swim( )隐藏了重载方法 Fish::Swim(bool) 

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: class Fish 
 4: { 
 5: public: 
 6: void Swim() 
 7: { 
 8: cout << "Fish swims... !" << endl; 
 9: } 
10: 
11: void Swim(bool isFreshWaterFish) // overloaded version
12: { 
13: if (isFreshWaterFish) 
14: 	cout << "Swims in lake" << endl; 
15: else 
16: 	cout << "Swims in sea" << endl; 
17: } 
18: }; 
19: 
20: class Tuna: public Fish 
21: { 
22: public: 
23: void Swim() 
24: { 
25: cout << "Tuna swims real fast" << endl; 
26: } 
27: }; 
28: 
29: int main() 
30: { 
31: Tuna myDinner; 
32: 
33: cout << "About my food" << endl; 
34: 
35: // myDinner.Swim(false);//failure: Tuna::Swim() hides Fish::Swim(bool) 
36: myDinner.Swim(); 
37: 
38: return 0; 
39: }
```

解决方案1：在 main( )中使用作用域解析运算符（::）

```c++
myDinner.Fish::Swim(false);
```

解决方案 2：在 Tuna 类中，使用关键字 using 解除对 Fish::Swim( )的隐藏

```c++
class Tuna: public Fish 
{ 
public: 
 using Fish::Swim; // unhide all Swim() methods in class Fish
 void Swim() 
 { 
 cout << "Tuna swims real fast" << endl; 
 } 
};
// 这样就可以直接调用myDinner.Swim(false);但是myDinner.Swim();还是调用派生类的函数，调用基类依然得用::。
```

解决方案 3：在 Tuna 类中，覆盖 Fish::Swim( )的所有重载版本（如果需要，可通过 Tuna::Fish(…)调用方法 Fish::Swim( )）

```c++
class Tuna: public Fish 
{ 
public: 
 void Swim(bool isFreshWaterFish) 
 { 
 Fish::Swim(isFreshWaterFish); 
 } 
 void Swim() 
 { 
 cout << "Tuna swims real fast" << endl; 
 } 
};
```

#### 5）构造顺序

如果 Tuna 类是从 Fish 类派生而来的，创建 Tuna 对象时，先调用 Tuna 的构造函数还是 Fish 的构造函数？另外，实例化对象时，成员属性（如 Fish::isFreshWaterFish）是调用构造函数之前还是之后实例化？好在实例化顺序已标准化，基类对象在派生类对象之前被实例化。

因此，首先构造 Tuna 对象的Fish 部分，这样实例化 Tuna 部分时，成员属性（具体地说是 Fish 的保护和公有属性）已准备就绪，可以使用了。实例化 Fish 部分和 Tuna 部分时，**先实例化成员属性**（如Fish::isFreshWaterFish），**再调用构造函数，确保成员属性准备就绪，可供构造函数使用**。这也适用于 Tuna::Tuna( )。

注意：如果继承的Fish里的成员是个类对象，**就先调用这个成员类的构造函数，再调用Fish的构造函数，最后才是调用自身的构造函数**。

析构顺序与构造顺序刚好相反！

#### 6）改变访问权限：

使用 using 关键字可以**改变基类成员在派生类中的访问权限**，例如将 public 改为 private、将 protected 改为 public。

注意：**using 只能改变基类中 public 和 protected 成员的访问权限，不能改变 private 成员的访问权限，因为基类中 private 成员在派生类中是不可见的，根本不能使用，所以基类中的 private 成员在派生类中无论如何都不能访问**。

```c++
//基类People
class People {
public:
    void show();
protected:
    char *m_name;
    int m_age;
};
void People::show() {
    cout << m_name << "的年龄是" << m_age << endl;
}
//派生类Student
class Student : public People {
public:
    void learning();
public:
    using People::m_name;  //将protected改为public
    using People::m_age;  //将protected改为public
    float m_score;
private:
    using People::show;  //将public改为private
};
void Student::learning() {
    cout << "我是" << m_name << "，今年" << m_age << "岁，这次考了" << m_score << "分！" << endl;
}
```

using前面也提到了，它还有一个很重要的作用就是为了避免隐藏基类的方法。

#### 7）关于private

仅当必要时才使用私有或保护继承。

对于大多数使用私有继承的情形（如 Car 和 Motor 之间的私有继承），更好的选择是，将基类对象作为派生类的一个成员属性。

将 Motor 对象作为 Car 类的私有成员被称为**组合（composition）或聚合**（aggergation），

这样的 Car 类类似于下面这样：

```c++
class Car 
{ 
private: 
 Motor heartOfCar; 
public: 
 void Move() 
 { 
 heartOfCar.SwitchIgnition(); 
 heartOfCar.PumpFuel(); 
 heartOfCar.FireCylinders(); 
 } 
}; 
```

这是一种不错的设计，让您能够轻松地在 Car 类中添加 Motor 成员，而无需改变继承层次机构，也不用修改客户看到的设计。

#### 8）切除问题

如果程序员像下面这样做，结果将如何呢？

```c++
Derived objDerived; 
Base objectBase = objDerived; 

如果程序员像下面这样做，结果又将如何呢？

void UseBase(Base input); 
... 
Derived objDerived; 
UseBase(objDerived); // copy of objDerived will be sliced and sent 
```

它们都将 Derived 对象复制给 Base 对象，一个是通过显式地复制，另一个是通过传递参数。在这些情形下，编译器将只复制 objDerived 的 Base 部分，即不是整个对象。换句话说，Derived 的数据成员包含的信息将丢失。这种无意间裁减数据，导致 Derived 变成 Base 的行为称为切除（slicing）。

要避免切除问题，不要按值传递参数，而应以指向基类的指针或 const 引用的方式传递。

#### 9）使用final禁止继承

从 C++11 起，编译器支持限定符 final。被声明为 final 的类不能用作基类。比如Platypus 类表示一种进化得很好的物种，因此您可能想将其声明为 final 的，从而禁止继承它。

```c++
class Platypus final: public Mammal, public Bird, public Reptile 
{ 
public: 
 void Swim() 
 { 
 cout << "Platypus: Voila, I can swim!" << endl; 
 } 
};
```

除用于类外，还可将 final 用于成员函数来控制多态行为。

**特别注意**：鸭嘴兽会游泳，但不属于鱼类。因此，在程序清单 10.10 中，没有仅为方便重用现有的Fish::Swim( )函数，而让 Platypus 也继承 Fish。**做设计决策时，别忘了公有继承应表示 is-a关系，因此不应为实现重用目标而不分青红皂白地使用公有继承**。可采取其他方式实现这种目标。

几点需要注意的：

要建立 is-a 关系，务必创建公有继承层次结构。

要建立 has-a 关系，务必创建私有或保护继承层次结构。

不要不分青红皂白地使用私有或公有继承，**因为这可能给应用程序的可扩展性带来架构瓶颈**。

在派生类中，不要编写与基类方法同名但参数不同的方法，以免隐藏基类方法。

9）如果继承时不写访问控制符，类的继承关系默认为私有。如果 Derived 是结构，继承关系将为公有。

## 第十一章.多态

### 知识点

#### 1）在函数中通过基类指针调用运算符 delete的问题 

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: class Fish 
 4: { 
 5: public: 
 6: Fish() 
 7: { 
 8: cout << "Constructed Fish" << endl; 
 9: } 
10: ~Fish() 
11: { 
12: cout << "Destroyed Fish" << endl; 
13: } 
14: }; 
15: 
16: class Tuna:public Fish 
17: { 
18: public: 
19: Tuna() 
20: { 
21: cout << "Constructed Tuna" << endl; 
22: } 
23: ~Tuna() 
24: { 
25: cout << "Destroyed Tuna" << endl; 
26: } 
27: }; 
28: 
29: void DeleteFishMemory(Fish* pFish) 
30: { 
31: delete pFish; 
32: } 
33: 
34: int main() 
35: { 
36: cout << "Allocating a Tuna on the free store:" << endl; 
37: Tuna* pTuna = new Tuna; 
38: cout << "Deleting the Tuna: " << endl; 
39: DeleteFishMemory(pTuna); 
40: 
41: cout << "Instantiating a Tuna on the stack:" << endl; 
42: Tuna myDinner; 
43: cout << "Automatic destruction as it goes out of scope: " << endl; 
44: 
45: return 0; 
46: }
```

```c++
// 输出
Allocating a Tuna on the free store: 
Constructed Fish 
Constructed Tuna 
//Deleting the Tuna: 
//Destroyed Fish 
Instantiating a Tuna on the stack: 
Constructed Fish 
Constructed Tuna 
Automatic destruction as it goes out of scope: 
Destroyed Tuna 
Destroyed Fish
```

注意到由于使用了关键字 new，在自由存储区中构造了 Tuna和 Fish，但 delete 没有调用 Tuna 的析构函数，而只调用了 Fish 的析构函数；而构造和析构局部变量myDinner 时，调用了基类和派生类的构造函数和析构函数，这形成了鲜明的对比。

对于使用 new 在自由存储区中实例化的派生类对象，**如果将其赋给基类指针，并通过该指针调用 delete，将不会调用派生类的析构函数。这可能导致资源未释放、内存泄露等问题，必须引起重视**。

要避免这种问题，可将析构函数声明为虚函数。

> 所以析构函数的多态实现是这样的：当一个基类的析构函数声明为虚析构函数,其派生类的析构函数也自动被系统默认为虚函数，**当Delete一个指向派生类对像的基类指针时**，系统会**先调用该派生类对象的析构函数**，而后**再调用指针本身的基类析构函数**。也就是两个类的析构函数都会被调用。

#### 2）抽象基类和纯虚函数

**不能实例化的基类被称为抽象基类**，这样的基类只有一个用途，那就是从它派生出其他类。在 C++中，要创建抽象基类，可声明纯虚函数。

> c++primer5:含有（或者未经覆盖直接继承）纯虚函数的类是抽象基类。
>
> 所以可以这样说：**只要类至少包含一个纯虚函数**，它就是抽象基类，而**不管它是否包含其他定义完整的函数和属性**。

编译器不允许您创建抽象基类（ABC）Fish 的实例。编译器要求您创建具体类（如 Tuna）的对象，这与现实世界一致（现实世界没有fish这个具体的东西，只有它的实例，fish是我们人为抽象出来的）。虽然不能实例化抽象基类，但是可将指针或引用的类型指定为抽象基类。

抽象基类提供了一种非常好的机制，让您能够声明所有派生类都必须实现的函数（即指定派生类的接口）。如果 Trout 类从Fish 类派生而来，但没有实现 Trout::Swim( )，将无法通过编译。抽象基类要求派生类必须提供虚方法 DoSomething( )的实现。

#### 3）虚函数表指针

编译器见到这种继承层次结构后，知道 Base 定义了一些虚函数，并在 Derived 中覆盖了它们。在这种情况下，编译器将为实现了虚函数的基类和覆盖了虚函数的派生类分别创建一个虚函数表（Virtual Function Table，VFT）。换句话说，Base 和 Derived 类都将有自己的虚函数表。实例化这些类的对象时，将创建一个隐藏的指针（我们称之为 VFT*），它指向相应的 VFT。可将 VFT 视为一个包含函数指针的静态数组，其中每个指针都指向相应的虚函数。

当派生类对象objDerived 传递给了基类对象 objBase，进而被解读为一个 Base 实例，但该实例的VFT 指针仍指向 Derived 类的虚函数表，因此通过该 VTF 执行的是 Derived::Func( )。

对两个相同的类（一个包含虚函数，另一个不包含）进行比较，证明确实存在隐藏的虚函数表指针

```c++
 #include <iostream>
 using namespace std;

 class Base
 {
	 int a, b;
 public:
	 virtual void DoSomething() {}
	 virtual void Doanother() {}
 };
 class SimpleClass:public Base
 {
 int a, b;
 public:
 void DoSomething() {}
 void Doanother() {}
 };
 
 int main()
 {
 cout << "sizeof(SimpleClass) = " << sizeof(SimpleClass) << endl;
 cout << "sizeof(Base) = " << sizeof(Base) << endl;

 return 0;
 }
// 不写继承时，输出8、12，即写了虚函数的类多了一个虚函数表指针，不管写了多少个虚函数，只有一个虚函数表指针，指向表头，至于怎么操纵的其它的虚函数，我猜测是和操纵数组的形式一样，有表头指针了后面的都很好操作。
//写继承时，输出20、12，就是继承的基类的内存加自身所以一共20字节。
```

注意：C++关键字 virtual 的含义随上下文而异（我想这样做的目的很可能是为了省事），对其含义总结如下：

<font color="00aaee">①在函数声明中，virtual 意味着当基类指针指向派生对象时，通过它可调用派生类的**相应函数**。</font>

②从 Base 类派生出 Derived1 和 Derived2 类时，如果使用了关键字 virtual，则意味着再从Derived1 和 Derived2 派生出 Derived3 时，每个 Derived3 实例只包含一个 Base的副本。

也就是说，关键字 virtual 被用于实现两个不同的概念。

#### 4）表明覆盖意图的限定符override

```c++
前面的基类 Fish 都包含虚函数 Swim()，如下面的代码所示：
class Fish 
{ 
public: 
 virtual void Swim() 
 { 
 cout << "Fish swims!" << endl; 
 } 
};
```

```c++
假设派生类 Tuna 要定义函数 Swim()，但特征标稍微不同—程序员原本想覆盖 Fish::Swim()，
但不小心插入了关键字 const，如下所示：
class Tuna:public Fish 
{ 
public: 
 void Swim() const 
 { 
 cout << "Tuna swims!" << endl; 
 } 
};
```

在这种情况下，函数 Tuna::Swim()实际上并不会覆盖 Fish::Swim()，这是因为 Tuna::Swim()包含const，导致它们的特征标不同。然而，这些代码能够通过编译，**导致程序员误以为他在 Tuna 类中成功地覆盖了函数 Swim()**。从 C++11 起，程序员可使用限定符 override 来核实被覆盖的函数在基类中是否被声明为虚的：

```c++
class Tuna:public Fish 
{ 
public: 
 void Swim() const override // Error: no virtual fn with this sig in Fish 
 // vs2019里提示:使用override声明的成员函数不能重写基类成员
 { 
 cout << "Tuna swims!" << endl; 
 } 
};
```

换而言之，override 提供了一种强大的途径，**让程序员能够明确地表达对基类的虚函数进行覆盖的意图**，进而让编译器做如下检查：

• 基类函数是否是虚函数？

• 基类中相应虚函数的特征标是否与派生类中被声明为 override 的函数完全相同？

#### 5）使用final来禁止覆盖函数

C++11 引入了限定符 final，这在第 10 章介绍过。被声明为 final 的类不能用作基类，同样，**对于被声明为 final 的虚函数，不能在派生类中进行覆盖**。

因此，要在 Tuna 类中禁止进一步定制虚函数 Swim()，可像下面这样做：

```c++
class Tuna:public Fish 
{ 
public: 
 // override Fish::Swim and make this final 
 void Swim() override final 
 { 
 cout << "Tuna swims!" << endl; 
 } 
}; 
```

您可继承这个版本的 Tuna 类，但不能进一步覆盖函数 Swim()：

```c++
class BluefinTuna final:public Tuna 
{ 
public: 
 void Swim() // Error: Swim() was final in Tuna, cannot override 
 { 
 } 
}; 
```

#### 6）可将复制构造函数声明为虚函数吗？

从技术上说，C++不支持虚复制构造函数。但如果能实现虚复制构造函数，则创建一个基类指针集合（如静态数组，其中的每个元素指向不同的派生类对象）：

```c++
// Tuna, Carp and Trout are classes that inherit public from base class Fish 
Fish* pFishes[3]; 
Fishes[0] = new Tuna(); 
Fishes[1] = new Carp(); 
Fishes[2] = new Trout(); 
```

并将其赋给另一个相同类型的数组时，虽然是通过 Fish 指针调用的复制构造函数，但将复制指向的派生类对象，并对其进行深复制。

**然而，这只是一种美好的梦想。**

根本不可能实现虚复制构造函数，**因为在基类方法声明中使用关键字 virtual 时，表示它将被派生类的实现覆盖**（当然，测试过了，**通过作用域解析法依然可以访问基类的虚函数**），这种多态行为是在运行阶段实现的。而构造函数只能创建固定类型的对象，不具备多态性，因此 C++不允许使用虚复制构造函数。虽然如此，但存在一种不错的解决方案，就是定义自己的克隆函数来实现上述目的：

```c++
class Fish 
{ 
public: 
 virtual Fish* Clone() const = 0; // pure virtual function 
}; 
class Tuna:public Fish 
{ 
// ... other members 
public: 
 Tuna * Clone() const // virtual clone function 
 { 
 return new Tuna(*this); // return new Tuna that is a copy of this 
 } 
};
```

虚函数 Clone 模拟了虚复制构造函数，但需要显式地调用。

<p align=center>Tuna 和 Carp 包含 Clone 函数，它们模拟了虚复制构造函数</p>

```c++
 0: #include <iostream> 
 1: using namespace std; 
 2: 
 3: class Fish 
 4: { 
 5: public: 
 6: virtual Fish* Clone() = 0; 
 7: virtual void Swim() = 0; 
 8: virtual ~Fish() {}; 
 9: }; 
10: 
11: class Tuna: public Fish 
12: { 
13: public: 
14: Fish* Clone() override 
15: { 
16: return new Tuna (*this); 
17: } 
18: 
19: void Swim() override final 
20: { 
21: cout << "Tuna swims fast in the sea" << endl; 
22: } 
23: }; 
24: 
25: class BluefinTuna final:public Tuna 
26: { 
27: public: 
28: Fish* Clone() override 
29: { 
30: return new BluefinTuna(*this); 
31: } 
32: 
33: // Cannot override Tuna::Swim as it is "final" in Tuna 
34: }; 
35: 
36: class Carp final: public Fish 
37: { 
38: Fish* Clone() override 
39: { 
40: return new Carp(*this); 
41: } 
42: void Swim() override final 
43: { 
44: cout << "Carp swims slow in the lake" << endl; 
45: } 
46: }; 
47: 
48: int main() 
49: { 
50: const int ARRAY_SIZE = 4; 
51: 
52: Fish* myFishes[ARRAY_SIZE] = {NULL}; 
53: myFishes[0] = new Tuna(); 
54: myFishes[1] = new Carp(); 
55: myFishes[2] = new BluefinTuna(); 
56: myFishes[3] = new Carp(); 
57: 
58: Fish* myNewFishes[ARRAY_SIZE]; 
59: for (int index = 0; index < ARRAY_SIZE; ++index) 
60: 	myNewFishes[index] = myFishes[index]->Clone(); 
61: 
62: // invoke a virtual method to check 
63: for (int index = 0; index < ARRAY_SIZE; ++index) 
64: 	myNewFishes[index]->Swim(); 
65: 
66: // memory cleanup 
    // 务必记得释放指针，当然，这个可以在析构中实现，当然，析构可以直接是虚的，所以没什么难度
67: for (int index = 0; index < ARRAY_SIZE; ++index) 
68: { 
69: delete myFishes[index]; 
70: delete myNewFishes[index]; 
71: } 
72: 
73: return 0; 
74: }
```

```
Tuna swims fast in the sea 
Carp swims slow in the lake 
Tuna swims fast in the sea 
Carp swims slow in the lake
```

注意到 myFishes 数组能够存储不同类型的对象，这些对象都是从 Fish 派生而来的。这太酷了，因为本书前面的大部分数组包含的都是相同类型的数据，如 int。如果这还不够酷，您还可以在循环中使用虚函数 Fish::Clone 将其复制到另一个 Fish*数组（myNewFishes）中，如第 60 行所示。注意到这里的数组很小，只有 4 个元素，但即便数组长得多，复制逻辑也差别不大，只需调整循环结束条件即可。第 64 行进行了核实，它通过新数组的每个元素调用虚函数 Swim( )，以验证 Clone( )复制了整个派生类对象，而不仅仅是 Fish 部分。输出表明，确实像预期的那样复制了整个派生类对象。另外，注意到对 BluefinTuna 和 Tuna 实例调用 Swim()得到的输出相同，这是因为Tuna::Swim()被声明为 final，因此 BluefinTuna 不能覆盖 Swim()，所以编译器在您对 BluefinTuna 实例调用 Swim()时执行 Tuna::Swim()。

> C++的析构函数是不可以传入参数的，所以参数需要在其他函数中传入；
>
> 如果你要达到这样的效果，自己写一个处理函数，它可以是你这个要析构类的成员函数，在里面做一些你要做的事情，它可以带参数。

### 习题

#### 1）为什么C++默认的析构函数不是虚函数？

C++默认的析构函数不是虚函数是因为虚函数需要额外的虚函数表和虚表指针，占用额外的内存。**而对于不会被继承的类来说，其析构函数如果是虚函数，就会浪费内存**。因此C++默认的析构函数不是虚函数，而是只有当需要当作父类时，设置为虚函数。

#### 2）析构函数设为虚函数的作用是什么

在类的继承中，如果有基类指针指向派生类，那么用基类指针delete时，如果不定义成虚函数，**派生类中派生的那部分无法析构**。

#### 3）构造函数不能声明为虚函数的原因是什么

> 1 构造一个对象的时候，必须知道对象的实际类型，而虚函数行为是在运行期间确定实际类型的。而在构造一个对象时，由于对象还未构造成功。编译器无法知道对象 的实际类型，是该类本身，还是该类的一个派生类，或是更深层次的派生类。无法确定。
>
> 2 虚函数的执行依赖于虚函数表。而虚函数表在构造函数中进行初始化工作，即初始化vptr，让他指向正确的虚函数表。而在构造对象期间，虚函数表还没有被初 始化，将无法进行。虚函数的意思就是开启动态绑定，程序会根据对象的动态类型来选择要调用的方法。然而在构造函数运行的时候，这个对象的动态类型还不完整，没有办法确定它到底是什么类型，故构造函数不能动态绑定。（动态绑定是根据对象的动态类型而不是函数名，在调用构造函数之前，这个对象根本就不存在，它怎么动态绑定？）编译器在调用基类的构造函数的时候并不知道你要构造的是一个基类的对象还是一个派生类的对象。
>
> 另外，不建议在构造函数和析构函数里面调用虚函数。
>
> https://blog.csdn.net/wk_bjut_edu_cn/article/details/80187658

> 一般不建议在构造函数或者析构函数中调用虚函数，因为**在构造函数和析构函数中调用虚函数不会呈现多态性**。
>
> ```c++
> class A{
> 	public:
> 		void foo() { printf("foo"); }
> 		virtual void bar() { printf("bar"); }
> 		A() { bar(); }
> 	};
> 	class B :public A {
> 	public:
> 		void foo() { printf("b_foo"); }
> 		void bar() { printf("b_bar"); }
> 	};
> 	int main() {
> 		A* p = new B();// bar,调用A类的构造函数
> 		p->foo();// foo 
> 		p->bar();// b_bar
> 	}
> ```
>
> 输出：barfoob_bar
>
> ```c++
> B *b = new B();// bar
> A* p = b; 
> // 这样也是调用基类的构造函数，注意只输出一个bar，和A* p = new B()等价，因为第二句是调用拷贝构造函数了
> 
> B b; // bar
> A* p = new B(); // bar
> 
> B b; // bar
> A p = b; // 没有输出，因为调用的是拷贝构造函数
> ```
>
> 分析：
>
> 在构造基类调用基类的构造函数时，派生类的部分还没有构造，怎么可能能用基类构造函数里的bar虚函数实现动态绑定派生生类对象呢，所以构造B类部分的时候，调用的基类的函数bar；
>
> 对于foo函数不是虚函数不会有动态绑定，所以调用的基类部分；
>
> 对于第三个bar调用，是虚函数，实现动态绑定，所以调用的是派生类部分。

## 第十二章.运算符类型与运算符重载

### 知识点

#### 1）C++运算符

**从语法层面看，除使用关键字 operator 外，运算符与函数几乎没有差别**。运算符声明看起来与函数声明极其相似：

```c++
return_type operator operator_symbol (...parameter list...);
```

要实现相关运算符，需要做额外的工作，但会让类使用起来将更容易，因此值得这样做。

C++运算符分两大类：单目运算符与双目运算符。

#### 2）单目运算符

顾名思义，单目运算符**只对一个操作数进行操作**。实现为全局函数或静态成员函数的单目运算符的典型定义如下：

```c++
return_type operator operator_type (parameter_type) 
{ 
 // ... implementation 
}
```

作为类成员（非静态函数）的单目运算符没有参数，因为它们使用的唯一参数是当前类实例（*this），

```c++
如下所示：

return_type operator operator_type () 
{ 
 // ... implementation 
} 
```

> 直接对对象进行操作符运算是怎样的原理
>
> ```c++
> 可以通过在运算符函数参数表中是否插入关键字int来区分这两种方式
> 声明：
> TYPE operator++();//前缀方式
> TYPE operator++(int);//后缀方式
> 调用时，参数int一般传递给值0，且在实现中不使用。
> 如：
> TYPE ob;
> ++ob;
> ob++;                    //隐式调用ob.operator++(int)
> ob.operator++();
> ob.operator++(0); //显式调用ob.operator++(int)，意为ob++
> ```

**小知识**：经过我的测试发现不能写++a++；编译器提示'++' needs l-value，即它需要的是左值，由于后缀++优先级更高，先执行它，但是返回的是a原来的值，它是个值不是变量即是个右值，不是左值，所以报错。

#### 3）双目运算符

对两个操作数进行操作的运算符称为双目运算符。以全局函数或静态成员函数的方式实现的双目运算符的定义如下：

```c++
return_type operator_type (parameter1, parameter2); 
```

以类成员的方式实现的双目运算符的定义如下：

```c++
return_type operator_type (parameter); 
```

以类成员的方式实现的双目运算符只接受一个参数，其原因是第二个参数通常是从类属性获得的。

### 习题

#### 1.我编写的类封装了一个动态整型数组，请问我至少应该实现哪些函数和方法？

编写这样的类时，必须明确定义下述情形下的行为：通过赋值直接复制对象或通过按值传递给函数间接复制对象。通常，应实现复制构造函数、复制赋值运算符和析构函数。另外，如果想改善这个类在某些情况下的性能，还应实现移动构造函数和移动赋值运算符。要能够像访问数组一样访问类实例存储的元素，可重载下标运算符 operator []。

#### 2.自己编写智能指针类时，至少需要实现哪些函数和运算符？

智能指针必须能够像常规指针那样使用，如* pSmartPtr 或 pSmartPtr->Func( )。为此，需要实现运算符*和->。**要确保它足够智能，还需合理地编写析构函数，以自动释放/归还资源**；另外，还需实现复制构造函数和复制赋值运算符，以明确定义复制和赋值的方式（也可将复制构造函数和复制赋值运算符声明为私有的，以禁止复制和赋值）。

#### 3.给 Date 类实现移动构造函数和移动赋值运算符有意义吗？

只有**动态分配的资源**才会导致复制构造函数和复制赋值运算符进行不必要的内存分配和释放，而 Date 类没有包含动态分配的资源，因此给它提供移动构造函数或移动赋值运算符没有意义。

#### 4.为 Date 类编写一个转换运算符，将其存储的日期转换为整数

```c++
class Date 
{ 
 int day, month, year; 
public: 
 explicit operator int() 
 { 
 return ((year * 10000) + (month * 100) + day); 
 } 
 // constructor etc 
};
```

#### 5.DynIntegers 类以 int*私有成员的方式封装了一个动态分配的数组，请给它编写移动构造函数和移动赋值运算符

```c++
class DynIntegers 
{ 
private: 
 int* arrayNums; 
public: 
 // move constructor 
 DynIntegers(DynIntegers&& moveSrc) 
 { 
 arrayNums = moveSrc.arrayNums; // take ownership 
 moveSrc.arrayNums = NULL; // release ownership from source 
 }
 // move assignment operator 
 DynIntegers& operator= (DynIntegers&& moveSrc) 
 { 
 if(this != &moveSrc) 
 { 
 delete [] arrayNums; // release own resources 
 arrayNums = moveSrc.arrayNums; 
 moveSrc.arrayNums = NULL; 
 } 
 return *this; 
 } 
 ~DynIntegers() {delete[] arrayNums;} // destructor 
 // implement default constructor, copy constructor, assignment operator 
};
```

6.可以像下面这样，编写两个版本的下标运算符，一个的返回类型为 const，另一个为非 const 吗？

```c++
const Type& operator[](int index); 

Type& operator[](int index); // is this OK? 
```

不可以。C++不允许两个函数的名称相同，但返回类型不同。您可编写运算符[]的这样两种实现：它们的返回类型相同，但一个为 const 函数，另一个不是。在这种情况下，如果执行的是与赋值相关的操作，编译器将使用非 const 版本，否则使用 const 版本：

```c++
Type& operator[](int Index) const; 

Type& operator[](int Index); 
```


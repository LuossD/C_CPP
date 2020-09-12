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

在下面的语句中，使用前缀还是后缀运算符对结果没有影响：

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

在c++中（void *）不能转化为任意类型的指针，即 int * p=(void*)是错误的，但int *p=nullptr是正确的，原因对于函数重载：若c++中 （void *）支持任意类型转换，函数重载时将出现问题下列代码中fun(NULL)将不能判断调用哪个函数

```c++
void fun(int i){cout<<"1";};
void fun(char *p){cout<<"2";};
int main()
{
fun(NULL);  //输出1，c++中NULL为整数0
fun(nullptr);//输出2，nullptr 为空指针常量。是指针类型
}
```

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

**注意**：new 表示请求分配内存，并不能保证分配请求总能得到满足，因为这取决于系统的状态以及内存资源的可用性。

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
// ++是运算符，但是a++是表达式（表达式是由运算符和操作数组合而成的式子）
```

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

3）悬浮指针（也叫迷途或失控指针）

使用 delete 释放后，任何有效指针都将无效。不应再使用。

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

5）如果对象是使用 new 在自由存储区中实例化的，或者有指向对象的指针，则可使用指针运算符（->）来访问成员属性和方法。->由一个连字符和大于号组成，也称箭头成员运算符，创建动态结构（或类）时，不能将成员运算符句点用于结构名，因为这种结构没有名称，只是知道它的地址。为此，c++专门为这种情况提供了这么一个运算符。

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

8）初始化列表由包含在括号中的**参数声明后面的冒号标识**，**冒号后面列出了各个成员变量及其初始值**。初始值可以是参数（如 humansName），也可以是固定的值。使用特定参数调用基类的构造函数时，初始化列表也很有用，这将在第 10 章讨论。

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


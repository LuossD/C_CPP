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

### 1．有符号整型和无符号整型有何不同？

有符号整型变量的最高有效位（MSB）用作符号位，指出了整数值是正还是负，0表示正，1表示负，而无符号整型变量只能存储正整数。

### 2．为何不应使用#define 来声明常量？

\#define 是一个预处理器编译指令，让编译器对定义的值进行文本替换。然而，**它不是类型安全的**，是一种原始的常量定义方式，应避免使用。

### 3．为何要对变量进行初始化？

确保变量包含非随机的确定值。

### 4．下述变量名有何问题？

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


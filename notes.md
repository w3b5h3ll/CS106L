Namespaces:
- ! `using namespace std;`, which automatically add std:: for you, but it's not good style.

Function overloading

使用方法重载，只需要如下
- same function name
- different typed arguments and different number of arguments

例如

```c
int half(int x)
{
    std::cout << "1" << endl;
    return x / 2;
}

double half(double x)
{
    cout << "2" << endl;
    return x / 2;
}

```
### problem 1:
- it can be a pain to konw what the type of a variable is.

自动类型推导, `auto` 关键字, 编译器决定类型

```c
auto a = 3; // int
auto b = 4.3; // float
auto c = 'x'; // char
auto d = "hello"; // char *




```

### problem 2:
- any given fuction can only have exactly one return type

使用结构体，就可以传递，返回多个信息

```c
struct Student
{
    string name;
    string state;
    int age;

};

```
STL structs
- std:: pair:, 这是一个模板 template

```cpp
std::pair<int, string> numSuffix = {1, "st"};

```

> `std::make_pair` 是 C++ 标准库中的一个函数模板，用于快速创建一个 `std::pair` 对象，而不需要显式指定其中元素的类型。`std::pair` 是一个结构，它可以存储两个可能不同类型的值。这个函数模板在 `<utility>` 头文件中定义。

一个简洁的例子，使用 `std::pair` 进行返回
```cpp
std::pair<bool, Student> lookupStudent(string name)
{
    Student blank;
    if (notFound(name)) return std::make_pair(false, blank);
    Student result = getStudent(name);
    return std::make_pair(true, result);
}

auto ouput = lookupStudent("Julie");
```
## Lecture 3: Initialization & Reference
初始化操作
> Provides initial values at the time of construction - cppreference.com

C++ it doesn't type check with direct initialization.

引起缩小转换范围，narrowing conversion, 例如
```cpp
int criticalSystemValue(42.5);
```

编译器给出了提示
```bash
 $ clang++ ./narrow_convert.cpp -o narrow_convert     
./narrow_convert.cpp:5:29: warning: implicit conversion from 'double' to 'int' changes value from 42.5 to 42 [-Wliteral-conversion]
    5 |     int criticalSystemValue(42.5);
      |         ~~~~~~~~~~~~~~~~~~~ ^~~~
1 warning generated.
[  1:16PM ]  [ c0r3dump@ArchLinux:~/Workspace/CS106L/code(master✗) ]
 $ ./narrow_convert 
critical system value: 42

```
<font color="red"> Uniform initalization (C++11)</font>

使用大括号进行初始化

```cpp
int numOne{12.0};
```
- 安全，不允许 narrowing conversion: `./narrow_convert.cpp: 6:16: error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]
    6 |     int numOne{12.5};
      |                ^~~~`
- 使用在多个地方，vector, maps, 等等
```cpp
std::map<std::string, int> ages
{
    {"Alice", 25},
    {"Bob", 30}
};

// 结构体初始化
Student s{"Haven", "AR", 21};

```

Structured Binding (C++17)
- 强大，可以组合多个子元素
```cpp
std:string className = "a";
std:string language = "C++";

return {className, language};


```

引用类型，可以提高性能，按引用传递 Pass by reference, there is no copy.

```cpp
int num = 5;
int& ref = num;

```

l-value, r-value
- r-value is temporary, x = 100, 100 is r-value

如果变量是 `const`, 那么引用也要是 `const`

使用 g++进行编译
`g++ -std=c++11 main.cpp -o main`

## Streams

I/O 输入输出流
- 读写数据

![image-20240616135950257](notes/image-20240616135950257.png)

std:: stringstream

- 一种将 string 作为 strams 的方式

- `>>` 会一直读取，知道遇见空字符
  - "", \n, \t 都是空字符
  - 使用 `getline()` 可以一直读取，直到 `\n`

```cpp
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot.";

    std::stringstream ss(initial_quote);

    std::string first;
    std::string second;
    std::string third;
    std::string extracted_quote;

    ss >> first >> second >> third;
    std::getline(ss, extracted_quote);
    std::cout << first << " " << second << " " << third << extracted_quote << std::endl;
}

```

std:: count 是 line-buffered, 知道 flush 时候才会输出

- 所以 `cout << i++`: 12345
- cout << i++ << endl; 1\n2\n3\n\4\n5\n



cerr and clong

- cerr 输出 error, unbufferd
- clog: 日志输出， bufferd



Output File Streams

std:: ofsteam 

- is_open()
- open()
- clonse()
- fail()

std:: cin 是 bufferd 的，

使用 `getline`

## Containers

容器

vectors, stacks, queues

重排列相关的数据

标准化

- 允许存储多个对象，相同类型
- 允许访问对象

- 允许，读写对象

STL 有许多的容器

- Vector
- Stack
- Queue
- Set
- Map

...

- Array, 固定大小的 vector
- Deque，双端 queue
- List， doubly linked list
- Unordered set
- Unordered map

![image-20240617223852207](notes/image-20240617223852207.png)

在 speed, power, 以及 safety 之间的取舍

C++设计哲学

- 只提供必要的检查
- 开发者应该知道一切

有两种类型的容器

Sequence

- 可顺序访问的容器

Associative 关联类型

- 容器不必有顺序
- 查找方便
- 例如 Maps 和 sets



Vector

- 一种有序的集合，并可以扩充和收缩

Internally, vectors implement an array

- _size, 元素个数
- _capacity, 实际分配的空间

Deque

一种实现方式

a array stored other arrays

- 减少，数组插入和删除时的移动开销

![image-20240617225219342](notes/image-20240617225219342.png)

![image-20240617225703050](notes/image-20240617225703050.png)

Map

std:: pair <const key, value>



Container Adaptors

是对容器的包装，增加/限制了原有容器的接口的访问

例如，stack_deque 是对 deque 的包装

stack_list 是对 list 的包装

- 可以更加满足某些场景需求
- 可以根据用途选择不同的容器类型

练习

- unordered sets/maps 对比 ordered
- 考虑如何使用 vector 实现 stack
- 浏览 C++官方文档



## 参考

https://learncs.me/stanford/cs106l

https://learncs.me/


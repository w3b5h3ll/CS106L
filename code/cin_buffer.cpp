#include <iostream>

int main()
{
    double pi;
    double tao;
    std::string name;
    std::string test;

    std::cin >> pi;
    // 读取并丢弃换行符
    std::getline(std::cin, name);
    // 接着读取下一行
    std::getline(std::cin, name);
    std::cin >> tao;
    std::cin >> test;

    // 如果名字是Fabio Ibanez,那么输入被切割
    // std::cin >> name;

    std::cout << pi << std::endl;
    std::cout << name << std::endl;

    // std::getline(std::cin, name);
    // double被读入string,报错
    std::cout << tao << std::endl;
    std::cout << test << std::endl;
    return 0;
}
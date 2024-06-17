#include <stdio.h>
#include <cmath>
#include <iostream>

// num 是一个左值变量
int squareN(int &num)
{
    // num ^ 2
    return std::pow(num, 2);
}

int main()
{
    int lValue = 2;
    auto four = squareN(lValue);
    // error
    // r-value is temporary
    auto fourAgain = squareN(2);
    std::cout << four << std::endl;
    std::cout << fourAgain << std::endl;
    return 0;
}
// 解决一个二次方程问题
#include <cmath>    // for sqrt
#include <iostream> // to print
#include <utility>  // for pairs

std::pair<bool, std::pair<int, int>> solveQuadratic(int a, int b, int c)
{
    // x = [-b +- sqrt(b^2 - 4ac)] / 2a
    //
    // TODO: Write this code!
    //
    // std::cout << b << std::endl;
    // std::cout << a << std::endl;
    // std::cout << c << std::endl;
    // std::cout << (b ^ 2) << std::endl;
    auto check = (b ^ 2) - (4 * a * c);
    // std::cout << check << std::endl;
    if (check < 0)
    {

        return std::make_pair(false, std::make_pair(0, 0));
    }

    else if (check == 0)
    {
        std::cout << "One real root" << std::endl;
        auto x = (0 - b) / (2 * a);
        return std::make_pair(true, std::make_pair(x, x));
    }
    else
    {
        auto x1 = (0 - b + sqrt(check)) / (2 * a);
        auto x2 = (0 - b - sqrt(check)) / (2 * a);
        return std::make_pair(true, std::make_pair(x1, x2));
    }
}

int main()
{
    // std::cout << "Hello World!" << std::endl;
    auto result = solveQuadratic(1, -1, 2);
    if (result.first == false)
    {
        std::cout << "No real roots" << std::endl;
        return 0;
    }

    std::cout << result.first << std::endl;
    std::cout << result.second.first << std::endl;
    std::cout << result.second.second << std::endl;
    // TODO: Write code to display the two roots! Make sure to handle if
    // there are no real roots!
}
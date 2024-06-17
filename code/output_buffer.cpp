#include <iostream>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << std::endl;
    }
    std::cout << "testing flush" << std::endl;
    std::ios::sync_with_stdio(true);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << i << "\n";
    }
}
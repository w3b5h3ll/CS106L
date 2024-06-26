#include <iostream>
#include <vector>

void removeOddsFromEnd(std::vector<int> &vec)
{
    while (!vec.empty() && vec.back() % 2 == 1)
    {
        vec.pop_back();
    }
}

int main()
{
    std::vector<int> vec;
    removeOddsFromEnd(vec);
    return 0;
}

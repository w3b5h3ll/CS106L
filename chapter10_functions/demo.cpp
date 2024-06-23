#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

// 判断元音
bool isVowel(char c)
{
    std::string vowels = "aeiou";
    return vowels.find(c) != std::string::npos;
}

template <typename InputIt, typename DataType>
int count_occurrences(InputIt begin, InputIt end, DataType target)
{
    int count = 0;
    for (auto iter = begin; iter != end; ++iter)
    {
        if (*iter == target)
        {
            /* code */
            count++;
        }
    }

    return count;
}

// 函数指针，callback回调
// 泛化能力较差
template <typename InputIt, typename UniPred>
int count_occurrences_pointer(InputIt begin, InputIt end, UniPred pred)
{
    int count = 0;
    for (auto iter = begin; iter != end; ++iter)
    {
        if (pred(*iter))
        {
            /* code */
            count++;
        }
    }

    return count;
}

int main()
{
    std::string str = "Tchaikovsky";
    std::cout << "Occurrences of the letter k in the string: " << count_occurrences(str.begin(), str.end(), 'k') << std::endl;
    std::cout << "Occurrences of the letter vowel in the string: " << count_occurrences_pointer(str.begin(), str.end(), isVowel) << std::endl;

    int limit = 5;
    // [limit], 外部参数
    // (int n), 参数)
    // [] 捕获器
    // [] nothing, [limit], captures limit by value
    // [=], captures everything by value
    auto isMoreThan = [limit](int n)
    { return n > limit; };
    std::cout << isMoreThan(10) << std::endl;

    return 0;
}

// Predicate functions
// 返回布尔值的函数都是谓词函数

// lambdas,匿名函数




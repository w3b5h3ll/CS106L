/*
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <unordered_set>

std::set<std::string> get_applicants(std::string filename)
{
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::set<std::string> applicants;
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            /* code */
            applicants.insert(line);
        }
    }
    inputFile.close();
    return applicants;
}

// 这里要求名字缩写相同, 并且放入queue
// 假设名字为 Jone Smith
// 是的，在 C++ 中，std::set 内部存储的元素确实是 const 的。这是因为 std::set 的实现依赖于排序和唯一性约束，所以它需要保证元素在插入后不能/被修改，否则会破坏集合的有序性和唯一性。
std::queue<std::string *> find_matches(std::set<std::string> &students)
{
    // TODO: Implement this function.
    std::queue<std::string *> queue;
    for (auto &student : students)
    {
        auto first = student[0];
        auto secondIndex = student.find_first_of(" ");
        auto second = student[secondIndex + 1];
        if (first == 'J' && second == 'S')
        {
            // 进行类型转换，否则报错
            // 这些错误信息表明，您试图将一个 const std::string* 类型的指针推入到一个 std::queue<std::string*> 类型的队列中，但由于类型不匹配，导致编译错误。
            // 间接说明了set中元素为const类型
            // 移除const
            // const_cast<new_type>(expression)
            // auto result = &student;
            auto result = const_cast<std::string *>(&student);

            queue.push(result);

            // queue.push(student);
        }
    }
    return queue;
}

// 自定义哈希函数，使用std::unordered_set
class CustomeHash
{
public:
    std::size_t operator()(const std::string &str) const
    {
        std::size_t hash = 0;
        for (auto c : str)
        {
            hash = hash * 31 + c;
        }
        std::cout << hash << std::endl;

        return hash;
    }
};

int main()
{
    // Your code goes here. Don't forget to print your true love!
    std::set<std::string> students = get_applicants("students.txt");
    // int count = 0;
    // for (auto student : students)
    // {
    //     std::cout << count << ": " << student << std::endl;
    //     count++;
    // }
    // std::cout << "--------------------------------" << std::endl;
    std::queue<std::string *> matches = find_matches(students);

    while (matches.size() > 0)
    {
        /* code */
        std::cout << *matches.front() << std::endl;
        matches.pop();
    }

    // std::cout << "--------------------------------" << std::endl;
    // std::unordered_set<std::string, CustomeHash> students2;
    // students2.insert("Jone Smith");
    // students2.insert("Jone Wirk");
    // students2.insert("Jone Goodley");
    // for (auto name : students2)
    // {
    //     std::cout << name << std::endl;
    // }

    return 0;
}

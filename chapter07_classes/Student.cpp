#include "Student.h"
#include <string>

Student::Student(std::string name, std::string state, int age)
{
    this->name = name;
    this->state = state;
    this->age = age;
}

// 使用C++11, uniform initialization, 参数列表初始化
Student::Student(std::string name, std::string state, int age) : name(name), state(state), age(age)
{
}
// 析构函数自动调用，当一个对象被销毁时
Student::~Student()
{
}

std::string Student::getName()
{
    return this->name;
}

std::string Student::getState()
{
    return this->state;
}

int Student::getAge()
{
    return this->age;
}

void Student::setName(std::string name)
{
    this->name = name;
}

void Student::setState(std::string state)
{
    this->state = state;
}

void Student::setAge(int age)
{
    if (age >= 0)
    {
        this->age = age;
    }
}

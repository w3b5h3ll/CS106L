#include <string>
#include <iostream>
#include <memory>

class B;
class A
{
public:
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A destory!" << std::endl; }
};

class B
{
public:
    // std::shared_ptr<A> ptrA;
    std::weak_ptr<A> ptrA;
    ~B() { std::cout << "B destory!" << std::endl; }
};

int main()
{
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->ptrB = b;
    b->ptrA = a;

    return 0;
}
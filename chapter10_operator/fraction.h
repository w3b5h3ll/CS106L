#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

// 分数
class Fraction
{
public:
    Fraction(int num, int denom);

    // 操作符重载, 成员函数
    bool operator<(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    Fraction operator-(const Fraction &rhs) const;

    // 操作符重载, 非成员函数
    friend Fraction &operator+=(Fraction &lhs, const Fraction &rhs);
    friend bool operator<(const double &lhs, const Fraction &rhs);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &target);

private:
    int num, denom;
    void reduce();
};

#endif
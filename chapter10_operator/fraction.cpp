#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "fraction.h"

Fraction::Fraction(int num, int denom)
{
    this->num = num;
    this->denom = denom;
    reduce();
}

// 分数简化
void Fraction::reduce()
{
    int gcd = std::__gcd(num, denom);
    num = num / gcd;
    denom = denom / gcd;
}

bool Fraction::operator<(const Fraction &rhs) const
{
    return num * rhs.denom < rhs.num * denom;
}

bool Fraction::operator>(const Fraction &rhs) const
{
    return num * rhs.denom > rhs.num * denom;
}

Fraction Fraction::operator-(const Fraction &rhs) const
{
    int newNum = num * rhs.denom - denom * rhs.num;
    int newDenom = denom * rhs.denom;

    return Fraction(newNum, newDenom);
}

// 实现非成员函数的重载
// 返回引用
Fraction &operator+=(Fraction &lhs, const Fraction &rhs)
{
    lhs.num = lhs.num * rhs.denom + lhs.denom * rhs.num;
    lhs.denom = lhs.denom * rhs.denom;
    lhs.reduce();

    return lhs;
}

bool operator<(const double &lhs, const Fraction &rhs)
{
    double fraction = rhs.num / rhs.denom;
    return lhs < fraction;
}

std::ostream &operator<<(std::ostream &out, const Fraction &rhs)
{
    out << rhs.num << "/" << rhs.denom;
    return out;
}
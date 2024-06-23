// Blank cpp file

#include "class.h"
Assignment3::Assignment3(std::string name, std::string address)
{
    this->name = name;
    this->address = address;
}

std::string Assignment3::getAddress()
{
    return this->address;
}

std::string Assignment3::getName()
{
    return this->name;
}

void Assignment3::setAddress(std::string address)
{
    this->address = address;
}

void Assignment3::setName(std::string name)
{
    this->name = name;
}
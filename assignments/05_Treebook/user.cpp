#include "user.h"
#include <set>
#include <iostream>
#include <string>

User::User(std::string name)
{
    // TODO: Implement the additional constructor here!
    name = name;
}

std::string User::getName() const
{
    return name;
}

std::set<User> User::getFriends() const
{
    return friends;
}

void User::setName(std::string name)
{
    this->name = name;
}

// TODO: Implement the < operator overload here!

bool User::operator<(const User &rhs) const
{
    return name < rhs.name;
}

User &User::operator=(User &&other)
{
    if (this != &other)
    {
        /* code */
        this->name = other.name;
        this->friends = other.friends;
    }
    return *this;
}

User &operator+(User &lhs, User &rhs)
{
    lhs.friends.insert(rhs.friends.begin(), rhs.friends.end());
    rhs.friends.insert(lhs.friends.begin(), rhs.friends.end());
    return lhs;
}
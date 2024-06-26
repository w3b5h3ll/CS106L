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
    return this.name < rhs.name;
}

User &&User::operator+(User &rhs) &&
{
    friends.insert(rhs);
    rhs.friends.insert(this);
    return std::move(this);
}
#include <set>
#include <string>

class User
{
public:
    // TODO: write special member functions, including default constructor!
    User();
    User(std::string name);
    User(const User &) = delete;
    User &operator=(const User &) = delete;
    // move constructor
    User(User &&other) = default;
    User &operator=(User &&other) = default;
    ~User();

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User &rhs) const;
    friend User &operator+(User &lhs, User &rhs);

private:
    std::string name;
    std::set<User> friends;
};
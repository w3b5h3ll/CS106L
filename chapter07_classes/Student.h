#include <string>
class Student
{
private:
    std::string name;
    std::string state;
    int age;

public:
    // constructor
    Student(std::string name, std::string state, int age);
    // methods
    std::string getName();
    std::string getState();
    int getAge();
    void setName(std::string name);
    void setState(std::string state);
    void setAge(int age);
    ~Student();
}
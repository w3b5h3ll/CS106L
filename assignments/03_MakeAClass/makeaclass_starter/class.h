// Blank header file
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

class Assignment3
{
public:
    // default constructor
    Assignment3();
    // custom constructor
    Assignment3(std::string name, std::string address);

    std::string getName();
    std::string getAddress();
    void setName(std::string name);
    void setAddress(std::string address);

private:
    std::string name;
    std::string address;
};

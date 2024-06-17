#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot.";

    std::stringstream ss(initial_quote);

    std::string first;
    std::string second;
    std::string third;
    std::string extracted_quote;

    ss >> first >> second >> third;
    std::getline(ss, extracted_quote);
    std::cout << first << " " << second << " " << third << extracted_quote << std::endl;
}
#include "class.h"

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main()
{
  // initialize class and run this file

  Assignment3 assignment3("John", "Shanghai");
  std::cout << assignment3.getName() << std::endl;
  std::cout << assignment3.getAddress() << std::endl;
  assignment3.setName("Jane");
  assignment3.setAddress("Beijing");
  std::cout << assignment3.getName() << std::endl;
  std::cout << assignment3.getAddress() << std::endl;

  return 0;
}
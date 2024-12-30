//
//  main.cpp
//  extern
//
//  Created by Yujian Zhao on 12/30/24.
//

#include <iostream>
#include "helper.h"

extern const std::string global_variable = "global";
// Without "extern" keyword, a const variable cannot be shared across different files
const std::string local_variable = "local";

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "The global variable in main is: " << global_variable << std::endl;
    std::cout << "The local variable in main is: " << local_variable << std::endl;
    foo();
}

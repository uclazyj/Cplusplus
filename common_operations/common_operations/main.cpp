//
//  main.cpp
//  common_operations
//
//  Created by Yujian Zhao on 5/9/25.
//

#include <iostream>
#include <cmath>
#include <string>

int main(int argc, const char * argv[]) {
    {
        // Math
        // TLDR use these functions with the prefix std::
        float a = std::abs(-1.5);
        double b = std::sqrt(4);
        int c = std::pow(3,4);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    std::cout << "==========" << std::endl;
    {
        // Chars
        std::cout << isalnum('8') << std::endl;
        std::cout << isalnum('a') << std::endl;
        std::cout << isalnum('(') << std::endl;
        
        char c;
        c = tolower('A');
        std::cout << c << std::endl;
        c = tolower('a');
        std::cout << c << std::endl;
        
        c = toupper('a');
        std::cout << c << std::endl;
        
        c = toupper('A');
        std::cout << c << std::endl;
    }
    std::cout << "==========" << std::endl;
    {
        // convert int to string
        std::string s = std::to_string(5);
        std::cout << s << std::endl;
        // convert string to int
        int num = std::stoi("9");
        std::cout << num << std::endl;

    }
}

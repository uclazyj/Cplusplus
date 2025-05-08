//
//  main.cpp
//  function_pointer
//
//  Created by Yujian Zhao on 5/8/25.
//

#include <iostream>

typedef void (*Print_type)(const std::string&);

void print(const std::string& message){
    std::cout << message << std::endl;
}

void PrintValue(int value){
    std::cout << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)){
    for (int value : values) {
        func(value);
    }
}


int main(int argc, const char * argv[]) {
    // Some basic examples
    {
        // fp1 now points to the function named print
        void (*fp1)(const std::string&) = print;
        fp1("Hello1");
        // Equivalent assignment: address-of operator is optional
        void (*fp2)(const std::string&) = print;
        fp2("Hello2");
        
        auto fp3 = print;
        fp3("Hello3");
        
        Print_type fp4 = print;
        fp4("Hello4");
    }
    {
        std::vector<int> values= {1,5,4,3,2};
        ForEach(values, PrintValue);
        // Or using lambda
        ForEach(values, [](int value){std::cout << value << std::endl;});
    }
    
    return 0;
}

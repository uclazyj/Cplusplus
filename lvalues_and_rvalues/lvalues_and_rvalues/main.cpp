//
//  main.cpp
//  lvalues_and_rvalues
//
//  Created by Yujian Zhao on 12/29/24.
//

#include <iostream>

void print_name_by_value(const std::string name){
    std::cout << name << std::endl;
}

void print_name_by_reference(std::string& name){
    std::cout << name << std::endl;
}

void print_name_by_const_reference(const std::string& name){
    std::cout << name << std::endl;
}

void print_name_by_r_value_reference(std::string&& name){
    std::cout << name << std::endl;
}

void print(const std::string& name){
    std::cout << "The constant reference version of the print is called: " << name << std::endl;
}

void print(std::string&& name){
    std::cout << "The r value reference version of the print is called: " << name << std::endl;
}

int main(int argc, const char * argv[]) {
    std::string first_name = "Yujian";
    std::string last_name = "Zhao";
    std::string full_name = first_name + last_name;
    
    print_name_by_value(full_name);
    print_name_by_value(first_name + last_name);
    
    print_name_by_reference(full_name);
    // This does not work
    // print_name_by_reference(first_name + last_name);
    
    print_name_by_const_reference(full_name);
    print_name_by_const_reference(first_name + last_name);
    
    print_name_by_r_value_reference(first_name + last_name);
    
    std::cout << "print is called: " << std::endl;
    print(first_name + last_name);
}

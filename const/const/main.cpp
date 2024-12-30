//
//  main.cpp
//  const
//
//  Created by Yujian Zhao on 12/30/24.
//

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    {
        // Const reference is nothing but reference to const
        
        int number = 42;
        int &ordinary_reference = number;
        // Ordinary reference can be used to change the object to which the reference is bound
        ordinary_reference = 43;
        
        // A reference to const (const reference) cannot be used to change the object to which the reference is bound
        const int& reference_to_const = number;
        // reference_to_const = 50; // Error
        
        // However, the object can still change. It's just that we cannot use the const reference of the object to change the object.
        number = 50;
        cout << reference_to_const << endl;
    }
    
    {
        // A pointer to const and const pointer are different
        
        int i = 10;
        // A pointer to const: Cannot use the pointer to change the pointee
        const int* ptr_to_const_pointee = &i;
        // *ptr_to_const_pointee = 20; // Error
        // But the pointee can change
        i++;
        
        // A const pointer: Pointer cannot be changed
        int a = 10;
        int* const const_ptr = &a;
        // const_ptr = nullptr; // Error
        // But the pointee can change
        a = 20;
        cout << *const_ptr << endl;
        
        // A const pointer to const: Neither pointer nor pointee can be changed
        int b = 30;
        const int* const const_ptr_to_const_pointee = &b;
    }
}

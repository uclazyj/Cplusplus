//
//  main.cpp
//  return_by_reference
//
//  Created by Yujian Zhao on 5/11/25.
//

#include <iostream>
#include <string>

using namespace std;

string& do_nothing_return_by_reference(string& s){
    return s;
}

// illegal
// string& do_nothing_return_by_reference(const string& s){
//     return s;
// }

// For the argument, both "const string& s" and "string& s" work
const string& do_nothing_return_by_const_reference(string& s){
    return s;
}

// When a function returns a variable by reference, the variable needs to outlive the function.

int main(int argc, const char * argv[]) {
    {
        string s = "apple";
        // Assign to another variable by copy
        string s2 = do_nothing_return_by_reference(s);
        s2 = "banana";
        string s3 = do_nothing_return_by_const_reference(s);
        s3 = "banana";
    }
    cout << "==========" << endl;
    {
        string s = "apple";
        // Assign to another variable by reference
        string& s2 = do_nothing_return_by_reference(s);
        s2 = "banana";
        cout << s << endl;
        // illegal
        // string& s3 = do_nothing_return_by_const_reference(s);
        
        const string& s3 = do_nothing_return_by_const_reference(s);
        // illegal
        // s3 = "banana";
    }
    
    
    
}

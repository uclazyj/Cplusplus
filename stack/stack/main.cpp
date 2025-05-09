//
//  main.cpp
//  stack
//
//  Created by Yujian Zhao on 5/9/25.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,5,4,2,3};
    stack<int> s;
    for (int num : nums) {
        s.push(num);
    }
    
    cout << "The size of the stack is: " << s.size() << endl;
    
    cout << "Pop from stack one by one: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

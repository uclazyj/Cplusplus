//
//  main.cpp
//  vector
//
//  Created by Yujian Zhao on 5/10/25.
//

#include <iostream>

using namespace std;

void print(const vector<int>& v) {
    for (int num : v){
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    {
        // insert an element at the beginning of a vector
        vector<int> v = {2,3,4,5};
        v.insert(v.begin(), 1);
        print(v);
        
        // insert an element at index 2
        v.insert(v.begin()+2, 100);
        print(v);
    }
    std::cout << "==========" << std::endl;
    {
        vector<int> v1 = {1, 2, 3};
        vector<int> v2 = {4, 5, 6};
        v1.insert(v1.end(), v2.begin(), v2.end());
        print(v1);
        
        v1 = {1, 2, 3};
        v2 = {4, 5, 6};
        vector<int> v3;
        v3.insert(v3.end(), v1.begin(), v1.end());
        v3.insert(v3.end(), v2.begin(), v2.end());
        print(v3);
    }
}

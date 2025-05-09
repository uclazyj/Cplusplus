//
//  main.cpp
//  unordered_set
//
//  Created by Yujian Zhao on 5/8/25.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    
    {
        unordered_set<int> s = {1,5,4,2,3};
        int item = 4;
        if (s.find(item) != s.end()) {
            cout << item << " is in the set!" << endl;
        } else {
            cout << item << " is not in the set!" << endl;
        }
        
        s.insert(item);
        cout << "The size of the set is " << s.size() << endl;
        s.erase(item);
        cout << "The size of the set is " << s.size() << endl;
    }
    {
        // We cannot have an std::unordered_set of std::pair (like Python) due to the hash problem.
        // We can either define a custom hash function, or use std::set instead, but the set operations will have a time complexity of O(log N).
        
        // unordered_set<pair<int, int>> s_does_not_work;
        
        set<pair<int, int>> s1;
        s1.insert({1,2});
        
        set<tuple<int, int, int>> s2;
        s2.insert({1,2,3});
        tuple t = {2,3,4};
        s2.insert(t);
    }
}

//
//  main.cpp
//  basic_data_structures
//
//  Created by Yujian Zhao on 5/8/25.
//

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    {
        std::unordered_map<int, int> map;
        const int key = 1;
        
        if (map.find(key) == map.end()) {
            cout << "Key does not exist in the map!" << endl;
        } else {
            cout << "Key exists in the map!" << endl;
        }
        
        // When accessing a key that does not exist, since the value type is int, 0 is returned.
        // However, after this attemp, the key is added to the map.
        cout << map[key] << endl;
        
        if (map.find(key) == map.end()) {
            cout << "Key does not exist in the map!" << endl;
        } else {
            cout << "Key exists in the map!" << endl;
        }
    }
    {
        // Similar to the unordered_set, we cannot have a std::pair as the key
        // unordered_map<pair<int, int>, int> map_does_not_work;
        map<pair<int,int>, int> map;
        map[{1,4}] = 5;
        map[{2,7}] = 9;
    }
    {
        std::unordered_map<int, int> map;
        map[1] = 10;
        map[2] = 20;
        map[3] = 30;
        // Use structured bindings
        for (const auto& [key, value] : map){
            cout << key << ":" << value << endl;
        }
    }
}

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
    std::cout << "==========" << std::endl;
    {
        // 2D vector
        vector<vector<int>> vec(3, vector<int>(4));
        cout << vec.size() << endl;
        cout << vec[0].size() << endl;
        cout << vec[1][2] << endl;
    }
    std::cout << "==========" << std::endl;
    {
        // delete an element
        vector<int> v = {1, 2, 3, 4, 5, 6};

        auto it = v.erase(v.begin()+2);
        cout << *it << endl;
    }
    std::cout << "==========" << std::endl;
    {
        // custom sort
        vector<pair<int, int>> v = {{1,10},{2,6},{1,100},{3,9}};
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){return a.first + a.second > b.first + b.second;});
        for (const auto& pair : v){
            cout << "(" << pair.first << "," << pair.second << ")" << endl;
        }
        
        // sort again, using functor
        struct Comparator {
            bool operator()(pair<int, int> a, pair<int,int> b) const {
                return a.first + a.second < b.first + b.second;
            }
        };
        std::cout << "----------" << std::endl;
        sort(v.begin(), v.end(), Comparator());
        for (const auto& pair : v){
            cout << "(" << pair.first << "," << pair.second << ")" << endl;
        }
        
    }
}

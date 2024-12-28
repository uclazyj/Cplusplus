//
//  main.cpp
//  STL
//
//  Created by Yujian Zhao on 12/28/24.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>

template <class T>
void print(const std::vector<T>& v){
    std::cout << "[";
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i];
        if (i != v.size() - 1){
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

template <class T>
void print(const std::list<T>& li){
    std::cout << "[";
    auto last = li.end();
    last--;
    for (auto it = li.begin(); it != last; ++it){
        std::cout << *it << "->";
    }
    std::cout << *last << "]" << std::endl;
}

template <class T>
void print(const std::set<T>& s){
    std::cout << "{";
    auto last = s.end();
    last--;
    for (auto it = s.begin(); it != last; ++it){
        std::cout << *it << ",";
    }
    std::cout << *last << "}" << std::endl;
}

template <class K, class V>
void print(const std::map<K, V>& map){
    std::cout << "{";
    auto last = map.end();
    last--;
    for (auto it = map.begin(); it != last; ++it){
        std::cout << it->first << ": " << it->second << ", ";
    }
    std::cout << last->first << ": " << last->second;
    std::cout << "}" << std::endl;
}

int main(int argc, const char * argv[]) {
    // vector
    std::vector<int> v(5,0);
    for (int i = 0; i < 5; i++){
        v[i] = i;
    }
    sort(v.begin(), v.end(), std::greater<int>());
    print(v);
    sort(v.begin(),v.end());
    print(v);
    sort(v.begin(), v.end(), [](int a, int b){return a > b;});
    print(v);
    auto it = std::find(v.begin(), v.end(), 9);
    if (it == v.end()){
        std::cout << "Not found" << std::endl;
    }
    else {
        std::cout << "Found " << *it << std::endl;
    }
    
    // list
    std::list<std::string> li;
    li.push_back("a");
    li.push_back("b");
    li.push_back("c");
    print(li);
    
    // map
    std::map<std::string, int> dic;
    dic["banana"] = 6;
    dic["watermelon"] = 10;
    dic["apple"] = 5;
    dic["blueberry"] = 9;
    dic.erase("banana");
    dic.erase("nonexist");
    print(dic);
    
    // set
    std::set<int> s = {1,2,3,4};
    s.insert(5);
    s.erase(0);
    print(s);
}

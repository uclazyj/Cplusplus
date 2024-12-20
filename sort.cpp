#include <iostream>
#include <vector>

int main() {
    
    std::vector<std::pair<int,int>> v{{10,1},{9,2},{8,3}};
    for (const auto& [first, second] : v){
        std::cout << "(" << first << "," << second << ")";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end());
    for (const auto& [first, second] : v){
        std::cout << "(" << first << "," << second << ")";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
    for (const auto& [first, second] : v){
        std::cout << "(" << first << "," << second << ")";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end(), [](auto &a, auto &b){return a.second > b.second;});
    for (const auto& [first, second] : v){
        std::cout << "(" << first << "," << second << ")";
    }
    std::cout << std::endl;
    return 0;
}
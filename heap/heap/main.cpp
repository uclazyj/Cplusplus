//
//  main.cpp
//  heap
//
//  Created by Yujian Zhao on 5/8/25.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    {
        std::priority_queue<int> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        std::vector<int> nums = {1,2,3,4,5};
        for (int num : nums) {
            maxHeap.push(num);
            minHeap.push(num);
        }
        std::cout << maxHeap.top() << std::endl;
        std::cout << minHeap.top() << std::endl;
    }
    std::cout << "==========" << std::endl;
    {
        // define a custom comparator for a heap
        struct Compare {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first > b.first;
            }
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> heap;
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype([](const std::pair<int, int>& a, const std::pair<int, int>& b){
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first > b.first;
        })> heap2;
        
        
        std::vector<std::pair<int, int>> v = {{8,2}, {1,1}, {7,3}, {5,5}};
        for (const auto& pair : v){
            heap.push(pair);
            heap2.push(pair);
        }
        
        while (!heap.empty()){
            std::pair<int, int> top = heap.top();
            std::cout << "(" << top.first << "," << top.second << ")" << std::endl;
            heap.pop();
        }
        
        std::cout << "----------" << std::endl;
        
        while (!heap2.empty()){
            std::pair<int, int> top = heap2.top();
            std::cout << "(" << top.first << "," << top.second << ")" << std::endl;
            heap2.pop();
        }
    }
}

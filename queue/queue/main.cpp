//
//  main.cpp
//  queue
//
//  Created by Yujian Zhao on 5/9/25.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,5,4,2,3};
    queue<int> q;
    for (int num : nums){
        q.push(num);
    }
    cout << "The size of the queue is: " << q.size() << endl;
    cout << "The back of the queue is: " << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

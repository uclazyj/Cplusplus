#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

std::deque<int> q;
std::mutex mu;

void function_1(){
    int count = 10;
    while (count > 10){
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

void function_2(){
    int data = 0;
    while (data != 1){
        std::unique_lock<std::mutex> locker(mu);
        if (!q.empty()){
            data = q.back();
            q.pop_back();
            locker.unlock();
            std::cout << "t2 got a value from t1: " << data << std::endl;
        } else {
            locker.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

    }
    
}

int main(){
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join(); 
    t2.join(); 
}
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void shared_print(std::string msg, int id){
    std::lock_guard<std::mutex> guard(mu); // RAII. Whenever guard goes out of scope, mu will always be unlocked, w/o exception.
    // mu.lock();
    std::cout << msg << id << std::endl;
    // mu.unlock();
}

void function_1(){
    for (int i = 0; i > -100; i--)
    shared_print(std::string("From t1: "), i);
}

int main(){
    std::thread t1(function_1); // t1 starts running

    for (int i=0; i < 100; i++){
        shared_print(std::string("From main: "), i);
    }

    t1.join();
}
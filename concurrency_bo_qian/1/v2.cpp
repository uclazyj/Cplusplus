#include <iostream>
#include <thread>

void function_1(){
    std::cout << "Beauty is only skin-deep" << std::endl; 
}

int main(){
    std::thread t1(function_1); // t1 starts running
    t1.detach();
    if (t1.joinable()){
        std::cout << "t1 is joinable!" << std::endl;
        t1.join();
    }
    else {
        std::cout << "t1 is NOT joinable!" << std::endl;
    }
}

// A thread should be either joined or detached only once.
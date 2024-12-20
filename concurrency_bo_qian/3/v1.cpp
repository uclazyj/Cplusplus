#include <iostream>
#include <thread>

void function_1(){
    for (int i = 0; i > -100; i--)
    std::cout << "From t1: " << i << std::endl;
}

int main(){
    std::thread t1(function_1); // t1 starts running

    for (int i=0; i < 100; i++){
        std::cout << "from main: " << i << std::endl;
    }

    t1.join();
}
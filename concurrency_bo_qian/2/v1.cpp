#include <iostream>
#include <thread>

void function_1(){
    std::cout << "Beauty is only skin-deep" << std::endl; 
}

int main(){
    std::thread t1(function_1); // t1 starts running
    
    // If the following code throws an exception, t1 is never joined.
    // So we have to wrap the following code with try & catch, 
    // or use RAII.
    try {
        for (int i=0; i < 100; i++){
            std::cout << "from main: " << i << std::endl;
        }
    } catch (...) {
        t1.join();
        throw;
    }

    t1.join();
}
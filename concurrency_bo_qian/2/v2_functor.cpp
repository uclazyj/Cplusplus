#include <iostream>
#include <thread>

void function_1(){
    std::cout << "Beauty is only skin-deep" << std::endl; 
}

class Fctor{
public:
    void operator()() {
        for (int i = 0; i > -100; i--){
            std::cout << "from t1 " << i << std::endl;
        }
    }
};


// The output is a mess because the main thread and the t1 thread are printing numbers concurrently
int main(){
    // We cannot use 
    // std::thread t1(Fctor());
    // Since it will be interpreted as a function declaration
    // We have to add another (): 
    std::thread t1((Fctor()));
    
    // Fctor fct;
    // std::thread t1(fct); // t1 starts running

    
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
#include <iostream>
#include <thread>

class Fctor{
public:
    void operator()(std::string& msg) {
        std::cout << "t1 says: " << msg << std::endl;
        msg = "Trust is the mother of deceit.";
    }
};


// The output is a mess because the main thread and the t1 thread are printing numbers concurrently
int main(){
    std::string s = "Where there is no trust, there is no love";
    // we need to use std::ref explicty to pass s by reference
    std::thread t1((Fctor()), std::ref(s));
    t1.join();
    
    std::cout << "from main: " << s << std::endl;
}
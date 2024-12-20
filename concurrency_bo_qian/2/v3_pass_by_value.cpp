#include <iostream>
#include <thread>

class Fctor{
public:
    void operator()(std::string msg) {
        std::cout << "t1 says: " << msg << std::endl;
    }
};


// The output is a mess because the main thread and the t1 thread are printing numbers concurrently
int main(){
    std::string s = "Where there is no trust, there is no love";
    std::thread t1((Fctor()), s);
    
    try {
        std::cout << "from main: " << s << std::endl;
    } catch (...) {
        t1.join();
        throw;
    }

    t1.join();
}
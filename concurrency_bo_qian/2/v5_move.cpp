#include <iostream>
#include <thread>

class Fctor{
public:
    void operator()(std::string& msg) {
        std::cout << "t1 says: " << msg << std::endl;
        msg = "Trust is the mother of deceit.";
    }
};


// This example is taken from https://www.youtube.com/watch?v=f2nMqNj7vxE&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&index=2&ab_channel=BoQian
// But it does not compile (g++ -std=c++11 v5_move.cpp). Not sure why.
int main(){
    std::string s = "Where there is no trust, there is no love";
    std::thread t1((Fctor()), std::move(s));
    std::thread t2 = std::move(t1);
    t2.join();
    
    std::cout << "from main: " << s << std::endl;
}
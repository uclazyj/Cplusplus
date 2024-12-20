#include <iostream>
#include <thread>

class Fctor{
public:
    void operator()(std::string msg) {
        std::cout << "t1 says: " << msg << std::endl;
        std::cout << "t1's id from t1 thread: " << std::this_thread::get_id() << std::endl;
    }
};


// The output is a mess because the main thread and the t1 thread are printing numbers concurrently
int main(){
    std::cout << "Main thread's id: " << std::this_thread::get_id() << std::endl;
    std::string s = "Where there is no trust, there is no love";
    std::thread t1((Fctor()), s);
    std::cout << "t1's id from main thread: " << t1.get_id() << std::endl;
    
    std::cout << "from main: " << s << std::endl;

    t1.join();
}
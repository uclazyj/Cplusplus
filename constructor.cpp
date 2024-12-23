// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    A() {cout << "Constructor A\n";}
    ~A() {cout << "Destructor A\n";}
};

class B: public A
{
public:
    B() {cout << "Constructor B\n";}
    ~B() {cout << "Destructor B\n";}
};

int main() {
    // Write C++ code here
    // B b;
    // std::cout << "=====" << std::endl;
    A* p = new B;
    B* q = new B;
    std::cout << "=====" << std::endl;
    delete p;
    std::cout << "=====" << std::endl;
    delete q;
    // std::cout << "=====" << std::endl;
    // delete p;
    // std::cout << "=====" << std::endl;
}
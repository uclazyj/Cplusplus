// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class B {
public:
    B(){cout << "Constructor B\n";}
    ~B(){cout << "Destructor B\n";}
};

class C {
public:
    C(){cout << "Constructor C\n";}
    ~C(){cout << "Destructor C\n";}
};

class A {
public:
    A() {cout << "Constructor A\n";}
    ~A() {cout << "Destructor A\n";}
private:
    B b;
    C c;
};


int main() {
    A a = A();
}
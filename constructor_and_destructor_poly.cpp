// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
    // Base() {cout << "Constructor Base\n";}
    virtual ~Base() {cout << "Destructor Base\n";}
};

class Derived: public Base
{
public:
    // Derived() {cout << "Constructor Derived\n";}
    ~Derived() {cout << "Destructor Derived\n";}
};

int main() {
    Base* b = new Derived();
    delete b;
    return 0;
}
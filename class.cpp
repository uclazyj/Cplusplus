#include <iostream>

using namespace std;

class Animal {
public:
    virtual void Greet(){
        cout << "I am an animal!" << endl;
    } 
};

class Dog : public Animal {
public:
    void Greet() override {
        cout << "I am an dog!" << endl;
    }
    void Bark(){
        cout << "Bark!" << endl;
    }
};

void say_hi(Animal& animal){
    animal.Greet();
}

int main() {
    Animal a = Animal();
    a.Greet();
    Dog dog = Dog();
    dog.Greet();

    say_hi(dog);
}
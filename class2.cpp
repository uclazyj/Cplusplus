#include <iostream>

using namespace std;

class Animal {
public:
    Animal(int weight):weight_(weight){}
    virtual void Greet(){
        cout << "I am an animal!" << endl;
    } 
    int get_weight(){return weight_;}
private:
    int weight_;
};

class Dog : public Animal {
public:
    Dog():Animal(2),cute_(true){}
    void Greet() override {
        cout << "I am an dog!" << endl;
    }
private:
    bool cute_;
};

int main() {
    Animal a = Animal(5);
    a.Greet();
    Dog dog = Dog();
    dog.Greet();
    cout << dog.get_weight() << endl;
}
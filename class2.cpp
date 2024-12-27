#include <iostream>

using namespace std;

class Animal {
public:
    Animal(int weight):weight_(weight){}

    virtual void Greet(){
        cout << "I am an animal!" << endl;
    } 

    int get_weight(){return weight_;}

    void SayHi(){
        Greet();
    }
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

// polymorphism only works with base pointer or base reference

void Greet_with_base_pointer(Animal* a){
    a->Greet();
}

void Greet_with_base_reference(Animal& a){
    a.Greet();
}

// Chopping happens
void Greet_with_base_copy(Animal a){
    a.Greet();
}

int main() {
    Animal* a = new Dog;
    Greet_with_base_pointer(a);
    Greet_with_base_reference(*a);
    Greet_with_base_copy(*a);

    a->SayHi();
}
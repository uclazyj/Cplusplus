//
//  main.cpp
//  class
//
//  Created by Yujian Zhao on 5/11/25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(const string& name):name_(name){}
    Animal() = default;
    
    Animal(const Animal& other) {
        cout << "Copy constructor called!" << endl;
        name_ = other.name_;
    }
    
    Animal& operator=(const Animal& other){
        cout << "Copy assignment operator called!" << endl;
        name_ = other.name_;
        return *this;
    }
    
    Animal(Animal&& other){
        cout << "Move constructor called!" << endl;
        name_ = other.name_;
        other.name_ = "";
    }
    
    Animal& operator=(Animal&& other) {
        cout << "Move assignment operator called!" << endl;
        if (&other != this){
            name_ = other.name_;
            other.name_ = "";
        }
        return *this;
    }
    
    virtual void sayHi(){
        cout << "Hi, I am " << name_ << endl;
    }
    
    const string& getName(){
        return name_;
    }
private:
    string name_;
};

class Dog : public Animal {
public:
    Dog(const string& name):Animal(name){}
    
    void sayHi() override {
        cout << "Bark bark! I am " << getName() << endl;
    }
private:
};

int main(int argc, const char * argv[]) {
    {
        Animal a("Alice");
        a.sayHi();
        
        Dog d("Dick");
        d.sayHi();
        
        Animal a2(a);
        a2.sayHi();
        
        a.sayHi();
    }
    cout << "==========" << endl;
    {
        vector<Animal> arr;
        Animal amy("Amy");
        for (int i = 1; i <= 9; ++i){
            cout << i << endl;
            arr.push_back(amy);
            cout << "The size of the arr: " << arr.size() << endl;
        }
        cout << "erase an element: " << endl;
        arr.erase(arr.begin() + 5);
    }
    cout << "==========" << endl;
    {
        Animal arr[3]; // Have to have a default constructor for this to work.
        arr[0] = Animal("Amy");
        cout << "----------" << endl;
        Animal amy("Amy");
        arr[1] = amy;
        cout << "----------" << endl;
        amy.sayHi();
        arr[2] = std::move(amy);
        // amy is in a "valid but unspecified" state. I can assign it to something new, but I cannot rely on its state.
        amy.sayHi();
    }
}

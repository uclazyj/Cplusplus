//
//  main.cpp
//  copy_elision
//
//  Created by Yujian Zhao on 12/31/24.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Person{
public:
    Person(std::string name):name_(name){
        cout << "Person constructor called!" << endl;
    }
    // copy constructor
    Person(const Person& other){
        cout << "Person copy constructor is called!" << endl;
        name_ = other.name_;
    }
    // Move constructor
    Person(Person&& other){
        cout << "Person move constructor is called!" << endl;
        name_ = other.name_;
        other.name_ = "";
    }
    std::string get_name(){return name_;}
private:
    std::string name_;
};

Person create_person(std::string name){
    return Person(name);
}

#include <iostream>

int main(int argc, const char * argv[]) {
    // Due to Copy Elision, the copy assignment operator was not called.
    cout << "Copy elision:" << endl;
    Person person = create_person("Tony");
    
    cout << endl << "Two-step construction:" << endl;
    Person person1 = create_person("Tony");
    Person person2 = person1;
}

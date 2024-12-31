//
//  main.cpp
//  return_const_reference
//
//  Created by Yujian Zhao on 12/31/24.
//
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
    
    std::string get_name() const {return name_;}
    
    void set_name(std::string name){
        name_ = name;
    }
    
private:
    std::string name_;
};

Person create_person(std::string name){
    return Person(name);
}

class Employee{
public:
    Employee(std::string name, int level):person_(name),level_(level){}
    Person get_person_by_value(){return person_;}
    const Person& get_person_by_const_reference(){return person_;}
    Person& get_person_by_reference(){return person_;}
private:
    Person person_;
    int level_;
};

#include <iostream>

int main(int argc, const char * argv[]) {
    Employee e("Tony",4);
    cout << "Get person member by value:" << endl;
    Person person_copy = e.get_person_by_value();
    cout << "Get person member by const reference:" << endl;
    const Person& person_const_reference = e.get_person_by_const_reference();
    cout << "Get person member by reference, then change person's name:" << endl;
    Person& person_reference = e.get_person_by_reference();
    person_reference.set_name("Amy");
    cout << e.get_person_by_value().get_name() << endl;
    
}


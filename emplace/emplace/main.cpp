//
//  main.cpp
//  emplace
//
//  Created by Yujian Zhao on 12/30/24.
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

int main(int argc, const char * argv[]) {
    {
        std::vector<Person> people;
        people.reserve(3);
        cout << "Using push_back:" << endl;
        for (int i = 0; i < 3; ++i){
            // If we didn't define a move constructor, copy constructor would be used instead.
            people.push_back(Person("Tony"));
        }
    }
    cout << endl;
    {
        std::vector<Person> people;
        people.reserve(3);
        cout << "Using emplace_back:" << endl;
        for (int i = 0; i < 3; ++i){
            people.emplace_back("Amy");
        }
    }
}

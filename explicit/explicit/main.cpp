//
//  main.cpp
//  explicit
//
//  Created by Yujian Zhao on 12/31/24.
//

#include <iostream>

class Person{
public:
    Person(int age):age_(age){}
    int get_age() const {return age_;}
private:
    int age_;
};


int main(int argc, const char * argv[]) {
    // The following won't be possible if we add explicit in front of the constructor
    Person person = 3;
    std::cout << person.get_age() << std::endl;
}

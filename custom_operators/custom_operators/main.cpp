//
//  main.cpp
//  custom_operators
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>

using namespace std;

class Dog{
public:
    Dog(int weight):weight_(weight){}
    int get_weight() const{
        return weight_;
    }
    // Comparison operator inside the class
    bool operator> (const Dog& other) const {
        return this->weight_ > other.weight_;
    }

private:
    int weight_;
};

// Comparison operator outside the class
bool operator< (const Dog& a, const Dog& b){
    return a.get_weight() < b.get_weight();
}

int main(int argc, const char * argv[]) {
    Dog dog1 = Dog(3);
    Dog dog2 = Dog(4);
    if (dog1 < dog2){
        cout << "dog 1 is heavier! " << endl;
    }
    else{
        cout << "dog 2 is heavier! " << endl;
    }
}

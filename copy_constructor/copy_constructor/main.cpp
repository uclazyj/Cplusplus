//
//  main.cpp
//  copy_constructor
//
//  Created by Yujian Zhao on 12/25/24.
//
#include <iostream>

using namespace std;

class Container {
public:
    Container(unsigned int capacity): capacity_(capacity), size_(0){
        container_ = new int[capacity];
    }
    
    // Copy constructor
    Container (const Container& other){
        capacity_ = other.capacity_;
        size_ = other.size_;
        container_ = new int[capacity_];
        for (int i = 0; i < size_; ++i){
            container_[i] = other.container_[i];
        }
    }
    
    // assignment operator
    Container& operator=(const Container& other){
        if (&other == this){
            return *this;
        }
        delete [] container_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        container_ = new int[capacity_];
        for (int i = 0; i < size_; ++i){
            container_[i] = other.container_[i];
        }
        // This allows assignment chaining, e.g.: a = b = c
        return *this;
    }
    
    void add(int number){
        if (size_ == capacity_){
            return;
        }
        container_[size_] = number;
        size_++;
    }
    void print(){
        for (int i = 0; i < size_; ++i){
            cout << container_[i] << " ";
        }
        cout << endl;
    }
    ~Container(){
        delete [] container_;
    }
private:
    int* container_ ;
    unsigned int capacity_;
    unsigned int size_;
};

int main(int argc, const char * argv[]) {
    Container c1 = Container(5);
    c1.add(1);
    c1 = c1;
    c1.print();
    cout << "Finish!" << endl;
    return 0;
}

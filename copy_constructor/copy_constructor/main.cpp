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
        cout << "Copy constructor is called! " << endl;
        capacity_ = other.capacity_;
        size_ = other.size_;
        container_ = new int[capacity_];
        for (int i = 0; i < size_; ++i){
            container_[i] = other.container_[i];
        }
    }
    
    // Copy assignment operator
    Container& operator=(const Container& other){
        cout << "Copy assignment operator is called! " << endl;
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
    
    // Move constructor
    Container(Container&& other) noexcept
    {
        cout << "Move constructor is called!" << endl;
        capacity_ = other.capacity_;
        size_ = other.size_;
        container_ = other.container_;
        
        other.container_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }
    
    // Move assignment operator
    Container& operator=(Container&& other){
        cout << "Move assignment operator is called!" << endl;
        if (&other != this){
            delete [] container_;
            
            capacity_ = other.capacity_;
            size_ = other.size_;
            container_ = other.container_;
            
            other.container_ = nullptr;
            other.capacity_ = 0;
            other.size_ = 0;
        }
        return *this;
    }
    
    void add(int number){
        if (size_ == capacity_){
            return;
        }
        container_[size_] = number;
        size_++;
    }
    
    unsigned int size(){
        return size_;
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
    // Copy constructor is called
    Container c2 = c1;
    // Copy assignment operator is called
    c2 = c1;
    c2.print();
    {
        Container c1_copy = c1;
        Container c3 = std::move(c1);
        c3.print();
        Container c4(10);
        c4 = std::move(c1_copy);
        c4.print();
    }
    return 0;
}

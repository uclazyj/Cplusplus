//
//  main.cpp
//  copy_constructor
//
//  Created by Yujian Zhao on 12/25/24.
//
#include <iostream>
#include <vector>

using namespace std;

#define CAPACITY 100

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
            cout << "cannot add more elements, reaching capacity!" << endl;
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

Container create_container(const vector<int>& nums) {
    Container c = Container(CAPACITY);
    for (int num : nums){
        c.add(num);
    }
    return c;
}

Container pass_by_value_return_by_value(Container c) {
    cout << "pass_by_value_return_by_value runs!" << endl;
    return c;
}

Container pass_by_reference_return_by_value(Container& c) {
    cout << "pass_by_reference_return_by_value" << endl;
    return c;
}

Container& pass_by_reference_return_by_reference(Container& c) {
    cout << "pass_by_reference_return_by_reference" << endl;
    return c;
}

int main(int argc, const char * argv[]) {
    {
        Container c1 = Container(5);
        c1.add(1);
        // Copy constructor is called
        Container c2 = c1;
        // Copy assignment operator is called
        c2 = c1;
        c2.print();
        Container c1_copy = c1;
        Container c3 = std::move(c1);
        c3.print();
        Container c4(10);
        c4 = std::move(c1_copy);
        c4.print();
    }
    cout << "==========" << endl;
    {
        vector<int> v = {1,2,3,4,5};
        Container c1 = create_container(v);
        
        cout << "----------" << endl;
        // Copy constructor is called when c1 is passed into the function by value
        // Move constructor (or copy constructor, if the move constructor is not defined) is called when the function returns.
        Container c2 = pass_by_value_return_by_value(c1);
        
        cout << "----------" << endl;
        Container c3 = pass_by_reference_return_by_value(c1);
        c3.add(100);
        c3.print();
        c1.print();
        
        cout << "----------" << endl;
        Container& c4 = pass_by_reference_return_by_reference(c1);
        c4.add(100);
        c4.print();
        c1.print();
    }
    
    return 0;
}

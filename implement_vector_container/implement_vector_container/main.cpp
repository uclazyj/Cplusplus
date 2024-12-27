//
//  main.cpp
//  implement_vector_container
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>

template<typename T>
class vector{
public:
    vector():capacity_(1),size_(0){
        data_ = new T[capacity_];
    }
    
    void push_back(const T& element){
        if (size_ == capacity_){
            resize(2 * capacity_);
        }
        data_[size_] = element;
        size_++;
    }

private:
    void resize(int capacity){
        T* data_new = new T[capacity];
        for (unsigned int i = 0; i < size_; ++i){
            data_new[i] = data_[i];
        }
        
        delete[] data_;
        data_ = data_new;
        capacity_ = capacity;
    }
    
    T* data_;
    unsigned int capacity_;
    unsigned int size_;
};

int main(int argc, const char * argv[]) {
    vector<int> v;
    for (int i = 0; i < 10; ++i){
        v.push_back(i);
    }
}

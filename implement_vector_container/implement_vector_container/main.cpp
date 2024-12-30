//
//  main.cpp
//  implement_vector_container
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>

template<typename T>
class Vector{
public:
    Vector():capacity_(1),size_(0){
        data_ = new T[capacity_];
    }
    
    ~Vector(){
        delete [] data_;
    }
    
    void push_back(const T& element){
        if (size_ == capacity_){
            resize(2 * capacity_);
        }
        data_[size_] = element;
        size_++;
    }
    
    void pop_back(){
        if (size_ > 0){
            size_--;
        }
    }
    
    unsigned int size() const {
        return size_;
    }
    
    
    void print() const {
        if (size_ == 0){
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[" << data_[0];
        for (int i = 1; i < size_; ++i){
            
            std::cout << "," << data_[i];
        }
        std::cout << "]" << std::endl;
    }

private:
    void resize(int capacity){
        std::cout << "capacity is resized to " << capacity << "!" << std::endl;
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
    Vector<int> v;
    for (int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    v.pop_back();
    v.pop_back();
    std::cout << "Size: " << v.size() << std::endl;
    v.print();
//    {
//        Vector<int> v2;
//        v2 = v;
//    }
//    v.print();
}

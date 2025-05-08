//
//  main.cpp
//  implement_vector_container
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

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
    
    T& operator[](unsigned int index){
        if (index >= size_){
            cerr << "Index out of range! " << endl;
            // Some error handling...
            return *data_;
        }
        return *(data_ + index);
    }
    
    void print() const {
        if (size_ == 0){
            cout << "[]" << endl;
            return;
        }
        cout << "[" << data_[0];
        for (int i = 1; i < size_; ++i){
            cout << "," << data_[i];
        }
        cout << "]" << endl;
    }

private:
    void resize(int capacity){
        cout << "capacity is resized to " << capacity << "!" << endl;
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
    cout << "Size: " << v.size() << endl;
    v.print();
    
    cout << v[2] << endl;
}

//
//  main.cpp
//  templates
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>
#include <string>

#include "helper.h"

class Point{
public:
    Point(int x, int y):x_(x),y_(y){}
    // Copy constructor
    Point (const Point& other){
        x_ = other.x_;
        y_ = other.y_;
    }
    // assignment operator
    Point& operator=(const Point& other){
        if (&other == this){
            return *this;
        }
        x_ = other.x_;
        y_ = other.y_;
        return *this;
    }
    
    int getX() const {return x_;}
    int getY() const {return y_;}
    
private:
    int x_;
    int y_;
};

template <typename T>
class Stack{
public:
    void push(T element){
        data_.push_back(element);
    }
    T pop(){
        int size = data_.size();
        T res = data_[size-1];
        data_.pop_back();
        return res;
    }
    T top(){
        return data_[data_.size()-1];
    }
    unsigned int size(){
        return data_.size();
    }
    bool empty(){
        return data_.size() == 0;
    }
private:
    std::vector<T> data_;
};

int main(int argc, const char * argv[]) {
    // The generic swap function works the same as the std::swap
    Point point1 = Point(1,2);
    Point point2 = Point(3,4);
    std::cout << "After calling my generic swap function: " << std::endl;
    swap(point1, point2);
    std::cout << "Point 1: (" << point1.getX() << "," << point1.getY() << ")" << std::endl;
    std::cout << "Point 2: (" << point2.getX() << "," << point2.getY() << ")" << std::endl;
    std::cout << "After calling the std::swap function: " << std::endl;
    std::swap(point1, point2);
    std::cout << "Point 1: (" << point1.getX() << "," << point1.getY() << ")" << std::endl;
    std::cout << "Point 2: (" << point2.getX() << "," << point2.getY() << ")" << std::endl;
    
    // Generic class Stack works when holding int
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    std::cout << s1.top() << std::endl;
    
    // Generic class Stack works when holding string
    Stack<std::string> s2;
    s2.push("abc");
    s2.push(" ");
    s2.push("de");
    std::cout << s2.top() << std::endl;
    std::cout << s2.size() << std::endl;
}

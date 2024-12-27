//
//  main.cpp
//  templates
//
//  Created by Yujian Zhao on 12/27/24.
//

#include <iostream>

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

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

int main(int argc, const char * argv[]) {
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
}

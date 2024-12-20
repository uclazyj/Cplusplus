#include <iostream>

using namespace std;

enum Color {
    RED,
    GREEN,
    BLUE
};

// enum with default values
enum Size {
    SMALL = 10,
    MEDIUM = 20,
    LARGE = 30
};

// Scoped enum (C++ 11)
enum class Shape {
    CIRCLE,
    SQUARE,
    TRIANGLE
};

// Scoped enums (C++ 11) with underlying type
enum class Gender : bool {
    MALE,
    FEMALE
};

int main() {
    Color color = RED;
    cout << color << endl;
    Size size = SMALL;
    cout << size << endl;

    // shape cannot be converted to an int
    Shape shape = Shape::CIRCLE;
    
    Gender gender = Gender::MALE;
    
}
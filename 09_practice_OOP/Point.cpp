#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0) {}

Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::Print() const {
    cout << '[' << x << ", " << y << ']';
}

Point& Point::operator++() {
    ++x;
    ++y;
    return *this;
}

Point Point::operator++(int) {
    Point temp(*this);
    ++(*this);
    return temp;
}

Point& Point::operator--() {
    --x;
    --y;
    return *this;
}

Point Point::operator--(int) {
    Point temp(*this);
    --(*this);
    return temp;
}

bool Point::operator<(const Point& other) const {
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
}

bool Point::operator>(const Point& other) const {
    return (x * x + y * y) > (other.x * other.x + other.y * other.y);
}

Point Point::operator!() const {
    return Point(-x, -y);
}
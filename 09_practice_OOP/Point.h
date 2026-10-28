#pragma once
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point();
    Point(int xVal, int yVal);
    Point(const Point& other);

    int getX() const;
    int getY() const;

    void Print() const;

    Point& operator++();
    Point operator++(int);
    Point& operator--();
    Point operator--(int);

    bool operator<(const Point& other) const;
    bool operator>(const Point& other) const;

    Point operator!() const;
};


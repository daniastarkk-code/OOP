#pragma once
#include "point.h"

class Vector {
private:
    Point* points;
    int countPoint;

public:
    Vector();
    Vector(int count);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    ~Vector();

    void Add(const Point& p);
    void Print() const;
    void PrintAtCoordinates() const;
};



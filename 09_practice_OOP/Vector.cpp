#include "Vector.h"
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
    int posX = (x < 0) ? 0 : x;
    int posY = (y < 0) ? 0 : y;
    cout << "\033[" << (posY + 1) << ";" << (posX + 1) << "H";
}

Vector::Vector() : points(nullptr), countPoint(0) {}

Vector::Vector(int count) : countPoint(count) {
    if (count > 0) {
        points = new Point[count];
    }
    else {
        points = nullptr;
        countPoint = 0;
    }
}

Vector::Vector(const Vector& other) : countPoint(other.countPoint) {
    if (countPoint > 0) {
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i) {
            points[i] = other.points[i];
        }
    }
    else {
        points = nullptr;
    }
}

Vector::Vector(Vector&& other) noexcept
    : points(other.points), countPoint(other.countPoint) {
    other.points = nullptr;
    other.countPoint = 0;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] points;

    countPoint = other.countPoint;
    if (countPoint > 0) {
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i) {
            points[i] = other.points[i];
        }
    }
    else {
        points = nullptr;
    }

    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] points;

    points = other.points;
    countPoint = other.countPoint;

    other.points = nullptr;
    other.countPoint = 0;

    return *this;
}

Vector::~Vector() {
    delete[] points;
}

void Vector::Add(const Point& p) {
    Point* newPoints = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; ++i) {
        newPoints[i] = points[i];
    }
    newPoints[countPoint] = p;

    delete[] points;
    points = newPoints;
    ++countPoint;
}

void Vector::Print() const {
    cout << "Vector contains " << countPoint << " point(s):\n";
    for (int i = 0; i < countPoint; ++i) {
        cout << "  [" << i << "] -> ";
        points[i].Print();
        cout << "\n";
    }
}

void Vector::PrintAtCoordinates() const {
    cout << "\033[2J\033[1;1H";

    const int centerX = 40;
    const int centerY = 12;

    gotoxy(centerX, 0); cout << "^ Y";
    gotoxy(80, centerY); cout << "> X";
    gotoxy(centerX, centerY); cout << "+ (0,0)";

    for (int i = 0; i < countPoint; ++i) {
        int xPos = centerX + points[i].getX();
        int yPos = centerY - points[i].getY();

        gotoxy(xPos, yPos);
        cout << "* ";
        points[i].Print();
    }

    gotoxy(0, 25);
}

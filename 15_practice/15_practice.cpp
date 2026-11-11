#include <iostream>
using namespace std;

class Shape
{
protected:
    string name;
public:
	Shape() : name("no name") {}
    Shape(string name) : name(name) {}
    float getArea()
    {

    }
    void Print()
    {
		cout << "Area of " << name << " is: " << getArea() << endl;
    }
};

class Circle : public Shape
{

    float radius;
    const float pi = 3.1415926;
public:
    Circle():Shape("no name"), radius(0) {}
	Circle(string name, float radius) :Shape(name), radius(radius) {}
    virtual float getArea(float radius)
    {
        return pi * radius * radius;
	}
};
class Rectangle : public Shape
{
    float length;
    float width;
public:
	Rectangle() :Shape("rectangle"), length(0), width(0) {}
    virtual float getArea()
    {
        return length * width;
	}
};

class Triangle : public Shape
{
    float base;
	float height;
public:
	Triangle() :Shape("triangle"), base(0), height(0) {}
    virtual float getArea()
    {
        return 0.5 * base * height;
    }
};

class Square : public Shape
{
	float side;
public:
	Square() :Shape("square"), side(0) {}
    virtual float getArea()
    {
        return side * side;
    }
};
 
class Trapezoid : public Shape
{
    float base1;
    float base2;
	float height;
public:
	Trapezoid() :Shape("trapezoid"), base1(0), base2(0), height(0) {}
    virtual float getArea()
    {
        return 0.5 * (base1 + base2) * height;
    }
};



int main()
{
    Circle c("circle", 5.0);
	c.getArea(5.0);
	c.Print();
	Rectangle r;
}

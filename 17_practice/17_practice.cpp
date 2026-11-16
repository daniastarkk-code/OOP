#include <iostream>
#include <fstream>
using namespace std;

struct Point
{
    int x;
    int y;
};

class Shape {
protected:
    string type;

public:
    Shape() : type("no type") {}
    Shape(const string& shapeType) : type(shapeType) {}

    virtual ~Shape() = default;

    string getType() const {
        return type;
    }

    virtual void Print() const = 0;
    //virtual void Save(ofstream& out) const = 0;
};

class Line : public Shape 
{
protected:
    Point p1, p2;

public:
    Line(Point start, Point end) : Shape("Line"), p1(start), p2(end) {}

    void Print() const override {
        cout << "Shape: " << type
            << " | Start: (" << p1.x << ", " << p1.y << ")"
            << " | End: (" << p2.x << ", " << p2.y << ")\n";
    }
};

class Rectangle : public Shape
{
protected:
    Point topLeft;
    int height;
    int width;
public:
    Rectangle(Point tl, int w, int h) : Shape("Rectangle"), topLeft(tl), width(w), height(h) {}

    void Print() const override {
        cout << "Shape: " << type
            << " | Top-left corner: (" << topLeft.x << ", " << topLeft.y << ")"
            << " | Width: " << width << ", Height: " << height << "\n";
    }

};

class Polyline : public Shape {
protected:
    Point* points;
    int count;

public:
    Polyline(const Point* pts, int cnt) : Shape("Polyline"), count(cnt) {
        points = new Point[count];
        for (int i = 0; i < count; ++i) {
            points[i] = pts[i];
        }
    }

    ~Polyline() override {
        delete[] points;
    }

    void Print() const override {
        cout << "Shape: " << type << " | Points: ";
        for (int i = 0; i < count; ++i) {
            cout << "(" << points[i].x << ", " << points[i].y << ") ";
        }
        cout << "\n";
    }
};

int main()
{
    Point polyPoints[] = { {0, 0}, {3, 4}, {6, 1}, {10, 5} };

    const int shapeCount = 3;
    Shape* shapes[shapeCount];

    shapes[0] = new Line({ 1, 2 }, { 10, 20 });
    shapes[1] = new Rectangle({ 5, 5 }, 40, 20);
    shapes[2] = new Polyline(polyPoints, 4);

    for (int i = 0; i < shapeCount; ++i) {
        shapes[i]->Print();
    }

    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
}


#include <iostream>
#include <list>
using namespace std;

class Point {
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double GetX() const { return x; }
    double GetY() const { return y; }

    void Print() const {
        cout << "[" << x << ", " << y << "]";
    }
};
class Vector {
    int size;
    list<Point> points;
public:
    Vector() : size(0) {}
    Vector(const Point& initialPoint)
    {
		points.push_back(initialPoint);
        size = 1;
    }
    void addToStart(const Point& p) {
        points.push_front(p);
        size++;
	}
    void addToEnd(const Point& p) {
        points.push_back(p);
        size++;
    }
    void removeFromStart() {
        if (size > 0) {
            points.pop_front();
            size--;
        }
	}
    void removeFromEnd() {
        if (size > 0) {
            points.pop_back();
            size--;
        }
	}

    void PrintVector()const
    {
        cout << "VEctor: ";
        if (points.empty())
        {
            cout << "Empty vector";
        }
        else
        {
            for (auto i = points.begin(); i != points.end(); i++)
            {
                i->Print();
                if (next(i) != points.end())
                {
                    cout << " -> ";
                }
            }
        }
        cout << "\n";
    }
};

int main()
{
    Vector v;
	v.addToEnd(Point(1, 2));
	v.addToEnd(Point(5.2, -4));
	v.addToStart(Point(0, 0));

    cout << "After addition points to vector : " << endl;
	v.PrintVector();

	v.removeFromStart();
    cout << "After delete first element from vector : " << endl;
	v.PrintVector();

}

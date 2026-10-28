#include <iostream>
#include "Point.h"
#include "Vector.h"
using namespace std;

int main()
{
    Point p1(3, 4);
    Point p2(1, 2);

    cout << "p1 = "; p1.Print(); cout << endl;;
    cout << "p2 = "; p2.Print(); cout << endl;

    ++p1;
    cout << "After ++p1: "; p1.Print(); cout << endl;

    --p2;
    cout << "After --p2: "; p2.Print(); cout << endl;

    if (p2 < p1) {
        cout << "p2 is closer to (0,0) than p1.\n";
    }
    else {
        cout << "p2 is further or at same distance as p1.\n";
    }

    Point p3 = !p1;
    cout << "Opposite point (!p1) = "; p3.Print(); cout << "\n\n";

    Vector v1;
    v1.Add(Point(2, 3));
    v1.Add(Point(-4, 1));
    v1.Add(Point(5, -2));

    cout << "Vector v1:\n";
    v1.Print();

    cout << "\nCreating v2 via move constructor from v1:\n";
    Vector v2(move(v1));
    cout << "v2 after move:\n";
    v2.Print();
    cout << "v1 after move:\n";
    v1.Print();

    cout << "\nCreating v3 and using move assignment (v3 = move(v2)):\n";
    Vector v3;
    v3 = move(v2);
    v3.Print();

    cout << "\nPress Enter to demonstrate gotoxy console output...";
    cin.get();

    v3.PrintAtCoordinates();
}


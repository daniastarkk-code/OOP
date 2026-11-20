#include <iostream>
using namespace std;

class Engine
{
    float volume;
    int count_cylinder;
public:
    Engine():volume(0),count_cylinder(0){}
    Engine(float v, int c): volume(v), count_cylinder(c)  {}
};

class Wheel
{
    float radius;
public:
    Wheel(): radius(0){}
    Wheel(float r): radius(r){}
};

class Door
{
    bool lock;
public:
    Door():lock(false) {}
    Door() : lock(false){}
};

class Headlight
{
    string light_color;
public:
    Headlight():light_color("no color") {}
    Headlight(string l):light_color(l) {}
};

class Backlight
{
    string light_color;
public:
    Backlight():light_color("no color") {}
    Backlight(string l) :light_color(l) {}
};

class Body
{
    string type;
public:
    Body():type("no type"){}
    Body(string t) : type(t) {}
};

class Car : public Engine, public Wheel, public Door, public Headlight, public Backlight, public Body
{

};

int main()
{
    
}


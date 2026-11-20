#include <iostream>
using namespace std;

enum Type{None, Standart, XL, XXL};
class Cartridge
{
    float volume;
    string color;
    Type type;
public:
    Cartridge() : volume(0), color("no color"), type(None) {}
    Cartridge(float v, string c, Type t) : volume(v), color(c), type(t) {}
    void ShowInfo()const
    {
        cout << "Volume : " << volume << endl;
        cout << "Color : " << color << endl;
        cout << "Type : ";
        switch (type)
        {
        case None: cout << "None"; break;
            break;
        case Standart: cout << "Standart"; break;
            break;
        case XL: cout << "XL"; break;
            break;
        case XXL: cout << "XXL"; break;
            break;
        default:
            break;
        }
        cout << endl;
    }
};

class Scaner
{
        float resolution;
        float height, width;
public:
    Scaner() : resolution(0), height(0), width(0) {}
    Scaner(float s, float h, float w) : resolution(s), height(h), width(w) {}
    void ShowInfo()const
    {
        cout << "Scan resolution " << resolution << endl;
        cout << "Area scaning " << height << "x" << width << endl;
    }
 };

class Printer
{
    string model;
    Cartridge* cartridges;
    int count_cartridges;
    Scaner scaner;
public:
    Printer():model("no model"), cartridges(nullptr), count_cartridges(0) {}
    Printer(string m, float s, float h, float w) :model(m)
    {
        count_cartridges = 4;
        cartridges = new Cartridge[count_cartridges];
        cartridges[0] = Cartridge(300, "Red", Type::Standart);
        cartridges[0] = Cartridge(300, "Green", Type::Standart);
        cartridges[0] = Cartridge(300, "Blue", Type::Standart);
        cartridges[0] = Cartridge(300, "Black", Type::Standart);
    }
    ~Printer()
    {
        if (cartridges != nullptr)delete[]cartridges;
    }
    void Scan()
    {
        cout << "Scanning.........." << endl;
    }
    void PrintDocument()
    {
        cout << "Print document..........." << endl;
    }
    void PrintSetting()
    {
        for (int i = 0; i < count_cartridges; i++)
        {
            cartridges[i].ShowInfo();
        }
        scaner.ShowInfo();
    }
};

class Document
{
    string name;
    string format;
    int pages;
public:
    Document() :name("none"), format("none"), pages(0) {}
    Document(string n, string f, int p):name(n), format(f), pages(p) {}
    void ShowInfo()const
    {
        cout << "-------------- Document :" << name << endl;
        cout << "Format :" << format << endl;
        cout << "Pages : " << pages << endl;
    }
};

int main()
{
    Printer printer("Cannon LBP2900", 300, 30, 50);
    printer.PrintDocument();
    printer.Scan();
    printer.PrintSetting();
}

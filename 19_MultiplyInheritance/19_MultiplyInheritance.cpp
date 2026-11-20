#include <iostream>
using namespace std;

class Car
{
    void Drive()
    {
        cout << "Idrive" << endl;
    }
};

class Airplane
{
public:
    void Fly()
    {
        cout << "I fly" << endl;
    }
};


class FlyCar : public Car, public Airplane
{

};

int main()
{
    std::cout << "Hello World!\n";
}


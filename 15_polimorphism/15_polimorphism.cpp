#include <iostream>
using namespace std;

class Car
{
    string model;
    int year;
    int speed;
    float volume;
public:
    Car():model("no model"), year(0), speed(0),volume(0) {}
	Car(string m, int y, int s, float v) :model(m), year(y), speed(s), volume(v) {}
    void Drive()
    {
		cout << "Car is driving" << endl;
    }
    void SetSpeed(int speed)
    {
        if (speed>0)
            this->speed = speed;
        else
			cout << "Speed must be positive" << endl;
    }
    void Print()
    {
		cout << "----------- car -----------" << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Speed: " << speed << endl;
        cout << "Volume: " << volume << endl;
	}
};

class PoliceCar : public Car
{

};


int main()
{
    
}

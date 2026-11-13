#include <iostream>
using namespace std;

class Employer
{
protected:
    string name;
    int income;
    string role;
public:
    Employer() : name(""), income(0), role("") {}
	Employer(string n, int i, string r) : name(n), income(i), role(r) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Income: " << income << endl;
        cout << "Role: " << role << endl;
	}
    void Work()
    {
        cout << name << " is working." << endl;
	}
    void GotSalary()
    {
        cout << name << " got salary: " << income << endl;
    }
    void SetPositions(string n, int i, string r)
    {
        cout << "Enter name: "; cin >> n;
        cin.ignore();
        cout << "Enter income: "; cin >> i;
        cout << "Enter role: "; cin >> r;
    }
};

class President : public Employer
{
protected:
	int bonus;
public:
    President() : Employer(), bonus(0) {}
	President(string n, int i, string r, int b) : Employer(n, i, r), bonus(b) {}
        void Print()
    {
        Employer::Print();
        cout << "Bonus: " << bonus << endl;
    }
    void GotSalary()
    {
        cout << name << " got salary: " << income + bonus << endl;
	}
    virtual void Work()
    {
        cout << name << " is working as a president." << endl;
	}
    void SetPositions(string n, int i, string r, int b)
    {
        Employer::SetPositions(n, i, r);
        cout << "Enter bonus: "; cin >> b;
	}
};

class Manager : public Employer
{
protected:
	string department;
public:
    Manager() : Employer(), department("") {}
    Manager(string n, int i, string r, string d) : Employer(n, i, r), department(d) {}
    void Print()
    {
        Employer::Print();
        cout << "Department: " << department << endl;
    }
    void Work()
    {
        cout << name << " is working as a manager." << endl;
    }
    void SetPositions(string n, int i, string r, string d)
    {
        Employer::SetPositions(n, i, r);
        cout << "Enter department: "; cin >> d;
    }
};

class Worker : public Employer
{
	string task;
public:
    Worker() : Employer(), task("") {}
    Worker(string n, int i, string r, string t) : Employer(n, i, r), task(t) {}
    void Print()
    {
        Employer::Print();
        cout << "Task: " << task << endl;
    }
    void Work()
    {
        cout << name << " is working as a worker." << endl;
    }
    void SetPositions(string n, int i, string r, string t)
    {
        Employer::SetPositions(n, i, r);
        cout << "Enter task: "; cin >> t;
    }
    int FindPrice()
    {
        
	}
};


class Vehicle
{
protected:
    string name;
	int speed;
    int time;
public:
	Vehicle() : name(""), speed(0), time(0) {}
	Vehicle(string n, int s, int p) : name(n), speed(s), time(p) {}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Speed: " << speed << endl;
        cout << "Time: " << time << endl;
    }
    void SetPositions(string n, int s, int p)
    {
        cout << "Enter name: "; cin >> n;
        cin.ignore();
        cout << "Enter speed: "; cin >> s;
        cout << "Enter time: "; cin >> p;
	}
    void Move()
    {
        cout << name << " is moving at speed " << speed << endl;
	}
    void FindPrice()
    {
        int price = speed * time / 100;
        cout << name << " will move for " << time << " hours and cover a distance of " << price << endl;
    }
};

class Car : public Vehicle
{
	int count_passengers;
public:
    Car() : Vehicle(), count_passengers(0) {}
    Car(string n, int s, int p, int c) : Vehicle(n, s, p), count_passengers(c) {}
    void Print()
    {
        Vehicle::Print();
        cout << "Count of passengers: " << count_passengers << endl;
    }
    int SetPositions(string n, int s, int p, int c)
    {
        Vehicle::SetPositions(n, s, p);
        cout << "Enter count of passengers: "; cin >> c;
    }
};

class Bycicle : public Vehicle
{
	int count_wheels;
public:
    Bycicle() : Vehicle(), count_wheels(0) {}
    Bycicle(string n, int s, int p, int c) : Vehicle(n, s, p), count_wheels(c) {}
    void Print()
    {
        Vehicle::Print();
        cout << "Count of wheels: " << count_wheels << endl;
    }
    void SetPositions(string n, int s, int p, int c)
    {
        Vehicle::SetPositions(n, s, p);
        cout << "Enter count of wheels: "; cin >> c;
    }
    int FindPrice()
    {
        int price = speed * time / 100;
        cout << name << " will move for " << time << " hours and cover a distance of " << price << endl;
        return price;
	}
};

class Cart : public Vehicle
{
	int count_wheels;
public:
    Cart() : Vehicle(), count_wheels(0) {}
    Cart(string n, int s, int p, int c) : Vehicle(n, s, p), count_wheels(c) {}
    void Print()
    {
        Vehicle::Print();
        cout << "Count of wheels: " << count_wheels << endl;
    }
    void SetPositions(string n, int s, int p, int c)
    {
        Vehicle::SetPositions(n, s, p);
        cout << "Enter count of wheels: "; cin >> c;
    }
    int FindPrice()
    {
        int price = speed * time / 100;
        cout << name << " will move for " << time << " hours and cover a distance of " << price << endl;
        return price;
    }
};
int main()
{
	cout << "===========Exercise 1===========" << endl;

	cout << "----------Worker----------" << endl;
	Worker worker("John", 3000, "Worker", "Cleaning");
	worker.Print();
	worker.Work();
	cout << endl;

	cout << "----------Manager----------" << endl;
	Manager manager("Alice", 5000, "Manager", "Sales");
	manager.Print();
	manager.Work();
	cout << endl;

	cout << "----------President----------" << endl;
	President president("Bob", 10000, "President", 2000);
	president.Print();
	president.Work();
	cout << endl;

	cout << "===========Exercise 2===========" << endl;

	cout << "----------Car----------" << endl;
	Car car("Toyota", 120, 2, 5);
	car.FindPrice();
	car.Move();
    car.Print();
	cout << endl;

	cout << "----------Bycicle----------" << endl;
	Bycicle bycicle("Canyon", 20, 1, 2);
	bycicle.FindPrice();
    bycicle.Print();
	cout << endl;

	cout << "----------Cart----------" << endl;
	Cart cart("Horse Cart", 10, 3, 4);
	cart.FindPrice();
	cart.Print();

}


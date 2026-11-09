#include <iostream>
using namespace std;

struct Course
{
    string course_name;
    int number_of_course;
};
struct DateBirth
{
    int day;
    int month;
    int year;
};
class Student
{
    string name;
    DateBirth age;
	string gender;
	Course course;
public:
    Student() :name("no name"), age{0,0,0000}, gender("not set"), course{"subject",0} {}
	Student(string n, DateBirth a, string g, Course c) :name(n), age(a), gender(g), course(c) {}
    void PrintStudent()
    {
		cout << "--------------   Student   ----------------" << endl;
        cout << "Name of student: " << name << endl;
        cout << "Date of birth of student: " << age.day << " | " << age.month << " | " << age.year << endl;
        cout << "Gender of student: " << gender << endl;
        cout << "Course subject: " << course.course_name << endl;
        cout << "Number of Course: " << course.number_of_course << endl;
    }
    void EnterStudent()
    {
        cout << "Enter name: ";
        cin >> name;
        cin.ignore();
        cout << "Enter date of birth (day month year): ";
        cin >> age.day >> age.month >> age.year;
        cout << "Enter gender: ";
        cin >> gender;
        cin.ignore();
        cout << "Enter course name: ";
        cin >> course.course_name;
		cin.ignore();
        cout << "Enter number of courses: ";
        cin >> course.number_of_course;
    }

};
class Aspirant : public Student
{
	string research_topic;
    int number_of_pages;
public:
    void PrintAspirant()
    {
		cout << "--------------   Aspirant   ----------------" << endl;
        PrintStudent();
        cout << "Research topic: " << research_topic << endl;
	}
    void EnterAspirant()
    {
        EnterStudent();
        cout << "Enter research topic: ";
        cin >> research_topic;
    }
    void WriteDesirtation()
    {
        cout << "Successfull wrote desertation" << endl;
		number_of_pages++;
    }
    void DefendDesirtation()
    {
        if (number_of_pages > 0)
        {
            cout << "Successfull defended desertation" << endl;
            number_of_pages--;
        }
        else
        {
            cout << "No desertation to defend" << endl;
        }
	}
};

int main()
{
	Student student1;
	student1.EnterStudent();
	student1.PrintStudent();
    
	cout << "--------------   Aspirant   ----------------" << endl;
	Aspirant aspirant1;
	aspirant1.EnterAspirant();
	aspirant1.PrintAspirant();
	cout << "--------------   Desertation   ----------------" << endl;
	aspirant1.WriteDesirtation();
	aspirant1.DefendDesirtation();
}


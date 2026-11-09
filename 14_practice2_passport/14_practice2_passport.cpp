#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};
class Passport
{
	Date date;
    string name;
	string surname;
    string nationality;
    string gender;
    Date date_of_given;
    Date date_of_expiry;
public:
    Passport() :date{ 0, 0, 0000 }, name("no name"), surname("no surname"), nationality("not found"), gender("not set"),date_of_given{0,0,0000}, date_of_expiry{0, 0, 0000} {}
	Passport(string name, string surname, string nationality, string gender,Date date_of_given, Date date_of_expiry) :date{ 0, 0, 0000 }, name(name), surname(surname), nationality(nationality), gender(gender), date_of_given{date_of_given}, date_of_expiry(date_of_expiry) {}
    void EnterData()
    {
        cout << "Enter name: ";
        cin >> name;
        cin.ignore();
        cout << "Enter surname: ";
        cin >> surname;
        cin.ignore();
		cout << "Enter date of birth (day month year): ";
		cin >> date.day >> date.month >> date.year;
        cout << "Enter nationality: ";
        cin >> nationality;
        cin.ignore();
        cout << "Enter gender: ";
        cin >> gender;
        cin.ignore();
		cout << "Enter date of given (day month year): ";
		cin >> date_of_given.day >> date_of_given.month >> date_of_given.year;
        cout << "Enter date of expiry (day month year): ";
        cin >> date_of_expiry.day >> date_of_expiry.month >> date_of_expiry.year;
	}
    void PrintPassport()
    {
        cout << "----------Passport of cityzen--------";
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Date of birth: " << date.day << " | " << date.month << " | " << date.year << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Gender: " << gender << endl;
		cout << "Date of given: " << date_of_given.day << " | " << date_of_given.month << " | " << date_of_given.year << endl;
		cout << "Date of expiry: " << date_of_expiry.day << " | " << date_of_expiry.month << " | " << date_of_expiry.year << endl;
    }
    bool IsActuall()
    {
        if (date_of_expiry.year > date.year || (date_of_expiry.year == date.year && date_of_expiry.month > date.month) || (date_of_expiry.year == date.year && date_of_expiry.month == date.month && date_of_expiry.day >= date.day))
        {
            cout << "Passport is actual" << endl;
			return true;
        }
        else
        {
            cout << "Passport is not actual" << endl;
			return false;
		}
	}
};

class ForeignPassport : public Passport
{
    string visa;
    int number_of_passport;
public:
	ForeignPassport() : Passport(), visa("no visa"), number_of_passport(0) {}
	ForeignPassport(string name, string surname, string nationality, string gender, Date date_of_given, Date date_of_expiry, string visa, int number_of_passport) : Passport(name, surname, nationality, gender, date_of_given, date_of_expiry), visa(visa), number_of_passport(number_of_passport) {}
    void PrintForeignPassport()
    {
		cout << "----------Foreign Passport of cityzen--------" << endl;
        PrintPassport();
        cout << "Visa: " << visa << endl;
        cout << "Number of passport: " << number_of_passport << endl;
	}
    void EnterForeignPassportData()
    {
		cout << "----------Enter data for foreign passport--------" << endl;
        EnterData();
        cout << "Enter visa: ";
        cin >> visa;
        cin.ignore();
        cout << "Enter number of passport: ";
        cin >> number_of_passport;
	}
    void IsActuallForeignPassport()
    {
        IsActuall();
	}


};

int main()
{
	Passport passport1;
	passport1.EnterData();
	passport1.PrintPassport();

	ForeignPassport foreign_passport1;
	foreign_passport1.EnterData();
	foreign_passport1.PrintForeignPassport();

}


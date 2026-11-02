#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct QueueElement
{
    int priority;
    string person;
    void Print()
    {
        cout << person << " : " << priority << "  |  ";
    }
};

class QueuePrinter
{
    QueueElement* elements;
    int count;
public:
    QueuePrinter() : elements(nullptr), count(0) {}
    ~QueuePrinter() {
        delete[] elements;
    }

    bool isEmpty() const {
        return count == 0;
    }
    void Enqueue(string person, int priority) {
        QueueElement* newElements = new QueueElement[count + 1];
        int i = 0;

        while (i < count && elements[i].priority >= priority) {
            newElements[i] = elements[i];
            i++;
        }

        newElements[i].person = person;
        newElements[i].priority = priority;

        for (int j = i; j < count; j++) {
            newElements[j + 1] = elements[j];
        }

        delete[] elements;
        elements = newElements;
        count++;
        cout << "\nSuccessfull addition to printer" << endl;
    }
    void PrintAll()
    {
        if (isEmpty()) 
        {
			cout << "Queue is empty" << endl;
        }

        cout << "==================================" << endl;
		cout << "Printing all elements in the queue:" << endl;
		cout << "==================================" << endl;
		cout << "Queue size: " << count << endl;
		cout << "==================================" << endl;

        if (count == 1)
        {
			delete[] elements;
			elements = nullptr;
        }
        else 
        {
			QueueElement* newElements = new QueueElement[count - 1];
            for (int  i = 0; i < count-1; i++)
            {
                newElements[i] = elements[i + 1];
            }
			delete[] elements;
			elements = newElements;
        }
        count--;
    }
    void Display() const {
        if (isEmpty()) {
            cout << "Current printing queue is empty.\n";
            return;
        }

        cout << "=== CURRENT PRINT QUEUE (by highest priority) ===\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            elements[i].Print();
            cout << "\n";
        }
        cout << "==================================" << endl;
    }
};

void DisplayMenu() {
    cout << "\n=== QUEUE MENU ===\n";
    cout << "1. Add a person to the print queue\n";
    cout << "2. Print all elements in the queue\n";
    cout << "3. Display current print queue\n";
    cout << "0. Exit\n";
    cout << "=========================\n";
}


int main()
{
    QueuePrinter printer;
    int choice;

    do {
        DisplayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string fileName;
            int roleChoice;
            int priority = 1;
            string roleName = "Guest";

            cout << "Enter file name: ";
            getline(cin, fileName);

            cout << "\nSelect your position:\n";
            cout << "1. Guest (priority 1)\n";
            cout << "2. Administrator (priority 2)\n";
            cout << "3. Manager (priority 3)\n";
            cout << "4. Director (priority 4)\n";
            cout << "Your choice: ";
            cin >> roleChoice;
            switch (roleChoice)
            {
            case 1:priority = 0; roleName = "Director";
                break;
            case 2:priority = 1; roleName = "Manager";
                break;
            case 3:priority = 2; roleName = "Administrator";
                break;
            case 4:priority = 3; roleName = "Guest";
                break;
            default:
                cout << "[Error] Invalid choice. Default priority set to (1).\n";
                priority = 3;
                roleName = "Guest";
                break;
            }
            string record = fileName + " [" + roleName + "";
            printer.Enqueue(record, priority);
            break;
        }
        case 2:
            printer.PrintAll();
            break;
        case 3:
            printer.Display();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "[Error] Invalid menu option. Please try again.\n";
            break;
        }

        if (choice != 0) {
            cout << "\nPress any key to continue...";
            _getch();
            system("cls");
        }

    } while (choice != 0);
}
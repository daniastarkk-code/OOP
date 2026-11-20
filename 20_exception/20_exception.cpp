#include <iostream>
using namespace std;

class List
{
private:
    int size;
    int* arr;
public:
    int GetElementByPos(int pos)
    {
        if (size == 0)return 1;

        if (pos < 0 || pos > size)return 0; cout << "no element";

        return rand() % 10;
    }
};

float Divide(float a, float b)
{
    float res = 0;
    if (b == 0) {
        throw exception("Cant divide by zero!");
    }
    else {
        res = a / b;
        cout << "Result : " << res << endl;
        return res;
    }
}

class PasswordInvalidException : public exception
{
public:
    PasswordInvalidException(const char* message) : exception(message) {}
};

class SmallPasswordException : public exception
{
    SmallPasswordException() {}
};

void ValidateLogin(const char* login, const char* password)
{
    if (strlen(password) < 6)
        throw exception("To small password");
    if (!islower(password[0] or !isalpha(password[0])))
        throw exception("Incorrect pasword");
    if (!isupper(login[0] or !isalpha(login[0])))
        throw exception("Incorrect login");

    cout << "Loading.........." << endl;
}

class MyArray
{
    int* arr;
    int size;
public:
    MyArray(int size = 20) :size(size) { arr = new int[size]; }
    void Print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }cout << endl;
    }
    int getElement(int index)
    {
        if (index >= 0 and index < size)
            return arr[index];
        else
            throw out_of_range("Index is less than 0 or more than size");
    }
    void CheckLenth(int len)
    {
        if (len < 0)
        {
            throw length_error("Some length error");
        }
        cout << "Length is valid" << endl;
    }
    void SetSize(int newSize)
    {
        if (newSize < 0)
            throw invalid_argument("Mew size is less than 0");
        else
        {
            int* temp = new int[newSize];
            for (int i = 0; i < size and i < newSize; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            size = newSize;
        }

    }
};

int main()
{
    MyArray arr(10);
    arr.Print();

    try
    {
        arr.getElement(100);
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    /*char login[100];
    char password[100];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter login : "; cin >> login;
        cout << "Enter password : "; cin >> password;
    }*/
  /*  float a, b;
    cout << "Enter numbers : ";
    cin >> a >> b;
    try
    {
        float res = Divide(a, b);
        cout << "Result in main : " << res << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknpen exception" << endl;
    }*/
}

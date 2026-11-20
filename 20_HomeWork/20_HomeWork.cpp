#include <iostream>

using namespace std;

class List
{
    struct Node
    {
        Node* prev;
        int value;
        Node* next;
        Node() : prev(nullptr), value(0), next(nullptr) {}
        Node(Node* p, int v, Node* n) : prev(p), value(v), next(n) {}
    };

private:
    Node* head;
    Node* tail;
    int size;

    Node* GetNodeAt(int index) const
    {
        if (index < 0 || index >= size)
            throw out_of_range("Incorrect position");

        Node* current;
        if (index < size / 2)
        {
            current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
        }
        else
        {
            current = tail;
            for (int i = size - 1; i > index; i--)
                current = current->prev;
        }
        return current;
    }

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    int GetSize() const
    {
        return size;
    }

    void AddToHead(int value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
        size++;
    }

    void DeleteFromHead()
    {
        if (IsEmpty())
            throw out_of_range("List is empty");

        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
        size--;
    }

    void AddToTail(int value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
            head = newNode;
        size++;
    }

    void DeleteFromTail()
    {
        if (IsEmpty())
            throw out_of_range("List is empty");

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
        size--;
    }

    int GetAt(int index) const
    {
        return GetNodeAt(index)->value;
    }

    void InsertAt(int index, int value)
    {
        if (index < 0 || index > size)
            throw out_of_range("Incorrect position to add");

        if (index == 0)
        {
            AddToHead(value);
            return;
        }
        if (index == size)
        {
            AddToTail(value);
            return;
        }

        Node* current = GetNodeAt(index);
        Node* newNode = new Node(current->prev, value, current);
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    void DeleteAt(int index)
    {
        if (IsEmpty())
            throw out_of_range("List is empty");
        if (index < 0 || index >= size)
            throw out_of_range("Incorrect position to delete");

        if (index == 0)
        {
            DeleteFromHead();
            return;
        }
        if (index == size - 1)
        {
            DeleteFromTail();
            return;
        }

        Node* target = GetNodeAt(index);
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
        size--;
    }

    void Print() const
    {
        if (IsEmpty())
            throw runtime_error("List is empty");

        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List()
    {
        try
        {
            while (!IsEmpty())
                DeleteFromHead();
        }
        catch (...)
        {
            cout << " Unknown exception" << endl;
        }
    }
};

int main()
{
    List l;

    try
    {
        l.DeleteFromHead();
        l.AddToHead(5);
        l.AddToTail(2);
        l.DeleteFromTail();
        l.DeleteAt(4);
        l.InsertAt(6, 2);
    }
    catch (runtime_error ex)
    {
        cout << ex.what() << endl;
    }

    try
    {
        for (int i = 0; i < 10; i++)
        {
            l.AddToHead(i);
        }
        l.Print();

        cout <<  l.GetAt(3) << endl;
        l.InsertAt(2, 999);
        l.Print();

        l.DeleteAt(50);
    }
    catch (out_of_range ex)
    {
        cout <<  ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error";
    }


}
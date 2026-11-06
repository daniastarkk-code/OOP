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
public:
    List()
    {
		head = tail = nullptr;
    }
    bool IsEmpty()
    {
        return head == nullptr;
	}
    void AddToHead(int value)
    {
        Node* newNode = new Node(nullptr, value, head);
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
			tail = newNode;
    }
    void DeleteFromHead()
    {
        if (head == nullptr)
            return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
	}
    void AddToTail(int value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
            head = newNode;
	}
    void DeleteFromTail()
    {
        if (tail == nullptr)
            return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }
    void Print()
    {
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
        while (head != nullptr)
            DeleteFromHead();
	}
};
int main()
{
    List l;
    for (int i = 0; i < 10; i++)
    {
        l.AddToHead(i);
    }l.Print();
}

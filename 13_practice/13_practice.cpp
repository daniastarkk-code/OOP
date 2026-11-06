#include <iostream>
using namespace std;

template <typename T>


class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node() : prev(nullptr), value(0), next(nullptr) {}
        Node(Node* p, T v, Node* n) : prev(p), value(v), next(n) {}
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
    void AddToHead(T value)
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
    void AddToTail(T value)
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

struct Vagon
{
    int count_sits;
    int Number_of_vagon;
    int count_of_passengers;
    friend ostream& operator<<(ostream& os, const Vagon& v) {
        os << v.Number_of_vagon;
        return os;
    }
};
class Train
{

    string model;
    List<Vagon> vagons;
	int count_vagons;
public:
    Train() :model("no model"), count_vagons( 0 ) {}
    Train(string model, int count_vagons) :model(model), count_vagons(count_vagons) {}
    void Print()
    {
        cout << "Model: " << model << endl;
        cout << "Count of vagons: " << count_vagons << endl;
        vagons.Print();
	}
    void AddVagonToHeadOfTrain(int count_sits, int Number_of_vagon, int count_of_passengers)
    {
        Vagon newVagon = { count_sits, Number_of_vagon, count_of_passengers };
        vagons.AddToHead(newVagon);
        count_vagons++;
	}
    void DeleteVagonFromHeadOfTrain()
    {
        vagons.DeleteFromHead();
        count_vagons--;
    }
    void AddVagonToTailOfTrain(int count_sits, int Number_of_vagon, int count_of_passengers)
    {
        Vagon newVagon = { count_sits, Number_of_vagon, count_of_passengers };
        vagons.AddToTail(newVagon);
        count_vagons++;
    }
    void DeleteVagonFromTailOfTrain()
    {
        vagons.DeleteFromTail();
        count_vagons--;
	}
};

int main()
{
	cout << "Train stantion Rivne:" << endl;
    Train train("Denis Expresso z molokom", 0);
	train.AddVagonToHeadOfTrain(100, 1, 50);
	train.AddVagonToTailOfTrain(120, 2, 80);
	train.AddVagonToHeadOfTrain(90, 3, 60);
	train.Print();

    Train train1("Vasiliy cargo train", 0);
	train1 = train;
    train1.Print();

	train1.DeleteVagonFromHeadOfTrain();
    train1.Print();
	train1.DeleteVagonFromTailOfTrain();
	train1.Print();
}

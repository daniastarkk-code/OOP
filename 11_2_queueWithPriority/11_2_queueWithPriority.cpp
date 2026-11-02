#include <iostream>
using namespace std;


struct Element
{
    char letter;
    int priority;
    void Print()const
    {
        cout << letter << " : " << priority << " ";
	}
};
class QueueWithPriority
{
	Element* elements;
    int count; 
public:
	QueueWithPriority() :elements(nullptr), count(0) {}
    ~QueueWithPriority()
    {
		if (elements != nullptr)delete[] elements;
    }
    void Enqueue(Element el)
    {
        int index = 0;
        while (index < count && elements[index].priority < el.priority)index++;
        Element* temp = new Element[count + 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }
		temp[index] = el;
        for (int i = index+1; i < count; i++)
        {
            temp[i + 1] = elements[i];
        }
		if (elements != nullptr)delete[] elements;
        count++;
    }
    bool IsEmpty()const
            {
        return count == 0;
	}
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = elements[0];
            for (int i = 0; i < count; i++)
            {
                elements[i] = elements[i + 1];
            }
            count--;
            return first;
        }
    }
    void Print()
    {
		cout << "-----------------------Queue-----------------------" << endl;
        for (int  i = 0; i < count; i++)
        {
            elements[i].Print();
        }
    }
};
int main()
{
    QueueWithPriority q;
	Element el = { 'A', 1 };
	q.Enqueue(el);
    q.Enqueue(Element{'B',2});
    q.Enqueue(Element{ 'C',3 });
    q.Enqueue(Element{ 'D',4 });
    q.Enqueue(Element{ 'E',5 });
    q.Enqueue(Element{ 'F',6 });
    q.Enqueue(Element{ 'G',7 });
    q.Enqueue(Element{ 'H',8 });
	q.Print();

    while (!q.IsEmpty())
    {
		cout << "delete element: ";
        q.Dequeue().Print();
        cout << endl;
    }
}

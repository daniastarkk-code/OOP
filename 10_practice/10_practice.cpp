#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    size_t Size;
    size_t topIndex;

    void resize(size_t newSize) {
        T* newData = new T[newSize];
        for (size_t i = 0; i < topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        Size = newSize;
    }

public:
    explicit Stack(size_t initialSize = 10) : Size(initialSize), topIndex(0) {
        if (Size == 0) Size = 1;
        data = new T[Size];
    }

    Stack(size_t initialSize, initializer_list<T> initList) {
        Size = (initialSize > initList.size()) ? initialSize : initList.size();
        if (Size == 0) Size = 1;
        data = new T[Size];
        topIndex = 0;
        for (const auto& item : initList) {
            data[topIndex++] = item;
        }
    }

    Stack(initializer_list<T> initList) {
        Size = (10 > initList.size()) ? 10 : initList.size();
        data = new T[Size];
        topIndex = 0;
        for (const auto& item : initList) {
            data[topIndex++] = item;
        }
    }

    ~Stack() {
        delete[] data;
    }

    Stack(const Stack& other) : Size(other.Size), topIndex(other.topIndex) {
        data = new T[Size];
        for (size_t i = 0; i < topIndex; ++i) {
            data[i] = other.data[i];
        }
    }

    bool isFull() const {
        return topIndex == Size;
    }

    bool isEmpty() const {
        return topIndex == 0;
    }

    size_t size() const {
        return topIndex;
    }

    size_t getSize() const {
        return Size;
    }

    void Push(const T& value) {
        if (isFull()) {
            resize(Size * 2);
        }
        data[topIndex++] = value;
    }

    void Pop() {
        if (isEmpty()) {
            cout << "Error!!! Your stack is empty" << endl;
            return;
        }
        --topIndex;
    }

    T& peek() {
        if (isEmpty()) {
            cout << "Error!!! Your stack is empty" << endl;
            static T bodik{};
            return bodik;
        }
        return data[topIndex - 1];
    }

    const T& peek() const {
        if (isEmpty()) {
            cout << "Error: stack is empty!\n";
            static T dummy{};
            return dummy;
        }
        return data[topIndex - 1];
    }

    void print() const {
        cout << "Stack : ";
        for (size_t i = 0; i < topIndex; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<char> charStack(5);
    charStack.Push('A');
    charStack.Push('B');
    charStack.Push('C');
    charStack.Push('D');
    charStack.Push('E');
    charStack.Push('F');

    cout << "Size : " << charStack.size() << endl;
    cout << "Top element: " << charStack.peek() << endl;
    charStack.Pop();
    cout << "After pop: ";
    charStack.print();

    Stack<int> intStack(2, { 10, 20, 30 });
    intStack.print();
    cout << "intStack size : " << intStack.size() << endl;
    cout << "Size : " << intStack.getSize() << endl;
    cout << "Top element : " << intStack.peek() << endl;

}
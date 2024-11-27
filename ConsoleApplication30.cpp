#include <iostream>
#include <list>

using namespace std;

class Stack {
private:
    list<int> data;

public:

    void Push(int value) {
        data.push_back(value);
    }

    // Удаление элемента из стека
    void Pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    // Метод Contains
    bool Contains(int value) const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == value) {
                return true;
            }
        }
        return false;
    }

    // Метод Print
    void Print() const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }

    // Метод PushLessValue
    void PushLessValue(int value) {
        if (data.empty() || value < data.back()) {
            data.push_back(value); // Добавляем только если стек пустой или значение меньше верхнего
        }
    }

    // Метод PushUnique
    void PushUnique(int value) {
        if (!Contains(value)) {
            data.push_back(value); // Добавляем только если значение отсутствует в стеке
        }
    }
};

int main() {
    Stack stack;

    stack.Push(5);
    stack.Push(10);
    stack.Push(15);

    cout << "Stack contains 10: " << (stack.Contains(10) ? "true" : "false") << "\n";

    cout << "Stack elements: ";
    stack.Print();

    cout << "Adding 7 (PushLessValue):\n";
    stack.PushLessValue(7);
    stack.Print();

    cout << "Adding 10 (PushUnique):\n";
    stack.PushUnique(10);
    stack.Print();

    cout << "Adding 3 (PushUnique):\n";
    stack.PushUnique(3);
    stack.Print();

}

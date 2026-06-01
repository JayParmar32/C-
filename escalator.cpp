#include <iostream>
using namespace std;

template <class T>

class Stack {
    int top;
    T arr[5];

public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 4) {
            cout << "Stack Overflow\n";
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top] << " popped from stack\n";
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Stack Elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Stack<int> s1;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    // User input values
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        s1.push(value);
    }

    // Display stack
    s1.display();

    // Pop one element
    s1.pop();

    // Display after pop
    s1.display();

    return 0;
}
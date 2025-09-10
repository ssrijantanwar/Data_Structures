#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek() {
        if (!isEmpty())
            cout << "Top element is " << arr[top] << endl;
        else
            cout << "Stack is empty\n";
    }

    bool isEmpty() { return (top < 0); }
    bool isFull() { return (top >= MAX - 1); }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack st;
    int choice, val;

    do {
        cout << "\n*** MENU ***\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; st.push(val); break;
            case 2: st.pop(); break;
            case 3: st.peek(); break;
            case 4: st.display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}


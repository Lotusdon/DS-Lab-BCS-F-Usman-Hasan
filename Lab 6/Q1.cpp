#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow! Cannot push " << element << endl;
            return;
        }
        arr[++top] = element;
        cout << "Pushed " << element << " to stack." << endl;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        int popped = arr[top--];
        cout << "Popped " << popped << " from stack." << endl;
        return popped;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;
        }
        cout << "Top element is " << arr[top] << endl;
        return arr[top];
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents from bottom to top:" << endl;
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();

    s.display();

    return 0;
}

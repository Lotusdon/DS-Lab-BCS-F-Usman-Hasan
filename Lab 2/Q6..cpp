#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    SafePointer() {
        ptr = new int;
    }

    ~SafePointer() {
        delete ptr;
    }

    void setValue(int val) {
        *ptr = val;
    }

    int getValue() {
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }
};

int main() {
    int n = 5;
    SafePointer* students = new SafePointer[n];

    cout << "Enter marks " << endl;
    for (int i = 0; i < n; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        students[i].setValue(mark);
    }

    cout << endl << " Marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }

    for (int i = 0; i < n; i++) {
        students[i].release();
    }

    delete[] students;
    return 0;
}

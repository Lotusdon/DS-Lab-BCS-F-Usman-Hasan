#include <iostream>
using namespace std;

class Box {
private:
    int* data;

public:
    
    Box(int val = 0) {
        data = new int(val);
    }

    
    ~Box() {
        delete data;
    }

    
    Box(const Box& b1) {
        data = new int(*b1.data);  
    }

    
    Box& operator=(const Box& b1) {
        if (this != &b1) {
            delete data;
            data = new int(*b1.data);
        }
        return *this;
    }

    
    void setValue(int val) {
        *data = val;
    }

    
    int getValue() const {
        return *data;
    }
};

int main() {
    Box b1(120);
    cout << "b1 value: " << b1.getValue() << endl;

    
    Box b2 = b1;
    cout << "b2 value: " << b2.getValue() << endl;

    b2.setValue(220);
    cout << "\n";
    
    cout << "Updated b2 value: " << b2.getValue() << endl;
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "\n";

    
    Box b3;
    b3 = b1;
    cout << "b3 value : " << b3.getValue() << endl;

    b3.setValue(320);
    cout << "\n";
    
    
    cout << "Updated b3 value: " << b3.getValue() << endl;
    cout << "b1 value: " << b1.getValue() << endl;

    return 0;
}

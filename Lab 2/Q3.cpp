#include <iostream>
using namespace std;

int main() {
    int nums;
    
    cout << "enter number of students:" << endl;
    cin >> nums;
    
    int* index = new int[nums];
    int** marks = new int*[nums];
    
    for(int i = 0; i < nums; i++) {
        cout << "enter number of courses for student " << i + 1 << ":" << endl;
        cin >> index[i];
        
        marks[i] = new int[index[i]];
        
        for(int j = 0; j < index[i]; j++) {
            cout << "enter marks for student " << i + 1 << ", course " << j + 1 << ":" << endl;
            cin >> marks[i][j];
        }
    }
    
    cout << "Printing marks array:" << endl;
    for(int i = 0; i < nums; i++) {
        cout << "Student " << i + 1 << ": ";
        for(int j = 0; j < index[i]; j++) {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < nums; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] index;
    
    return 0;
}


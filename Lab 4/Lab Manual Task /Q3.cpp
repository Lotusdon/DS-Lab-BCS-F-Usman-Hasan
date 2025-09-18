#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < 9; i++) {
        int id = i;
        for(int j = i + 1; j < 10; j++) {
            if(arr[j] < arr[id]) {
                id = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[id];
        arr[id] = temp;
    }
    
    cout << "sorted array: ";
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

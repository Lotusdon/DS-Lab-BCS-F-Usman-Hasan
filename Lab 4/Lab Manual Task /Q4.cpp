#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[5];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    cout << "sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int target;
    cout << "enter value: ";
    cin >> target;
    
    int l = 0, r = n - 1, id = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] == target) {
            id = mid;
            break;
        }
        else if(arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    if(id != -1) {
        cout << "value foud " << id << endl;
    }
    else {
        cout << "value not found" << endl;
    }
    
    return 0;
}

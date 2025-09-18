#include <iostream>
using namespace std;

int main() {
    int n = 10, target, pos = -1;
    int arr[10];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "enter value: ";
    cin >> target;
    
    int l = 0, r = n - 1;
    while(l <= r && target >= arr[l] && target <= arr[r]) {
        if(l == r) {
            if(arr[l] == target) pos = l;
            break;
        }
        int mid = l + ((target - arr[l]) * (r - l)) / (arr[r] - arr[l]);
        if(arr[mid] == target) {
            pos = mid;
            break;
        }
        else if(arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    if(pos == -1) {
        cout << "value not found";
    }
    else {
        cout << "value found at index: " << pos;
    }
    
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int arr[10];
    int swaps = 0, comps = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int gap = n;
    bool done = false;
    
    while(gap > 1 || done == true) {
        gap = (gap * 10) / 13;
        if(gap < 1) gap = 1;
        
        done = false;
        
        for(int i = 0; i + gap < n; i++) {
            comps++;
            if(arr[i] > arr[i + gap]) {
                int t = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = t;
                swaps++;
                done = true;
            }
        }
    }
    
    cout << endl;
    
    cout << "total comparisons: " << comps << endl;
    cout << "total swaps: " << swaps << endl;
    
    return 0;
}

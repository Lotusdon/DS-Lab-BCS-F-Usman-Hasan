#include <iostream>
using namespace std;

void bubblesort(int arr[], int n, int &comps, int &swaps) {
    comps = swaps = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            comps++;
            if(arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                swaps++;
            }
        }
    }
}

void insertionsort(int arr[], int n, int &comps, int &swaps) {
    comps = swaps = 0;
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0) {
            comps++;
            if(arr[j] > key) {
                arr[j+1] = arr[j];
                swaps++;
                j--;
            } else break;
        }
        arr[j+1] = key;
    }
}

void shellsort(int arr[], int n, int &comps, int &swaps) {
    comps = swaps = 0;
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int t = arr[i];
            int j = i;
            while(j >= gap) {
                comps++;
                if(arr[j-gap] > t) {
                    arr[j] = arr[j-gap];
                    swaps++;
                    j -= gap;
                } else break;
            }
            arr[j] = t;
        }
    }
}

void copyarray(int src[], int dest[], int n) {
    for(int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;
    int arr[10000];
    
    cout << "enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int comps, swaps;
    int temp[10000];

    copyarray(arr, temp, n);
    bubblesort(temp, n, comps, swaps);
    cout << "bubble sort -> comps: " << comps << ", swaps: " << swaps << endl;

    copyarray(arr, temp, n);
    insertionsort(temp, n, comps, swaps);
    cout << "insertion sort -> comps: " << comps << ", swaps: " << swaps << endl;

    copyarray(arr, temp, n);
    shellsort(temp, n, comps, swaps);
    cout << "shell sort -> comps: " << comps << ", swaps: " << swaps << endl;

    return 0;
}

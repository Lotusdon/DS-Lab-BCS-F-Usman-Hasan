#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int capacity;
    int heapsize;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

public:

    MaxHeap(int c) {
        capacity = c;
        arr = new int[c];
        heapsize = 0;
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void heapifydown(int i) {

        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heapsize && arr[l] > arr[largest])
            largest = l;

        if (r < heapsize && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            int t = arr[i];
            arr[i] = arr[largest];
            arr[largest] = t;

            heapifydown(largest);
        }
    }

    void heapifyup(int i) {

        while (i != 0 && arr[parent(i)] < arr[i]) {

            int t = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = t;

            i = parent(i);
        }
    }

    bool isempty() const {
        return heapsize == 0;
    }

    bool isfull() const {
        return heapsize == capacity;
    }

    void insert(int key) {
        if (isfull()) {
            cout << "heap overflow" << endl;
            return;
        }

        int i = heapsize;
        arr[i] = key;
        heapsize++;

        heapifyup(i);
    }

    void print() {
        for (int i = 0; i < heapsize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void deleteat(int i) {
        if (i < 0 || i >= heapsize) {
            cout << "invalid index" << endl;
            return;
        }

        arr[i] = arr[heapsize - 1];
        heapsize--;

        heapifydown(i);
        heapifyup(i);
    }

    int extractmax() {
        if (heapsize <= 0)
            return -1;

        int root = arr[0];

        arr[0] = arr[heapsize - 1];
        heapsize--;

        heapifydown(0);

        return root;
    }
};

int kthlargest(int arr[], int n, int k) {

    MaxHeap heap(n);

    for (int i = 0; i < n; i++) {
        heap.insert(arr[i]);
    }

    int ans = -1;

    for (int i = 0; i < k; i++) {
        ans = heap.extractmax();
    }

    return ans;
}

int main() {

    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    cout << "3rd largest: " << kthlargest(arr1, 7, 3) << endl;

    int arr2[] = {12, 3, 5, 7, 19};
    cout << "2nd largest: " << kthlargest(arr2, 5, 2) << endl;

    return 0;
}

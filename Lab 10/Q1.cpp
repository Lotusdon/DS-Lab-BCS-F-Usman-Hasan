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
        return (2 * i) + 1; 
    }

    int right(int i) { 
        return (2 * i) + 2; 
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
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapifydown(largest);
        }
    }

    void heapifyup(int i) {
        while (i != 0 && arr[parent(i)] < arr[i]) {

            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;

            i = parent(i);
        }
    }

    bool isempty() const { 
        return heapsize == 0; 
    }

    bool isfull() const { 
        return heapsize == capacity; 
    }

    void insert_key(int key) {
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
        for (int i = 0; i < heapsize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void delete_at(int i) {
        if (i < 0 || i >= heapsize) {
            cout << "invalid index" << endl;
            return;
        }

        arr[i] = arr[heapsize - 1];
        heapsize--;

        heapifydown(i);
        heapifyup(i);
    }

    void update_key(int i, int newval) {
        if (i < 0 || i >= heapsize) {
            cout << "invalid index" << endl;
            return;
        }

        arr[i] = newval;

        heapifydown(i);
        heapifyup(i);
    }
};

int main() {

    MaxHeap heap(100);

    heap.insert_key(4);
    heap.insert_key(5);
    heap.insert_key(6);
    heap.insert_key(7);
    heap.insert_key(8);

    heap.print();

    heap.update_key(2, 9);

    heap.print();

    return 0;
}

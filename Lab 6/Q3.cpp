#include <iostream>
using namespace std;

#define max_size 100

class queue {
private:
 int arr[max_size];
 int front;
 int rear;

public:
 queue() {
  front = -1;
  rear = -1;
 }

 bool is_empty() {
  return front == -1 || front > rear;
 }

 bool is_full() {
  return rear == max_size - 1;
 }

 void enqueue(int element) {
  if (is_full()) {
   cout << "queue overflow! cannot enqueue " << element << endl;
   return;
  }
  if (front == -1) front = 0;
  arr[++rear] = element;
  cout << "enqueued " << element << " to queue." << endl;
 }

 int dequeue() {
  if (is_empty()) {
   cout << "queue underflow! cannot dequeue." << endl;
   return -1;
  }
  int removed = arr[front++];
  cout << "dequeued " << removed << " from queue." << endl;
  if (front > rear) front = rear = -1;
  return removed;
 }

 void display() {
  if (is_empty()) {
   cout << "queue is empty." << endl;
   return;
  }
  cout << "queue contents from front to rear:" << endl;
  for (int i = front; i <= rear; i++) {
   cout << arr[i] << " ";
  }
  cout << endl;
 }
};

int main() {
 queue q;

 q.enqueue(10);
 q.enqueue(20);
 q.enqueue(30);

 q.display();

 q.dequeue();

 q.display();

 q.dequeue();
 q.dequeue();

 q.display();

 return 0;
}

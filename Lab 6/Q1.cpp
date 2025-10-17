#include <iostream>
using namespace std;

#define max_size 100

class stack {
private:
 int arr[max_size];
 int top;

public:
 stack() {
  top = -1;
 }

 void push(int element) {
  if (top >= max_size - 1) {
   cout << "stack overflow! cannot push " << element << endl;
   return;
  }
  arr[++top] = element;
  cout << "pushed " << element << " to stack." << endl;
 }

 int pop() {
  if (top < 0) {
   cout << "stack underflow! cannot pop." << endl;
   return -1;
  }
  int popped = arr[top--];
  cout << "popped " << popped << " from stack." << endl;
  return popped;
 }

 int peek() {
  if (top < 0) {
   cout << "stack is empty. nothing to peek." << endl;
   return -1;
  }
  cout << "top element is " << arr[top] << endl;
  return arr[top];
 }

 void display() {
  if (top < 0) {
   cout << "stack is empty." << endl;
   return;
  }
  cout << "stack contents from bottom to top:" << endl;
  for (int i = 0; i <= top; i++) {
   cout << arr[i] << " ";
  }
  cout << endl;
 }
};

int main() {
 stack s;

 s.push(10);
 s.push(20);
 s.push(30);

 s.display();

 s.peek();

 s.pop();

 s.display();

 return 0;
}

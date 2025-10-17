#include <iostream>
using namespace std;

class node {
public:
 int data;
 node* next;
};

class stack {
private:
 node* top;

public:
 stack() {
  top = nullptr;
 }

 void push(int element) {
  node* temp = new node();
  temp->data = element;
  temp->next = top;
  top = temp;
  cout << "pushed " << element << " to stack." << endl;
 }

 int pop() {
  if (top == nullptr) {
   cout << "stack underflow! cannot pop." << endl;
   return -1;
  }
  int popped = top->data;
  node* temp = top;
  top = top->next;
  delete temp;
  cout << "popped " << popped << " from stack." << endl;
  return popped;
 }

 int peek() {
  if (top == nullptr) {
   cout << "stack is empty. nothing to peek." << endl;
   return -1;
  }
  cout << "top element is " << top->data << endl;
  return top->data;
 }

 void display() {
  if (top == nullptr) {
   cout << "stack is empty." << endl;
   return;
  }
  cout << "stack contents from top to bottom:" << endl;
  node* temp = top;
  while (temp != nullptr) {
   cout << temp->data << " ";
   temp = temp->next;
  }
  cout << endl;
 }
};

int main() {
 stack history;

 history.push(1);
 history.push(2);
 history.push(3);

 history.display();

 history.peek();

 history.pop();
 history.display();

 history.pop();
 history.display();

 return 0;
}

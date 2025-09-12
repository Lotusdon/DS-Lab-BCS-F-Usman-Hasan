#include <iostream>
using namespace std;

int main() {
 int n, target, idx=-1;
 cout << "enter size of array: ";
 cin >> n;

 int arr[n];
 cout << "enter " << n << " elements: ";
 for(int i=0;i<n;i++) {
  cin >> arr[i];
 }

 cout << "enter target value: ";
 cin >> target;

 for(int i=0;i<n;i++) {
  if(arr[i]==target) {
   idx=i;
   break;
  }
 }

 if(idx==-1) {
  cout << "value not found";
 } else {
  cout << "value found at index " << idx;
 }

 return 0;
}

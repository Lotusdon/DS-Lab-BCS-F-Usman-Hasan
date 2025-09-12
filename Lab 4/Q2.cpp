#include <iostream>
using namespace std;

int main() {
 int n, roll, val, pos=-1;
 cout << "enter size of array: ";
 cin >> n;

 int arr[n];
 cout << "enter " << n << " employee ids : ";
 for(int i=0;i<n;i++) {
  cin >> arr[i];
 }

 cout << "enter your roll number: ";
 cin >> roll;
 val = roll % 100;

 int l=0, r=n-1;
 while(l<=r) {
  int mid=(l+r)/2;
  if(arr[mid]==val) {
   pos=mid;
   break;
  } else if(arr[mid]<val) {
   l=mid+1;
  } else {
   r=mid-1;
  }
 }

 if(pos==-1) {
  for(int i=n;i>l;i--) {
   arr[i]=arr[i-1];
  }
  arr[l]=val;
  n++;
  pos=l;
  cout << "value not found, inserted at index " << pos << endl;
 } else {
  cout << "value found at index " << pos << endl;
 }

 cout << "final array: ";
 for(int i=0;i<n;i++) {
  cout << arr[i] << " ";
 }

 return 0;
}

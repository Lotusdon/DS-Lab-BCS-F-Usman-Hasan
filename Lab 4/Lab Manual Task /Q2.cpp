#include <iostream>
using namespace std;

int main() {
 int n=10;
 int arr[n];
 for (int i=0;i<n;i++) {
     cout<< "enter value at index "<<i+1<<": ";
     cin>> arr[i];
 }
 cout << "unsorted array: ";
 for(int i=0;i<n;i++) {
  cout << arr[i] << " ";
 }
 cout<<endl;
 for(int i=0;i<n-1;i++) {
  for(int j=0;j<n-i-1;j++) {
   if(arr[j]>arr[j+1]) {
    int temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }

 cout << "sorted array: ";
 for(int i=0;i<n;i++) {
  cout << arr[i] << " ";
 }

 return 0;
}

#include <iostream>
using namespace std;

int main() {
 int n=10;
 int arr[10]={5,1,3,6,2,9,7,4,8,10};

 for(int i=0;i<n-1;i++) {
  for(int j=0;j<n-i-1;j++) {
   if(arr[j]<arr[j+1]) {
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

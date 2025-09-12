#include <iostream>
using namespace std;

int main() {
 int n, target, pos=-1;
 cout << "enter size of array: ";
 cin >> n;

 int arr[n];
 cout << "enter " << n << " values: ";
 for(int i=0;i<n;i++) {
  cin >> arr[i];
 }

 bool sorted=true;
 for(int i=1;i<n;i++) {
  if(arr[i]<arr[i-1]) {
   sorted=false;
   break;
  }
 }

 if(sorted==false) {
  for(int i=0;i<n-1;i++) {
   for(int j=0;j<n-i-1;j++) {
    if(arr[j]>arr[j+1]) {
     int temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
    }
   }
  }
  cout << "array sorted automatically" << endl;
 }

 cout << "enter target value: ";
 cin >> target;

 int l=0, r=n-1;
 while(l<=r && target>=arr[l] && target<=arr[r]) {
  if(l==r) {
   if(arr[l]==target) pos=l;
   break;
  }
  int mid=l+((target-arr[l])*(r-l))/(arr[r]-arr[l]);
  if(arr[mid]==target) {
   pos=mid;
   break;
  } else if(arr[mid]<target) {
   l=mid+1;
  } else {
   r=mid-1;
  }
 }

 if(pos==-1) {
  cout << "value not found";
 } else {
  cout << "value found at index " << pos;
 }

 return 0;
}

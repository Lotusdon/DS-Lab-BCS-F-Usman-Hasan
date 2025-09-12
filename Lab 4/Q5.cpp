#include <iostream>
#include <string>
using namespace std;

int getsort(string word) {
 if(word=="CEO") return 1;
 if(word=="CTO") return 2;
 if(word=="CFO") return 3;
 if(word=="VP") return 4;
 if(word=="MGR") return 5;
 return 6;
}

int main() {
 int n=8;
 string arr[8]={"EMP","CFO","MGR","EMP","VP","CTO","MGR","CEO"};

 for(int i=1;i<n;i++) {
  string key=arr[i];
  int j=i-1;
  while(j>=0 && getsort(arr[j])>getsort(key)) {
   arr[j+1]=arr[j];
   j--;
  }
  arr[j+1]=key;
 }

 cout << "sorted order: ";
 for(int i=0;i<n;i++) {
  cout << arr[i] << " ";
 }

 return 0;
}

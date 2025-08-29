#include <iostream>
using namespace std;
void update(int *arr,int i,int v) {
	arr[i]=v;
	cout<<"value updated"<<endl;
}
int main() {
	int size,index,val;
	
	cout<<"enter array size:"<<endl;
	cin>>size;
	
	int* arr=new int[size];
	
	for(int i=0;i<size;i++) {
		arr[i]=0;
	}
	
	cout<<"enter element to update"<<endl;
	cin>>index;
	cout<<"enter value to replace"<<endl;
	cin>>val;
	
	update(arr,index,val);
	
	for(int y=0;y<size;y++) {
		cout<<y<<" "<<arr[y]<<endl;
	}
	
	
		delete[]arr;
	
}


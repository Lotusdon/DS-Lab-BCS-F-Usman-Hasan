#include <iostream>
using namespace std;

class safepointer {
private:
	int *p;
	
public:
	safepointer() {
		p=new int;
	}
	
	~safepointer() {
		delete p;
	}
	
	void setval(int v) {
		*p=v;
	}
	
	int getval() {
		return *p;
	}
	
	void release() {
		delete p;
		p=nullptr;
	}
};

int main() {
	int n=5;
	safepointer *arr=new safepointer[n];
	
	cout<<"enter marks"<<endl;
	for(int i=0;i<n;i++){
		int m;
		cout<<"student "<<i+1<<": ";
		cin>>m;
		arr[i].setval(m);
	}
	
	cout<<"marks:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"student "<<i+1<<": "<<arr[i].getval()<<endl;
	}
	
	for(int i=0;i<n;i++){
		arr[i].release();
	}
	
	delete[] arr;
}

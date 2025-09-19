#include <iostream>
using namespace std;

int mul2(int n);
int mul1(int n) {
	if (n==0) {
		
		return 1;
	}
	else {
		
		return n-mul1(n-1)+mul2(n-1);
	}
}

int mul2(int n) {
	if (n==0) {
		
		return 1;
	}
	else {
		
		return n+mul1(n-1)+mul2(n-1);
	}
}
int main() {
	int n;
	cout<<"enter number: ";
	cin>>n;
	cout<<"output:"<<mul1(n)<<endl;
	cout<<"output:"<<mul2(n)<<endl;
}

#include <iostream>
using namespace std;

int main() {
	int cat;
	cout<<"enter number of categories: ";
	cin>>cat;
	
	int *nbooks=new int[cat];
	int **lib=new int*[cat];
	
	for(int i=0;i<cat;i++){
		cout<<"enter number of books in category "<<i+1<<": ";
		cin>>nbooks[i];
		lib[i]=new int[nbooks[i]];
		
		cout<<"enter book ids for category "<<i+1<<":"<<endl;
		for(int j=0;j<nbooks[i];j++){
			cin>>lib[i][j];
		}
	}
	
	int sid;
	cout<<"enter book id to search: ";
	cin>>sid;
	
	bool found=false;
	int c=-1;
	for(int i=0;i<cat;i++){
		for(int j=0;j<nbooks[i];j++){
			if(lib[i][j]==sid){
				found=true;
				c=i;
				break;
			}
		}
		if(found) break;
	}
	
	if(found){
		cout<<"book id "<<sid<<" available in category "<<c+1<<endl;
	}else{
		cout<<"book id "<<sid<<" not available"<<endl;
	}
	
	for(int i=0;i<cat;i++){
		delete[] lib[i];
	}
	delete[] lib;
	delete[] nbooks;
}

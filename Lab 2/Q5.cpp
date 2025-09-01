#include <iostream>
using namespace std;

int main() {
	int row,col;
	cout<<"enter number of rows: ";
	cin>>row;
	cout<<"enter number of columns: ";
	cin>>col;
	
	double **a=new double*[row];
	double **b=new double*[row];
	double **add=new double*[row];
	double **sub=new double*[row];
	
	for(int i=0;i<row;i++){
		a[i]=new double[col];
		b[i]=new double[col];
		add[i]=new double[col];
		sub[i]=new double[col];
	}
	
	cout<<"enter elements of matrix a:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<"a["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	
	cout<<"enter elements of matrix b:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<"b["<<i<<"]["<<j<<"]: ";
			cin>>b[i][j];
		}
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			add[i][j]=a[i][j]+b[i][j];
			sub[i][j]=a[i][j]-b[i][j];
		}
	}
	
	cout<<"matrix a:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"matrix b:"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"addition (a+b):"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<add[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"subtraction (a-b):"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<sub[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<row;i++){
		delete[] a[i];
		delete[] b[i];
		delete[] add[i];
		delete[] sub[i];
	}
	
	delete[] a;
	delete[] b;
	delete[] add;
	delete[] sub;
}

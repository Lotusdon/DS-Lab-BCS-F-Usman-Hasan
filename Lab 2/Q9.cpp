#include <iostream>
using namespace std;

int main() {
	int r,c;
	cout<<"enter number of rows: ";
	cin>>r;
	cout<<"enter number of cols: ";
	cin>>c;
	
	int **mat=new int*[r];
	for(int i=0;i<r;i++){
		mat[i]=new int[c];
	}
	
	cout<<"enter elements of matrix:"<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	
	cout<<"matrix in normal form:"<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int nz=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]!=0){
				nz++;
			}
		}
	}
	
	int **comp=new int*[nz];
	for(int i=0;i<nz;i++){
		comp[i]=new int[3];
	}
	
	int k=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]!=0){
				comp[k][0]=i;
				comp[k][1]=j;
				comp[k][2]=mat[i][j];
				k++;
			}
		}
	}
	
	cout<<"matrix in compressed form (row col val):"<<endl;
	for(int i=0;i<nz;i++){
		cout<<comp[i][0]<<" "<<comp[i][1]<<" "<<comp[i][2]<<endl;
	}
	
	for(int i=0;i<r;i++){
		delete[] mat[i];
	}
	delete[] mat;
	
	for(int i=0;i<nz;i++){
		delete[] comp[i];
	}
	delete[] comp;
}

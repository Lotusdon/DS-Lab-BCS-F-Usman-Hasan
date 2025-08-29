

#include <iostream>
using namespace std;

int main() {
	int row,col,choice;
	
	cout<<"enter number of rows: "<<endl;
	cin>>row;
	cout<<"enter number of columns: "<<endl;
	cin>>col;
	
	int **arr=new int*[row];
	
	for(int i=0;i<row;i++){
		arr[i]=new int[col];
		  for(int j=0;j<col;j++){
		  	arr[i][j]=0;
		  }
	}
	cout<<"enter 1 to mark the seat as occupied , enter 0 to keep it unoccupied";
	for(int x=0;x<row;x++){
		for(int y=0;y<col;y++){
			cout<<"enter choice:"<<endl;
			cin>>choice;
			if(choice)
			{
				arr[x][y]=1;
			}
		}
	}
	
	cout<<"printing array " <<endl;
	for(int w=0;w<row;w++){
		cout<<endl;
		for(int z=0;z<col;z++){
			cout<<arr[w][z];
		}
	}
	
	for(int i=0;i<row;i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	
}

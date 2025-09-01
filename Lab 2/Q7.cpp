#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"enter number of departments: ";
	cin>>n;
	
	int *emp=new int[n];
	int **sal=new int*[n];
	
	for(int i=0;i<n;i++){
		cout<<"enter number of employees in dept "<<i+1<<": ";
		cin>>emp[i];
		sal[i]=new int[emp[i]];
		
		cout<<"enter salaries for dept "<<i+1<<":"<<endl;
		for(int j=0;j<emp[i];j++){
			cout<<"employee "<<j+1<<": ";
			cin>>sal[i][j];
		}
	}
	
	cout<<"highest salary in each dept"<<endl;
	for(int i=0;i<n;i++){
		int mx=sal[i][0];
		for(int j=1;j<emp[i];j++){
			if(sal[i][j]>mx){
				mx=sal[i][j];
			}
		}
		cout<<"dept "<<i+1<<": "<<mx<<endl;
	}
	
	int best=0;
	double mxavg=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<emp[i];j++){
			sum+=sal[i][j];
		}
		double avg=(double)sum/emp[i];
		if(avg>mxavg){
			mxavg=avg;
			best=i;
		}
	}
	
	cout<<"dept with max avg salary: dept "<<best+1<<" (avg = "<<mxavg<<")"<<endl;
	
	for(int i=0;i<n;i++){
		delete[] sal[i];
	}
	delete[] sal;
	delete[] emp;
}

#include <iostream>
using namespace std;

int main() {
	int d,t;
	cout<<"enter total days: ";
	cin>>d;
	cout<<"enter number of readings per day: ";
	cin>>t;
	
	int **temp=new int*[d];
	for(int i=0;i<d;i++){
		temp[i]=new int[t];
	}
	
	int *avg=new int[d];
	
	for(int i=0;i<d;i++){
		cout<<"day "<<i+1<<" readings:"<<endl;
		for(int j=0;j<t;j++){
			cout<<"reading "<<j+1<<": ";
			cin>>temp[i][j];
		}
	}
	
	for(int i=0;i<d;i++){
		int sum=0;
		for(int j=0;j<t;j++){
			sum+=temp[i][j];
		}
		avg[i]=sum/t;
	}
	
	int hot=0,cold=0;
	for(int i=1;i<d;i++){
		if(avg[i]>avg[hot]) hot=i;
		if(avg[i]<avg[cold]) cold=i;
	}
	
	cout<<"daily avg temps:"<<endl;
	for(int i=0;i<d;i++){
		cout<<"day "<<i+1<<": "<<avg[i]<<endl;
	}
	
	cout<<"hottest day: day "<<hot+1<<" (avg: "<<avg[hot]<<")"<<endl;
	cout<<"coldest day: day "<<cold+1<<" (avg: "<<avg[cold]<<")"<<endl;
	
	for(int i=0;i<d;i++){
		delete[] temp[i];
	}
	delete[] temp;
	delete[] avg;
}

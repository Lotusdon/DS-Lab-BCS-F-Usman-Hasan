#include <iostream>
using namespace std;

int main() {
	int n,choice;
	
	cout<<"enter number of months: "<<endl;
	cin>>n;
	
	double *arr=new double[n];
	
	cout<<"enter expenses"<<endl;
	for(int i=0;i<n;i++){
		cout<<"month "<<i+1<<": ";
		cin>>arr[i];
	}
	
	do{
		cout<<"expenses"<<endl;
		cout<<"1. display expenses"<<endl;
		cout<<"2. show total and average"<<endl;
		cout<<"3. add more months"<<endl;
		cout<<"4. exit"<<endl;
		cout<<"enter choice:"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:{
				cout<<"expenses list:"<<endl;
				for(int i=0;i<n;i++){
					cout<<"month "<<i+1<<": "<<arr[i]<<endl;
				}
				break;
			}
			
			case 2:{
				double total=0;
				for(int i=0;i<n;i++){
					total+=arr[i];
				}
				cout<<"total expenses = "<<total<<endl;
				cout<<"average expenses = "<<total/n<<endl;
				break;
			}
			
			case 3:{
				int extra;
				cout<<"enter number of extra months: ";
				cin>>extra;
				
				double *newarr=new double[n+extra];
				for(int i=0;i<n;i++){
					newarr[i]=arr[i];
				}
				
				cout<<"enter expenses for new months:"<<endl;
				for(int i=n;i<n+extra;i++){
					cout<<"month "<<i+1<<": ";
					cin>>newarr[i];
				}
				
				delete[] arr;
				arr=newarr;
				n+=extra;
				break;
			}
			
			case 4:
				cout<<"program ending"<<endl;
				break;
				
			default:
				cout<<"invalid choice"<<endl;
		}
		
	}while(choice!=4);
	
	delete[] arr;
}

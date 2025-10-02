#include <iostream>
using namespace std;

int iabs(int x)
{
 if(x<0) return -x;
  return x;
}

bool canplace(int row,int col,int* pos)
{
 for(int r=0;r<row;r++)
 {
   if(pos[r]==col) return false;
   if(iabs(pos[r]-col)==iabs(r-row)) return false;
 }
 return true;
}

void printboard(int n,int* pos)
{
 for(int r=0;r<n;r++)
 {
   for(int c=0;c<n;c++)
   {
     if(pos[r]==c)
      cout<<'Q';
     else
      cout<<'.';
   }
   cout<<'\n';
 }
 cout<<'\n';
}

void solvenq(int n,int row,int* pos,long long& ways)
{
 if(row==n)
 {
   ways++;
   printboard(n,pos);
   return;
 }
 for(int c=0;c<n;c++)
 {
   if(canplace(row,c,pos))
   {
     pos[row]=c;
     solvenq(n,row+1,pos,ways);
     pos[row]=-1;
   }
 }
}

int main()
{
 int n;
 cout<<"enter n: ";
 cin>>n;
 int* pos=new int[n];
 for(int i=0;i<n;i++) pos[i]=-1;

 long long ways=0;
 solvenq(n,0,pos,ways);
 cout<<"total solutions: "<<ways<<'\n';
 delete[] pos;
}

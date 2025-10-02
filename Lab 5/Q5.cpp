#include <iostream>
using namespace std;

bool isvalid(int a[9][9],int r,int c,int v)
{
 for(int i=0;i<9;i++)
 {
   if(a[r][i]==v || a[i][c]==v)
     return false;
 }
 int sr=(r/3)*3, sc=(c/3)*3;
   for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
      {
        if(a[sr+i][sc+j]==v)
          return false;
      }
   }
 return true;
}

bool solve(int a[9][9])
{
 for(int r=0;r<9;r++)
 {
   for(int c=0;c<9;c++)
   {
     if(a[r][c]==0)
      {
        for(int v=1;v<=9;v++)
        {
          if(isvalid(a,r,c,v))
           {
             a[r][c]=v;
             if(solve(a))
               return true;
             a[r][c]=0;
           }
        }
        return false;
      }
   }
 }
 return true;
}

int main()
{
 int a[9][9]={
   {0,0,3,0,2,0,6,0,0},
   {9,0,0,3,0,5,0,0,1},
   {0,0,1,8,0,6,4,0,0},
   {0,0,8,1,0,2,9,0,0},
   {7,0,0,0,0,0,0,0,8},
   {0,0,6,7,0,8,2,0,0},
   {0,0,2,6,0,9,5,0,0},
   {8,0,0,2,0,3,0,0,9},
   {0,0,5,0,1,0,3,0,0}
 };

 cout<<"original sudoku:"<<endl;
 for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
     cout<<a[i][j]<<(j==8?'\n':' ');
  }

 cout<<endl;
 cout<<"solved sudoku:"<<endl;
 if(solve(a))
 {
   for(int i=0;i<9;i++)
   {
     for(int j=0;j<9;j++)
      cout<<a[i][j]<<(j==8?'\n':' ');
   }
 }
 else
  cout<<"no solution"<<endl;
}

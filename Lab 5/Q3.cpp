#include <iostream>
using namespace std;

int sumtail(int n, int total)
{
 if (n == 0)  
   return total;
    
    return sumtail(n - 1, total + n);
}

int sumnontail(int n)
 {
    if (n == 0)  
        return 0;
  return n + sumnontail(n - 1);
 }

int main()
{
 int n;
    
    cin >> n;
    cout << "tail sum: " << sumtail(n, 0) << endl;
    cout << "non-tail sum: " << sumnontail(n) << endl;
}

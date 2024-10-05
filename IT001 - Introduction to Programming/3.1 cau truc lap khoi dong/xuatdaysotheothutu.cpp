#include <iostream>
using namespace std;
int main () 
{
    int n;
    cin >> n;
   for (int i = 1;i<=n; i++)
   if (i%2==0)
    cout << i << " ";
 cout << endl;
  for (int i = n;i >=1; i --)
    if (i%2!=0)
     cout << i << " ";
 cout << endl;
 cout << "Done";
   return 0;
}
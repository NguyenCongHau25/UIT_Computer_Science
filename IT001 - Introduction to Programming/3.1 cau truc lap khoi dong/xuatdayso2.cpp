#include <iostream>
using namespace std;
int main () 
{
    int n;
    cin >> n;
    for (int i = 1;i<=n; i++)
      cout << i << " ";
    cout << endl;
    for (int i =10 ; i<=n; i+=5)
     cout << i << " ";
    cout << endl;
    for ( int i = 20; i<=n;i+=10)
     cout << i << " ";
    cout << endl;
    return 0;
}
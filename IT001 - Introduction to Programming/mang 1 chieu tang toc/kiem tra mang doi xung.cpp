/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
using namespace std;
int kiemtra(int a[], int n)
{
    for (int i=0; i<n/2;i++)
        
        {
            if (a[i]!=a[n-i-1])
            return 0;
        }
return 1;
}

int main()
{
    int a[10000];
    int n;
    cin >>n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    if (kiemtra(a,n)==1) cout << "array is palindrome";
    else cout << "array is not palindrome";
    return 0;
    
}



#include <iostream>
using namespace std;
int main()
{
    int n,m;
    int a[10],b[10];
    int na=0, nb=0;
    cin >> n;
    m=n;
    while (n>0)
    {
        a[na++]=n%10;
        n/=10;
    }
    for (int i=na-1; i>=0; i--)
        b[nb++]=a[i];
    for (int i=0; i<nb; i++)
        cout << b[i] << " ";
    
    return 0;
}




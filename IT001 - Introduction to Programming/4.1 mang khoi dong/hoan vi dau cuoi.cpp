#include <iostream>
using namespace std;
int main()
{   int b;
    int a[50];
    int n;cin >>n;
    for (int i=0;i<n; i++)
        cin >> a[i];
    b = a[0];
    a[0]=a[n-1];
    a[n-1]=b;
    for (int i=0;i<n;i++)
        cout <<a[i]<< endl;
    return 0;
}
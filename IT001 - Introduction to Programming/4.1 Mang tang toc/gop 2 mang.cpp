#include <iostream>
using namespace std;
int main()
{
    int na,nb, a[15], b[15],c[30];
    cin >> na >> nb;
    int nc=na+nb;
    for (int i=0; i < na; i++)
        {cin >> a[i];
        c[i]=a[i];}
    for (int i=0; i< nb; i++)
        {cin >> b[i];
        c[na+i]=b[i];}
    for (int i=0; i<nc; i++)
        cout << c[i]<< " ";
    return 0;
}
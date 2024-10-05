
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[], int &na)
{
    cin >> na;
    for (int i=0; i<na; i++)
        cin >> a[i];
}
void outputArray(int a[], int na)
{
    for (int i=0; i<na; i++)
    cout <<  a[i] << " ";
}
void getNumber(int a[], int &na, int b[], int &nb, int c[], int &nc, int d[], int &nd)
{
    nb=0;
    nc=0;
    nd=0;
    for (int i=0; i<na; i++)
    {
        if (a[i]>0)
            b[nb++]=a[i];
        else if(a[i]<0)
            c[nc++]=a[i];
        else if(a[i]==0)
            d[nd++]=a[i];
    }
}
int main()
{
    int na, a[100], nb, b[100], nc, c[100], nd, d[100];
    inputArray(a,na);
    cout<<"Array a:"<<endl;
    outputArray(a,na);
    cout<<endl;

    getNumber(a,na,b,nb,c,nc,d,nd);

    cout<<"\nArray b:";outputArray(b,nb);
    cout<<"\nArray c:";outputArray(c,nc);
    cout<<"\nArray d:";outputArray(d,nd);

    return 0;
}

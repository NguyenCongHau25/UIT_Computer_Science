#include <iostream>
using namespace std;
int kiemtra(int a[],int n)
{
    for (int i=0; i<n; i++)
    {
        if(a[i]<0)
        return 0;
    }
    return 1;
}
void tachmang(int a[], int &n, int b[], int &nb)
{
    nb=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]<0)
        b[nb++]=a[i];
    }
}
int max(int a[], int n, int b[], int &nb)
{
    tachmang(a,n,b,nb);
    int max=b[0];
    for (int i=0; i<nb; i++)
    {
        if (b[i]>=max)
        max=b[i];
    }
    return max;;
}
int vitri(int a[], int n, int b[], int nb)
{
    for (int i=0; i<n; i++)
    {
        if (a[i]==max(a,n,b,nb))
        return i;
    }
}
int main()
{
    int a[100], b[100];
    int n,nb;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    if (kiemtra(a,n)==1) 
        cout << "-1";
    else 
        cout << vitri(a,n,b,nb);
    return 0;
}
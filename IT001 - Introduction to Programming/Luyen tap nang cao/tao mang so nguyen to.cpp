#include <iostream>
using namespace std;

void inputArray(int a[], int &na)
{
    cin >> na;
    for (int i=0; i<na; i++)
        cin >> a[i];
}

void outputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
}

bool snt(int x)
{
    if (x<2)
        return 0;
    for (int i=2; i<x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

void trichsnt(int a[], int na, int b[], int m)
{
    int nb=0;
    int dem=0;
    for (int i=0; i<na; i++)
        if (snt(a[i]))
            {
                b[nb++]=a[i];
                dem++;
            }
    if (dem==0)  
        cout << "Mang a khong co chua so nguyen to" << endl;

    else if (dem<m)
        {
        cout << "Mang a khong co du "<< m <<" so nguyen to" << endl;
        for (int i=0; i<nb; i++)
            cout << b[i] << " ";
        }
    else if (dem>=m)
        {
            nb=m;
            cout << "Mang b" << endl;
            for (int i=0; i<nb; i++)
                cout << b[i] << " ";
        }
}



int main()
{
    int na;
    int a[100];
    int b[100];
    int m;
    inputArray(a,na);
    cin >> m;
    outputArray(a,na);
    cout << endl;
    trichsnt(a,na,b,m);

    return 0;
}
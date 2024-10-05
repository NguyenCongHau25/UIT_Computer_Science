#include <iostream>
using namespace std;
void tachmang(int a[], int n, int b[], int &nb, int x)
{
    nb=0;
    for (int i=0; i<n; i++)
        {
            if(a[i]!=x)
                b[nb++]=a[i];
        }
}
int main()
{
    int a[100], n,x, b[100],nb;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    cin >> x;
    tachmang(a,n,b,nb,x);
    for (int i=0; i<nb; i++)
        cout << b[i] << " ";
    return 0;
}
#include <iostream>
using namespace std;
void sapxep(int a[], int n)
{
    int tg=0;
    for(int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
    {
        if(a[i]>a[j])
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }
    }
}
int main()
{
    int n, a[20];
    int dem=0;
    int x=0;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sapxep(a,n);
    for (int i=0; i<n-1; i++)
        {
            x=a[i+1]-a[i];
            for (int j=1; j<x; j++)
             dem++;
        }
    cout << dem;
    return 0;
}
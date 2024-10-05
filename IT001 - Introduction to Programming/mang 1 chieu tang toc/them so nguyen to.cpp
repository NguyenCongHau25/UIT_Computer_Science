#include <iostream>
using namespace std;
int kiemtranguyento(int x)
{
    if (x<2) return 0;
    for (int i = 2; i<=x-1;i++)
        {
            if (x%i==0)
             return 0;
        }
        return 1;
}
void chen(int a[], int n)
{
    int d=0;
    for (int i=0; i<n; i++)
    {
        if (kiemtranguyento(a[i])==1 )
        {
            cout << -1 << " ";
            cout << a[i] << " ";
        }
        else cout << a[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++)
    {
        if (kiemtranguyento(a[i])==1)
        {
        cout << d+i<< " ";
        d++;
        }
    }
}
int main()
{
    int a[100];
    int n; 
    cin >>n ;
    for (int i=0; i<n; i++)
        cin >> a[i];
    chen(a,n);
    return 0;
}

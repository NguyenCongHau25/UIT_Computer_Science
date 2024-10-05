#include <iostream>
using namespace std;
void xoakitu(int a[], int n, int x, int y)
{
    for(int i=0; i<n; i++)
    {
        if (i<x || i>y)
            cout << a[i] << " ";
    }
}
int main()
{
    int a[20];
    int n,x,y;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    cin >> x >> y;
    xoakitu(a,n,x,y);
    return 0;

}

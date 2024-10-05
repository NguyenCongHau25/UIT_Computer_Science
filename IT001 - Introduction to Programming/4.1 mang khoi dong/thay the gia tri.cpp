#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int n; cin >> n;
    for (int i=0; i<n;i++)
    {
        cin >> a[i];
    }
    int x; cin >>x;
    int y; cin >>y;
    for (int i=0; i<n;i++)
    {
        if (a[i]==x) a[i]=y;
    }
    for (int i=0; i<n;i++)
    {
        cout << a[i]<< endl;
    }
}
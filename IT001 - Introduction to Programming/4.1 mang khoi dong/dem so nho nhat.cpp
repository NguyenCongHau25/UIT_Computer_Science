#include <iostream>
using namespace std;
int main()
{
    int a[10000];
    int n; cin >> n;
    for (int i=0; i<n;i++)
    {
        cin >> a[i];
    }
    int dem=0;
    int min=a[0];
    for (int i=1; i<n;i++)
    {
        if (a[i]<=min)
            min =a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]==min)
            dem++;
    }
    cout << min <<" " << dem;
    return 0;
}
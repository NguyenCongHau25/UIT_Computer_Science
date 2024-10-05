#include <iostream>
using namespace std;
int demuoc(int n)
{
    int dem=0;
    for (int i=1; i<=n; i++)
        if (n%i==0)
            dem++;
    return dem;
}

int main()
{
    int n;
    int s=0;
    int a[200000];
    cin >> n;
    for (int i=1; i<=n-1; i++)
        s+=demuoc(i)*demuoc(n-i);
    cout << s;
    return 0;
}
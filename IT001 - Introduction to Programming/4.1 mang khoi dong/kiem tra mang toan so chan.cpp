#include <iostream>
using namespace std;
void kiemtra(int n, int a[])
{
    int dem=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]%2==0)
        dem++;
    }
    if (dem==n) cout << "yes";
    else cout <<"no";
}

int main()
{
    int a[50];
    int n; cin >> n;
    for (int i=0; i<n;i++)
    {
        cin >> a[i];
    } 
    kiemtra(n,a);
    return 0;
}
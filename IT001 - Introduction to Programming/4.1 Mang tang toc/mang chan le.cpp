#include <iostream>
using namespace std;
int kiemtrachan(int n, int a[])
{
    int flag =0;
    for (int i=0; i<n; i++)
        if (a[i]%2!=0)
                flag = 1;
        if (flag==0) return 1;
        return 0;
}
int kiemtrale(int n, int a[])
{
    int flag =0;
    for (int i=0; i<n; i++)
        if (a[i]%2==0)
                flag = 1;
        if (flag==0) return 1;
        return 0;
}
int main()
{
    int n,a[100];
    cin >>n;
    for (int i=0; i<n ; i++)
     cin >> a[i];
    if (n==0)
        cout << "Mang rong";
    else 
    {
     if(kiemtrachan(n,a)==1) cout << "Mang chua toan so chan";
    else if (kiemtrale(n,a)==1) cout << "Mang chua toan so le";
    else cout << "Mang khong chua toan so chan hay so le";
    }
    return 0;
}
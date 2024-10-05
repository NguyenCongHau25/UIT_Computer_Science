#include <iostream>
using namespace std;
int mangtang(int a[], int n)
{
   
    for (int i=0; i<n-1; i++)
    {
        if (a[i]>=a[i+1])
          return 0;
    }
    return 1;
}
int manggiam(int a[], int n)
{

    for (int i=0; i<n-1; i++)
    {
        if(a[i]<=a[i+1])
            return 0;
    }
    return 1;
}
int khongtanggiam( int a[], int n)
{
    int flag=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]==a[0])
        flag +=1;
    }
    if (flag==n) return 1;
    return 0;
}
int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    if (n == 0) 
        return 0;
    if (n==1) cout << "Mang tang dan";
    else if (khongtanggiam(a,n)==1) cout << "Mang khong tang, khong giam";
    else 
    {
        if (mangtang(a,n)==1) cout << "Mang tang dan";
        else if (manggiam(a,n)==1) cout << "Mang giam dan";
        else cout << "Mang khong tang, khong giam";
    }

    return 0;
}
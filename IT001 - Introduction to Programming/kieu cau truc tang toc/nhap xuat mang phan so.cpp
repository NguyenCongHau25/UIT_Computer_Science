#include <iostream>
using namespace std;

typedef struct PhanSo
{
int tuso;
int mauso;
}PS ;
void nhapmotps(PS &x)
{
    cin >> x.tuso;
    cin >> x.mauso;
}
void inputarray(PS a[], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        nhapmotps(a[i]);
}

int ucln(int a, int b)
{
    a=abs(a);
    b=abs(b);
    while (a!=b)
    {
       if (a>b)
        a=a-b;
        else b=b-a;
    }
    return a;
}
void xuly(PS c)
{
    int a=c.tuso;
    int b=c.mauso;
    if (a!=0)
    {
        if (a%b==0)
        cout << a/b;
        else 
        {
        if (a>0&&b<0)
           cout<<"-"<<a/ucln(a,b)<<"/"<<abs(b/ucln(a,b));
        else if (a<0&&b>0)
            cout<<a/ucln(a,b)<<"/"<<b/ucln(a,b);
        else if (a<0&&b<0)
            cout<<-a/ucln(a,b)<<"/"<<abs(b/ucln(a,b));
        else if (a>0&&b>0)
            cout<<a/ucln(a,b)<<"/"<<b/ucln(a,b);
        }
    }
    else 
        cout << 0;
}
void outputarray(PS a[], int n)
{
    for (int i=n-1; i>=0; i--)
        {
                if (a[i].mauso==0)
                    cout << "Khong thoa yeu cau bai toan";
                else 
                    xuly(a[i]);
                    cout << endl;
                    //cout << a[i].tuso << "/" << a[i].mauso << endl;
        }    
}
int main()
{   
    PS a[10000];
    int n;
    inputarray(a,n);
    outputarray(a,n);
    return 0;
}
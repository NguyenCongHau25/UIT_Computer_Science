#include <iostream>
using namespace std;

typedef struct PhanSo
{
int tuso;
int mauso;
}PS ;

int ucln(int a, int b)
{
    a=abs(a);
    b=abs(b);
    if (a*b==0) 
        return a+b;
    while (a!=b)
    {
       if (a>b)
        a=a-b;
        else b=b-a;
    }
        return a;
}
PS cong(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso*b.mauso + b.tuso*a.mauso;
    c.mauso=a.mauso*b.mauso;
    return c;
}
PS tru(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso*b.mauso - b.tuso*a.mauso;
    c.mauso=a.mauso*b.mauso;
    return c;
}
PS nhan(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso * b.tuso;
    c.mauso = a.mauso*b.mauso;
    return c;
}
PS chia(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso * b.mauso;
    c.mauso= a.mauso * b.tuso;
    return c;
}
void xuly(PS c)
{
    if (c.tuso < 0 && c.mauso < 0)
        cout << abs(c.tuso)/ucln(c.tuso,c.mauso) << "/" << abs(c.mauso)/ucln(c.tuso, c.mauso);
    else if (c.mauso <0 )
        cout << "-" <<c.tuso /ucln(c.tuso,c.mauso)<< "/" << abs(c.mauso)/ucln(c.tuso,c.mauso);
    else if (c.tuso ==0)
        cout << 0;
    else if (c.mauso==0)
        cout << "Phep chia khong xac dinh";
    else cout << c.tuso / ucln(c.tuso, c.mauso)<< "/" << c.mauso/ucln(c.tuso,c.mauso);
}
int main()
{   
    PS a,b,kq;
    char x;
    cin >> a.tuso >> a.mauso;
    cin >> b.tuso >> b.mauso;
    cin >> x;
    if (a.mauso==0 || b.mauso ==0)
        cout << "Khong thoa yeu cau bai toan";
    else if (a.tuso==0 && b.tuso ==0)
        cout << "Phep chia khong xac dinh";
    else 
    {
        switch (x)
        {
            case '+': 
            {
                kq=cong(a,b);
                break;
            }
            case '-':
            {
                kq=tru(a,b);
                break;
            }
            case '*':
            {
                kq=nhan(a,b);
                break;
            }
            case '/':
            {
                kq=chia(a,b);
                break;
            }
        }
        xuly(kq);
    }
   // cout << kq.tuso/ucln(kq.tuso,kq.mauso) << "/" << kq.mauso/ucln(kq.tuso,kq.mauso);
 return 0;
}
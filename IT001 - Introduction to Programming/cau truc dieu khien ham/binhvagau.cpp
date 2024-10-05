#include <iostream>
#include <cmath> 
using namespace std;
int thoigian(int x, int y , int z)
{
    return x*3600+y*60+z;
}
int ucln(int a, int b)
{

    while (a!=b)
    {
       if (a>b)
        a=a-b;
        else b=b-a;
    }
    return a;
}
int main ()
{
    int a,b,c, h, m,s,uc;
    double tl,tg;
    cin >> a >> b >> c ;
    cin >> h >> m >> s;
    tl = thoigian(a,b,c);
    tg = thoigian (h,m,s);
    if (tg == 0)
        cout << 0 << " " << 1;
    else {
    uc = ucln(tl,tg);
    cout << tg /uc << " "<< tl/ uc;
    }
   return 0;
}
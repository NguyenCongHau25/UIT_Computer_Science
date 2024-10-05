#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    if  (((a<1) || (a>12)) && ( (b<=1975) || (b>=2019) ))
    {
      cout << "Thang khong hop le.";
      cout << "Nam khong hop le.";
    }
    else if  ( (a<1) || (a>12))
      cout << "Thang khong hop le.";
    else if ( b<=1975 || b>=2019 )
      cout << "Nam khong hop le.";
    else
       if ((((b%4==0) && (b%100 !=0))||(b%400==0))&& (a==2))
         cout << 29;
       else
         if (a== 4 || a== 6 || a== 9 || a==11)
            cout << 30;
         else if (a==2)
            cout << 28;
         else
            cout << 31;
    return 0;
}
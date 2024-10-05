#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if (delta > 0)
    {
        cout << "PT co hai nghiem phan biet:" << endl;
         cout << "x1 = " << (-b+sqrt(delta))/(2.0*a)<< endl;
         cout << "x2 = " << (-b-sqrt(delta))/(2.0*a) ;
    }
    else if (delta == 0 )
        cout << "PT co nghiem kep: x1 = x2 = " << (-b)/(2.0*a);

    else
         cout << "PTVN";
         return 0;
}
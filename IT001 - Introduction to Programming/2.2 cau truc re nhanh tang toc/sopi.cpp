#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
   
    double s=1;
    int i =3;
    int dau=-1;
    while (i<=(2*n+1))
    {
        s=s+dau*1.0/i;
        dau=-1*dau;
        i=i+2;

    }
    double kq=4*s;
    cout << kq ;
}
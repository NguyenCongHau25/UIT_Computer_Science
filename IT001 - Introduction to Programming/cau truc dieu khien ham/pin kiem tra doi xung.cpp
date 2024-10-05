#include <iostream>
using namespace std;
long doixung( long n)
{   long tg;
    long dx= 0;
    while (n!=0)
    { 
        tg = n%10;
        dx = dx*10 + tg ;
        n = n/10;
    }
    return dx;
}
int main()
{
    long x;
    cin >> x;
    if ( x == doixung(x))
        cout << 0;
    else cout << 1;
    return 0;
}
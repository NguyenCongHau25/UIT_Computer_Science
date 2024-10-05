#include <iostream>
using namespace std;
long giaithua(int n, int i)
{
   long t=1;
   
    while (i <=n)
    {
        t=t*i;
        i+=2;

    }
    return t;
}
int main ()
{
    int n;
    cin >> n;
    if (n%2==0)

        cout << giaithua(n,2);
    else 
         cout << giaithua(n,1);
}

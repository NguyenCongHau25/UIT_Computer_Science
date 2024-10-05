#include <iostream>
using namespace std;
int main ()
{
    int n,a,b,s;
    cin >> a >> b >> n;
    int i = 1;
    s=0;
    while (i<=n)
    {
       s +=a*b;
        a++;b++;
        i++;
    }
    cout << s;
    return 0;
}
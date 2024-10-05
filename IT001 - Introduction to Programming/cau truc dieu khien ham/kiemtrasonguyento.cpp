#include <iostream>
using namespace std;
int kiemtra(int x)
{
        for (int i = 2; i<=x-1;i++)
        {
            if (x%i==0)
             return 0;
        }
        return 1;
}
int main ()
{
    int x;
    cin >> x;
    if (x==1)
        cout << -1;
    else 
        cout << kiemtra(x);
    return 0;
}
#include <iostream>
using namespace std;
bool prime(int k)
{
    int dem=0;
    for (int i = 1; i <= k; i++)
    {
        if (k %i ==0)
        dem+=1;

    }
    if (dem == 2 )
    return true ;
    return false;
}
long giaithuanguyento(int n)
{
    long t=1;
    for (int i =1 ; i <= n; i++)
    {
        if (prime (i))
        t =t*i;

    }
    return t;
}
int main()
{
    int n;
    cin >> n;
    cout << giaithuanguyento(n);
    return 0;
}
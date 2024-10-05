#include <iostream>
using namespace std;
int kiemtranguyento(int n)
{
   for (int i = 2; i<=n-1;i++)
    {
       if (n%i==0)
       return 0;
    }
   if (n == 1)
    return 0;
return 1;

}
int main()
{
    int n;
    unsigned long long m;
    cin >> n;
    for (int i=2; i<=n; i++)
    {
        if (kiemtranguyento(n)) 
            {
            n*=2;
            break;
            }
    
        if (kiemtranguyento(i) && n%i==0)
        {
        n+=i;
        break;
        }
    }
    cout << n;
    return 0;
}

#include <iostream>
using namespace std;


int main()
{
    long long n;
    cin >> n;
    int dem=0;
    while (n%10==0)
        n/=10;

    while (true)
    {
            if (n==0) break;
            if (n%10==0)
                dem++;
            n/=10;
            
    }
    cout << dem;
    
    return 0;

}
#include <iostream>
using namespace std;
int main () 
{
    int n,i,sum;
    cin >> n;
    sum = 0;
    i=1;
    while (i<n)
    {
        if (n%i==0)
           sum+=i;
           i++;
    }
    cout << sum;
    return 0;
}
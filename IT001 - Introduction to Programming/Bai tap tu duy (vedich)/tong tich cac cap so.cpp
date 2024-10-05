#include <iostream>
using namespace std;

int main()
{
    long n;
    long a[200000];
    long long s=0;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<n; j++)
            s=s+((a[i]*a[j])%1000000007)%1000000007;
    cout << s;
    return 0;
}
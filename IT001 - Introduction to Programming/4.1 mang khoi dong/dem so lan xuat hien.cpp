#include <iostream>
using namespace std;
int main()
{  
    int a[10000];
    int n;cin >>n;
    
    for (int i=0;i<n; i++)
        cin >> a[i];
    int x; cin >> x;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]==x)
            dem++;
    }
    cout << dem;
    return 0;
}
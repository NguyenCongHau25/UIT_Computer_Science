#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    int a[200000];
    for (int i=1; i<=n; i++)
        cin >> x >> y;
    for (int j=x; j<y; j++)
        a[j]++;
    

    return 0;
}
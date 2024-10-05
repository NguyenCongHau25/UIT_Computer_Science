#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;
    long long a[100000], b[100000];
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    int max=a[0];
    for (int i=1; i<n; i++)
        if (a[i]>max)
            max=a[i];

    int min=b[0];
    for (int i=1; i<n; i++)
        if (b[i]<min)
            min=b[i];
    int dem=0;
    for (int i=max; i <= min; i++)
        dem++;
    cout << dem;
    return 0;

}
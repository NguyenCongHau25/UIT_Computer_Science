#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double trungbinh(int a[], int &n)
{   
    double s=0;
    for (int i=0; i<n;i++)
     s+= a[i];
    return s/n;
}
int main()
{
    int a[10000];
    int n;
    double x,sum;
    cin >> n;
    for (int i=0; i<n;i++)
        cin >> a[i];
    x=trungbinh(a,n);
    for (int i=0; i<n; i++)
    {
        sum+=(a[i]-x)*(a[i]-x);
    }
    cout << setprecision(10) << sqrt(sum/n);
    return 0;
    
}
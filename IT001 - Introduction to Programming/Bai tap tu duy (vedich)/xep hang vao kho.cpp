#include <iostream>
using namespace std;

void xuly(int a[][100], int m, int n)
{
    int sum=0;
    int min=a[0][0];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i][j]<min)
                min = a[i][j];
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i][j] > min)
                sum+=a[i][j]-min;
    
    cout << sum;


}
int main()
{
    int a[100][100];
    int m,n;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    xuly(a,m,n);
    return 0;

}
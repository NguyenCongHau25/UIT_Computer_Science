#include <iostream>
using namespace std;
int kt(double a[][100], int m, int n)
{
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            if ( i!=j && a[i][j] !=0 ) 
                return 0;
        }
        return 1;
}
int main()
{
    double a[100][100];
    int m,n;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    if (kt(a,m,n)== 0 ) cout << "NO";
    else cout << "YES";
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    double a[100][100];
    double s=0;
    int m,n;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            {
                if (j==i && a[i][j])
                s+=a[i][j];
            }
    cout << s;
    return 0;
}
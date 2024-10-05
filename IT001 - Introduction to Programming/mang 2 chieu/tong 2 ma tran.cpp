#include <iostream>
using namespace std;
int main()
{
    float a[100][100];
    float b[100][100];
    int m,n;
    int l,k;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    cin >> l >> k;
    for (int i=0; i<l; i++)
        for (int j=0; j<k;j++)
            cin >> b[i][j];

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            {
                cout << a[i][j]+b[i][j] << " ";
            }
        cout << endl;
    }
    return 0;
}
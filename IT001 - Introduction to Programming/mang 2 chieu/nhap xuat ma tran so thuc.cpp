#include <iostream>
using namespace std;
int main()
{
    double a[100][100];
    int m,n;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            {
            cout << a[i][j] << "\t";
            }
        cout << endl;
    }
    return 0;
}
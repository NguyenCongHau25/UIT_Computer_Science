#include <iostream>
using namespace std; 
int main()
{
    float a[100][100];
    float b[100][100];
    float c[100][100];
    int m,n;
    int l,k;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    cin >> l >> k;
    for (int i=0; i<l; i++)
        for (int j=0; j<k; j++)
            cin >> b[i][j];
    for(int i=0; i<m; i++)
        for (int j=0; j<k; j++)
            {
                for (int z=0; z<l; z++)
                    c[i][j]+=a[i][z]*b[z][j];
            }
    for (int i=0; i<m;i++)
    {
        for (int j=0; j<k; j++)
        cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
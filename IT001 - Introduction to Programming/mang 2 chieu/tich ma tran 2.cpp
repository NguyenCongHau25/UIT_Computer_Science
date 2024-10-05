#include <iostream>
using namespace std;
void matrixMultiply(int a[][100], int a[][100], int c[][100])
{
    int m, n, i;
    int sum;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;
            for (i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            *(*(res + row) + col) = sum;
        }
    }
}
int main()
{
    double a[100][100];
    double b[100][100];
    double c[100][100];
    int m,n;
    int l,k;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    
    cin >> l >> k;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> b[i][j];
    for (int i=0; i<m; i++)
        for (int j=0; j<n;j++)
            c[i][j]= nhan(a,b,i,j);
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            cout << c[i][j]<< " ";
            cout << endl;

    return 0;
}
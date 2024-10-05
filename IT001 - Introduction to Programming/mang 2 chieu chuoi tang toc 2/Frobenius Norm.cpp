#include <iostream>
#include <math.h>
using namespace std;
void intputmatrix(double a[][100], int &m, int &n)
{
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
void Frobenius(double a[][100], int m, int n)
{
    float s=0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            s+=(pow(a[i][j],2));
    cout << scientific << sqrt(s);
}
int main()
{
    double a[100][100];
    int n,m;
    intputmatrix(a,m,n);
    Frobenius(a,m,n);
    return 0;
}
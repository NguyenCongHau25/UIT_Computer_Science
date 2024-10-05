#include <iostream>
using namespace std;

void inputmatrixA(double a[][100], int &n, int &m)
{
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
void inputmatrixv(double v[], int &k)
{
    cin >> k;
    for (int i=0; i<k; i++)
        cin >> v[i];
}
void tichAv(double a[][100], int n, int m, double v[])
{
 
    for (int i=0; i<m; i++)
    {
        double s=0;
        for (int j=0; j<n; j++)
            s+=a[i][j]*v[j];
        cout << s << endl;
 
    }
}

int main()
{
    int n,m,k;
    double a[100][100];
    double v[100];
    inputmatrixA(a,n,m);
    inputmatrixv(v,k);
    tichAv(a,n,m,v);

}
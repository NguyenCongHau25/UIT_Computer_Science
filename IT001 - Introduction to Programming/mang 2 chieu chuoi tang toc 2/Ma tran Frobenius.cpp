#include <iostream>
#include <math.h>
using namespace std;
void intputmatrix(double a[][100], int &m, int &n)
{
    cin >> n;
    cin >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
bool cheochinh(double a[][100], int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if(i==j && a[i][j]!=1)
                return 0;
    return 1;
}
bool tamgiactren(double a[][100], int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i<j && a[i][j]!=0)
                return 0;
    return 1;
}
int cot(double a[][100], int n)
{
    int dem=0;
    for (int i=0; i<n; i++)
        {   int s=0;
            for (int j=0; j<n; j++)
            {
                if (j>i)
                {
                    s+= a[j][i];
                }
            }
            if (s>0)
                dem++;
        }
    if (dem>1)
        return 0;
    return 1;

}
int main()
{
    double a[100][100];
    int n,m;
    intputmatrix(a,m,n);
    if (cheochinh(a,n)==1 && tamgiactren(a,n)==1 && cot(a,n)==1)
        cout << "Yes";
    else cout << "No";
    
    return 0;
}
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <math.h>
using namespace std;

const int MAXR=100;
const int MAXC=100;

void NhapMaTran(int a[MAXR][MAXC], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
void matrancon (int a[MAXR][MAXC], int c[MAXR][MAXC], int n, int y)
{
    int e=0, f=0;
    for (int i=1; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if ( j==y ) continue;
                c[e][f++]= a[i][j]; 
            }
            f=0;e++;
        }
}
long long TinhDinhThuc(int a[MAXR][MAXC], int n)
{
    long long s=0;
    int c[MAXR][MAXC];
    if (n==1) return a[0][0];
    for (int i=0; i<n; i++)
    {
        matrancon(a,c,n,i);
        s+=a[0][i]*pow(-1,i)*TinhDinhThuc(c,n-1);
    }
    return s;
}
int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout << TinhDinhThuc(a, n);
    return 0;
}

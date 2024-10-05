/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void nhapMaTran(int a[][100], int n, int m)
{
    for (int i=0;i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[j][i];
}
void xuatMaTran(int a[][100], int n, int m)
{
    cout << "Ma tran A("<<n<<"x"<<m<<") da nhap:" << endl;
    for (int i=0;i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << a [i][j] << " ";
    cout << endl;
    }
}

int main()
{
    int a[100][100], n, m;
    cin>>n>>m; //n: so dong, m: so cot
    nhapMaTran(a,n,m); //nhap theo thu tu tung cot: nhap cot 0 truoc, roi den cot 1, 2, ...
    xuatMaTran(a,n,m);
    return 0;
}


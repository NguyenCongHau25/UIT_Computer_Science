
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int isBinary(int **a, int m, int n)
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if(a[i][j]!=0&&a[i][j]!=1) // neu co 1 phan tu khong phai 0 hoac 1 thi khong phai ma tran nhi phan
            return 0;
    return 1;
}

int main()
{
//###INSERT CODE HERE -
    int n,m;
    cin >> m;
    cin >> n;
    int **a= new int*[m]; //tao mang con tro
    for (int i=0; i<m; i++)
        a[i]= new int [n];
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            a[i][j]= 0 + rand () %(1-0+1);
    }
     if (isBinary(a,m,n)==1) cout<<"Ma tran nhi phan";

    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


void inputMatrix(int a[][100], int &n);

void outputMatrix(int a[][100], int n);

/* Ham kiem tra ma tran tam giac tren
 La ma tran tam giac tren neu moi phan tu o ben duoi duong cheo chinh bang 0*/
int isUpperTriangularmatrix(int a[][100], int n);

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

//###INSERT CODE HERE -
    if(isUpperTriangularmatrix(a,n))
    cout << "a is called an upper triangular matrix";
    return 0;
}
void inputMatrix(int a[][100], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
int isUpperTriangularmatrix(int a[][100], int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if(i>j && a[i][j]!=0)
                return 0;
    return 1;
            
}
void outputMatrix(int a[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << a[i][j]<< " ";
        cout << endl;
    }
}


/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix( int a[][100], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
void outputMatrix(int a[][100], int n)
{
    for (int i=0; i<n; i++)
        {
        for (int j=0; j<n; j++)
            cout <<  a[i][j] << " ";
        cout << endl;
        }
}
int rowWithMaximumSum (int a[][100], int n)
{   int vt=0;
    int max=0;
    for (int i=0; i<n; i++)
    {
        int d=0;
        int s=0;
        for (int j=0; j<n; j++)   
            s+=a[i][j];   
        if (s>max)
        {
                max = s;

                vt = i;
 
                d++;
        }

    }
    return vt;
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    //Tim dong co tong lon nhat trong ma tran
    cout << "Row " <<  rowWithMaximumSum(a,n) << " has max sum "<<endl;

    return 0;
}




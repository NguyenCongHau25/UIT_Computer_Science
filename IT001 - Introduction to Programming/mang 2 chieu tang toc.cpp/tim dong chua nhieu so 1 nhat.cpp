/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[][100], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    cout << endl;
}

void outputMatrix(int a[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}
int rowWithMax1s(int a[][100], int n)
{
    int vt=0, max=0, t=0;
    for (int i=0; i<n; i++)
    {
        int d=0;
        for(int j=0; j<n; j++)
            if(a[i][j]==1)
                d++;
        if (d>max)
        {
            max=d;
            vt=i;
        }
        if(d==0)
            t+=1;
    }
    if(t==n) return -1;
    return vt;
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    int i = rowWithMax1s(a,n); //Tim dong co chua nhieu so 1 nhat
    if(i==-1) cout<<"No row has 1"<<endl;
    else cout << "Index of row with maximum number of 1s is " << i<<endl;

    return 0;
}




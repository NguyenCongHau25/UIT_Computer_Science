/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(char a[][100], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    cout << endl;
}

void outputMatrix(char a[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            {
            a[i][j]=toupper(a[i][j]);
            cout << a[i][j] << " ";
            }
        cout << endl;
    }

}
int checkWin(char a[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        int d=0;
        for (int j=0; j<n; j++)
            {
                if (a[i][j]=='X')
                    d++;
            }
       if (d==n) 
       return i;
    }
    return -1;
}

int main()
{
    int n; char a[100][100];
    inputMatrix(a,n);
    cout<<"Ma tran vua nhap:\n";
    outputMatrix(a,n);
    int x=checkWin(a,n);
    if(x!=-1) cout<<"You win at row "<<x;
    else cout<<"I win";
    return 0;
}



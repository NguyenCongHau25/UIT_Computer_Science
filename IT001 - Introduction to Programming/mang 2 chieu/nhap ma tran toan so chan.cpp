#include <iostream>
using namespace std;
int main()
{
    int a[100][100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

   for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if ((a[i][j])%2!=0)
            a[i][j]=0;
        }
    cout << "Matrix:" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            {
            cout << a[i][j] << " ";
            }
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

void inputmatrix(float a[][100], int &n, int &m)
{
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}
void maxvalue(float a[][100], int n, int m)
{
    for (int i=0; i<n; i++)
    {
        float max = a[0][i];
        for(int j=0; j<m; j++)
            {
                if (a[j][i] > max)
                    max = a[j][i];
            }
        cout << "Gia tri lon nhat tren cot "<<i<< " la: "<<max<< endl;

    }
}

int main()
{
    int n,m;
    float a[100][100];
    inputmatrix(a,n,m);
    maxvalue(a,n,m);

}
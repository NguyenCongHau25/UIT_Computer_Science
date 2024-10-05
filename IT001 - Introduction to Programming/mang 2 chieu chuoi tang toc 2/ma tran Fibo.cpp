/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAX 16

void Nhapmang(int a[][MAX], int &n);
void Xuatmang(int a[][MAX], int n);

//###INSERT CODE HERE -
int Fibo(int x)
{
	int x1 = 1;
	int x2 = 1;
	int xn ;
	if (x < 3)
	 	return 1;
	for (int i=3; i <= x; i++)
	{
		xn = x1 + x2;
		x1 = x2;
		x2 = xn;
	}
	return xn;
}
void Nhapmang(int a[][MAX], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            {
                a[i][j]=Fibo(i+j+1);
            }
}
void Xuatmang(int a[][MAX], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, a[MAX][MAX];
	Nhapmang(a,n);
	Xuatmang(a,n);
	
    return 0;
}
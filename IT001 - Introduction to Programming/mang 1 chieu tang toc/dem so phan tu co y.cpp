/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n,int y);

//###INSERT CODE HERE -
bool kiemtra(int x)
{
	int dem=0;
	for (int i=1; i<=x; i++)
	{
		if (x%i==0)
		dem++;
	}
	return (dem==2);
}
void NhapmangSNT(int a[], int &n)
{
	cin >> n;
	int q = -1;
	for (int i = 2; i >= 0; i++)
	{
		if (kiemtra(i))
			{
				q++;
				a[q]=i;
			}
		if (q==n-1)
			break;
	}
	
}
int SoPhanTuChuaY (int a[], int n, int y)
{
	int b=0,x=0;
	int d=0;
	for (int i=0; i<n; i++)
	{
		b=a[i];
		x=0;
		while(b!=0) 
		{
			x=b%10;
			if (x==y)
			{
				d++;
				break;
			}
			b=b/10;
		}
	}
	return d;
}

int main()
{
	int a[MAX], n, y;
	cin >>y;
	NhapmangSNT(a,n);
	cout << SoPhanTuChuaY(a, n, y) << endl;;
	return 0;
}
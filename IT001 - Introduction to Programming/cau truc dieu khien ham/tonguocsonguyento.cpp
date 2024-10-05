/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cmath>
using namespace std;


//###INSERT CODE HERE -
int kiemtranguyento(int m)
{
	if (m != 1)
	{
		int d = 0;
		int z = sqrt(m);
		for (int i = 2; i <= z; i++)
		{
			if (z % i == 0)
				d = d + 1;
		}
		if (d == 0) return m;
	}
	else return 0;
}
int sum_common_prime(int i, int j)
{
	if (i != 0 && j != 0)
	{
		while (i != j)
		{
			if (i > j)
				i = i - j;
			else j = j - i;
		}
		int t = 0;
		if (i != 1)
		{
			for (int k = 2; k <= i; k++)
			{
				if (i % k == 0)
					t += kiemtranguyento(k);
			}
		}
		else t = -1;
		return t;
	}
	if (i == 0 || j == 0)
	{
		int n;
		if (i > j)
			n = i;
		else
			n = j;
		int t = 0;
		for (int k = 1; k <= n; k++)
		{
			if (n % k == 0)
				t += kiemtranguyento(k);
		}
		return t;
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << sum_common_prime(m, n);
}
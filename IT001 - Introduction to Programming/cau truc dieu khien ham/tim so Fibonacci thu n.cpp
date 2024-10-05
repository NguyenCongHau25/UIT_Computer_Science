/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
Fibo
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
	int x;
	cin >> x;
	if (x < 1 || x>30)
		cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
	else
	{
		cout << Fibo(x) << endl;
	}
	return 0;
}

int Fibo(int x)
{
//###INSERT CODE HERE -
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

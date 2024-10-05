/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
#include <iomanip>
using namespace std;
double calculate(double a)
{
	double t=0;
	for (int i=1; i<=a; i++)
	{
		t=sqrt(i+t);
	}
	return t;
}

int main() {
	int n;
	cin >> n;
    cout << setprecision(3) << calculate(n);
}


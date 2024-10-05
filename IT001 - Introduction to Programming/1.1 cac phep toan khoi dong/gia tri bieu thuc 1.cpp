#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a, b,c;
   cin >>a>>b>>c;
   cout << fixed<< setprecision(2)  << pow(a,5)-2*sqrt(abs(b))+a*b*c;
   return 0;
}
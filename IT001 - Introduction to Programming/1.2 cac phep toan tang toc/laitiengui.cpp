#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   long long x;
   double y,z,s;
   cin >>x>>y>>z;
   s= x*(1+y*((z/12)/100)) ;
   cout << (long long)s;
   return 0;

}
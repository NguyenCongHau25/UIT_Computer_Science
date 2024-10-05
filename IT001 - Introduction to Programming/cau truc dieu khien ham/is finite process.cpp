#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a >>b;
   if (a>b || abs(a-b)%2==1)
   cout << "TRUE";
   else 
   cout << "FALSE";
    return 0;
}
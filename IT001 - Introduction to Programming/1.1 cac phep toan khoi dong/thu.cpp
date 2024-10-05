#include <iostream>
using namespace std;
int x = 9;
int main()
{
         cout << x;
         int x = 1;
         {
                  cout << x;
                  int x = 7;
                  cout << x;
                  cout << ::x;
         }
         cout << x;
         cout << ::x;

         return 0;
}
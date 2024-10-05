#include <iostream>
#include <string>
using namespace std;
int main()
{
   int x, y;
   int a, b;
   cin >> x >> y;
   cin >> a >> b ;
   cout << "So tien ma ban Nguyen nhan lai: " << 500000 - (x*a + y*b) << endl;
   return 0;
}
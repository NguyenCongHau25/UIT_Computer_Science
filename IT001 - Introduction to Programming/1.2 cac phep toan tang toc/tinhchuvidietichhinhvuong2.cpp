#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  float a;
  cin >>a;
  cout << "Chu vi: "<< fixed << setprecision (2) << a*4 << endl;
  cout << "Dien tich: "<< fixed << setprecision (2) <<a*a;
}
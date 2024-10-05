#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int n;
    cin >> n; 
    cout << "Chu so thuoc hang don vi: "<<  (n % 10) << endl;

    cout << "Chu so thuoc hang chuc: "<< ((n/10))%10 << endl;

    cout << "Chu so thuoc hang tram: " << n/100;
    
  return 0;
}
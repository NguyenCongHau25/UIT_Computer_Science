/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
#include <cmath>


int main()
{
    double a;
    int n;
    std::cin >> a >> n;

//###INSERT CODE HERE -
    a*=n;
    a=round(a);
    a/=n;
    std::cout.precision(10);
    std::cout << a;
    return 0;

}

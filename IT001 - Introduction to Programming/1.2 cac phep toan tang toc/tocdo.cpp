#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double x,y;
    cin >>x>>y;
    cout << setprecision(15) << (x*1000)/(y*3600) << endl;
    return 0;

}
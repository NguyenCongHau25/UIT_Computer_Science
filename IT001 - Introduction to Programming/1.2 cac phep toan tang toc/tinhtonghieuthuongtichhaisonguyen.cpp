#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a,b;
    cin >>a>>b;
    cout << a << " + " << b<< " = "<< a+b<<endl;
    cout << a << " - " << b<< " = "<< a-b<<endl;
    cout << a << " x " << b<< " = "<< a*b<<endl;
    cout << a << " : " << b<< " = "<< fixed << setprecision (2) <<(float) a/b<<endl;
    return 0;
}
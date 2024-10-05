#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if (a!=0)
       cout << "x = " << (float)(-b)/a;
    else
       if(b==0)
        cout << "VSN";
       else
        cout << "VN";
    return 0;
}
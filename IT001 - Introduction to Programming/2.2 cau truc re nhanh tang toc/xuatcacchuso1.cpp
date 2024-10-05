#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >>x;
    x/1;
    if (x==0) cout << x;
    else 
       while (x>0)
       {
        cout << x%10<< endl;
        x/=10;
       }
    return 0;

}
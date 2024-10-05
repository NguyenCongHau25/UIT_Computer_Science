#include <iostream>
using namespace std;
int main()
{
    int n,a,b,s;
    cin >>n>>a>>b;
    s=0;
    for (int i = 1; i <=n; i++ )
        {
            if (i%a==0 && i%b!=0)
            s+=i;
        }
        cout << s;
    return 0;

}
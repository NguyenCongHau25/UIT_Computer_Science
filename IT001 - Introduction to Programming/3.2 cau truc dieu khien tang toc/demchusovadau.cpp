#include <iostream>
using namespace std;
int main()
{
    int n,a;
    cin >>a;
    n=a;
    int i=0;
    if (a==0) cout << "So 0 co 1 chu so";
    else {
        while (a!=0)
        {
            a/=10;
            i++;
        }
        cout << "So "<<n<<" co "<<i<<" chu so";
        if (n<0) cout << " va 1 dau";
    }
    return 0;

}
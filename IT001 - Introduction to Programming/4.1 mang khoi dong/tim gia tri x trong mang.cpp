/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;



int main()
{
    int n, a[100];

//###INSERT CODE HERE -
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    int x; cin >>x;
    int dem=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]==x) 
        {
        cout << x<<" xuat hien dau tien tai vi tri thu "<<i+1<<" trong mang";
        dem++;
        break;
        }
        
    }
    if (dem==0) cout <<"Khong tim thay "<<x;


    return 0;
}


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
    cin >>n;
    for (int i=0; i<n ; i++)
     cin >> a[i];
    if(n==0) cout <<"Mang rong";
    else 
    {   
        if(a[0]%2==0)
        {
            int flag1 =0;
            for(int i=0; i<n; i++)
                if(a[i]%2!=0)
                    flag1 =1;
            if(flag1 == 0) cout << "Mang chua toan so chan";
            else cout <<"Mang khong chua toan so chan hay so le";
        }
        else 
        {
            int flag2=0;
            for (int i=0; i<n;i++)
                if (a[i]%2==0)
                    flag2=1;
            if(flag2==0) cout << "Mang chua toan so le";
            else cout <<"Mang khong chua toan so chan hay so le";
        }
    }







    return 0;
}

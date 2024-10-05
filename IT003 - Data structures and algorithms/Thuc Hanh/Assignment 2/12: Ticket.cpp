#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, mid_left, mid_right, temp, s;

    cin >> n;

    int flag = 0;
    int z;
    for (int i = 1000; i < 10000; i++)
    {
        temp = i;
   
        mid_right = temp % 10 + (temp % 100)/10;
        temp = temp / 100;
        mid_left = temp%10 + temp/10;



        if (mid_left <= mid_right)
        {
            if (mid_left / 10 == 0 )
                s = mid_right * 10 + mid_left;
            else
                s = mid_right * 100 + mid_left;
        }
        else
        {
            if (mid_right/10 == 0)
                s = mid_left * 10 + mid_right;
            else
                s = mid_left * 100 + mid_right;
        }


        if (s == n)
        {
            z = i;
            flag = 1;
            break;
        }
    }
    
    if (flag == 0)
        cout << 0;
    else 
        cout << z;

    return 0;
}
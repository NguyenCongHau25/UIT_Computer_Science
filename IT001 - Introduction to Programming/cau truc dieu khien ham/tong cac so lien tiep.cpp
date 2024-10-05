/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;


//###INSERT CODE HERE -
int isSumOfConsecutive(int n)
{
    int sum;
    int d =0;
    for (int i=1; i<n; i++)
    {
        int k = i;
        sum=0;
        while (true)
        {
            sum+=k;
            k++;
            if (sum>n)
            break;
            if (sum==n)
            {
             d++;
             break;
            }
        }
    }
    return d;
}


int main()
{
    int n;cin>>n;
    cout <<isSumOfConsecutive(n)<< endl;
    return 0;
}



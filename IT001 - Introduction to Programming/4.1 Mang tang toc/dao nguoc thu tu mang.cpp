
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
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Mang da nhap:"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
//###INSERT CODE HERE -
    int c;
    int q=n-1;
    for (int i=0; i<(n+1)/2; i++)
        {
            c=a[i];
            a[i]=a[q];
            a[q]=c;q--;
        }
    cout<<endl<<"Mang sau khi dao:"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}

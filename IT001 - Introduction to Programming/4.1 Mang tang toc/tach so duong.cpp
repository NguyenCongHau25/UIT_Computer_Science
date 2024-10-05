
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;


//###INSERT CODE HERE -
void inputArray(int a[],int &na)
{
    
    cin >> na;
    for (int i=0; i<na;i++)
    cin >> a[i];
}
void outputArray(int a[],int na)
{   
    for(int i=0;i<na;i++)
     cout << a[i] << " ";
}
void getPositiveNumber(int a[], int &na, int b[], int &nb)
{   nb=0;
    for(int i=0; i<na; i++)
        if (a[i]>0)
            b[nb++]=a[i];
            
                      
}

int main()
{
    int na, a[100], nb, b[100];
    inputArray(a,na);
    cout<<"Array a:"<<endl;
    outputArray(a,na);
    cout<<endl;

    getPositiveNumber(a,na,b,nb);

    cout<<"Array b:"<<endl;
    outputArray(b,nb);

    return 0;
}

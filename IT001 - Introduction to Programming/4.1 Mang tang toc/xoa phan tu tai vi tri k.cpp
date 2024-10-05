
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i =0; i < n;i++)
        cin >> a[i];
}
void outputArray(int a[], int &na)
{
   for (int i=0; i < na; i++ )
        cout << a[i]<< " ";

}
int deleteElement(int a[], int &n, int &pos)
{       if (pos <0 || pos >= n) 
        {
            cout << endl; 
            cout << "Loi xoa: Vi tri khong hop le";
            return -1;        
        }
           
            
        else
        {
            for (int i= pos + 1; i<= n-1; i++)
            a[i-1]=a[i];
            n--;
            return 1;
        }
}

int main()
{
    int n, a[100],pos;
    inputArray(a,n);
    cin>>pos;
    cout<<"Before: ";
    outputArray(a,n);

    if (deleteElement(a,n,pos)!=-1)
    {
        cout<<"\nAfter: ";
        outputArray(a,n);
    }

    return 0;
}

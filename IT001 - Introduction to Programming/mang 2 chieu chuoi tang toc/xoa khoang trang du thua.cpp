#include <iostream>
#include <string>
using namespace std;
string xoakhoangtrang( string a)
{
    for (int i=0; i<a.length(); i++)
    {   if (a[0]==' ')
            a.erase(0,1);
        if (a[i]==' '&& a[i+1]==' ')
            {
                a.erase(i,1);
                i-=1;
            }            
        if (a[a.length()-1]==' ')
            a.erase(a.length()-1,1);
    }
    return a;
}
int main ()
{
    string a;
    getline(cin,a);
    cout << xoakhoangtrang(a);
    return 0;
}
#include <iostream>
using namespace std;
int main ()
{
   int n,hd,td;
   cin >> n;
    for (int i = 0;i < n; i++)
    {
        cin  >> hd >> td;
        if (hd==0 && td==0) cout << "O"<< endl;
        if (hd==0 && td!=0) cout << "T"<< endl;
        if (hd!=0 && td==0) cout << "H"<< endl;
        if (hd>0  && td >0) cout << "I" << endl;
        if (hd>0  && td <0 ) cout << "IV"<< endl;
        if (hd<0  && td >0) cout << "II"<< endl;
        if (hd<0  && td <0) cout << "III"<< endl;
    }
    return 0;
}
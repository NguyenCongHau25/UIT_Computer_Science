#include <bits/stdc++.h>
using namespace std;

int main()
{
        double a,b,c,DTB;
        cin >> a >> b >> c;
        DTB=(a+b+c)/3;
        
        cout << "DTB = " << setprecision(3)<<DTB << endl;
        if (DTB >= 9 && DTB <= 10)
            cout << "Loai: XUAT SAC";
        else if (DTB >= 8)
            cout << "Loai: GIOI";
        else if (DTB >= 7)
            cout << "Loai: KHA";
        else if (DTB >= 6)
            cout << "Loai: TB KHA";
        else if (DTB >= 5)
            cout << "Loai: TB";
        else if (DTB >= 4)
            cout << "Loai: YEU";
        else cout << "Loai: KEM";


         return 0;
}
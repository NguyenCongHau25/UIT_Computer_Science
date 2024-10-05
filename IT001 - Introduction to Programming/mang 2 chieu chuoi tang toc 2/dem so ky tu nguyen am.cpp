
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -
int DemSoKyTuNguyenAm(char s[256])
{
    int dem=0;
    for (int i=0; i<strlen(s); i++)
        if (s[i]=='O' || s[i] == 'o' || s[i] == 'A' || s[i] == 'a' || s[i]=='e' || s[i]=='E' || s[i]=='U' || s[i] == 'u' || s[i]=='i' || s[i]=='I')
            dem++;
    return dem;
}

int main()
{
    char s[256];
    cin.getline(s,256);
    cout<<DemSoKyTuNguyenAm(s);
    return 0;
}

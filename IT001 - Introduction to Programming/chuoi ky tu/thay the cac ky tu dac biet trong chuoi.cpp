/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -
void ThayTheKyTuDacBiet(char s[])
{
   
    for (int i=0; i<strlen(s); i++)
    {
        if ('a'<=s[i] && s[i]<= 'z' || 'A' <= s[i] && s[i]<= 'Z' || '0'<=s[i]&& s[i]<= '9')
            continue;
        s[i]='.';
    }
}

int main()
{
    char s[256];
    cin.getline(s,256);
    ThayTheKyTuDacBiet(s);// Ham thay the cac ky tu dac biet co trong chuoi s thanh ky tu .
    cout<<s;
    return 0;
}

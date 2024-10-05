/*###Begin banned keyword -SoSanhBangNhauTheoChuC each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -
int SoSanhBangNhauTheoChuCai(char s[], char t[])
{
    if (strlen(s)!= strlen(t))
        return 0;
    for (int i=0; i<strlen(s); i++)
            {
                if (('0' <= s[i] && s[i] <='9') && !('0'<=t[i]<='9'))
                    return 0;
                if ( ('0'<=t[i] && t[i] <='9') && !(s[i]>='0' || s[i]<='9') )
                    return 0;
                if( ('a'<=s[i] && s[i]<='z') || ('A' <=s[i] && s[i] <='A'))
                {
                    if(abs(s[i]-t[i])!=32)
                        return 0;
                }
                if ('a'<=t[i] && s[i] <='z' || 'A' <=t[i] && t[i] <='A')
                {
                    if(abs(s[i]-t[i])!=32)
                        return 0;
                }
  
            }
       return 1; 
 }
int main()
{
    char s[256], t[256];
    cin.getline(s,256);
    cin.getline(t,256);
    cout<<SoSanhBangNhauTheoChuCai(s,t);//chu cai giong nhau khac loai chu hoa va thuong, cung la so

    return 0;
}

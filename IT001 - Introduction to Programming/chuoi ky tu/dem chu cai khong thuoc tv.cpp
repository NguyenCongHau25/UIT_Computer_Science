
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
int countLetters(char s[])
{
    int d=0;
    for (int i=0; i<strlen(s); i++)
        if(s[i]=='w' || s[i]=='W' || s[i]== 'f' || s[i]=='F' || s[i]== 'j' || s[i]== 'J' || s[i]=='z' || s[i]=='Z')
            d++;
    return d;
}
int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countLetters(s) << endl;
    return 0;
}

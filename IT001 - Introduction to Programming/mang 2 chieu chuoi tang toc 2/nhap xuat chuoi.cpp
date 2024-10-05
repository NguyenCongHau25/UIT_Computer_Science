/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

//###INSERT CODE HERE -
int check(char s[MAX])
{
    int i=0;
    while (s[i]!= '\0')
    {
        if (s[i]>'0' && s[i]<'9')
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    char s[MAX];
    cin.getline(s,MAX);
    if (check(s))   
        cout << s;
    else 
        cout << "CHUOI KHONG HOP LE.";
    return 0;
}
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
using namespace std;

//###INSERT CODE HERE
void encloseInBrackets(char a[])
{
    char b[45]="(";
    strcat(b,a);
    strcat(b,")");
    strcpy(a,b);
}

int main ()
{
    char a[100];
    cin.getline(a,40);
    encloseInBrackets(a);
    cout<<a;
    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//###INSERT CODE HERE -
void MaHoaMatThu(char s[])
{ 
    for (int i=0; i<strlen(s); i++)
    {
        s[i]=tolower(s[i]);
        if ('a'<=s[i] && s[i]<='z')
            {
                cout << s[i]-'a'+1;
            if (s[i+1]!=' ' && i+1 <strlen(s)) 
                cout << '.';
            }
        else if(s[i]==' ')
            cout << '-';  
            
    }    
}

int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nChuoi sau khi duoc ma hoa: ";
    MaHoaMatThu(s);

    return 0;
}

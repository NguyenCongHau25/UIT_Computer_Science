/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
toupper
tolower
###End banned keyword*/
#include <iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
void transformString(char s1[], char s2[])
{
    strcpy(s2,s1);
    for (int i=0; i<strlen(s2);i++)
        {
            if ( 'a'<=s2[i]&&s2[i]<='z' || 'A' <= s2[i] && s2[i]<='Z') 
            {
                if (i%2==0 && 'a'<=s2[i]&&s2[i]<='z')
                    s2[i]=s2[i]-32;
                else if (i%2!=0 && 'A' <= s2[i] && s2[i]<='Z')
                    s2[i]=s2[i]+32;
            }
                
            else s2[i]='*';
                
            
        }
}
int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";
    cin.getline(s1, 199);
    transformString(s1, s2); //khong dung duoc ham toupper, tolower
    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}


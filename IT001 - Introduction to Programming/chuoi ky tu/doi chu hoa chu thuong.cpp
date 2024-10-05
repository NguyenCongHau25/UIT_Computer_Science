#include <iostream>
#include <cstring>
using namespace std;

void properNounCorrection(char str[])
{
   for (int i=0; i<strlen(str); i++)
   {
    if('a'<=str[i]&&str[i]<='z') 
        str[i]=toupper(str[i]);
    else if( 'A' <= str[i] && str[i]<='Z')
        str[i]=tolower(str[i]);
   }
}
int main()
{

   char str[10000];
   cin.getline(str,10000);
   properNounCorrection(str);
   cout<<str;
   return 0;
}
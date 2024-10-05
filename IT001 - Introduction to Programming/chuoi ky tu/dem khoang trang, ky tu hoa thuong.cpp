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

//###INSERT CODE HERE -
int countBlankSpace(char str[])
{
   int dem=0;
   for (int i=0; i<strlen(str); i++)
   
      if (str[i]==' ')
      dem++;
   
   return dem;
}
void countUpperLower( char str[])
{
   int d=0; 
   for (int i=0; i < strlen(str); i++)
   {
      if('A' <= str[i] && str[i]<='Z')
      d++;
   }
   cout << "\nSo ky tu hoa: " << d << endl;
   int s=0;
   for (int i=0; i<strlen(str); i++)
   {
      if ('a'<=str[i]&&str[i]<='z')
         s++;
   }
   cout << "So ky tu thuong: " << s;
}
int main()
{

   char str[100], str1[100];
   cin.getline(str,100);
   cout<<"Chuoi: "<<str;
   cout<<"\nSo ky tu khoang trang: "<<countBlankSpace(str);
   countUpperLower(str);



   return 0;
}

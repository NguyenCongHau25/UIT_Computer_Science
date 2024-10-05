/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
string
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

//###INSERT CODE HERE -

void xoakhoangtrang( char s[])
{
	int i=0;
	while (s[i]==' ')
	{
		i++;
	}
	if (i>0)
		for (int j=0; j<strlen(s); j++)
			s[j]=s[j+i];
	
	int z=strlen(s);
	while (s[z]==' ')
	{
		z--;
	}
	if (z<strlen(s))
		s[z]='\0';

}
void Chuanhoa(char s[])
{
    xoakhoangtrang(s);
	for (int i=0; i<strlen(s); i++)
		s[i]=tolower(s[i]);
	for (int i=0; i<strlen(s);i++)
	{
		s[0]=toupper(s[0]);
		if (s[i]==' ')
			s[i+1]=toupper(s[i+1]);
	}
	

}

int main()
{
	char s[MAX];
	cin.getline(s, 299);
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}


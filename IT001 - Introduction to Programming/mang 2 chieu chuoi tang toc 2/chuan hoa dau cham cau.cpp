/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
class
string
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

//###INSERT CODE HERE -
void erase(char s[], int pos)
{
	
	for (int i=pos; i<strlen(s); i++)
		s[i]=s[i+1];
	s[strlen(s)]='\0';
}

void thua(char s1[])
{
	for (int i=0; i<strlen(s1); i++)
	{
		if (s1[i]==' ' && s1[i+1]==' ')
			{
				erase(s1,i);
				i--;
			}
	}
}
void truoccham(char s[])
{
	for (int i=0; i<strlen(s); i++)
	{
		if (s[i]==' ' && s[i+1]=='.')
			{
				erase(s,i);
				i--;
			}
	}
}
void xoadaucham(char s[])
{
	for (int i=0; i<strlen(s); i++)
	{
		if (s[i]=='.' && s[i+1]=='.')
			{
				erase(s,i);
				i--;
			}
	}
}
void themkc(char s[])
{
	int index=strlen(s);
	for (int i=0; i<index; i++)
	{
		if (s[i]=='.' && s[i+1]!=' ' && s[i+1] !='\0')
			{	index++;
				int n=index;
				while (n!= i + 1)
					{
						s[n]=s[n-1];
						n--;
					}
				s[i+1]=' ';
			}
		
	}
	s[index+1]='\0';
}

void Chuanhoa (char s[])
{
	thua(s);
	truoccham(s);
	xoadaucham(s);
	themkc(s);
	
}

int main()
{
	char s[MAX];
	cin.getline(s, 299);
	char s1[MAX];
	strcpy(s1, s);
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}


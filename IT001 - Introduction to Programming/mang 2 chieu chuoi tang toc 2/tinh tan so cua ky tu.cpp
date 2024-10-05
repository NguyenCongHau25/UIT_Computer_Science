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

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	cin.getline(s, 299);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);

	return 0;
}

//###INSERT CODE HERE -
int myStrlen(char s[], int k)
{
	int i=0;
	int dem=0;
	while(s[i]!='\0')
	{
		dem++;
		i++;
	}
	return dem;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
	return (myStrlen(s1,0)==myStrlen(s2,0))?0:1;
}
int kiemtra(char n, char s[], int i)
{
	int k=0;
	for (int j=0; j<i; j++)
	{
		if (s[j]==n)
			k++;
	}
	return (k>0)?0:1;
}
void DemKyTu(char s[])
{
	for (int i=0; i<myStrlen(s,0); i++)
	{
		int d=0;
		for (int j=0; j<myStrlen(s,0);j++)
			{
				if (s[j]==s[i])	
				d++;
			}
		if (kiemtra(s[i],s,i))
			cout << s[i] << ": "<<d << endl;
		
	}
}


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
#define MAX 255

int myStrcmp(char s1[], char s2[]);


int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1, 254);
	cin.getline(s2, 254);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
	return 0;
}
//###INSERT CODE HERE -
int myStrlen(char s[])
{
	int i=0;
	int d=0;
	while (s[i]!='\0')
	{
		d++;
		i++;
	}
	return d;
}
int myStrcmp (char s1[], char s2[])
{
	if (myStrlen(s1)==myStrlen(s2))
	{
		int d=0;
		for (int i=0; i<myStrlen(s1); i++)
			if (s1[i]!=s2[i])
				d++;
		if (d>0)
		for (int i=0; i<myStrlen(s1); i++)
			{
				if (s1[i]>s2[i]) 
				return 1;
				if (s1[i]<s2[i])
				return -1;
			}
		return 0;
	}
	else if (myStrlen(s1)>myStrlen(s2)) return 1;
	else if (myStrlen(s1)<myStrlen(s2)) return -1;
}
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
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1, 254);
	cin.getline(s2, 254);
	bool kt = myStrcat(s1, s2);
	
//###INSERT CODE HERE -
	if (kt)
		cout << s1 << s2;
	else
		cout << "Khong noi duoc. Khong du bo nho.";
}
int myStrlen(char s[])
{
	int d=0, i=0;
	while (s[i]!='\0')
	{
		d++;
		i++;
	}
	return d;
}

bool myStrcat(char s1[], char s2[])
{
	if (myStrlen(s1)+myStrlen(s2)>254)
		return 0;
	return 1;
}

